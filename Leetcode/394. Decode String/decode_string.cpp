class Solution 
{
public:
    string decodeString(string s) 
    {
        string result = "";
        int i = 0;
        int times = 0;
        int diff = 0;
        int beg = -1;
        
        while (i < s.length())
        {
            while (isalpha(s[i]))
            {
                result.push_back(s[i]);
                i++;
            }
            
            while (isdigit(s[i]))
            {
                times *= 10;
                times += (s[i] - '0');
                i++;
            }
            
            if (s[i] == '[')
            {
                diff++;
                if (beg == -1)
                {
                    beg = i + 1;
                }
                
                while (diff > 0)
                {
                    i++;
                    if (s[i] == ']')
                    {
                        diff--;
                    }
                    else if (s[i] == '[')
                    {
                        diff++;
                    }
                }
                
                // make substring between '[' and ']'
                string tmp = s.substr(beg, i - beg + 1);
                string decoded_str = decodeString(tmp);

                while (times > 0)
                {
                    times--;
                    result += decoded_str;
                }
                
                beg = -1;
            }
            
            i++;
        }
        
        return result;
    }
};
