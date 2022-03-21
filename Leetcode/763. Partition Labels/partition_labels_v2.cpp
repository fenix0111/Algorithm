// Leetcode 763. Partition Labels
// https://leetcode.com/problems/partition-labels/
// time complexity: O(N)
// space complexity: O(1)

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int len = s.length();
        int i = 0;
        vector<int> result;

        int pos[26] = { 0 };
        for (int i = 0; i < len; i++)
        {
            char c = s[i];
            pos[c - 'a'] = i;
        }
        
        int start = 0;
        int end = -1;
        for (int i = 0; i < len; i++)
        {
            char c = s[i];
            end = max(end, pos[c - 'a']);
            if (i == end)
            {
                result.push_back(end - start + 1);
                start = i + 1;
                end = -1;
            }
        }
        
        return result;
    }
};
