// Leetcode 146. LRU Cache
// https://leetcode.com/problems/lru-cache/
// Runtime: 168 ms
// Memory: 38.4 MB

class LRUCache 
{
    int capacity = 0;
    list<int> key_list;
    unordered_map<int, int> cache_map;
    unordered_map<int, list<int>::iterator> cache_addr; 
    
public:
    LRUCache(int capacity) 
    {
        this->capacity = capacity;
    }
    
    int get(int key) 
    {
        auto it = cache_map.find(key);
        
        int ret = 0;
        if (it != cache_map.end())
        {
            list<int>::iterator lit = cache_addr.find(key)->second;

            key_list.erase(lit);
            key_list.push_back(key);
            
            auto end_it = key_list.end();
            end_it--;
            
            cache_addr.find(key)->second = end_it;
            
            ret = it->second;
        }
        else
        {
            ret = -1;
        }
        
        return ret;
    }
    
    void put(int key, int value) 
    {
        if (cache_map.find(key) == cache_map.end())
        {
            if (key_list.size() == capacity)
            {
                int evicted = key_list.front();
                key_list.pop_front();
                cache_map.erase(evicted);
                
                cache_addr.erase(evicted);
            }
            
            key_list.push_back(key);
            cache_map.insert(make_pair(key, value));
            
            auto end_it = key_list.end();
            end_it--;
            cache_addr.insert(make_pair(key, end_it));
        }
        else
        {
            list<int>::iterator lit = cache_addr.find(key)->second;
            key_list.erase(lit);
            
            cache_map.find(key)->second = value;
            key_list.push_back(key);
            
            auto end_it = key_list.end();
            end_it--;
            cache_addr.find(key)->second = end_it;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
