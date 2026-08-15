class Solution {
public:
    bool isPalindrome(string s) {
        
        int i = 0; int j = s.length()-1;
        string finalstr;

        while( i < s.length())
        {
            if(((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')))
                {
                    finalstr += tolower(s[i]);
                    i++;
                }
            else i++;
        }
        string temp = finalstr;
        
        reverse(finalstr.begin(), finalstr.end());
        cout<<"Temp: "<<temp<<endl;
        cout<<"Finalstr: "<<finalstr;
        if(temp == finalstr)
            return true;
        
        return false;
    }
};
