// Leetcode 475. Heaters
// https://leetcode.com/problems/heaters/
// time complexity: O(nlogn)
// space complexity: O(1)

// control the radius of heaters using binary search
class Solution 
{
public:
    bool canCover(vector<int>& houses, vector<int>& heaters, int radius)
    {
        bool result = true;
        int i = 0;
        int j = 0;
        while (j < houses.size())
        {
            int house = houses[j];
            while (i < heaters.size())
            {
                int heater = heaters[i];
                if (house < heater - radius || house > heater + radius)
                {
                    i++;
                }
                else
                {
                    break;
                }
            }
            
            if (i == heaters.size())
            {
                result = false;
                break;
            }
            
            j++;
        }
        
        return result;
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int radius = 0;

        radius = max(abs(heaters.front() - houses.back()), 
                     abs(heaters.front() - houses.front()));
            
        radius = max(radius, 
                     max(abs(heaters.back() - houses.back()), 
                         abs(heaters.back() - houses.front())));

        int l = 0;
        int r = radius;
        int m;
        
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (canCover(houses, heaters, m))
            {
                radius = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        
        return radius;
    }
};
