// 1170. Compare Strings by Frequency of the Smallest Character
// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
// time complexity: O(xy) , x = vector size, y = string length
// space complexity: O(n)

class Solution 
{
public:
    int getFLS(string& s)
    {
        int counter[26] = { 0 };
        for (char c : s)
        {
            counter[c - 'a']++;
        }
        
        for (int i = 0; i < 26; i++)
        {
            if (counter[i] > 0)
            {
                return counter[i];
            }
        }
        
        return 0;  // never reach here
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) 
    {
        vector<int> result;
        map<int, int> fls;
        for (string word : words)
        {
            int counts = getFLS(word);
            fls[counts]++;
        }
        
        for (string query : queries)
        {
            char c = query[0];
            int counts = getFLS(query);
            
            int nums = 0;
            for (auto it = fls.rbegin(); it != fls.rend(); it++)
            {
                if (it->first > counts)
                {
                    nums += it->second;
                }
                else
                {
                    break;
                }
            }
            
            result.push_back(nums);
        }
        
        return result;
    }
};
