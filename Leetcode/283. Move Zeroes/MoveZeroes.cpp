// Leetcode 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/
// Runtime: 28ms

class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
	    int len = nums.size();

	    if (len == 1)
		    return;

    int pzero = 0;
    int pnum = 0;
    int tmp = 0;

    while (pnum < len && pzero < len)
    {
      while (pzero < len && nums[pzero] != 0)
        pzero++;

      while (pnum < len && nums[pnum] == 0)
        pnum++;

      if (pnum > pzero)
      {
        if (pzero < len && pnum < len)
        {
          tmp = nums[pzero];
          nums[pzero] = nums[pnum];
          nums[pnum] = tmp;

          pzero++;
          pnum = pzero + 1;
        }
      }
      else
      {
        pnum = pzero + 1;
      }
    }
  }
};
