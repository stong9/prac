class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		if (n < 1){
			return 0;
		}
		int i = -1;
		int j = 0;
		while (j < n){
			while (A[j] == elem){
				++j;
			}
			if (j >= n){
				break;
			}
			++i;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			++j;
		}
		return ++i;
		
	}
};