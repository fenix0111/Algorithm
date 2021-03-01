// Leetcode 895. Maximum Frequency Stack
// https://leetcode.com/problems/maximum-frequency-stack/
// time complexity: O(logn)  --> for erasing key from the map
// space complexity: O(n) 

class FreqStack 
{
    map<int, stack<int>> tbl;  // frequency -> stack
    unordered_map<int, int> counter;
public:
    FreqStack() { }
    
    void push(int x) 
    {
        counter[x]++;
        tbl[counter[x]].push(x);
    }
    
    int pop() 
    {
        int result = 0;
        auto mostFrequent = tbl.rbegin();
        result = mostFrequent->second.top();
        mostFrequent->second.pop();
        if (mostFrequent->second.empty())
        {
            tbl.erase(mostFrequent->first);
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
