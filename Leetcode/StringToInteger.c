// Leetcode 8. String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/description/Runtime: 15ms
// Runtime: 15ms

int myAtoi(char* str) 
{
    int isMinus = -1;  // -1 for no sign
	int len = strlen(str);
	int result = 0;
	long long tmp = 0;
	int begin = 0;
	int end = -1;
	int actlen = 0;

	while (isspace(str[begin]))
	{
		begin++;
	}

	if (str[begin] == '+')
	{
		isMinus = 0;
		begin++;
	}
	else if (str[begin] == '-')
	{
		isMinus = 1;
		begin++;
	}

	for (int i = begin; i < len; i++)
	{
		if (isdigit(str[i]))
		{
			end = i;
		}
		else
		{
			break;
		}
	}

	actlen = end - begin + 1;

	if (actlen == 0)
	{
		return 0;
	}
	
	if (actlen > 10)
	{
		if (isMinus == 1)
		{
			return INT_MIN;
		}
		else
		{
			return INT_MAX;
		}
	}
	
	for (int j = 0; j < actlen; j++)
	{
		tmp += pow(10, actlen - j - 1) * (str[begin + j] - 48);
	}

	if (isMinus == 1)
	{
		tmp = -tmp;
	}

	if (tmp > INT_MAX)
	{
		result = INT_MAX;
	}
	else if (tmp < INT_MIN)
	{
		result = INT_MIN;
	}
	else
	{
		result = tmp;
	}
	return result;
}
