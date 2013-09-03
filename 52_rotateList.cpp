 ListNode *rotateRight(ListNode *head, int k) {  
   // Start typing your C/C++ solution below  
   // DO NOT write int main() function  
   if(head == NULL || k ==0) return head;  
   int len =1;  
   ListNode* p = head,*pre;  
   while(p->next!=NULL)  
   {  
	 p = p->next;  
	 len++;      
   }  
   k = len-k%len;  
   p->next = head;  
   int step =0;  
   while(step< k)  
   {  
	 p = p->next;  
	 step++;  
   }  
   head = p->next;  
   p->next = NULL;  
   return head;  
 }  