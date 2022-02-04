// Leetcode 748. Shortest Completing Word
// https://leetcode.com/problems/shortest-completing-word/
// time complexity: O(len(words) * len(word))
// space complexity: O(1)

class Solution
{
public:
    bool isValid(const int* license, const int* word)
    {
        for (int i = 0; i < 26; i++)
        {
            if (license[i] > word[i])
            {
                return false;
            }
        }
        return true;
    }
    
    void clearCounter(int* a)
    {
        for (int i = 0; i < 26; i++)
        {
            a[i] = 0;
        }
    }
    
    string shortestCompletingWord(string licensePlate, vector<string>& words)
    {
        int license_counter[26] = { 0 };
        for (char c : licensePlate)
        {
            if (isalpha(c))
            {
                license_counter[tolower(c) - 'a']++;
            }
        }
        
        int minlen = INT_MAX;
        int result = -1;
        int buf[26] = { 0 };
        for (int i = 0; i < words.size(); i++)
        {            
            string& word = words[i];
            for (char c : word)
            {
                if (isalpha(c))
                {
                    buf[tolower(c) - 'a']++;
                }
            }
            
            if (isValid(license_counter, buf) && minlen > word.length())
            {
                minlen = word.length();
                result = i;
            }
            
            clearCounter(buf);
        }
        
        return words[result];
    }
};
