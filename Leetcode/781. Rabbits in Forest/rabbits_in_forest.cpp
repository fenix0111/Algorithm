// Leetcode 781. Rabbits in Forest
// https://leetcode.com/problems/rabbits-in-forest/
// time complexity: O(nlogn)
// space complexity: O(1)

// if answer is n, then at least needs n + 1 rabbits
// count the number of rabbits with same answer
// if exceeds n + 1, then add one more n + 1, repeat until the end
class Solution
{
public:
    int numRabbits(vector<int>& answers)
    {
        sort(answers.begin(), answers.end());
        int rabbits = answers[0] + 1;
        int last = answers[0];
        int num = 1;
        for (int i = 1; i < answers.size(); i++)
        {
            int ans = answers[i];
            if (ans == 0)
            {
                rabbits++;
                last = 0;
                num = 1;
                continue;
            }
            
            int n = ans + 1;
            if (ans == last)
            {                
                if (num < n)
                {
                    num++;
                }
                else
                {
                    rabbits += n;
                    num = 1;
                }
            }
            else
            {
                rabbits += n;
                last = ans;
                num = 1;
            }
        }
        
        return rabbits;
    }
};
