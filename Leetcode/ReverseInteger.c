// Leetcode 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/description/
// Runtime: 19ms

// The input is assumed to be a 32-bit signed integer. 
// Your function should return 0 when the reversed integer overflows.
int reverse(int x) 
{
    long long result = 0;
    int count = 0;
    int r = x;

    while (r)
    {
        r = r / 10;
        count++;
    }

    r = x;
    for (int i = count - 1; i >=0; i--)
    {
        int mod = r % 10;
        result += mod * pow(10, i);
        r = r / 10;
    }

    if (result > INT_MAX || result < INT_MIN)
    {
        return 0;
    }
    return result;
}

// 9ms 参考解法
int reverse(int x) 
{
    unsigned int ux, res = 0, tmp, res1;
    if(x < 0)
        ux = 0 - x;
    else
        ux = x;
    
    while(ux)
    { 
        tmp = ux - (ux/10)*10;
        if(res > (0x80000000/10))
            return 0;
        res = res*10;
        if(res >= (0x80000000 - tmp))
            return 0;
        res += tmp;
        ux = ux/10;
    }
    
    if(x < 0)
        return 0 - (int)res;
    
    return res;
}
