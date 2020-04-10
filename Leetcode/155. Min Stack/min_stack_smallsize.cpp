// Leetcode 155. Min Stack
// https://leetcode.com/problems/min-stack/
// Runtime: 40 ms
// Memory: 14.3 MB (100%)

// more memory efficient solution
// main idea is keep second most small element under the most small element
// when pop smalles element, along with the element under it 
class MinStack 
{
    stack<int> st;
    int min = INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) 
    {
        if (x <= min)
        {
            st.push(min);
            min = x;
        }
        st.push(x);
    }
    
    void pop() 
    {
        if (st.top() == min)
        {
            st.pop();
            min = st.top();
        }
        st.pop();
    }
    
    int top() 
    {        
        return st.top();
    }
    
    int getMin() 
    {
        return min;
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
