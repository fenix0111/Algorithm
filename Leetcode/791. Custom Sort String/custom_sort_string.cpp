// Leetcode 791. Custom Sort String
// https://leetcode.com/problems/custom-sort-string/
// time complexity: O(len(str) + len(order))
// space complexity: O(len(str))

class Solution 
{
public:
    string customSortString(string order, string str) 
    {
        bool contain[128] = { false };
        for (char c : order)
        {
            contain[c] = true;
        }
        
        string remain = "";
        int counter[128] = { 0 };
        for (char c : str)
        {
            if (contain[c])
            {
                counter[c]++;
            }
            else
            {
                remain.push_back(c);
            }
        }
        
        string result = "";
        for (char c : order)
        {
            int count = counter[c];
            while (count > 0)
            {
                result.push_back(c);
                count--;
            }
        }
        
        result += remain;
        return result;
    }
};
