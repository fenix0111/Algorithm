// Leetcode 526. Beautiful Arrangement
// https://leetcode.com/problems/beautiful-arrangement/
// 
// 

class Solution 
{
public:
    void swap(vector<int>& v, int i, int j)
    {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
    
    void check(int& count, vector<int>& v, int index)
    {
        if (index == v.size())
        {
            count += 1;
        }
        
        for (int i = index; i < v.size(); i++)
        {
            if (v[i] % (index + 1) != 0 && (index + 1) % v[i] != 0)
                continue;
            
            swap(v, i, index);
            check(count, v, index + 1);
            swap(v, i, index);
        }
    }
    
    int countArrangement(int N) 
    {
        vector<int> v;
        for (int i = 1; i <= N; i++)
        {
            v.push_back(i);
        }
        
        int count = 0;
        check(count, v, 0);
        
        return count;
    }
};
