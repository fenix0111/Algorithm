// Leetcode 146. LRU Cache
// https://leetcode.com/problems/lru-cache/description/
// Runtime: 120ms

// need some optimizations..
class LRUCache 
{
private:
    unordered_map<int, int> *m;
    vector<int> *keylist;
    int maxsize = 0;
    int current = 0;
public:
    LRUCache(int capacity) 
    {
        maxsize = capacity;
        m = new unordered_map<int, int>();
        keylist = new vector<int>();
    }
    
    int get(int key) 
    {
        //cout << "get: " << key << endl;
        int ret = -1;
        for (auto it = keylist->begin(); it != keylist->end(); it++)
        {
            if (*it == key)
            {
                ret = m->find(key)->second;
                
                keylist->erase(it);
                keylist->push_back(key);
                break;
            }
        }
        
        return ret;
    }
    
    void put(int key, int value) 
    {
        //cout << "put: " << key << endl;
        for (auto it = keylist->begin(); it != keylist->end(); it++)
        {
            if (*it == key)
            {
                m->find(key)->second = value;
                keylist->erase(it);
                keylist->push_back(key);
                return;
            }
        }
        
        if (current == maxsize)
        {
            int evicted = keylist->front();
            keylist->erase(keylist->begin());
            keylist->push_back(key);
            m->erase(evicted);
            m->insert(make_pair(key, value));
        }
        else
        {
            keylist->push_back(key);
            m->insert(make_pair(key, value));
            current++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
