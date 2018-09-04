// Leetcode 225. Implement Stack using Queues
// https://leetcode.com/problems/implement-stack-using-queues/description/
// Runtime: 0ms

class MyStack 
{
private:
    queue<int> main_q;
    queue<int> extra;
    
public:
    /** Initialize your data structure here. */
    MyStack() { }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        main_q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        while (main_q.size() > 1)
        {
            extra.push(main_q.front());
            main_q.pop();
        }
        int ret = main_q.front();
        
        main_q.pop();  // now main queue is empty
        
        while (!extra.empty()) 
        {
            main_q.push(extra.front());
            extra.pop();
        }
        
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        while (main_q.size() > 1) 
        {
            extra.push(main_q.front());
            main_q.pop();
        }
        
        int ret = main_q.front();
        
        extra.push(main_q.front());
        main_q.pop();
        
        while (!extra.empty()) 
        {
            main_q.push(extra.front());
            extra.pop();
        }
        
        return ret;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        return main_q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
