// Leetcode 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
// Runtime: 6ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) 
{
    if (numsSize == 0)
    {
        return NULL;
    }

    struct TreeNode *head = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid = numsSize / 2;
    int left = mid;
    int right = numsSize - mid - 1; 
    head->val = nums[mid];
    head->left = sortedArrayToBST(nums, left);
    head->right = sortedArrayToBST(nums + mid + 1, right);
    
    return head;
}
