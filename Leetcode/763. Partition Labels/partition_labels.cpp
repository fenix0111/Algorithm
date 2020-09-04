// Leetcode 763. Partition Labels
// https://leetcode.com/problems/partition-labels/
// time complexity: O(length of input string)
// space complexity: O(1)

class Solution 
{
public:
    vector<int> partitionLabels(string S) 
    {
        // record the most right position of each character
        vector<int> furthest(26, 0);  
        for (int i = 0; i < S.length(); i++)
        {
            furthest[S[i] - 'a'] = i;
        }
        
        int left = 0;
        int right = 0;
        
        vector<int> partition;
        while (left < S.length())
        {
            int current = left;
            int right = furthest[S[left] - 'a'];
            while (left < right)
            {
                if (right < furthest[S[left] - 'a'])
                {
                    right = furthest[S[left] - 'a'];
                }

                left++;
            }
            
            partition.push_back(right - current + 1);
            left++;
        }
        
        return partition;
    }
};
