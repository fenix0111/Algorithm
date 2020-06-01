// Leetcode 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/
// time complexity: O(n*n)
// space complexity: O(n);

// assume A[i] + B[j] = sum, and there are X cases equal to sum.
// and C[k] + D[l] = -sum, Y cases equal to -sum;
// then total number of A[i] + B[j] + C[k] + D[l] = 0 is X * Y. 
class Solution 
{
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
        unordered_map<int, int> absum;
        for (int a : A)
        {
            for (int b : B)
            {
                int sum = a + b;
                if (absum.find(sum) == absum.end())
                {
                    absum[sum] = 1;
                }
                else
                {
                    absum[sum]++;
                }
            }
        }
        
        int ret = 0;
        
        for (int c : C)
        {
            for (int d : D)
            {
                int sum = c + d;
                auto it = absum.find(-sum);
                if (it != absum.end())
                {
                    ret += it->second;
                }
            }
        }
        
        return ret;
    }
};
