string getPermutation(int n, int k) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	char nums[] = "123456789";
	string str;
	int it = 2;
	--k;
	int product = 1;
	while (it <= n){
		product *= it;
		++it;
	}
	it = 0;
	while (it < n){
		product /= (n-it);
		int index = k/product;
		str.append(1,nums[index]);
		for (int i = index; i < n-1; i++){
			nums[i] = nums[i+1];
		}
		k = k % product;
		++it;
	}
	return str;
	
}