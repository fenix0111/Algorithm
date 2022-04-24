// Leetcode 1436. Destination City
// https://leetcode.com/problems/destination-city/
// time complexity: O(n)
// space complexity: O(n)

class Solution
{
public:
    string destCity(vector<vector<string>>& paths)
    {
      unordered_map<string, int> inout;
      for (vector<string>& path : paths)
      {
        inout[path[0]]--;
        inout[path[1]]++;
      }
      
      string result = "";
      for (const auto& [k, v] : inout)
      {
        if (v == 1)
        {
          result = k;
          break;
        }
      }
      
      return result;
    }
};
