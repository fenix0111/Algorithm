// Leetcode 171. Excel Sheet Column Number
// https://leetcode.com/problems/excel-sheet-column-number/description/
// Runtime: 3ms

int titleToNumber(char* s) {
    int res = 0;
    int len = strlen(s);
    int n = 0;    
    while (n < len - 1)
    {
        // 'A' is 65   
        res = res + (pow(26, len - n - 1) * (s[n] - 'A' + 1));
        n = n + 1;
    }
    res = res + (s[n] - 'A' + 1);
    return res;
}
