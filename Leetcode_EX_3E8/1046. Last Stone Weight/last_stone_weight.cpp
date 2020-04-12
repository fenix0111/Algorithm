// Leetcode 1046. Last Stone Weight
// https://leetcode.com/problems/last-stone-weight/
// Runtime: 0 ms
// Memory: 6.2 MB

// make_heap is viable as well
class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> pq;
        for (int stone : stones)
        {
            pq.push(stone);
        }
        
        while (pq.size() > 1)
        {
            int heaviest = pq.top();
            pq.pop();
            int heavier = pq.top();
            pq.pop();
            
            int remain = heaviest - heavier;
            if (remain > 0)
            {
                pq.push(remain);
            }
        }
        
        return pq.size() > 0 ? pq.top() : 0;
    }
};
