// Leetcode 1649. Create Sorted Array through Instructions
// https://leetcode.com/problems/create-sorted-array-through-instructions/
// time complexity: O(nlogn)
// space complexity: O(n)

// reference: https://leetcode.com/problems/create-sorted-array-through-instructions/discuss/927531/JavaC%2B%2BPython-Binary-Indexed-Tree
class Solution 
{
public:
    int createSortedArray(vector<int>& A) 
    {
        vector<int> buf(100001, 0);
        int res = 0;
        int sz = A.size();
        int mod = 1e9 + 7;
        for (int i = 0; i < sz; i++) 
        {
            int less_than_current = get(buf, A[i] - 1);
            
            // total number of instructions traversed is i, 
            // therefore subtract get(buf, A[i]) from i means the number of instructions greather than current instruction
            int greater_than_current = i - get(buf, A[i]); 
            res = (res + min(less_than_current, greater_than_current)) % mod;
            
            update(buf, A[i]);
        }
        return res;
    }

    void update(vector<int>& buf, int x) 
    {
        while (x < 100001) 
        {
            buf[x]++;
            x += (x & -x);
        }
    }

    // return number of instructions less or equal to x
    int get(vector<int>& buf, int x) 
    {
        int res = 0;
        while (x > 0) 
        {
            res += buf[x];
            x -= x & -x;
        }
        return res;
    }
};
