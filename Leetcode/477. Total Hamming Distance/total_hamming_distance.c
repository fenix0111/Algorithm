// Leetcode 477. Total Hamming Distance
// https://leetcode.com/problems/total-hamming-distance/
// time complexity: O(N)
// space complexity: O(1)

int totalHammingDistance(int* nums, int numsSize)
{
    unsigned int result = 0;
    for (int i = 0; i < 32; i++)
    {
        int count = 0;
        for (int j = 0; j < numsSize; j++)
        {
            if (((nums[j] >> i) & 1) == 1)
            {
                count++;
            }
        }
        
        result += (count * (numsSize - count));
    }
    
    return result;
}
