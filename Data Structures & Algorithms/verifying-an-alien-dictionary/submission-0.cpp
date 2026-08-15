class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        unordered_map<char, int> hashmap;

        for(int i = 0; i < order.length(); i++)
        {
            hashmap[order[i]] = i;
        }

        auto compare = [&] (string a, string b)
        {
            for(int i = 0; i < min(a.length(), b.length()); i++)
            {
                if(a[i] != b[i])
                {
                    return hashmap[a[i]] < hashmap[b[i]];
                }
            }

            return a.length() < b.length();
        };

        return is_sorted(words.begin(), words.end(), compare);
    }
};