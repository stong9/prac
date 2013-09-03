int removeDuplicates(int A[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (n == 0){
		return n;
	}
	int i = 0;
	int j = 1;
	int count = 1;
	for (;j < n; ++j){
		if (A[i] == A[j]){
			if (count < 2){
				++i;
				++count;
				A[i] = A[j];
			}
		}
		else{
			count = 1;
			++i;
			A[i] = A[j];
		}
		
	}
	return i+1;

}