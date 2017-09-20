// Leetcode 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/description/
// Runtime: 3ms

bool isValid(char* s) 
{
    int len = strlen(s);
    if (len % 2 != 0)
    {
        return false;
    }

    char *stack = (char*)malloc(sizeof(char) * (len));
    char *cur = stack;
	
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
        {
            *cur = s[0];
            cur++;
        }
        else
        {
            *cur = s[i];
            if (cur - stack > 0)
            {
                if (*cur - *(cur - 1) <= 2 && *cur - *(cur - 1) > 0)
                {
                    cur--;
                }
                else
                {
                    cur++;
                }
            }
        }
    }
    
    if (cur == stack)
    {
        return true;
    }
    else
    {
        return false;
    }
}
