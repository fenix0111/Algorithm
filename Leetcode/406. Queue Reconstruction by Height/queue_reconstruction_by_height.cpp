// Leetcode 406. Queue Reconstruction by Height
// https://leetcode.com/problems/queue-reconstruction-by-height/
// time complexity: O(N*N)
// space complexity: O(N)

// pick the heighest group first
// then insert next group into this
class Solution 
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        list<vector<int>> ll;
        map<int, vector<int>> m;
        
        for (vector<int>& v : people)
        {
            m[v[0]].push_back(v[1]);
        }
        
        for (auto rit = m.rbegin(); rit != m.rend(); rit++)
        {
            sort(rit->second.begin(), rit->second.end());
        }
        
        for (auto rit = m.rbegin(); rit != m.rend(); rit++)
        {
            vector<int> vk = rit->second;
            int h = rit->first;
            for (int k : vk)
            {
                auto lit = ll.begin();
                int count = 0;
                while (count < k)
                {
                    lit++;
                    count++;
                }

                vector<int> val = {h, k};
                ll.insert(lit, val);
            }
        }

        vector<vector<int>> ret(ll.begin(), ll.end());
        
        return ret;
    }
};
