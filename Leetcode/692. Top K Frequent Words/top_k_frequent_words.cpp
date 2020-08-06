// Leetcode 692. Top K Frequent Words
// https://leetcode.com/problems/top-k-frequent-words/
// time complexity: 
// space complexity: 

struct comp
{
    bool operator() (unordered_map<string, int>::iterator& A, unordered_map<string, int>::iterator& B)
    {
        if (A->second < B->second)
            return true;
        else if (A->second == B->second)
            return (A->first).compare(B->first) > 0;
        else
            return false;
    }
};

class Solution 
{
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string, int> counter;
        vector<string> topK;
        priority_queue<unordered_map<string, int>::iterator, vector<unordered_map<string, int>::iterator>, comp> q;
        
        for (string& word : words)
        {
            counter[word]++;
        }
        
        for (auto it = counter.begin(); it != counter.end(); it++)
        {
            q.push(it);
        }
        
        while (!q.empty())
        {
            if (topK.size() < k)
                topK.push_back(q.top()->first);
            q.pop();
        }
        
        return topK;
    }
};
