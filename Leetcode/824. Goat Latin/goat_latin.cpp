// Leetcode 824. Goat Latin
// https://leetcode.com/problems/goat-latin/
// time complexity: O(length of input string)
// space complexity: O(1)

class Solution 
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    string toGoatLatin(string S) 
    {
        string goatLatin = "";
        int index = 1;
        bool is_begin = true;
        char first_consonant = 0;
        for (char c : S)
        {
            if (c == ' ')
            {
                int i = 1;
                if (first_consonant != 0)
                {
                    goatLatin.push_back(first_consonant);
                    first_consonant = 0;
                }
                
                goatLatin.push_back('m');
                goatLatin.push_back('a');
                while (i <= index)
                {
                    goatLatin.push_back('a');
                    i++;
                }
                
                goatLatin.push_back(' ');
                index++;
                is_begin = true;
            }
            else
            {
                if (is_begin && !isVowel(c))
                {
                    first_consonant = c;
                    is_begin = false;
                }
                else
                {
                    goatLatin.push_back(c);
                }
                
                if (is_begin)
                {
                    is_begin = false;
                }
            }
        }
        
        int i = 1;
        if (first_consonant != 0)
        {
            goatLatin.push_back(first_consonant);
            first_consonant = 0;
        }

        goatLatin.push_back('m');
        goatLatin.push_back('a');
        while (i <= index)
        {
            goatLatin.push_back('a');
            i++;
        }
        
        return goatLatin;
    }
};
