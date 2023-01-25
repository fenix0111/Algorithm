// Leetcode 2359. Find Closest Node to Given Two Nodes
// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/
// 
// 

class Solution
{
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2)
    {
        int sz = edges.size();
        vector<int> color(sz, -1);

        int step = 0;
        int cur = node1;
        while (cur != -1 && color[cur] == -1)
        {
            color[cur] = step;
            step++;
            cur = edges[cur];
        }

        cur = node2;
        step = 0;
        int max_dist = INT_MAX;
        int min_node = INT_MAX;
        vector<int> visited(sz, false);
        while (cur != -1 && !visited[cur])
        {
            if (color[cur] != -1)
            {
                if (max(step, color[cur]) < max_dist)
                {
                    min_node = cur;
                    max_dist = max(step, color[cur]);
                }
                else if (max(step, color[cur]) == max_dist)
                {
                    min_node = min(min_node, cur);
                }
            }

            visited[cur] = true;
            cur = edges[cur];
            step++;
        }

        return min_node == INT_MAX ? -1 : min_node;
    }
};
