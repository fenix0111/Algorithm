// Leetcode 682. Baseball Game
// https://leetcode.com/problems/baseball-game/submissions/
// Runtime: 4ms

class Solution 
{
public:
    int calPoints(vector<string>& ops) 
    {
        int *point = (int*)malloc(sizeof(int) * ops.size());
        memset(point, 0, ops.size());
        
        char *C = "C";
        char *D = "D";
        char *PLUS = "+";
        int idx = 0;
        for (int i = 0; i < ops.size(); i++)
        {
            const char *c = ops[i].c_str();        
            int num;
            if (sscanf(c, "%d", &num))
            {
                point[idx++] = num;
            }
            else
            {
                if (strcmp(c, C) == 0)
                {
                    idx--;
                }
                else if (strcmp(c, D) == 0)
                {
                    point[idx] = point[idx - 1] * 2;
                    idx++;
                }
                else if (strcmp(c, PLUS) == 0)
                {
                    point[idx] = point[idx - 1] + point[idx - 2];
                    idx++;
                }
            }
        }
        
        int ret = 0;
        for (int i = 0; i < idx; i++)
        {
            ret += point[i];
        }
        return ret;
    }
};
