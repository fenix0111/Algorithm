// Leetcode 402. Remove K Digits
// https://leetcode.com/problems/remove-k-digits/
// Runtime: 8 ms
// Memory: 6.9 MB

class Solution 
{
public:
    string removeKdigits(string num, int k) 
    {
        int sz = num.length();
        if (sz == k)
        {
            return "0";
        }
        
        deque<char> q;
        int deleted = 0;
        int i = 0;
        string ret = "";
        
        // checkpoint would be used to set point when while loop below terminated before reach the end of num
        int cp = 0;  
        
        // only pop back from queue when next number is less than the last element in the queue
        while (i < sz && deleted < k)
        {
            if (q.empty())
            {
                q.push_back(num[i]);
                i++;
            }
            else
            {
                if (q.back() <= num[i])
                {
                    q.push_back(num[i]);
                    i++;
                }
                else
                {
                    q.pop_back();
                    deleted++;
                }
            }
            
            cp = i;
        }

        // loop ended before reach the k, erase from back
        while (deleted++ < k )
        {
            q.pop_back();
        }
        
        // fill the queue with the remaining numbers
        while (cp < sz)
        {
            q.push_back(num[cp++]);
        }
        
        // clear the leading zeroes
        while (q.front() == '0')
        {
            q.pop_front();
        }
        
        // build result string
        while (!q.empty())
        {
            ret += q.front();
            q.pop_front();
        }
        
        // return zero when the result is an empty string
        if (ret == "")
        {
            ret = "0";
        }
        
        return ret;
    }
};
