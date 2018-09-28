// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/description/
// Runtime: 84ms

// this problem has assumption that letters may consist of a to z.
// so using vector would be more efficient.

class Trie 
{
public:
    /** Initialize your data structure here. */
    
    // do not declare member variable like this..
    map<char, Trie*> *m;
    string val = "";
    
    Trie() 
    {
        m = new map<char, Trie*>();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Trie* t = this;
        for (int i = 0; i < word.size(); i++)
        {
            auto it = t->m->find(word[i]);
            if (it == t->m->end())
            {
                Trie* newTrie = new Trie();
                t->m->insert(make_pair(word[i], newTrie));
                
                t = newTrie;
            }
            else
            {
                t = it->second;
            }
        }
        t->val = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Trie *t = this;
        for (int i = 0; i < word.size(); i++)
        {
            auto it = t->m->find(word[i]);
            if (it == t->m->end())
            {
                return false;
            }
            else
            {
                t = it->second;
            }
        }
        
        // check if node has target string
        if (t->val != word)
            return false;
        
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        Trie *t = this;
        for (int i = 0; i < prefix.size(); i++)
        {
            auto it = t->m->find(prefix[i]);
            if (it == t->m->end())
            {
                return false;
            }
            else
            {
                t = it->second;
            }
        }
        
        return true;
    }
};
