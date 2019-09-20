// Leetcode 155. Min Stack
// https://leetcode.com/problems/min-stack/
// Runtime: 28ms

// using stack and priority heap as min-heap
class MinStack 
{
    priority_queue< int, vector<int>, greater<int> > h;
    stack<int> st;
    int min;
public:
    /** initialize your data structure here. */
    MinStack() 
    {
        min = INT_MAX;
    }
    
    void push(int x) 
    {
        st.push(x);
        h.push(x);
        if (x < min)
        {
            min = x;
        }
    }
    
    void pop() 
    {
        int i = st.top();
        if (i == min)
        {
            h.pop();
            min = h.top();
        }
        st.pop();
    }
    
    int top() 
    {
        return st.top();
    }
    
    int getMin() 
    {
        return h.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
