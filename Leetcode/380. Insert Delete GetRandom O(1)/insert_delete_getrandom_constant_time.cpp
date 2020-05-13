// Leetcode 380. Insert Delete GetRandom O(1)
// https://leetcode.com/problems/insert-delete-getrandom-o1/
// Runtime: 72 ms
// Memory: 22.9 MB

class RandomizedSet 
{
    // value is the index of value in  the vector
    unordered_map<int, int> _m;
    vector<int> _list;
public:
    /** Initialize your data structure here. */
    RandomizedSet() { }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) 
    {
        auto it = _m.find(val);
        if (it == _m.end())
        {
            _list.push_back(val);
            _m.insert(make_pair(val, _list.size() - 1));
            return true;
        }
        else
        {
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    {
        auto it = _m.find(val);
        if (it == _m.end())
        {
            return false;
        }
        else
        {
            int idx = it->second;
            // change the element be removed with last element in vector 
            _list[idx] = _list[_list.size() - 1];
            
            // update index in map
            _m[_list[_list.size() - 1]] = idx;
            
            _list.pop_back();
            _m.erase(val);
            
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() 
    {        
        return _list[rand() % _list.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
