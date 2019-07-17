// Leetcode 500. Keyboard Row
// https://leetcode.com/problems/keyboard-row/
// Runtime: 0ms

class Solution 
{
public:
    vector<string> findWords(vector<string>& words) 
    {        
        int qc = 0;
        int ac = 0;
        int zc = 0;

        vector<string> ret;
        for (int i = 0; i < words.size(); i++)
        {
            string tmp = words[i];
            qc = 0;
            ac = 0;
            zc = 0;
            char c;
            for (int j = 0; j < tmp.size(); j++)
            {
                c = tmp[j];
                switch(c)
                {
                    case 'a':
                        ac++;
                        break;
                    case 'b':
                        zc++;
                        break;
                    case 'c':
                        zc++;
                        break;
                    case 'd':
                        ac++;
                        break;
                    case 'e':
                        qc++;
                        break;
                    case 'f':
                        ac++;
                        break;
                    case 'g':
                        ac++;
                        break;
                    case 'h':
                        ac++;
                        break;
                    case 'i':
                        qc++;
                        break;
                    case 'j':
                        ac++;
                        break;
                    case 'k':
                        ac++;
                        break;
                    case 'l':
                        ac++;
                        break;
                    case 'm':
                        zc++;
                        break;
                    case 'n':
                        zc++;
                        break;
                    case 'o':
                        qc++;
                        break;
                    case 'p':
                        qc++;
                        break;
                    case 'q':
                        qc++;
                        break;
                    case 'r':
                        qc++;
                        break;
                    case 's':
                        ac++;
                        break;
                    case 't':
                        qc++;
                        break;
                    case 'u':
                        qc++;
                        break;
                    case 'v':
                        zc++;
                        break;
                    case 'w':
                        qc++;
                        break;
                    case 'x':
                        zc++;
                        break;
                    case 'y':
                        qc++;
                        break;
                    case 'z':
                        zc++;
                        break;
                }
            }
            
            if ((ac == 0 && zc == 0) || (qc == 0 && ac == 0) || (qc == 0 && zc == 0))
            {
                ret.push_back(tmp);
            }
        }
        
        return ret;
    }
};
