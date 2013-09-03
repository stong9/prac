int ladderLength(string start, string end, unordered_set<string> &dict) {
    int ret = 0;
    if (start == end)
        return ret;

    unordered_set<string> added;
    queue<string> que;
    int lev1 = 1;
    int lev2 = 0;
    que.push(start);
    added.insert(start);

    while (!que.empty()) {
        string s = que.front();
        que.pop();
        --lev1;

        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j < 26; ++j) {
                string t = s;
                t[i] = 'a' + j;
                if (t == end)
                    return ret + 2;
                if (dict.find(t) != dict.end()
                    && added.find(t) == added.end()) {
                    que.push(t);
                    added.insert(t);
                    ++lev2;
                }
            }
        }

        if (lev1 == 0) {
            ++ret;
            lev1 = lev2;
            lev2 = 0;
        }
    }

    return 0;
}