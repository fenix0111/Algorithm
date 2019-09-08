// Leetcode 307. Range Sum Query - Mutable
// https://leetcode.com/problems/range-sum-query-mutable/
// Runtime: 28ms

// segment tree
class NumArray 
{
private:
    int sz;
    vector<int> segment_tree;
public:
    NumArray(vector<int>& nums) 
    {
        sz = nums.size();
        segment_tree.reserve(sz * 2);
        for (int i = sz; i < sz * 2; i++)
        {
            segment_tree[i] = nums[i - sz];
        }
        for (int i = sz - 1; i > 0; i--)
        {
            segment_tree[i] = segment_tree[i * 2] + segment_tree[i * 2 + 1];
        }
    }
    
    void update(int i, int val) 
    {
        int index = i + sz;
        segment_tree[index] = val;
        while (index > 0)
        {
            int l, r;
            if ((index & 1))
            {
                // index is right child
                l = index - 1;
                r = index;
            }
            else
            {
                // left child
                l = index;
                r = index + 1;
            }
            
            index = index >> 1;
            segment_tree[index] = segment_tree[l] + segment_tree[r];
        }
    }
    
    int sumRange(int i, int j) 
    {
        int l = i + sz;
        int r = j + sz;
        int sum = 0;
        while (l <= r)
        {
            if (l & 1)
            {
                // left
                sum += segment_tree[l];
                l++;
            }
            
            if ((r & 1) == 0)
            {
                sum += segment_tree[r];
                r--;
            }
            
            l >>= 1;
            r >>= 1;
        }
        
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
