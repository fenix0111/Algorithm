// Leetcode 804. Unique Morse Code Words
// https://leetcode.com/problems/unique-morse-code-words/
// Runtime: 4ms

class Solution 
{
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        char *tbl[26] = {   
                            ".-",
                            "-...",
                            "-.-.",
                            "-..",
                            ".",
                            "..-.",
                            "--.",
                            "....",
                            "..",
                            ".---",
                            "-.-",
                            ".-..",
                            "--",
                            "-.",
                            "---",
                            ".--.",
                            "--.-",
                            ".-.",
                            "...",
                            "-",
                            "..-",
                            "...-",
                            ".--",
                            "-..-",
                            "-.--",
                            "--.." 
                        };
        int unique = 0;
        string morse = "";
        unordered_map<string, bool> um;
        for (string s : words)
        {
            morse.clear();
            for (char c : s)
            {
                morse += tbl[c - 'a'];
            }
            if (um.find(morse) == um.end())
            {
                unique++;
                um.insert(make_pair(morse, true));
            }   
        }
        
        return unique;
    }
};
