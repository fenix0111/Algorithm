// Leetcode 69. Sqrt(x)
// https://leetcode.com/problems/sqrtx/description/
// Runtime: 19ms

int mySqrt(int x) {
    if (x == 0 || x == 1)
		{
			return x;
		}

		long long i = 1;
		while (i * i <= x)
		{
			i++;
		}

		return (int)(i - 1);
}

// 3ms参考解法
int mySqrt(int x) {
    unsigned long long begin = 0;
    unsigned long long end = (x+1)/2;
    unsigned long long mid;
    unsigned long long tmp;
    while(begin < end)
    {
        mid = begin + (end - begin)/2;
        tmp = mid * mid;
        if(tmp==x)
            return mid;
        else if(tmp < x)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    tmp = end * end;
    if(tmp>x)
        return end -1;
    else
        return end;
}
