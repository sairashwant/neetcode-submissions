class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        vector<string> digiToChar = {"","","abc","def","ghi","jkl",
        "mno","qprs","tuv","wxyz"};
        if(digits.length()==0)
            return result;
        backtrack(digits, digiToChar, result, "", 0);

        return result;
    }

    void backtrack(string digits,vector<string> digiToChar, vector<string> &result, string temp, int start)
    {
        if(start >= digits.length() && temp.length()==digits.length())
            {
                result.push_back(temp);
                return;
            }

        for(int i = start; i < digits.length(); i++)
        {
            int dig = (int)(digits[i] - '0');
            
            for(int j = 0; j < digiToChar[dig].length(); j++)
            {
                temp = temp + digiToChar[dig][j];
                backtrack(digits, digiToChar, result, temp, i+1);
                temp.erase(temp.length()-1);
            }
        }
    }
};
