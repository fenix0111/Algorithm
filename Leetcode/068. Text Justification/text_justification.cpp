// Leetcode 68. Text Justification
// https://leetcode.com/problems/text-justification/
// time complexity: O(total number of words)
// space complexity: O(total number of words)

class Solution 
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> result;
        vector<vector<string>> aux;
        
        int currentWidth = maxWidth;
        int i = 0;
        vector<string> tmp;
        string space = " ";
        
        // split words into lines
        while (i < words.size())
        {
            if (currentWidth >= words[i].length())
            {
                tmp.push_back(words[i]);
                currentWidth -= words[i].length();
                
                if (i < words.size() - 1 && currentWidth > words[i + 1].length())
                {
                    tmp.push_back(space);
                    currentWidth--;
                }
                else
                {
                    aux.push_back(tmp);
                    tmp.clear();
                    currentWidth = maxWidth;
                }
            }
            else
            {
                aux.push_back(tmp);
                tmp.clear();
                currentWidth = maxWidth;
            }
            
            i++;
        }
        
        for (int i = 0; i < aux.size(); i++)
        {
            int totalWidth = 0;
            int totalSpace = 0;
            for (int j = 0; j < aux[i].size(); j++)
            {
                totalWidth += aux[i][j].length();
                if (aux[i][j] == space)
                {
                    totalSpace++;
                }
            }
            
            string s = "";
            if (totalWidth == maxWidth)
            {
                // copy the line as is
                for (int j = 0; j < aux[i].size(); j++)
                {
                    s += aux[i][j];
                }
                result.push_back(s);
            }
            else
            {
                int diff = maxWidth - totalWidth;
                int div = 0;
                int remain = 0;
                if (totalSpace > 0)
                {
                    div = diff / totalSpace;
                    remain = diff % totalSpace;
                }
                
                for (int j = 0; j < aux[i].size(); j++)
                {
                    if (space.compare(aux[i][j]) == 0)
                    {
                        // when not last line
                        if (i < aux.size() - 1)
                        {
                            int i = div;
                            while (i >= 0)
                            {
                                s += space;
                                i--;
                            }

                            // for evenly insert spaces from left to right
                            if (remain > 0)
                            {
                                s += space;
                                remain--;
                            }
                        }
                        else
                        {
                            // last line, left alignment
                            s += space;
                        }
                    }
                    else
                    {
                        s += aux[i][j];
                    }
                }
                
                // last line padding, hit this while loop only in the last line
                while (s.length() < maxWidth)
                {
                    s += space;
                }
                
                result.push_back(s);
            }
        }
        
        return result;
    }
};
