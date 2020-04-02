// Leetcode 648. Replace Words
// https://leetcode.com/problems/replace-words/
// Runtime: 56 ms
// Memory: 46.7 MB

const int ALPHABET_SIZE = 26; 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 

int search_and_return(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (pCrawl->isEndOfWord)
        {
            cout << key[i] << endl;
            return i;
        }
            
        if (!pCrawl->children[index]) 
        {
            return -1;
        }    
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    if (pCrawl != NULL && pCrawl->isEndOfWord)
    {
        return key.length();
    }
    else
    {
        return -1;
    }
} 

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) 
    {
        struct TrieNode *root = getNode(); 
        for (string s : dict)
        {
            insert(root, s);
        }
        
        int r = 0;
        int l = 0;
        string ret = "";
        while (r < sentence.length())
        {
            if (sentence[r] == ' ')
            {
                string subs = sentence.substr(l, r - l);
                r++;
                l = r;
                int len = search_and_return(root, subs);
  
                if (len == -1)
                {
                    ret.append(subs);
                }
                else
                {
                    ret.append(subs.substr(0, len));
                }
                ret.append(" ");
            }
            else
            {
                r++;
            }
        }
        
        string subs = sentence.substr(l, r - l);
        int len = search_and_return(root, subs);
        if (len == -1)
        {
            ret.append(subs);
        }
        else
        {
            ret.append(subs.substr(0, len));
        }
        
        return ret;
    }
};
