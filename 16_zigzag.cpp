class Solution
{
public:
	string convert(string s, int nRows)
	{
		if (nRows < 2) return s;
		int N = s.size();
		int L = 2 * (nRows - 1); // provide offset
		string res;
		res.clear();
		for (int i = 0; i < N; i += L)
		{
			res.push_back(s[i]);
		}
		for (int i = 1; i < nRows - 1; i++)
		{
			for (int j = i; j < N; j += L)
			{
				res.push_back(s[j]);
				// j - i: provide offset L for each row
				// L - i: provide reverse for each column
				int k = (j - i) + (L - i);
				if (k < N) res.push_back(s[k]);
			}
		}
		for (int i = nRows - 1; i < N; i += L)
		{
			res.push_back(s[i]);
		}
		return res;
	}
};