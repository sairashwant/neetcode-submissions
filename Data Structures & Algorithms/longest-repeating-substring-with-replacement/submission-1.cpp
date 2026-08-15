class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
		int res = 0;

		int l = 0, maxf = 0;
		
		for(int r = 0; r < s.size(); r++)
		{
			count[s[r]]++;
			maxf = max(maxf, count[s[r]]);
			int windowSize = r - l + 1;
			if(windowSize - maxf > k)
			{
				count[s[l]]--;
				l++;
			}

			res = max(res, r - l + 1);
		}

		return res;
    }
};
