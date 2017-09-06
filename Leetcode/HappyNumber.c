// Leetcode 202. Happy Number
// https://leetcode.com/problems/happy-number/description/
// Runtime: 19ms

bool isHappy(int n) 
{
    int num = n;
    int count = 10;
    int sum = 0;
    int mod;
        
    while (--count)
    {
        mod = 0;
        sum = 0;
        while (num)
        {
            mod = num % 10;
            sum += mod * mod;
            num = num / 10;
        }
        
        num = sum;
        
        if (sum == 86 || sum == 68 || sum == 1)
            return true;
    }
    return false;
}

// 0ms参考解法
bool isHappy(int n) 
{
    int dig,sum=0;
    while(n>=10)
    {
        for(;n>0;)
        {
            dig = n-n/10*10;
            n = n/10;
            sum += dig*dig;
        }
        n = sum;
        sum = 0;
    }
    if(n == 1||n==7)
        return 1;
    else 
        return 0;
}
