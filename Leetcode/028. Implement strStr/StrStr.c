// Leetcode 28. Implement strStr()
// https://leetcode.com/problems/implement-strstr/description/
// Runtime: 3ms

// 实现C标准库的strstr函数。(返回needle第一次出现在haystack的指针)
int strStr(char* haystack, char* needle) 
{
    int len_haystack = strlen(haystack);
    int len_needle = strlen(needle);

    // 被比较字符串长度大于目标字符串时直接返回-1
    if (len_haystack < len_needle)
        return -1;

    int diff = len_haystack - len_needle;
    for (int i = 0; i <= diff; i++)
    {
        if (strncmp(haystack + i, needle, len_needle) == 0)
            return i;
    }
    return -1;
}
