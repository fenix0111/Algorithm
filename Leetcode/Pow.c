// 网上参考解法
// 主要思想是x的4次方等于x2的两次方，所以没必要在while循环里从0乘到n

// 实现C的pow函数
double myPow(double x, int n) 
{
    if (n == 0) 
		    return 1;

    double half = myPow(x, n / 2);

	  if (n % 2 == 0) 
		    return half * half;
	  else if (n > 0) 
		    return half * half * x;
	  else 
		    return half * half / x;
}
