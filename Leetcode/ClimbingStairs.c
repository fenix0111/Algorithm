// Leetcode 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/description/
// Runtime: 0ms

int climbStairs(int n) {
    if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	int f1 = 1;
	int f2 = 2;

	int sum = 0;
	for (int i = 3; i <= n; i++)
	{
		sum = f1 + f2;
		f1 = f2;
		f2 = sum;
	}

	return sum;
}
