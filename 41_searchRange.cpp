vector<int> searchRange(int A[], int n, int target) {  
	 // Start typing your C/C++ solution below  
	 // DO NOT write int main() function  
	 vector<int> range;  
	 int index = searchTarget(A, 0, n-1, target);  
	 if(index == -1)  
	 {  
		  range.push_back(-1);  
		  range.push_back(-1);  
	 }  
	 else  
	 {  
		  int is = index;  
		  while(is>0 && A[is-1] == A[index]) is--;  
		  int ie = index;  
		  while(ie<n-1 && A[ie+1] == A[index]) ie++;  
		  range.push_back(is);  
		  range.push_back(ie);        
	 }  
	 return range;  
}  
int searchTarget(int A[], int start, int end, int target)  
{  
	 if(start > end) return -1;  
	 int mid = (start+end)/2;  
	 if(A[mid] == target) return mid;  
	 if(A[mid]<target)  
	 return searchTarget(A, mid+1, end, target);  
	 else  
	 return searchTarget(A, start, mid-1, target);      
}  