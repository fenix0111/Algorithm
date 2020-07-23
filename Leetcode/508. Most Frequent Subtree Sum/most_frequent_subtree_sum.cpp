// Leetcode 508. Most Frequent Subtree Sum
// https://leetcode.com/problems/most-frequent-subtree-sum/
// time complexity: O(number of nodes)
// space complexity: O(number of nodes)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    // using bottom-up method to calculate subtree sum
    int getSubtreeSumFrequency(unordered_map<int, int>& sumFrequencies, TreeNode* node, int& maxFrequency)
    {
        if (node == nullptr)
        {
            return 0;
        }
        
        int leftSum = getSubtreeSumFrequency(sumFrequencies, node->left, maxFrequency);
        int rightSum = getSubtreeSumFrequency(sumFrequencies, node->right, maxFrequency);
        
        int sum = node->val + leftSum + rightSum;
        sumFrequencies[sum]++;
        
        if (sumFrequencies[sum] > maxFrequency)
        {
            maxFrequency = sumFrequencies[sum];
        }
        
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        vector<int> subtreeSums;
        unordered_map<int, int> sumFrequencies;
        int maxFrequency = INT_MIN;
        
        getSubtreeSumFrequency(sumFrequencies, root, maxFrequency);
        
        for (auto it = sumFrequencies.begin(); it != sumFrequencies.end(); it++)
        {
            if (it->second == maxFrequency)
            {
                subtreeSums.push_back(it->first);
            }
        }
        
        return subtreeSums;
    }
};
