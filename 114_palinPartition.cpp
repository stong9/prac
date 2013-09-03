class Solution {
public:
	vector<vector<string>> partition(string s) {  
		vector<vector<string>> result;  
		vector<string> output;  

		int** ary = new int*[s.size()];

		for (int j = 0; j < s.size(); ++j){
			ary[j] = new int[j+1];
		}
		for (int j = 0; j < s.size(); ++j){
			for (int i = 0; i <= j; ++i){
				ary[j][i] = -1;
			}
		}
		DFS(s, 0, output, result,ary);  
		return result;  
	}  
	void DFS(string &s, int start, vector<string>& output, vector<vector<string>> &result,int** ary)  
	{      
		if(start == s.size())  
		{  
			result.push_back(output);  
			return;  
		}  
		for(int i = start; i< s.size(); i++)  
		{    
			int judge = ary[i][start];
			if (judge == -1){
				if (isPalindrome(s,start,i)){
					judge = 1;
					ary[i][start] = 1;
				}else{
					judge = 0;
					ary[i][start] = 0;
				}
			}
			if(judge == 1)  
			{  
				output.push_back(s.substr(start, i-start+1));  
				DFS(s, i+1, output, result,ary);  
				output.pop_back();  
			}  
		}  
	}  
	bool isPalindrome(string &s, int start, int end)  
	{  
		while(start< end)  
		{  
			if(s[start] != s[end])  
			return false;  
			start++; end--;  
		}  
		return true;  
	}  
};