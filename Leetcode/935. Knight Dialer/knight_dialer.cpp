// Leetcode 935. Knight Dialer
// https://leetcode.com/problems/knight-dialer/
// time complexity: O(N)
// space complexity: O(N)

// increment using branch in each step
class Solution
{
public:
    int knightDialer(int n) 
    {
        int mod = 1000000007;
        int result = 0;
        vector<vector<int>> branch = {{4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4}};
        
        unsigned int counter[10] = { 1 };
        for (int i = 0; i < 10; i++)
        {
            counter[i] = 1;
        }
        
        for (int i = 1; i < n; i++)
        {
            unsigned int buf[10] = { 0 };
            for (int j = 0; j < 10; j++)
            {
                vector<int>& b = branch[j];
                for (int next : b)
                {
                    buf[next] += counter[j];
                    buf[next] %= mod;
                }
            }
            
            for (int k = 0; k < 10; k++)
            {
                counter[k] = buf[k];
            }
        }
        
        for (int i = 0; i < 10; i++)
        {
            result += counter[i];
            result %= mod;
        }
        
        return result;
    }
};
