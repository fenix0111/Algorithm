// Leetcode 1359. Count All Valid Pickup and Delivery Options
// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
// time complexity: O(N)
// space complexity: O(N)

// we can try several number to guess the solution
// 2 : 6, 3 : 90, 4 : 2520...
// it seems that solution is equal to number of orders of previous number multiply by current number * (current number - 1)
// after guessing, we have to figure out why..
class Solution
{
    int MOD = 1000000007;
public:
    int countOrders(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        
        return (((unsigned long long)(countOrders(n - 1)) * n % MOD) * (2 * n - 1)) % MOD;
    }
};
