// Leetcode 66. Plus One
// https://leetcode.com/problems/plus-one/description/
// Runtime: 0ms

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

// returnSize一定要传否则结果会不正确。
// 预先分配了比digitsSize大一个的临时数组。注意判断进位
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int newsize = digitsSize + 1;
    int* ret = (int*)malloc(sizeof(int) * newsize);
    for (int i = 0; i < newsize; i++) {
        ret[i] = 0;
    }
    
    int carry = 0;
    
    int leastsum = digits[digitsSize - 1] + 1;
    if (leastsum > 9) {
        carry = 1;
        ret[newsize - 1] = 0;
    } else {
        ret[newsize - 1] = leastsum;
    }
    
    for (int i = digitsSize - 2; i>= 0; i--) {
        if (carry) {
            int leastsum = digits[i] + 1;
            if (leastsum > 9) {
                carry = 1;
                ret[i + 1] = 0;
            } else {
                ret[i + 1] = leastsum;
                carry = 0;
            }
            
        } else {
            ret[i + 1] = digits[i];
        }
    }
    
    if (carry) {
        ret[0] = 1;
        *returnSize = newsize;
        return ret;
    } else {
        *returnSize = newsize - 1;
        return ret + 1;
    }
}
