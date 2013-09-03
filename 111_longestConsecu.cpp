class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		map<int, int> mapping;
		int maxNum = 1;
		for (int j = 0; j< num.size();++j ) {
			int i = num[j];
			if (mapping.find(i) != mapping.end()) continue;
			mapping.insert(pair<int,int>(i, 1));
			if (mapping.find(i - 1) != mapping.end()) {
				maxNum = max(maxNum, merge(mapping, i-1, i));
			}
			if (mapping.find(i+1) != mapping.end()) {
				maxNum = max(maxNum, merge(mapping, i, i+1));
			}
		}
		return maxNum;
	}
	int merge(map<int, int> &mapping, int left, int right) {
		
		int upper = right + mapping[right] - 1;
		int lower = left - mapping[left] + 1;
		int len = upper - lower + 1;
		mapping[upper]= len;
		mapping[lower]= len;
		return len;
	}
};