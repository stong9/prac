ListNode *deleteDuplicates(ListNode *head) {  
	 if(head == NULL) return head;  
	 ListNode *G = new ListNode(INT_MIN);  
	 G->next = head;  
	 ListNode *cur = G, *pre = head;  
	 while(pre!=NULL)  
	 {  
		  bool isDup = false;  
		  while(pre->next!=NULL && pre->val == pre->next->val)  
		  {  
			   isDup = true;  
			   ListNode *temp = pre;  
			   pre = pre->next;  
			   delete temp;  
		  }  
		  if(isDup)  
		  {  
			   ListNode *temp = pre;  
			   pre = pre->next;  
			   delete temp;  
			   continue;  
		  }  
		  cur->next = pre;  
		  cur = cur->next;  
		  pre= pre->next;  
	 }  
	 cur->next = NULL;  
	 ListNode *temp = G->next;  
	 delete G;  
	 return temp;      
}  