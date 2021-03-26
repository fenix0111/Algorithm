// Leetcode 916. Word Subsets
// https://leetcode.com/problems/word-subsets/
// time complexity: O(sizeof array * length of each string)
// space complexity: O(n)

class Solution 
{
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<vector<int>> counts(A.size(), vector<int>(26, 0));
        vector<int> b(26, 0);
        
        // count appearances of each character of each string in A
        for (int i = 0; i < A.size(); i++)
        {
            string& a = A[i];
            for (char c : a)
            {
                counts[i][c - 'a']++;
            }
        }
        
        // as previously done, count array B
        for (int i = 0; i < B.size(); i++)
        {
            int tmp[26] = {0};
            string& str = B[i];
            
            for (char c : str)
            {
                tmp[c - 'a']++;
            }
            
            // take the greater one
            for (int i = 0; i < 26; i++)
            {
                if (tmp[i] > b[i])
                {
                    b[i] = tmp[i];
                }
            }
        }
        
        vector<string> result;
        for (int i = 0; i < counts.size(); i++)
        {
            bool valid = true;
            for (int j = 0; j < 26; j++)
            {
                if (b[j] > 0 && b[j] > counts[i][j])
                {
                    valid = false;
                    break;
                }
            }
            
            if (valid)
            {
                result.push_back(A[i]);
            }
        }
        
        return result;
    }
};
