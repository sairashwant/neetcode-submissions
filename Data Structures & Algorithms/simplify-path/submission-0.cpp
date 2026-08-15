class Solution {
public:
    string simplifyPath(string path) {
        
        string curr = "";
        path = path + "/";
        vector<string> stk;

        for(int i = 0; i < path.length(); i++)
        {
            if(path[i] == '/')
            {
                if(curr == "..")
                {
                    curr.clear();
                    if(!stk.empty())
                        stk.pop_back();
                }
                
                else if(curr == ".")
                {
                    curr.clear();
                }

                else
                {
                    if(curr != "")
                        stk.push_back(curr);
                    curr.clear();
                }
            }

            else
            {
                curr = curr + path[i];
            }
        }

        string resultPath;

        for(int i = 0; i < stk.size(); i++)
        {
            resultPath += "/" + stk[i];
        }

        if(stk.empty())
            return "/";

        return resultPath;
    }
};