// 
// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/
// time complexity: O(n)
// space complexity: O(1)

class Solution
{
public:
    double average(vector<int>& salary)
    {
        int min_salary = INT_MAX;
        int max_salary = INT_MIN;
        unsigned int sum = 0;
        for (int s : salary)
        {
            min_salary = min(min_salary, s);
            max_salary = max(max_salary, s);
            sum += s;
        }

        sum -= min_salary;
        sum -= max_salary;

        return (double)sum / (double)(salary.size() - 2);
    }
};
