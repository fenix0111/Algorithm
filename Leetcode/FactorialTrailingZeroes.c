// Leetcode 172. Factorial Trailing Zeroes
// https://leetcode.com/problems/factorial-trailing-zeroes/description/
// Runtime: 3ms

// 很有意思的题
// 理论基础：
// https://en.wikipedia.org/wiki/Trailing_zero#Factorial
// https://en.wikipedia.org/wiki/Legendre%27s_formula

// 代码只是把维基百科的公式代码化罢了

int trailingZeroes(int n)
{
    int k = floor(log(n) / log(2));
    int num = 0;
    for (int i = 1; i <= k; i++)
    {
        num = num + floor((n / pow(5, i)));
    }
    return num;
}
