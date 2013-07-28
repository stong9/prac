class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort (num.begin(),num.end());
		int i = 0;
		int n = num.size();
		int result = num[0] + num[1] + num[2];
		for (;i<n-2;i++){
			int j = i+1;
			int k = n-1;
			
			while (j < k){
				int sum_two = num[i] + num[j];
				if (abs(target - result) > abs(target - sum_two - num[k])){
					result = sum_two + num[k];
				}
				if ((sum_two + num[k]) == target){
					return sum_two + num[k];
				}
				else if ((sum_two + num[k]) > target){
					
					--k;
				}
				else{
					++j;
				}
			}
		}
		return result;
	}
};