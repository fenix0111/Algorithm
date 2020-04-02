// Leetcode 648. Replace Words
// https://leetcode.com/problems/replace-words/
// Runtime: 444 ms
// Memory: 440.2 MB

// slow and cost huge memory 

////////////// Trie //////////////
// https://www.geeksforgeeks.org/trie-insert-and-search/
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
  
// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
////////////// Trie END ////////////// 

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) 
    {
        struct TrieNode *root = getNode(); 
        for (string s : dict)
        {
            insert(root, s);
        }
        
        vector<string> splitted;
        split(sentence, splitted);
        
        string ret = "";
        for (string s : splitted)
        {
            int len = 1;
            bool found = false;
            while (len <= s.length())
            {
                string subs = s.substr(0, len);
                if (search(root, subs))
                {
                    ret.append(subs);
                    ret.append(" ");
                    found = true;
                    break;
                }
                len++;
            }
            if (!found)
            {
                ret.append(s);
                ret.append(" ");
            }
        }
        
        if (ret.length() > 1)
            ret.pop_back();  // delete last space
        
        return ret;
    }
    
    size_t split(const string &txt, vector<std::string> &strs)
    {
        size_t pos = txt.find(' ');
        size_t initialPos = 0;
        strs.clear();

        while( pos != string::npos ) 
        {
            strs.push_back( txt.substr( initialPos, pos - initialPos ) );
            initialPos = pos + 1;
            pos = txt.find( ' ', initialPos );
        }

        strs.push_back( txt.substr( initialPos, min( pos, txt.size() ) - initialPos + 1 ) );

        return strs.size();
    }
};
