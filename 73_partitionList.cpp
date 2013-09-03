ListNode *partition(ListNode *head, int x) {  
	// Start typing your C/C++ solution below  
	// DO NOT write int main() function      
	ListNode* p = new ListNode(x-1);  
	p->next = head;  
	head = p;  
	ListNode* pre;  
	while(p!=NULL && p->val < x)  
	{  
		pre = p;  
		p = p->next;  
	}  
	if(p!=NULL)  
	{      
		ListNode* cur = pre;  
		while(p!=NULL)      
		{  
			if(p->val <x)  
			{  
				ListNode* temp = cur->next;  
				pre->next = p->next;  
				cur->next = p;  
				cur = p;  
				p->next = temp;  
				p = pre;  
			}  
			pre=p;  
			p= p->next;        
		}  
	}  
	ListNode* temp = head;  
	head = head->next;  
	delete temp;  
	return head;      
}  