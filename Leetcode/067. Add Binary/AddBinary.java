// Leetcode 67. Add Binary
// https://leetcode.com/problems/add-binary/description/
// Runtime: 7ms

public class Solution {
    public String addBinary(String a, String b) {
        int len_a = a.length();
        int len_b = b.length();
        String tmp = null;
        Stack<Character> st = new Stack<>();
        int len_res = 0;
        if (len_a > len_b) {
            len_res = len_a;
            tmp = a;
        } else {
            len_res = len_b;
            tmp = b;
        }

        int ida = len_a - 1;
        int idb = len_b - 1;
        int idr = len_res - 1;
        boolean isCarry = false;

        while (ida >= 0 && idb >= 0) {
            char ca = a.charAt(ida);
            char cb = b.charAt(idb);
            if (ca == '1' && cb == '1') {
                if (isCarry) {
                    st.push('1');
                } else {
                    st.push('0');
                }
                isCarry = true;

            } else if (ca == '0' && cb == '0') {
                if (isCarry)
                {
                    st.push('1');
                } else {
                    st.push('0');
                }
                isCarry = false;

            } else {
                if (isCarry) {
                    st.push('0');
                } else {
                    st.push('1');
                }
            }
            ida--;
            idb--;
            idr--;
        }

        while (idr >= 0) {
            char cr = tmp.charAt(idr);
            if (isCarry) {
                if (cr == '1') {
                    st.push('0');
                } else {
                    st.push('1');
                    isCarry = false;
                }
            } else {
                st.push(tmp.charAt(idr));
            }
            idr--;
        }

        if (isCarry) {
            st.push('1');
        }

        StringBuilder sb = new StringBuilder();
        while (!st.empty()) {
            sb.append(st.pop());
        }
        return sb.toString();
    }
}
