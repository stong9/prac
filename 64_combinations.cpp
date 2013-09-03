class Solution {
public:
	vector<vector<int> > combine(int n, int k) {  
		// Start typing your C/C++ solution below  
		// DO NOT write int main() function  
		vector<vector<int> > result;  
		vector<int> solution;  
		GetCombine(n,k,0,1,solution, result);  
		return result;  
	}  
	void GetCombine(  
	int n,   
	int k,   
	int choosed,
	int start,  
	vector<int>& solution,  
	vector<vector<int> >& result)  
	{      
		if(choosed == k)  
		{  
			result.push_back(solution);  
			return;  
		}
		++choosed;
		for(int i =start; i<= n - (k - choosed); i++)  
		{  
			solution.push_back(i);  
			GetCombine(n,k,choosed, i+1, solution, result);  
			solution.pop_back();  
		}  
	} 
};