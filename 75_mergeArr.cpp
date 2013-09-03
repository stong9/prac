class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int pos = m + n -1;
        int a = m - 1;
        int b = n - 1;
        while(a>=0 && b>=0) A[pos--] = A[a]>B[b] ? A[a--] : B[b--];
        while(b>=0) A[pos--] = B[b--];      
    }
};