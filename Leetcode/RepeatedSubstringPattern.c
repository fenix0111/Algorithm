// Leetcode 459. Repeated Substring Pattern
// https://leetcode.com/problems/repeated-substring-pattern/description/
// Runtime: 19ms

bool repeatedSubstringPattern(char* str) {
    char begin = str[0];

	int len = strlen(str);
	if (len == 0 || len == 1)
		return false;
	
	int mid = len / 2;

	char *pattern = (char*)malloc(sizeof(char) * mid);
	char *tmp = (char*)malloc(sizeof(char) * mid);

	for (int range = 1; range <= mid; range++)
	{
		if (len % range != 0)
			continue;

		bool result = true;
		strncpy(tmp, str, range);
		for (int base = 0; base < len; base = base + range)
		{
			if (strncmp(tmp, str + base, range) != 0)
			{
				result = result && false;
				continue;
			}
			else
			{
				result = result && true;
			}
		}
		if (result)
			return true;
	}
	
	return false;
}

// 6ms 参考解法
bool repeatedSubstringPattern(char* s) {
    int iLen = strlen(s);
    if (iLen == 1) {
        return false;
    }
    if (memcmp(s, s + 1, iLen - 1) == 0) {
        return true;
    }
    for (int iIndex = 2; iIndex * iIndex <= iLen; iIndex++) {
        if (iLen % iIndex != 0) {
            continue;
        }
        int iSubLen = iIndex;
        if (memcmp(s, s + iSubLen, iLen - iSubLen) == 0) {
            return true;
        }
        iSubLen = iLen / iIndex;
        if (memcmp(s, s + iSubLen, iLen - iSubLen) == 0) {
            return true;
        }
    } 
    return false;
}
