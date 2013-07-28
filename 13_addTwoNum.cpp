class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (l1 == NULL && l2 == NULL)
		return NULL;
		ListNode *result = NULL;
		ListNode *head = result;
		int carry = 0;
		while (l1 != NULL || l2 != NULL)
		{
			int m = 0;

			if (l1 != NULL)
			{
				m += l1 -> val;
				l1 = l1 -> next;
				
			}
			if (l2 != NULL)
			{
				m += l2 -> val;
				l2 = l2 -> next;
				
			}
			m += carry;
			
			carry = m / 10;
			m = m % 10;
			
			if (head == NULL){
				head = new ListNode(m);   
				
				result = head;    
				
			}
			else{
				head->next = new ListNode(m);
				head = head->next;
			}
		}
		if (carry != 0)
		{

			head -> next = new ListNode(carry);
		}
		return result;
	}
};