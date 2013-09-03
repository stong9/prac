class Solution {
public:
bool isInterleave(string s1, string s2, string s3) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function          
    int len1=s1.size(), len2=s2.size(), len3=s3.size();        
    if(len1+len2 != len3) return false;

    //switch to save space later on.
    if(len2>len1)  {string tmp=s2; s2=s1; s1=tmp;}

    vector<bool> isPrefix(s2.size()+1, false);
    isPrefix[0]=true;

    for(int i=1; i<=s2.size(); i++) isPrefix[i] = s2.substr(0, i) == s3.substr(0, i);

    for(int i=1; i<=s1.size(); i++){
        isPrefix[0] = s1.substr(0, i)==s3.substr(0,i);
        for(int j=1; j<=s2.size(); j++)
            isPrefix[j]= (isPrefix[j-1]&&s2[j-1]==s3[i+j-1] || isPrefix[j]&&s1[i-1]==s3[i+j-1]);
    }
    return isPrefix.back();
}
};