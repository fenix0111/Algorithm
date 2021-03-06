// Leetcode 820. Short Encoding of Words
// https://leetcode.com/problems/short-encoding-of-words/
// time complexity: 
// space complexity: 

typedef struct Trie
{
    Trie* children[26];
    bool end;
    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        end = false;
    }
};

class Solution 
{
public:
    void check(Trie* trie, int& result, int depth)
    {
        if (trie == nullptr)
        {
            return;
        }
        
        if (trie->end)
        {
            result += depth;
            result += 1;
        }
        
        for (int i = 0; i < 26; i++)
        {
            check(trie->children[i], result, depth + 1);
        }
    }
    
    int minimumLengthEncoding(vector<string>& words) 
    {
        Trie* root = new Trie();
        for (string& word : words)
        {
            Trie* p = root;
            bool visited = false;
            for (int i = word.length() - 1; i >= 0; i--)
            {
                char c = word[i];
                if (p->children[c - 'a'] == nullptr)
                {
                    p->children[c - 'a'] = new Trie();
                    visited = false;
                }
                else
                {
                    visited = true;
                }
                
                if (p->end)
                {
                    p->end = false;
                }
                p = p->children[c - 'a'];
            }
            
            if (!visited)
                p->end = true;
        }
        
        int result = 0;
        check(root, result, 0);
        
        return result;
    }
};
