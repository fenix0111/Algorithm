// Leetcode 792. Number of Matching Subsequences
// https://leetcode.com/problems/number-of-matching-subsequences/
// time complexity: O(length of word * numberof words * log(length of word))
// space complexity: O(length of S)

class Solution 
{
public:   
    int numMatchingSubseq(string S, vector<string>& words) 
    {
        int num = 0;
        vector<vector<int>> v(26);  // index list of S
        for (int i = 0; i < S.length(); i++)
        {
            v[S[i] - 'a'].push_back(i);
        }
        for (string& word : words)
        {
            int next = -1;
            bool found = true;
            
            for (int i = 0; i < word.length(); i++)
            {
                vector<int>& index = v[word[i] - 'a'];
                auto it = upper_bound(index.begin(), index.end(), next); // --> IMPORTANT
                if (it != index.end())
                {
                    next = *it;
                }
                else
                {
                    found = false;
                    break;
                }
            }
            
            if (found)
                num++;
        }
        
        return num;
    }
};
