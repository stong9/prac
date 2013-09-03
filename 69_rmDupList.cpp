 ListNode *deleteDuplicates(ListNode *head) {  
   // Start typing your C/C++ solution below  
   // DO NOT write int main() function  
   if(head == NULL) return NULL;  
   ListNode * pre = head;  
   ListNode *p = head->next;  
   while(p!=NULL)  
   {  
	 if(pre->val == p->val)  
	 {  
	   ListNode* temp = p;  
	   p = p->next;  
	   pre->next =p;  
	   delete temp;  
	   continue;  
	 }  
	 pre = pre->next;  
	 p = p->next;  
   }  
   return head;  
 }