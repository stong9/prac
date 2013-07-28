class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {  
		if(lists.size() == 0) return NULL;  
		ListNode *p = lists[0];  
		for(int i =1; i< lists.size(); i++)  
		{  
			p = merge2Lists(p, lists[i]);  
		}  
		return p;  
	}  
	ListNode * merge2Lists(ListNode *head1, ListNode *head2)  
	{  
		ListNode *head = new ListNode(INT_MIN);  
		ListNode *p = head;  
		while(head1!=NULL && head2!=NULL)  
		{  
			if(head1->val < head2->val)  
			{  
				p->next = head1;  
				head1 = head1->next;  
			}  
			else  
			{  
				p->next = head2;  
				head2 = head2->next;  
			}  
			p = p->next;  
		}  
		if(head1 !=NULL)  
		{  
			p->next = head1;  
		}  
		if(head2 != NULL)  
		{  
			p->next = head2;  
		}  
		p = head;  
		head = head->next;  
		delete p;  
		return head;  
	}  
};