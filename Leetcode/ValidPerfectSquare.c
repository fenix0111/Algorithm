// Leetcode 367. Valid Perfect Square
// https://leetcode.com/problems/valid-perfect-square/description/
// Runtime: 942 ms (不及格)

bool isPerfectSquare(int num) 
{
    if (num == 0 || num == 2 || num == 3)
        return false;
        
    if (num == 1 )
        return true;
        
    int n = num / 2;
	
    for (int i = 2; i <= n; i++)
    {
        int prdt = i * i;
        if (prdt == num)
            return true;
        if (prdt > num)
            return false;
    }
    return false;
}
