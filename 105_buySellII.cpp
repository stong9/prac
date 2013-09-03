int maxProfit(vector<int> &prices) {  
  // Start typing your C/C++ solution below  
  // DO NOT write int main() function  
  int max=0;  
  int sum = 0;  
  for(int i =1; i< prices.size(); i++)  
  {  
	int diff = prices[i] -prices[i-1];  
	if(diff>0)  
	  sum+=diff;  
  }  
  return sum;  
}  