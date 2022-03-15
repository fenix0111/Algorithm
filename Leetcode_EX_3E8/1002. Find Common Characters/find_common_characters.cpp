// Leetcode 1002. Find Common Characters
// https://leetcode.com/problems/find-common-characters/
// time complexity: O(len(words) * len(word))
// space complexity: O(1)

class Solution
{
public:
    vector<string> commonChars(vector<string>& words)
    {
        vector<string> result;
        
        for (char a = 'a'; a <= 'z'; a++)
        {
            int minCount = INT_MAX;
            for (int i = 0; i < words.size(); i++)
            {
                int count = 0;
                string& word = words[i];
                for (char c : word)
                {
                    if (c == a)
                    {
                        count++;
                    }
                }
                
                minCount = min(minCount, count);
            }
            
            string str(1, a);
            while (minCount > 0)
            {
                result.push_back(str);
                minCount--;
            }
        }
        
        return result;
    }
};
