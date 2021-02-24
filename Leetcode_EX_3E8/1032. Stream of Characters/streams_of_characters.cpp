// Leetcode 1032. Stream of Characters
// https://leetcode.com/problems/stream-of-characters/
// time complexity: O(len(word))
// space complexity: O(n) 

// store each word in reverse order in a trie
// each time when a new letter is inserted, check the array of stored letters back to front
typedef struct Trie
{
    Trie* children[128];
    bool isEnd;
    
    Trie()
    {
        for (int i = 0; i < 128; i++)
        {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class StreamChecker 
{
    Trie* trie;
    vector<char> streamArray;
    
public:
    StreamChecker(vector<string>& words) 
    {
        trie = new Trie();
        for (int i = 0; i < words.size(); i++)
        {
            Trie* node = trie;
            string& word = words[i];
            for (int j = word.length() - 1; j >= 0; j--)
            {
                char c = word[j];
                if (node->children[c] == nullptr)
                {
                    node->children[c] = new Trie();
                }
                node = node->children[c];
            }
            node->isEnd = true;
        }
    }
    
    bool query(char letter) 
    {
        Trie* node = trie;
        streamArray.push_back(letter);
        for (int i = streamArray.size() - 1; i >= 0; i--)
        {
            char c = streamArray[i];
            node = node->children[c];
            if (node == nullptr)
            {
                return false;
            }
            
            if (node->isEnd)
            {
                return true;
            }
        }
        
        // never reach here
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
