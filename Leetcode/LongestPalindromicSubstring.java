// 断断续续想了好几天的题。。45ms。网上比较快的是16、17ms，比我的快两倍多
// 维基百科的说明。Manacher算法是比较高效的算法。另外还有使用suffix tree的算法。
// https://en.wikipedia.org/wiki/Longest_palindromic_substring
// https://en.wikipedia.org/wiki/Suffix_tree

// Leetcode 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/description/
// Runtime: 45ms

// 主要采用遍历字符串定好一个字符后以该字符为中心向两边扩散的方法。
// 需要注意的是回文有“偶数长度”和“奇数长度”两种，要提前判断。
class Solution {
    public String longestPalindrome(String s) {
        if (s.length() == 0 || s.length() == 1) {
            return s;
        }

        if (s.length() == 2) {
            if (s.charAt(0) == s.charAt(1)) {
                return s;
            } else {
                return "";
            }
        }
        
        // 检测字符串s是否由同一个字符所组成
        boolean allEqual = true;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) != s.charAt(i + 1)) {
                allEqual = false;
                break;
            }
        }

        if (allEqual) {
            return s;
        }

        int len = s.length();
        int left = 0;
        int right = 0;
        int maxLeft = 0;
        int maxRight = 0;
        int maxPalinLen = 0;
        for (int i = 0; i < len - 1; i++) {
            char l = 0;
            char r = 0;

            if (s.charAt(i) == s.charAt(i + 1)) {
                if (i < len - 2) {
                    int j = i + 2;
                    while (j < len) {
                        if (s.charAt(i) == s.charAt(j)) {
                            j++;
                        } else {
                            break;
                        }
                    }
                    left = i;
                    right = j - 1;
                } else {
                    left = i;
                    right = i + 1;
                }
            } else if (i < len - 2) {
                if (s.charAt(i) == s.charAt(i + 2)) {
                    left = i;
                    right = i + 2;
                } else {
                    continue;
                }
            } else {
                continue;
            }

            while (true) {
                if (left >= 0) {
                    l = s.charAt(left);
                }
                if (right < len) {
                    r = s.charAt(right);
                }
                if (l == r) {
                    if ((right - left) > maxPalinLen) {
                        maxLeft = left;
                        maxRight = right;
                        maxPalinLen = maxRight - maxLeft;
                    }
                    if (left >= 0) {
                        left--;
                    }
                    if (right < len) {
                        right++;
                    }
                    if ((left < 0) || (right >= len)) {
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        return s.substring(maxLeft, maxRight + 1);
    }
}
