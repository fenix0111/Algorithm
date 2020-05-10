// Leetcode 997. Find the Town Judge
// https://leetcode.com/problems/find-the-town-judge/
// Runtime: 344 ms
// Memory: 61 MB

typedef struct degree
{
    int in;
    int out;
};
    
class Solution 
{
public:
    int findJudge(int N, vector<vector<int>>& trust) 
    {
        degree* tbl = (degree*)malloc(sizeof(degree) * (N + 1));
        for (int i = 0; i <= N; i++)
        {
            tbl[i].in = 0;
            tbl[i].out = 0;
        }
        
        int judge = -1;
        for (int r = 0; r < trust.size(); r++)
        {
            tbl[trust[r][0]].out++;
            tbl[trust[r][1]].in++;
        }

        for (int i = 1; i <= N; i++)
        {
            // town judge need to be trusted by all the people and trust nobody 
            if (tbl[i].in == N - 1 && tbl[i].out == 0)
            {               
               return i;
            }
        }
        
        return judge;
    }
};
