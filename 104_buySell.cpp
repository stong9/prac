class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int sz = prices.size();
		if (sz < 2)
		return 0;
		int min = prices[0];
		int maxDiff = 0;

		for (int i = 1; i < sz; i++) {
			if (prices[i] < min){
				min = prices[i];
				continue;
			}
			int diff = prices[i] - min;
			if (diff > maxDiff) {

				maxDiff = diff;
			}
		}
		return maxDiff;
	}
};