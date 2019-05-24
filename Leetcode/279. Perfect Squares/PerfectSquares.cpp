// Leetcode 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/
// Runtime: 0ms

// Lagrange's four-square theorem
// https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
// Thanks for https://leetcode.com/problems/perfect-squares/discuss/290396/c%2B%2B-DP-and-math
class Solution 
{  
private:  
    int is_square(int n)
    {  
        int res = (int)(sqrt(n));  
        return (res * res == n);  
    }
    
public:
    int numSquares(int n) 
    {  
        if(is_square(n)) 
        {
            return 1;  
        }
        
        while ((n & 3) == 0) 
        {
            n >>= 2;  
        }
        if ((n & 7) == 7) 
        {
            return 4;
        }
        
        int sqrt_n = (int)(sqrt(n)); 
        for(int i = 1; i <= sqrt_n; i++)
        {  
            if (is_square(n - i*i)) 
            {
                return 2;  
            }
        }  
        
        return 3;  
    }  
}; 
