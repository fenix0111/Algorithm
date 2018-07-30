// Leetcode 60. Permutation Sequence
// https://leetcode.com/problems/permutation-sequence/description/
// Runtime: 20 ms

// 我也不清楚是什么原理...
// 仅仅是观察了几个结果调参数给整的
public class Solution {
    public String getPermutation(int n, int k) {
        if (n == 1) {
            return "1";
        }

        if (n == 2) {
            if (k == 1) {
                return "12";
            } else {
                return "21";
            }
        }
        StringBuilder sb = new StringBuilder();
        int w = n;

        ArrayList<Integer> m = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            m.add(i);
        }

        // n!
        int[] nmax = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        int num = (int)Math.ceil((double)k / (double)nmax[w - 1]);

        sb.append(m.get(num - 1));
        m.remove(num - 1);
        w--;

        int kk = k;
        while (kk > nmax[w]) {
            kk = kk - nmax[w];
        }

        while (w > 1) {
            num = (int)Math.ceil((double)kk / (double)nmax[w - 1]);
            if (m.size() > 2) {
                sb.append(m.get(num-1));
                m.remove(num-1);
            } else {
                int f = m.get(0);
                int s = m.get(1);
                if (k % 2 == 0) {
                    if (f > s) {
                        sb.append(f);
                        sb.append(s);
                    } else {
                        sb.append(s);
                        sb.append(f);
                    }
                } else {
                    if (f > s) {
                        sb.append(s);
                        sb.append(f);
                    } else {
                        sb.append(f);
                        sb.append(s);
                    }
                }
            }
            w--;
            while (kk > nmax[w]) {
                kk = kk - nmax[w];
            }
        }

        return sb.toString();
    }
}
