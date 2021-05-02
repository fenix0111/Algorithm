// Leetcode 745. Prefix and Suffix Search
// https://leetcode.com/problems/prefix-and-suffix-search/
// 
// 

class Trie
{
    Trie* children[26];
    int depth;
    bool end;
public:
    Trie() 
    {
        depth = 0;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        end = false;
    }
    
    Trie(char c, int d)
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        end = false;
        
        depth = d;
        children[c - 'a'] = new Trie();
    }
    
    void init(string& s)
    {
        int d = 0;
        Trie* node = this;
                
        for (char c : s)
        {
            if (node->children[c - 'a'] == nullptr)
            {
                node->children[c - 'a'] = new Trie(c, d);
            }
            
            node = node->children[c - 'a'];
        }
        
        node->end = true;
    }
    
    void dfs(string& p, unordered_map<string, int>& M, Trie* node, priority_queue<int>& resultSet)
    {
        if (node != nullptr && node->end)
        {
            resultSet.push(M[p]);
            return;
        }
        
        if (node == nullptr)
        {
            return;
        }
        
        for (int i = 0; i < 26; i++)
        {
            p.push_back(i + 'a');
            dfs(p, M, node->children[i], resultSet);
            p.pop_back();
        }
    }
    
    void search(string& p, unordered_map<string, int>& M, priority_queue<int>& resultSet)
    {
        Trie* node = this;
        for (char c : p)
        {
            if (node->children[c - 'a'] == nullptr)
            {
                return;
            }
            node = node->children[c - 'a'];
        }
        
        dfs(p, M, node, resultSet);
    }
};

class WordFilter 
{
    Trie* prefixTrie;
    unordered_map<string, int> M;
    vector<string> w;
    
public:
    WordFilter(vector<string>& words) 
    {
        for (int i = 0; i < words.size(); i++)
        {
            w.push_back(words[i]);
        }
        
        prefixTrie = new Trie();
        
        for (int i = 0; i < words.size(); i++)
        {
            string& word = words[i];
            prefixTrie->init(word);
            M[word] = i;
        }
    }
    
    bool validSuffix(string& str, string& suffix)
    {
        if (suffix.length() > str.length())
            return false;
        
        int j = str.length() - 1;
        int i = suffix.length() - 1;
        while (i >= 0)
        {
            if (str[j] != suffix[i])
            {
                return false;
            }
            
            j--;
            i--;
        }
        
        return true;
    }
    
    int f(string prefix, string suffix) 
    {
        priority_queue<int> prefixResult;     
        prefixTrie->search(prefix, M, prefixResult);
        while (!prefixResult.empty())
        {
            string& str = w[prefixResult.top()];
            if (validSuffix(str, suffix))
            {
                return prefixResult.top();
            }
            
            prefixResult.pop();
        }
        
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
