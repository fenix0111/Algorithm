// Leetcode 1710. Maximum Units on a Truck
// https://leetcode.com/problems/maximum-units-on-a-truck/
// time complexity: O(nlogn)
// space complexity: O(n)

struct comp
{
    bool operator()(vector<int>& x, vector<int>& y)
    {
        return x[1] < y[1];
    }
};

class Solution 
{
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        priority_queue<vector<int>, vector<vector<int>>, comp> q;
        for (vector<int>& box : boxTypes)
        {
            q.push(box);
        }
        
        int result = 0;
        int loadedBoxes = 0;
        while (!q.empty())
        {
            const vector<int>& box = q.top();
            
            if (box[0] <= truckSize)
            {
                result += (box[1] * box[0]);
                truckSize -= box[0];
            }
            else if (truckSize > 0)
            {
                result += (box[1] * truckSize);
                break;
            }
            
            q.pop();
        }
        
        return result;
    }
};
