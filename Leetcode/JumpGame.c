// Leetcode 55. Jump Game
// https://leetcode.com/problems/jump-game/description/
// Runtime: 6ms

bool canJump(int* nums, int numsSize) 
{
	if (numsSize == 1)
		return true;
	
	if (nums[0] == 0)
		return false;

	int index = numsSize - 2;  // skip last zero
	int diff = 1;
	int non_zero_distance = 0;

	while (index > 0)
	{
		if (nums[index] == 0)
		{
			int next_zero_index = index - 1;

			while ((next_zero_index > 0) && (nums[next_zero_index] == 0))
			{
				next_zero_index--;
				//diff++;
			}

			int diff = index - next_zero_index;
			
			bool res = false;
			while (next_zero_index >= 0 && diff < 9)
			{
				if (nums[next_zero_index] > diff)
				{
					res = res || true;
				}
				else
				{
					res = res || false;
				}
				
				next_zero_index--;
				diff++;
			}

			if (!res)
			{
				return false;
			}
		}
		index--;
	}
    
	return true;
}
