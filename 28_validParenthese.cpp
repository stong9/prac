class Solution {
public:
	bool isValid(string s) {  
		// Start typing your C/C++ solution below  
		// DO NOT write int main() function  
		vector<char> sta;  
		if(s.size() ==0) return false;  
		sta.push_back(s[0]);  
		for(int i =1; i< s.size(); i++)  
		{  
			if(s[i] == '(' || s[i] == '[' || s[i] == '{')  
			{  
				sta.push_back(s[i]);  
				continue;  
			}  
			char current = sta.back();  
			if(s[i] == ')' && current != '(')  
			return false;  
			if(s[i] == ']' && current != '[')  
			return false;  
			if(s[i] == '}' && current != '{')  
			return false;  
			sta.pop_back();  
		}  
		if(sta.size() !=0) return false;  
		return true;  
	}  
};