// Leetcode 97. Interleaving String
// https://leetcode.com/problems/interleaving-string/
// time complexity: 
// space complexity: O(n)

class Solution 
{
public:
    bool check(string& s1, string& s2, string& s3, vector<vector<bool>>& visited, int i, int j, int k)
    {        
        if (k == s3.length())
        {
            return true;
        }        
        
        if (i < s1.length() && j < s2.length())
        {
            if (visited[i][j])
            {
                return false;
            }
            
            visited[i][j] = true;
            
            if (s1[i] == s3[k])
            {
                if (s2[j] == s3[k])
                {
                    return check(s1, s2, s3, visited, i + 1, j, k + 1) || 
                           check(s1, s2, s3, visited, i, j + 1, k + 1);
                }
                
                return check(s1, s2, s3, visited, i + 1, j, k + 1);
            }
            else if (s2[j] == s3[k])
            {
                return check(s1, s2, s3, visited, i, j + 1, k + 1);
            }
            else
            {
                return false;
            }
        }
        else if (i < s1.length())
        {
            if (s1[i] == s3[k])
            {
                return check(s1, s2, s3, visited, i + 1, j, k + 1);
            }
        }
        else
        {
            if (s2[j] == s3[k])
            {
                return check(s1, s2, s3, visited, i, j + 1, k + 1);
            }
        }
        
        return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) 
    {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if ((len1 + len2) != len3)
        {
            return false;
        }
        
        vector<vector<bool>> visited(len1, vector<bool>(len2, false));
        
        return check(s1, s2, s3, visited, 0, 0, 0);
    }
};
