// Leetcode 677. Map Sum Pairs
// https://leetcode.com/problems/map-sum-pairs/
// Runtime: 4ms

// trivial solution (brutal force)
class MapSum 
{
private:
    unordered_map<string, int> tbl;
public:
    /** Initialize your data structure here. */
    MapSum() 
    {
        
    }
    
    void insert(string key, int val) 
    {
        if (tbl.find(key) == tbl.end())
        {
            tbl.insert(make_pair(key, val));
        }
        else
        {
            tbl.find(key)->second = val;
        }
    }
    
    int sum(string prefix) 
    {
        int sum = 0;
        for (auto it = tbl.begin(); it != tbl.end(); it++)
        {
            string k = it->first;
            if (k.size() < prefix.size())
            {
                continue;
            }
            else
            {
                bool same = true;
                for (int i = 0; i < prefix.size(); i++)
                {
                    if (k[i] != prefix[i])
                    {
                        same = false;
                        break;
                    }
                }
                
                if (same)
                {
                    sum += it->second;
                }
            }
        }
        
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
