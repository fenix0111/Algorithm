// Leetcode 1338. Reduce Array Size to The Half
// https://leetcode.com/problems/reduce-array-size-to-the-half/
// time complexity: O(nlogn)
// space complexity: O(n)

class Solution 
{
public:
    int minSetSize(vector<int>& arr) 
    {
        unordered_map<int, int> counter;
        for (int e : arr)
        {
            counter[e]++;
        }
        
        priority_queue<int> q;
        int total = 0;
        for (auto it : counter)
        {
            total += it.second;
            q.push(it.second);
        }
        
        int half = total / 2; 
        int result = 0;
        while (!q.empty() && total > half)
        {
            total -= q.top();
            q.pop();
            result++;
        }
        
        return result;
    }
};
