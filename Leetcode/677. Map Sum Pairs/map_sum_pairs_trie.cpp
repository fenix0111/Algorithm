// Leetcode 677. Map Sum Pairs
// https://leetcode.com/problems/map-sum-pairs/
// Runtime: 0ms

// exceptioinally ugly code... though it works
typedef struct Trie
{
    int val;
    unordered_map<char, Trie*> children;
    
    Trie(int v) { this->val = v; }
} Trie;

class MapSum 
{
    unordered_map<char, Trie*> dic;
    unordered_set<string> bag;
    
public:
    /** Initialize your data structure here. */
    MapSum() 
    {
        
    }
    
    void insert(string key, int val) 
    {
        bool already = false;
        if (bag.find(key) != bag.end())
        {
            already = true;
        }
        else
        {
            bag.insert(key);
        }
        
        Trie *node;
        
        if (already)
        {
            if (dic.find(key[0]) == dic.end())
            {
                dic.insert(make_pair(key[0], new Trie(val)));
            }
            else
            {
                dic.find(key[0])->second->val += val - dic.find(key[0])->second->val;
            }
        }
        else
        {
            if (dic.find(key[0]) == dic.end())
            {
                dic.insert(make_pair(key[0], new Trie(val)));
            }
            else
            {
                dic.find(key[0])->second->val += val;
            }
        }
        
        node = dic.find(key[0])->second;
        
        if (already)
        {
            for (int i = 1; i < key.size(); i++)
            {
                if (node->children.find(key[i]) == node->children.end())
                {
                    node->children.insert(make_pair(key[i], new Trie(val)));
                }
                else
                {
                    node->children.find(key[i])->second->val += val - node->children.find(key[i])->second->val;
                }

                node = node->children.find(key[i])->second;
            }
        }
        else
        {
            for (int i = 1; i < key.size(); i++)
            {
                if (node->children.find(key[i]) == node->children.end())
                {
                    node->children.insert(make_pair(key[i], new Trie(val)));
                }
                else
                {
                    node->children.find(key[i])->second->val += val;
                }

                node = node->children.find(key[i])->second;
            }
        }
    }
    
    // the problem description didn't say the value to be returned when prefix match nothing
    // return 0 works fine
    int sum(string prefix) 
    {        
        if (dic.find(prefix[0]) == dic.end())
            return 0;
        
        Trie *root = dic.find(prefix[0])->second;
        if (!root)
            return 0;
        
        int sum = root->val;
        for (int i = 1; i < prefix.size(); i++)
        {
            if ((root->children).find(prefix[i]) == (root->children).end())
                return 0;
            
            root = (root->children).find(prefix[i])->second;
            if (!root)
                return 0;
        }
        
        return root->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
