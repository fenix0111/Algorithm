// Leetcode 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
// time complexity: O(n)
// space complexity: O(1)

class Solution
{
public:
  int isPrefixOfWord(string sentence, string searchWord)
  {
    int result = -1;
    int i = 0;
    int count = 1;
    
    int lenS = sentence.length();
    int lenPrefix = searchWord.length();
    
    while (i < lenS)
    {
      int j = 0;
      while (i < lenS && j < lenPrefix && sentence[i] == searchWord[j])
      {
        i++;
        j++;
      }
      
      if (j == lenPrefix)
      {
        result = count;
        break;
      }
      
      count++;
      
      while (i < lenS && sentence[i] != ' ')
      {
        i++;
      }
      i++;
    }
    
    return result;
  }
};
