bool isAlphanumeric(char &c) {
    if(c >= 'A' && c <= 'Z') c += 32;
    else if(c >= '0' && c <= '9' || c >= 'a' && c <= 'z') return true;
    else return false;

    return true;
}

bool isPalindrome(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int i = 0, j = s.length()-1;

    while(i < j) {
        if(!isAlphanumeric(s[i])) ++i;
        else if(!isAlphanumeric(s[j])) --j;
        else if(s[i++] != s[j--]) return false;
    }

    return true;
}