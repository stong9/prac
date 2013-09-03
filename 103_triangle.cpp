int minimumTotal(vector<vector<int> > &triangle) {  
  // Start typing your C/C++ solution below  
  // DO NOT write int main() function  
  int row = triangle.size();  
  if(row ==0) return 0;  
  int *minV = new int[triangle[row-1].size()];  
  for(int i = row-1; i>=0; i--)  
  {  
	int col = triangle[i].size();  
	for(int j =0; j<col; j++)  
	{  
	  if(i == row-1)  
	  {  
		minV[j] = triangle[i][j];  
		continue;  
	  }  
	  minV[j] = min(minV[j+1], minV[j]) + triangle[i][j];  
	}        
  }      
  int min = minV[0];  
  delete minV;  
  return min;  
}  