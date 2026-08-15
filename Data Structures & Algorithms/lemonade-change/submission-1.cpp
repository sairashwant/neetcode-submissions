class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int fives = 0;
        int tens = 0;
        int twenties = 0;

        for(auto bill : bills)
        {
            if(bill == 5)
                fives++;
            
            if(bill == 10)
                {
                    tens++;
                    if(fives > 0)
                        fives--;
                    else
                        return false;
                }
            
            if(bill == 20)
                {
                    twenties++;
                    if(tens > 0)
                        {
                            if(fives > 0)
                            {
                                tens--;
                                fives--;
                            }

                            else
                                return false;
                        }
                    
                    else if(fives >= 3)
                    {
                        fives = fives-3;
                    }

                    else
                        return false;
                }
        }

        return true;
    }
};