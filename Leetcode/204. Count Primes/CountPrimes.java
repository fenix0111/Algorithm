// 使用埃拉托斯特尼筛法。
// https://zh.wikipedia.org/wiki/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95

// 网上参考代码：
// Leetcode 204. Count Primes
// https://leetcode.com/problems/count-primes/description/
// Runtime: 32ms
class Solution {
    public int countPrimes(int n) {
        if (n <= 2)
            return 0;

        // init an array to track prime numbers
        boolean[] primes = new boolean[n];
        for (int i = 2; i < n; i++)
            primes[i] = true;

        for (int i = 2; i <= Math.sqrt(n - 1); i++) {
            // or for (int i = 2; i <= n-1; i++) {
            if (primes[i]) {
                for (int j = i + i; j < n; j += i)
                    primes[j] = false;
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (primes[i])
                count++;
        }

        return count;
    }
    
    // 12ms解法（又一黑魔法）
    class Solution {
    public int countPrimes(int n) {
        if(n==499979) return(41537);
        if(n== 999983) return(78497);
        if(n==1500000) return(114155);
        
        double res2 = n/Math.log(n);
        if(n>50000) return((int) (res2+0.5));
        int[] dp = new int[n]; int res = 0;
        for(int i=2; i<n; i++){
            if(dp[i]==0){
                res++;
                int max = (int) Math.floor(n/i);
                for(int j=2; j<=max; j++){
                    if(j*i<n)
                        dp[j*i] = 1;
                }
            }
        }
        return(res);
    }   
}

// 更加理论化的方法：
// https://en.wikipedia.org/wiki/Prime-counting_function

// ==============================================================================

// 特典：费马小定理，但只能猜某个数是否可能为素数。要是不满足公式则必为合数
// https://zh.wikipedia.org/wiki/%E8%B4%B9%E9%A9%AC%E5%B0%8F%E5%AE%9A%E7%90%86
