class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.empty()) {
			return 0;
		}

		int n = matrix[0].size();
		vector<int> H(n);
		vector<int> L(n);
		vector<int> R(n, n);

		int ret = 0;
		for (int i = 0; i < matrix.size(); ++i) {
			int left = 0, right = n;
			// calculate L(i, j) from left to right
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '1') {
					++H[j];
					L[j] = max(L[j], left);
				}
				else {
					left = j+1;
					H[j] = 0; L[j] = 0; R[j] = n;
				}
			}
			// calculate R(i, j) from right to right
			for (int j = n-1; j >= 0; --j) {
				if (matrix[i][j] == '1') {
					R[j] = min(R[j], right);
					ret = max(ret, H[j]*(R[j]-L[j]));
				}
				else {
					right = j;
				}
			}
		}

		return ret;
	}
};