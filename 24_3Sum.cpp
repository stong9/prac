class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &arr) {
		sort(arr.begin(), arr.end());
		set<vector<int> > triplets;
		vector<int> triplet(3);
		int n = arr.size();
		for (int i = 0;i < n; i++) {
			int j = i + 1;
			int k = n - 1;
			while (j < k) {
				int sum_two = arr[i] + arr[j];
				if (sum_two + arr[k] < 0) {
					j++;
				} else if (sum_two + arr[k] > 0) {
					k--;
				} else {
					triplet[0] = arr[i];
					triplet[1] = arr[j];
					triplet[2] = arr[k];
					triplets.insert(triplet);
					j++;
					k--;
				}
			}
		}
		vector<vector<int>> result;
		copy(triplets.begin(),triplets.end(),back_inserter(result));
		return result;
		
	}
};