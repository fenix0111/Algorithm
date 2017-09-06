// Leetcode 118. Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/description/
// Runtime: 3ms

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > output;
		int arr1[] = { 1 };
		int arr2[] = { 1, 1 };

        if (numRows == 0)
			return output;
			
		if (numRows < 3)
		{
			vector<int> row;
			row.push_back(1);
			output.push_back(row);

			if (numRows == 2)
			{
				vector<int> row;
				row.push_back(1);
				row.push_back(1);
				output.push_back(row);
			}

			return output;
		}

		vector<int> fr(arr1, arr1 + 1);
		vector<int> sr(arr2, arr2 + 2);

		output.push_back(fr);
		output.push_back(sr);

		for (int i = 3; i <= numRows; i++)
		{
			vector< vector<int> >::iterator it = output.end();
            vector<int> prev = *(it - 1);
			vector<int> row;
			row.push_back(1);
			for (vector<int>::iterator itor = prev.begin(); itor != prev.end() - 1; itor++)
			{
				row.push_back(*(itor) + *(itor + 1));
			}
			row.push_back(1);
			output.push_back(row);
		}

		return output;
    }
    
    // 0ms参考解法
    vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> answer;
		if(numRows == 0)
		{
			return answer;
		}
		vector<int> last(1,1);
		answer.push_back(last);

		for(int i = 2; i <= numRows; i++)
		{
			last.push_back(0);
			vector<int> current = last;
			for(int j = 1; j < i; j++)
			{
				current[j] = last[j] + last[j - 1];
			}
			answer.push_back(current);
			last = current;
		}
		return answer;
	}
};
