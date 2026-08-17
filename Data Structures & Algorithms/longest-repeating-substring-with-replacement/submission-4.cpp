class Solution {
public:
    int characterReplacement(string s, int k) {

		int result = 0;
		int l = 0;
		unordered_map<char, int> charSet;
		int maxFreq = 0;

		for(int r = 0; r < s.size(); r++)
		{
			charSet[s[r]]++;
			maxFreq = max(maxFreq, charSet[s[r]]);
			int windowSize = r - l + 1;
			
			if(windowSize - maxFreq > k)
			{
				charSet[s[l]]--;
				l++;
			}

			result = max(result, r - l + 1);
		}
        
		return result;
    }
};
