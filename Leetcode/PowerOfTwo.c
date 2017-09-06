// Leetcode 231. Power of Two
// https://leetcode.com/problems/power-of-two/description/
// Runtime: 3ms

bool isPowerOfTwo(int n) {
    if (n == 0)
	{
		return false;
	}

	if (n == 1)
	{
		return true;
	}

	if (n % 2 == 0)
	{
		return isPowerOfTwo(n / 2);
	}
	else
	{
		return false;
	}
}
