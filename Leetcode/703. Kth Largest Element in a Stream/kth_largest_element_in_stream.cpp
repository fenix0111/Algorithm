// Leetcode 703. Kth Largest Element in a Stream
// https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Runtime: 44ms

class KthLargest 
{
    int k;
    vector<int> v;
    vector<int> heap;
public:
    KthLargest(int k, vector<int>& nums) 
    {
        this->k = k;
        this->v = nums;
        sort(this->v.begin(), this->v.end(), greater<int>());

        int end = k;
        if (nums.size() < k)
            end = nums.size();        
        
        for (int i = 0; i < end; i++)
        {
            heap.push_back(this->v[i]);
        }

        if (heap.size() > 0)
            make_heap(this->heap.begin(), this->heap.end(), greater<int>());
    }
    
    int add(int val) 
    {
        if (heap.size() < this->k)
        {
            heap.push_back(val);
            push_heap(this->heap.begin(), this->heap.end(), greater<int>());
 
            return this->heap.front();
        }
        else
        {
            if (val <= this->heap.front())
            {
                return this->heap.front();
            }
            else
            {
                pop_heap(this->heap.begin(), this->heap.end(), greater<int>());
                this->heap.pop_back();

                this->heap.push_back(val);
                push_heap(this->heap.begin(), this->heap.end(), greater<int>());
                
                return this->heap.front();
            }
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
