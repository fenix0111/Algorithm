// Leetcode 954. Array of Doubled Pairs
// https://leetcode.com/problems/array-of-doubled-pairs/
// time complexity: O(nlogn)
// space complexity: O(n)

class Solution 
{
public:
    bool canReorderDoubled(vector<int>& arr) 
    {
        unordered_map<int, int> count;
        for (int e : arr)
        {
            count[e]++;
        }
        
        int size = arr.size();
        
        sort(arr.begin(), arr.end());
        
        for (int e : arr)
        {
            int ee = e * 2;
            
            if (count[ee] == 0 || count[e] == 0)
            {
                continue;
            }
            
            if (count[ee] > 0)
            {
                size--;
                count[ee]--;
            }
            
            if (count[e] > 0)
            {
                size--;
                count[e]--;
            }
        }
        
        return size == 0;
    }
};
