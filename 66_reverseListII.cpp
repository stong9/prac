/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {   
		// Start typing your C/C++ solution below   
		// DO NOT write int main() function   
		if (head == NULL){
			return head;
		}
		ListNode* safeG = new ListNode(-1);
		safeG->next = head;
		ListNode* pre = safeG;   
		ListNode* cur = head;
		int step = 0;
		while(step < m - 1)   
		{   
			pre = cur;
			cur = cur->next;
			++step;   
		}   
		
		ListNode* beforeM = pre;
		ListNode* M = cur;
		ListNode* next = cur->next;
		step = 0; 
		while(step < n - m )   
		{   
			pre = cur;
			cur = next;
			next = cur->next;   
			cur->next = pre;   
			
			++step;   
		}   
		beforeM->next = cur;   
		M->next = next;   
		
		
		head = safeG->next;
		delete safeG;
		return head;     
	}   
};