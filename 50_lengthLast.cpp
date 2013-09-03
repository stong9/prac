int lengthOfLastWord(const char *s) {  
	 const char *p =s;  
	 const char *start=p;  
	 int len=0;  
	 while(*p!='\0')  
	 {  
		  if(*p == ' ')  
		  {  
			   len = p - start;  
			   while(*p == ' ') p++;  
			   start = p;   
			   continue;  
		  }  
		  p++;                 
	 }  
	 if(*start !='\0')  
		  len = p-start;  
	 return len;  
}  