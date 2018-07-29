// Leetcode 482. License Key Formatting
// https://leetcode.com/problems/license-key-formatting/description/
// Runtime: 17ms

// 先把输入进来的S合并为一个String，再根据K分割。
class Solution {
    public String licenseKeyFormatting(String S, int K) {
        String res = "";
        final String DASH = "-";
        String[] splitted = S.split(DASH);
        StringBuilder sb = new StringBuilder();

        for (String s : splitted) {
            sb.append(s);
        }

        String temp = sb.toString();
        sb.setLength(0);

        int len = temp.length();
        int remaining = len % K;

        int i = 0;

        if (remaining > 0) {
            sb.append(temp.substring(i, remaining));
            i = i + remaining;
        }

        while (i < len) {
            if (sb.length() > 0) {
                sb.append(DASH);
            }

            sb.append(temp.substring(i, i + K));

            i = i + K;
        }

        return sb.toString().toUpperCase();
    }
}
