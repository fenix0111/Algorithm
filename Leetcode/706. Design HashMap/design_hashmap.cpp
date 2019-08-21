// Leetcode 706. Design HashMap
// https://leetcode.com/problems/design-hashmap/
// Runtime: 120ms

typedef struct {
    int k;
    int v;
} KV;

class MyHashMap 
{
private:
    int size = 1000;
    vector< list<KV> > tbl;

public:
    /** Initialize your data structure here. */
    MyHashMap() 
    {
        for (int i = 0; i < size; i++)
        {
            list<KV> l;
            tbl.push_back(l);
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) 
    {
        int k = key % size;
        list<KV> &ll = tbl[k];
        
        for (auto it = ll.begin(); it != ll.end(); it++)
        {
            if ((*it).k == key)
            {
                (*it).v = value;
                return;
            }
        }
        
        KV new_kv;
        new_kv.k = key;
        new_kv.v = value;
        
        ll.push_back(new_kv);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) 
    {
        int k = key % size;
        list<KV> ll = tbl[k];
        
        for (auto it = ll.begin(); it != ll.end(); it++)
        {
            if ((*it).k == key)
            {
                return (*it).v;
            }
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) 
    {
        int k = key % size;
        list<KV> &ll = tbl[k];
        
        list<KV>::iterator target;
        bool has = false;
        for (auto it = ll.begin(); it != ll.end(); it++)
        {
            if ((*it).k == key)
            {
                target = it;
                has = true;
                break;
            }
        }
        
        if (has)
            ll.erase(target);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
