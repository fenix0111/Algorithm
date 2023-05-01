// Leetcode 839. Similar String Groups
// https://leetcode.com/problems/similar-string-groups/
// 
// 

typedef struct UnionFin
{
    vector<int> parent;
    UnionFind(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
        }
    };
  
    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);
        parent[y] = x;
    };

    int Find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        else
        {
            return Find(parent[x]);
        }
    };
};

class Solution
{
public:
    int numSimilarGroups(vector<string>& strs)
    {
        int sz = strs.size();
        int len = strs[0].size();
        UnionFind uf(sz);
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                const string& str_i = strs[i];
                const string& str_j = strs[j];
                int diff = 0;
                for (int k = 0; k < len; k++)
                {
                    if (str_i[k] != str_j[k])
                    {
                        diff++;
                    }
                }

                if (diff == 2 || diff == 0)
                {
                    uf.Union(i, j);
                }
            }
        }

        int result = 0;
        for (int i = 0; i < sz; i++)
        {
            if (uf.Find(i) == i)
            {
                result++;
            }
        }

        return result;
    }
};
