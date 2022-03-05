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
