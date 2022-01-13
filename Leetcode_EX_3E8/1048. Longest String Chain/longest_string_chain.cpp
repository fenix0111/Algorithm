// Leetcode 1048. Longest String Chain
// https://leetcode.com/problems/longest-string-chain/
// time complexity: O(n * n * m), n is length of words, m is length of word
// space complexity: O(n)

class Solution
{
public:
    int find(unordered_map<string, int>& tbl, map<int, vector<string>>& counter, 
             string& word, int len, int step)
    {
        int result = step;
        if (tbl.count(word))
        {
            return tbl[word];
        }
        
        if (counter.count(len) == 0)
        {
            return step;
        }
        
        vector<string>& bag = counter[len];

        for (int j = 0; j < bag.size(); j++)
        {
            string& s = bag[j];
            for (int k = 0; k < s.length(); k++)
            {
                char c = s[k];
                s.erase(k, 1);

                if (s.compare(word) == 0)
                {
                    s.insert(k, 1, c);
                    result = max(result, find(tbl, counter, s, len + 1, step + 1));
                }                
                else
                {
                    s.insert(k, 1, c);
                }
            }            
        }
        
        tbl[word] = result;
        return result;
    }
    
    int longestStrChain(vector<string>& words)
    {
        map<int, vector<string>> counter;
        unordered_map<string, int> tbl;
        for (string& word : words)
        {
            counter[word.length()].push_back(word);
        }
        
        int result = 1;
        sort(words.begin(), words.end(), [](string& x, string& y) {
            return x.length() < y.length();
        });
        
        for (int i = 0; i < words.size(); i++)
        {
            string& word = words[i];
            result = max(result, find(tbl, counter, word, word.length() + 1, 1));
        }
        
        return result;
    }
};
