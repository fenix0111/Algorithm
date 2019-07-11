// Leetcode 401. Binary Watch
// https://leetcode.com/problems/binary-watch/
// Runtime: 0ms

// used next_permutation() in STL
class Solution 
{
public:
    vector<string> readBinaryWatch(int num) 
    {
        int hr;  // number of lighted LED in hour
        int min;  // number of lighted LED in minute
        
        int c = 0;
        vector<string> ret;
        while (c <= num)
        {
            if (c > 4)
            {
                hr = 4;  // maximmum 4 lights in hour
            }
            else
            {
                hr = c;
            }
            
            min = num - hr;
            
            // maximum 6 lights in minute
            if (min > 6)
            {
                c++;
                continue;
            }
            
            if (hr == 0)
            {
                int led[6] = { 0 };
                for (int i = 5; i >= 6 - min; i--)
                {
                    led[i] = 1;
                }
                
                do 
                {
                    string time = "";
                    
                    int led_min = 0;
                    for (int i = 0; i < 6; i++)
                    {
                        led_min += pow(2, 5 - i) * led[i];
                    }
                    
                    if (led_min > 59)
                    {
                        continue;
                    }
                    
                    time.append("0:");
                    if (led_min < 10)
                    {
                        time.append("0");
                    }
                    time.append(to_string(led_min));
                    ret.push_back(time);
                } while (next_permutation(led, led + 6));
            }
            else
            {
                int hrled[4] = { 0 };
                for (int i = 3; i >= 4 - hr; i--)
                {
                    hrled[i] = 1;
                }
                
                do 
                {
                    string time = "";
                    int led_hr = 0;
                    for (int i = 0; i < 4; i++)
                    {
                        led_hr += pow(2, 3 - i) * hrled[i];
                    }
                    
                    // hour range is 0 ~ 11
                    if (led_hr > 11)
                    {
                        continue;
                    }
                    
                    time.append(to_string(led_hr));
                    time.append(":");
                    
                    int led[6] = { 0 };
                    for (int i = 5; i >= 6 - min; i--)
                    {
                        led[i] = 1;
                    }

                    // count minute
                    do 
                    {
                        string inner(time);
                        int led_min = 0;
                        for (int i = 0; i < 6; i++)
                        {
                            led_min += pow(2, 5 - i) * led[i];
                        }
                        
                        // minute range is 0 ~ 59
                        if (led_min > 59)
                        {
                            continue;
                        }

                        if (led_min < 10)
                        {
                            inner.append("0");
                        }
                        inner.append(to_string(led_min));
                        ret.push_back(inner);
                        
                    } while (next_permutation(led, led + 6));
                    
                } while (next_permutation(hrled, hrled + 4));

            }
            
            c++;
        }
        
        return ret;
    }
};
