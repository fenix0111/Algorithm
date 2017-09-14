// Leetcode 109. Convert Sorted List to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
// Runtime: 23ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 跟数组转BST思路相同
// 先把链表的元素放进临时数组后转为BST即可
class Solution {
public:
    TreeNode *makeBST(int* nums, int numsSize)
    {
        if (numsSize == 0)
            return NULL;
        
        TreeNode *head = (TreeNode*)malloc(sizeof(TreeNode));
        int mid = numsSize / 2;
        int left = mid;
        int right = numsSize - mid - 1;
        head->val = nums[mid];
        head->left = sortedArrayToBST(nums, left);
        head->right = sortedArrayToBST(nums + mid + 1, right);
        return head;
    }

    TreeNode* sortedListToBST(ListNode* head) 
    {
        if (head == NULL)
            return NULL;
        
        ListNode* pl = (ListNode*)malloc(sizeof(ListNode));
        pl = head;
        int size = 0;
        while (pl)
        {
            size++;
            pl = pl->next;
        }

        pl = head;
        int *tmp = (int*)malloc(sizeof(int) * size);
        int i = 0;
        while (pl)
        {
            tmp[i] = pl->val;
            pl = pl->next;
            i++;
        }
        
        return makeBST(tmp, size);
    }
};
