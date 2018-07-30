// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// Runtime: 62ms
// 庆祝第一道Hard题。主要思路是先整合成临时数组，然后挑中间数。

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double median = 0.f;
        int size1 = nums1.length;
        int size2 = nums2.length;
        int med = (size1 + size2) / 2;
        boolean even = false;
        int[] tmp = new int[size1 + size2];
        if ((size1 + size2) % 2 == 0) {
            even = true;
        }

        int p1 = 0;
        int p2 = 0;
        for (int i = 0; i < size1 + size2; i++) {
            if ((p1 < nums1.length) && (p2 < nums2.length)) {
                if (nums1[p1] < nums2[p2]) {
                    tmp[i] = nums1[p1];
                    p1++;
                } else {
                    tmp[i] = nums2[p2];
                    p2++;
                }
            } else {
                if (p1 < nums1.length) {
                    tmp[i] = nums1[p1];
                    p1++;
                }
                if (p2 < nums2.length) {
                    tmp[i] = nums2[p2];
                    p2++;
                }
            }
        }

        // 因为是求中间数，而数组元素是整数，所以最后要注意转为double型
        if (even) {
            median = (double)(tmp[med] + tmp[med - 1]) / 2.0f;
        } else {
            median = (double)tmp[med];
        }

        return median;
    }
}
