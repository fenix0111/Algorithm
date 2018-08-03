// Leetcode 93. Restore IP Addresses
// https://leetcode.com/problems/restore-ip-addresses/description/
// Runtime: 4ms

// 直接用了暴力解法。这个问题比较特殊，就是IP每个部分仅有4位，枚举了也没多少运算量。
class Solution {
    boolean isValidIp(String ipStr, int b, int e) {
        String ip = ipStr.substring(b, e);
        if (ip.length() > 1 && ip.startsWith("0")) {
            return false;
        }

        int ipInt = Integer.parseInt(ip);
        if (ipInt >= 0 && ipInt <= 255) {
            return true;
        } else {
            return false;
        }
    }
    
    public List<String> restoreIpAddresses(String s) {
        LinkedList<String> res = new LinkedList<String>();

        if (s.length() > 12 || s.length() < 4) {
            return res;
        }

        int len = s.length();

        for (int u = 0; u < 3; u++) {
            for (int d = 0; d < 3; d++) {
                for (int t = 0; t < 3; t++) {
                    for (int q = 0; q < 3; q++) {
                        int curlen = u + d + t + q + 3;
                        if (curlen == len - 1) {
                            if (    isValidIp(s, 0, u + 1) &&
                                    isValidIp(s, u + 1, u + d + 2 ) &&
                                    isValidIp(s, u + d + 2, u + d + t + 3) &&
                                    isValidIp(s,u + d + t + 3, u + d + t + q + 4) ) {

                                String ss = s.substring(0, u + 1) + "." +
                                            s.substring(u + 1, u + d + 2) + "." +
                                            s.substring(u + d + 2, u + d + t + 3) + "." +
                                            s.substring(u + d + t + 3, u + d + t + q + 4);

                                res.add(ss);
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
}
