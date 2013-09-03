class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > table(word1.size()+1, vector<int>(word2.size()+1));
        for(int i = 0; i < word1.size()+1; ++i) {
            for(int j = 0; j < word2.size()+1; ++j) {
                if(i == 0)
                    table[i][j] = j;
                else if(j == 0)
                    table[i][j] = i;
                else {
                    if(word1[i-1] == word2[j-1])
                        table[i][j] = table[i-1][j-1];
                    else
                        table[i][j] = min(min(1+table[i-1][j-1],
                                1+table[i-1][j]), 1+table[i][j-1]);
                }
            }
        }
        return table[word1.size()][word2.size()];
    }
};
