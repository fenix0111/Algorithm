// Leetcode 263. Ugly Number
// https://leetcode.com/problems/ugly-number/description/
// Runtime: 6ms

bool isUgly(int num) {
    if (num == 1)
		return true;
		
	if (num == 0)
		return false;

	int n = num;
	while (n != 1)
	{
		if (n % 2 == 0)
		{
			n = n / 2;
			continue;
		}
		else if (n % 3 == 0)
		{
			n = n / 3;
			continue;
		}
		else if (n % 5 == 0)
		{
			n = n / 5;
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

// 3ms参考解法
bool isUgly(int num) {
    if(num<=0)
        return false;
    if(num==1)
        return true;
    if(num%2 == 0)
        return isUgly(num/2);
    
    else if(num%3 == 0)
        return isUgly(num/3);
    
    else if(num%5 == 0)
        return isUgly(num/5);
    else
        return false;
}
