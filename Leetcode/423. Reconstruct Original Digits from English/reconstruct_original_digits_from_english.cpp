// Leetcode 423. Reconstruct Original Digits from English
// https://leetcode.com/problems/reconstruct-original-digits-from-english/
// time complexity: 
// space complexity: O(n)

class Solution 
{
    char* numToStr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    
public:
    bool subtraction(int num, int* counts)
    {
        char* str = numToStr[num];
        for (char* t = str; *t != '\0'; t++)
        {
            counts[*t - 'a']--;
        }
        
        bool valid = true;
        for (char* t = str; *t != '\0'; t++)
        {
            if (counts[*t - 'a'] < 0)
            {
                valid = false;
                break;
            }
        }
        
        if (valid)
        {
            return true;
        }
        else
        {
            for (char* t = str; *t != '\0'; t++)
            {
                counts[*t - 'a']++;
            }
            return false;
        }
    }
    
    bool isClear(int* counts)
    {
        for (int i = 0; i < 26; i++)
        {
            if (counts[i] > 0)
            {
                return false;
            }
        }
        
        return true;
    }
    
    void resetCounts(int* counts, char* str)
    {
        for (char* t = str; *t != '\0'; t++)
        {
            counts[*t - 'a']++;
        }
    }
    
    bool originalDigits(vector<int>& buf, int* counts, int num)
    {
        if (isClear(counts))
        {
            return true;
        }
        
        if (num == 10)
        {
            if (!isClear(counts))
            {
                buf.pop_back();
                return false;
            }
            else
            {
                return true;
            }
        }
        
        for (int i = num; i <= 9; i++)
        {
            if ((i & 1) == 0)
            {
                continue;
            }
            
            if (subtraction(i, counts))
            {
                buf.push_back(i);
                if (originalDigits(buf, counts, i))
                {
                    return true;
                }
                else
                {
                    buf.pop_back();
                    resetCounts(counts, numToStr[i]);
                }
            }
        }
        
        return false;
    }
    
    // 0,2,4,6,8 each has unique character
    void eliminateZeroTwoFourSixEight(int* counts, vector<int>& buf)
    {
        int c = counts['z' - 'a'];
        while (c > 0)
        {
            subtraction(0, counts);
            buf.push_back(0);
            c--;
        }
        
        c = counts['w' - 'a'];
        while (c > 0)
        {
            subtraction(2, counts);
            buf.push_back(2);
            c--;
        }
        
        c = counts['u' - 'a'];
        while (c > 0)
        {
            subtraction(4, counts);
            buf.push_back(4);
            c--;
        }
        
        c = counts['x' - 'a'];
        while (c > 0)
        {
            subtraction(6, counts);
            buf.push_back(6);
            c--;
        }
        
        c = counts['g' - 'a'];
        while (c > 0)
        {
            subtraction(8, counts);
            buf.push_back(8);
            c--;
        }
    }
    
    string originalDigits(string s) 
    {
        int* counts = new int[26];
        memset(counts, 0, sizeof(int) * 26);
        
        for (char c : s)
        {
            counts[c - 'a']++;
        }
        
        vector<int> buf;
        string result = "";
        
        eliminateZeroTwoFourSixEight(counts, buf);
        
        originalDigits(buf, counts, 1);
        sort(buf.begin(), buf.end());
        
        for (int i = 0; i < buf.size(); i++)
        {
            result.push_back(buf[i] + '0');
        }
        
        return result;
    }
};
