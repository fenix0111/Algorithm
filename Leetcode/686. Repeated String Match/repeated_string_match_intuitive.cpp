// Leetcode 686. Repeated String Match
// https://leetcode.com/problems/repeated-string-match/
// time complexity: 
// space complexity: O(n)

class Solution 
{
public:
    int repeatedStringMatch(string A, string B) 
    {
        if (A.size() == 0)
        {
            return -1;
        }
        
        string strA = A;
        int count = 1;
        int len;
        if (A.size() > B.size())
        {
            len = A.size();
        }
        else
        {
            len = B.size();
        }
        
        // append string A until its length exceeds the limit(variable len)
        while (strA.size() <= len)
        {
            if (strA.length() < B.length())
            {
                count++;
                strA.append(A);
            }
            else
            {
                if (strA.find(B) == string::npos)
                {
                    count++;
                    strA.append(A);
                }
                else
                {
                    break;
                }
            }
        }
        
        // do final check here, append one more time see if concatenated string has string B
        if (strA.find(B) == string::npos)
        {
            count++;
            strA.append(A);
            if (strA.find(B) == string::npos)
            {
                return -1;
            }
            else
            {
                return count;
            }
        }
        else
        {
            return count;
        }
    }
};
