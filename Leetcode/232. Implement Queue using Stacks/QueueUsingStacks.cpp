// Leetcode 232. Implement Queue using Stacks
// https://leetcode.com/problems/implement-queue-using-stacks/description/
// Runtime: 0ms

class MyQueue 
{
private:
    stack<int> st;
    stack<int> ext;
    
public:
    /** Initialize your data structure here. */
    MyQueue() { }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        st.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        while (!st.empty()) 
        {
            ext.push(st.top());
            st.pop();
        }
        
        int ret = ext.top();
        ext.pop();
        
        while (!ext.empty()) 
        {
            st.push(ext.top());
            ext.pop();
        }
        
        return ret;
    }
    
    /** Get the front element. */
    int peek() 
    {
         while (!st.empty()) 
         {
            ext.push(st.top());
            st.pop();
        }
        
        int ret = ext.top();
        
        while (!ext.empty()) 
        {
            st.push(ext.top());
            ext.pop();
        }
        
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return st.empty();
    }
};
