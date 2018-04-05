// Leetcode 18. 4Sum
// https://leetcode.com/problems/4sum/description/
// Runtime: 39ms

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector< vector<int> > result;
        
        if (nums.size() == 0)
		{
			return result;
		}
        
		sort(nums.begin(), nums.end());
		vector<int>::iterator it_front = nums.begin();
		vector<int>::iterator it_end = nums.end() - 1;
        
        int last_front = INT_MAX;
		int last_end = INT_MAX;
        int last_it_front = INT_MAX;
		int last_it_end = INT_MAX;

		while (it_front < nums.end())
		{
            if (it_front > nums.begin() && *it_front == *(it_front - 1))
			{
				it_front++;
				continue;
			}
            
			it_end = nums.end() - 1;

			while (it_front < it_end)
			{
				if (it_end < nums.end() - 1 && *it_end == *(it_end + 1))
				{
					it_end--;
					continue;
				}
                
				vector<int>::iterator front = it_front + 1;
				vector<int>::iterator end = it_end - 1;

				while (front < end)
				{
					int sum = *it_front + *front + *end + *it_end;
					if (sum > target)
					{
						end--;
						continue;
					}
					else if (sum < target)
					{
						front++;
						continue;
					}
					else if (sum == target)
					{
						if ((last_it_front == *it_front) && 
                            (last_it_end == *it_end) &&
                            (last_front == *front || last_end == *end))

						{
							end--;
							front++;
							continue;
						}

						vector<int> quad;
						quad.push_back(*it_front);
						quad.push_back(*front);
						quad.push_back(*end);
						quad.push_back(*it_end);

						result.push_back(quad);

                        last_it_front = *it_front;
						last_it_end = *it_end;
						last_front = *front;
						last_end = *end;
                        
                        end--;
						front++;
						continue;
					}
				}
				it_end--;
			}
			it_front++;
		}

		return result;
    }
};
