class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (s2.size() != n) return false;

        bool f[n][n][n];

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                f[i][j][0] = s1[i] == s2[j];

        for (int l=1; l<n; l++) {
            for (int i=0; i+l<n; i++) {
                for (int j=0; j+l<n; j++) {
                    f[i][j][l] = false;
                    for (int k=0; k<l; k++) {
                        if (f[i][j][k] && f[i+k+1][j+k+1][l-1-k]
                            || f[i][j+l-k][k] && f[i+k+1][j][l-1-k]) {
                            f[i][j][l] = true;
                            break;
                        }
                    }
                }
            }
        }

        return f[0][0][n-1];
    }
};