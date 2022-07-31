// Leetcode 1410. HTML Entity Parser
// https://leetcode.com/problems/html-entity-parser/
// time complexity: O(n)
// space complexity: O(n) in worst case, O(1) average

class Solution
{
public:
    string entityParser(string text)
    {
      string result = "";
      int i = 0;
      int len = text.length();
      vector<char> buf;
      
      const string quot = "&quot;";
      const string apos = "&apos;";
      const string amp = "&amp;";
      const string gt = "&gt;";
      const string lt = "&lt;";
      const string frasl = "&frasl;";
        
      while (i < len)
      {
        if (text[i] == '&')
        {
          string tmp = "&";
          i++;
          while (i < len && text[i] != ';' && text[i] != '&')
          {
            buf.push_back(text[i]);
            i++;
          }
          
          for (char c : buf)
          {
            tmp.push_back(c);
          }
          
          buf.clear();
          
          if (i < len && text[i] == ';')
          {
            tmp.push_back(';');
          }
          else if (i < len && text[i] == '&')
          {
            i--;
          }
          
          if (quot.compare(tmp) == 0)
          {
            result.push_back('"');
          }
          else if (apos.compare(tmp) == 0)
          {
            result.push_back('\'');
          }
          else if (amp.compare(tmp) == 0)
          {
            result.push_back('&');
          }
          else if (gt.compare(tmp) == 0)
          {
            result.push_back('>');
          }
          else if (lt.compare(tmp) == 0)
          {
            result.push_back('<');
          }
          else if (frasl.compare(tmp) == 0)
          {
            result.push_back('/');
          }
          else
          {
            result.append(tmp);
          }
        }
        else
        {
          result.push_back(text[i]);
        }
        
        i++;
      }
      return result;
    }
};
