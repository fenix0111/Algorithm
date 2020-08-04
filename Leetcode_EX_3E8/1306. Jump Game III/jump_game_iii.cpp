// Leetcode 1306. Jump Game III
// https://leetcode.com/problems/jump-game-iii/
// time complexity: O(size of array)
// space complexity: O(size of array)

class Solution 
{
public:
    bool jump(vector<int>& arr, int start, unordered_set<int>& forward_visited, unordered_set<int>& back_visited)
    {
        if (arr[start] == 0)
            return true;
        
        int forward = start + arr[start];
        int backward = start - arr[start];
        
        bool result_forward = false; 
        if (forward_visited.find(forward) == forward_visited.end() && forward >= 0 && forward < arr.size())
        {
            forward_visited.insert(forward);
            result_forward = jump(arr, forward, forward_visited, back_visited);
        }

        bool result_backward = false; 
        if (back_visited.find(backward) == back_visited.end() && backward >= 0 && backward < arr.size())
        {
            back_visited.insert(backward);
            result_backward = jump(arr, backward, forward_visited, back_visited);
        }

        return result_forward || result_backward;
    }
    
    bool canReach(vector<int>& arr, int start) 
    {
        unordered_set<int> forward_visited;
        unordered_set<int> back_visited;
        
        return jump(arr, start, forward_visited, back_visited);
    }
};
