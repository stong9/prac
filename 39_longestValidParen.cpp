int longestValidParentheses(string s) {  
	 const char* str = s.c_str();  
	 int nMax=0;  
	 const char *p = str;  
	 vector<const char*> sta;  
	 while(*p !='\0')  
	 {  
		  if(*p == '(')  
		  {  
			   sta.push_back(p);                      
		  }  
		  else  
		  {  
			   if(!sta.empty() && *sta.back()=='(')  
			   {  
					sta.pop_back();  
					nMax = max(nMax, p-(sta.empty()?str- 1:sta.back()));  
			   }  
			   else  
			   {  
					sta.push_back(p);  
			   }  
		  }  
		  p++;  
	 }  
	 return nMax;  
}  