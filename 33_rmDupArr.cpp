class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n < 2){
			return n;
		}
		int i = 0;
		int j = 1;
		while (j < n){
			int index = 0;
			for (; index <= i; index++){
				if (A[index] == A[j]){
					break; 
				}
			}
			if (index == (i + 1)){
				++i;
				A[i] = A[j];
			}
			++j;
		}
		return ++i;
	}
};