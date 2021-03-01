class FreqStack 
{
    unordered_map<int, stack<int>> tbl;
    unordered_map<int, int> counter;
    int maxFrequency;
    
public:
    FreqStack() 
    {
        maxFrequency = 0;
    }
    
    void push(int x) 
    {
        counter[x]++;
        maxFrequency = max(maxFrequency, counter[x]);
        tbl[counter[x]].push(x);
    }
    
    int pop() 
    {
        int result = 0;
        result = tbl[maxFrequency].top();
        tbl[maxFrequency].pop();
        if (tbl[maxFrequency].empty())
        {
            maxFrequency--;
        }
        
        counter[result]--;
        
        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
