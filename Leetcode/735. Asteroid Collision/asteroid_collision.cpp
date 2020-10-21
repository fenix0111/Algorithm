// Leetcode 735. Asteroid Collision
// https://leetcode.com/problems/asteroid-collision/
// time complexity: O(N)
// space complexity: O(N)

class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st;
        for (int asteroid : asteroids)
        {
            if (st.empty())
            {
                st.push(asteroid);
            }
            else
            {
                int val = st.top();
                if ( (val >= 0 && asteroid >= 0) || (val < 0 && asteroid < 0) )
                {
                    st.push(asteroid);
                    continue;
                }
                
                if (val > 0 && asteroid < 0 && val + asteroid == 0)
                {
                    st.pop();
                    continue;
                }
                
                if (val < 0 && asteroid > 0)
                {
                    st.push(asteroid);
                    continue;
                }

                while (!st.empty() && st.top() * asteroid < 0 && abs(st.top()) < abs(asteroid))
                {
                    st.pop();
                }
                
                if (!st.empty() && st.top() * asteroid < 0 && st.top() + asteroid == 0 && asteroid < 0)
                {
                    st.pop();
                    continue;
                }
                
                if (st.empty() || st.top() == asteroid || st.top() < 0 && asteroid > 0 || st.top() * asteroid > 0)
                {
                    st.push(asteroid);
                }
            }
        }
        
        vector<int> result(st.size(), 0);
        int i = st.size() - 1;
        while (!st.empty())
        {
            result[i] = st.top();
            i--;
            st.pop();
        }
        
        return result;
    }
};
