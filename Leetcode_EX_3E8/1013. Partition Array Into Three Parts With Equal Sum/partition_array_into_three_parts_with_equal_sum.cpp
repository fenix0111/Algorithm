// Leetcode 1013. Partition Array Into Three Parts With Equal Sum
// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/

// very interesting question
// have to very careful about several edge cases
// ex, array like [0,0,0,0,0], 
// or an array with total sum is zero, with final element of array is zero

class Solution
{
public:
    bool canThreePartsEqualSum(vector<int>& arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3 != 0)
        {
            return false;
        }
        
        int target = sum / 3;
        int sz = arr.size();
        int left = 0;
        int right = sz - 1;
        int leftSum = 0;
        int rightSum = 0;
        
        while (left < sz)
        {
            leftSum += arr[left];
            if (leftSum == target)
            {
                break;
            }
            
            left++;
        }
        
        while (right > left + 1)
        {
            rightSum += arr[right];
            if (rightSum == target)
            {
                break;
            }
            right--;
        }
        
        // have to check right > left + 1
        // without this check, it would be failed in this case:
        // sum of subarray except final element is zero, and final element is zero
        // the target is 0, both left sum and right sum are zero, so the result will be "true" but it is incorrect
        return leftSum == rightSum && right > left + 1;
    }
};
