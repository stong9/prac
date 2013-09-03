ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {  
	ListNode* head = new ListNode(-1);  
	ListNode* p = head;  
	while(l1!=NULL && l2!= NULL)  
	{  
		int val1 = l1->val;  
		int val2 = l2->val;  
		if(val1<=val2)  
		{  
			p->next = l1;          
			l1=l1->next;  
		}  
		else  
		{  
			p->next = l2;  
			l2 = l2->next;  
		}  
		p= p->next;  
	} 
	if (l1 != NULL){
		p->next = l1;
	}
	else{
		p->next = l2;
	}
	p = head->next;  
	delete head;  
	return p;  
}  