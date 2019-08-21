// Leetcode 705. Design HashSet
// https://leetcode.com/problems/design-hashset/
// Runtime: 96ms

class MyHashSet 
{
private:
    int size = 1000;  // not fixed
    vector< list<int> > tbl;
    
public:
    /** Initialize your data structure here. */
    MyHashSet() 
    {
        for (int i = 0; i < size; i++)
        {
            list<int> l;
            tbl.push_back(l);
        }
    }
    
    void add(int key) 
    {
        list<int>& ll = tbl[key % size];
        if (find(ll.begin(), ll.end(), key) == ll.end())
        {
            ll.push_back(key);
        }
    }
    
    void remove(int key) 
    {
        list<int> &ll = tbl[key % size];
        auto it = find(ll.begin(), ll.end(), key);
        if (it != ll.end())
        {
            ll.remove(key);
        }         
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) 
    {
        list<int> ll = tbl[key % size];
        auto it = find(ll.begin(), ll.end(), key);
        if (it != ll.end())
            return true;
        else
            return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
