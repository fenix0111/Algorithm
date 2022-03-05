// Leetcode 904. Fruit Into Baskets
// https://leetcode.com/problems/fruit-into-baskets/
// time complexity: O(N)
// space complexity: O(N)

class Solution
{
public:
    int totalFruit(vector<int>& fruits)
    {
        int result = 0;
        unordered_map<int, int> basket;
        int i = 0;
        int j = 0;
        while (i < fruits.size())
        {
            if (basket.count(fruits[i]) == 0 && basket.size() == 2)
            {
                result = max(result, i - j);
                int remove_fruit = fruits[j];
                
                // move the left pointer while decreasing the fruit counts
                // we can't just let j pointer jump to current position directly
                // because there is a chance that suffix of current subarray would make the solution with prefix of remaining subarray
                // ex, in the case of array "[1,2,1,1,1,3,3,3,3]"
                // in the first stop, i would be 5 and j would be 0
                // the solution is 7, which is the length of the subarray begin with index 2 and end with index 9
                while (j < fruits.size() && fruits[j] == remove_fruit)
                {
                    basket[remove_fruit]--;
                    if (basket[remove_fruit] == 0)
                    {
                        basket.erase(remove_fruit);
                    }
                    j++;
                }
                
                continue;
            }
        
            basket[fruits[i]]++;
            i++;
        }

        result = max(result, i - j);
        
        return result;
    }
};
