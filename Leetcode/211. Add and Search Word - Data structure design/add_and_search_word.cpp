// Leetcode 211. Add and Search Word - Data structure design
// https://leetcode.com/problems/add-and-search-word-data-structure-design/

// quite messy..
class Trie 
{
public:
    Trie* children[26];
    bool is_end;
    
    /** Initialize your data structure here. */
    Trie() 
    {
        is_end = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->children[word[i] - 'a'] == nullptr)
            {
                node->children[word[i] - 'a'] = new Trie();
            }
            node = node->children[word[i] - 'a'];
        }
        
        node->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (int i = 0; i < word.length(); i++)
        {
            node = node->children[word[i] - 'a'];
            if (node == nullptr)
            {
                break;
            }
        }
        
        return (node != nullptr) && (node->is_end == true);
    }
};

class WordDictionary 
{
private:
    Trie *node = NULL;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() 
    {
        this->node = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) 
    {
        this->node->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) 
    {
        return helper(word, this->node, 0);
    }
    
    bool helper(string word, Trie* node, int idx)
    {
        if (!node)
            return false;
        
        char c = word[idx];
        bool res = false;
        if (c == '.')
        {
            if (idx == word.length() - 1)
            {
                for (int i = 0; i < 26; i++)
                {
                    Trie* child = node->children[i];
                    if (child && child->is_end)
                    {
                        return true;
                    }
                }
                return false;
            }
            
            for (int i = 0; i < 26; i++)
            {
                res = res || helper(word, node->children[i], idx + 1);
            }
        }
        else
        {
            Trie* child = node->children[c - 'a'];
            if (idx == word.length() - 1)
            {
                if (child && child->is_end)
                {
                    return true;
                }
                return false;
            }
            
            res = helper(word, child, idx + 1);
        }
        
        return res;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
