// Leetcode 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/description/
// Runtime: 3ms

bool isValid(char* s) {
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

// 0ms参考解法
#define MAX_LENGTH 10000
bool isValid(char* s) {
    char stack[MAX_LENGTH];
    int top = -1;
    while(*s != '\0') {
        if (*s == '['  || *s == '{' || *s == '(') {
            stack[++top] =  *s;
        } else if (top < 0){
            return false;
        } else if (*s == ']') {
            if (stack[top--] != '[') {
                return false;
            }
        } else if (*s == '}') {
            if (stack[top--] != '{') {
                return false;
            }
        } else if (*s == ')') {
            if (stack[top--] != '(') {
                return false;
            }
        } else {
            return false;
        }
        ++s;
    }
    if (top != -1) {
        return false;
    }
    return true;
}
