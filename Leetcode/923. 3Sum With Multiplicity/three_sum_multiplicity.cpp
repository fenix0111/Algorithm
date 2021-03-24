// Leetcode 923. 3Sum With Multiplicity
// https://leetcode.com/problems/3sum-with-multiplicity/
// time complexity: O(nlogn)
// space complexity: O(n)

// 3sum (https://leetcode.com/problems/3sum/) + combination
class Solution 
{
public:
    int combination(int n, int r)
    {
        if(n == r || r == 0) 
            return 1; 
        
        unsigned long long N = 1;
        unsigned long long K = 1;
        long long NK = 1;
        
        int i = 1;
        while (i <= r)
        {
            N *= (n - i + 1);     
            i++;
        }
        
        i = 1;
        while (i <= r)
        {
            K *= i;
            i++;
        }
        
        return (N / K) % 1000000007 ;
    }
    
    int threeSumMulti(vector<int>& arr, int target) 
    {
        int sz = arr.size();
        int MOD = 1000000007;
        int result = 0;
        
        // sorting does not effect final result
        sort(arr.begin(), arr.end());
        
        // number => number of appearances
        unordered_map<int, int> counter;  
        
        for (int n : arr)
        {
            counter[n]++;
        }
        
        int l = -1;
        int m = 1;
        int r = sz - 1;
        
        while (l < r)
        {
            l++;
            m = l + 1;
            r = sz - 1;
            while (m < r)
            {      
                int sum = arr[l] + arr[m] + arr[r];
                if (sum == target)
                {                    
                    int ll = arr[l];
                    int mm = arr[m];
                    int rr = arr[r];
                    
                    if (ll != mm && ll != rr && mm != rr)
                    {
                        result += (combination(counter[ll], 1) * combination(counter[mm], 1) * combination(counter[rr], 1)) % MOD;
                    }
                    else
                    {
                        if (ll == mm && mm != rr)
                        {
                            result += (combination(counter[rr], 1) * combination(counter[ll], 2)) % MOD;
                        }
                        else if (ll != mm && mm == rr)
                        {
                            result += (combination(counter[ll], 1) * combination(counter[rr], 2)) % MOD;
                        }
                        else
                        {
                            result += (combination(counter[ll], 3)) % MOD;
                        }
                    }
                    
                    while (m < r && arr[m] == mm) m++;
                    
                    while (m < r && arr[r] == rr) r--;
                }
                else if (sum < target)
                {
                    m++;
                }
                else
                {
                    r--;
                }
            }
            
            while (l < sz - 1 && arr[l] == arr[l + 1])  l++;         
        }
        
        return result;
    }
};
