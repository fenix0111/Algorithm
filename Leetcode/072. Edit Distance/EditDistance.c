// Leetcode 72. Edit Distance
// https://leetcode.com/problems/edit-distance/description/
// Runtime: 9ms

// Wagner–Fischer算法专治Edit Distance问题
// https://en.wikipedia.org/wiki/Wagner%E2%80%93Fischer_algorithm
int min(int x, int y, int z) 
{
    int min = 0;
    if (x <= y && x <= z)
        min = x;
    if (y <= x && y <= z)
        min =  y;
    if (z <= x && z <= y)
        min =  z;
    return min;
}

int minDistance(char* word1, char* word2) 
{
    int len_s = strlen(word1) + 1;
    int len_t = strlen(word2) + 1;

    int** d = (int**)malloc(sizeof(int*) * len_s);
    for (int i = 0; i < len_s; i++)
    {
        d[i] = (int*)malloc(sizeof(int) * len_t);
    }

    for (int i = 0; i < len_s; i++) 
    {
        d[i][0] = i;
    }

    for (int j = 0; j < len_t; j++) 
    {
        d[0][j] = j;
    }

    for (int j = 0; j < len_t - 1; j++) 
    {
        for (int i = 0; i < len_s - 1; i++) 
        {
            if (word1[i] == word2[j]) 
            {
                d[i + 1][j + 1] = d[i][j];
            } 
            else 
            {
                d[i + 1][j + 1] = min( d[i][j + 1] + 1, d[i + 1][j] + 1, d[i][j] + 1 );
            }
        }
    }
    
    return d[len_s - 1][len_t - 1];
}
