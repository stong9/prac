class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if(strs.size() == 0) return "";

		int num = strs.size();
		int len = strs[0].size();

		for(int j = 0; j<len; j++){
			for(int i = 1; i <num; i++){
				if(strs[i][j]!=strs[i-1][j]){
					return strs[0].substr(0,j);
				}
			}
		}
		return strs[0];
	}
};