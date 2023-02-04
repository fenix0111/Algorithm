// Leetcode 1061. Lexicographically Smallest Equivalent String
// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/
// time complexity: O(N)
// space complexity: O(N)

typedef struct UnionFind
{
    vector<char> parent;
    UnionFind() {};
    ~UnionFind() {};
    UnionFind(int size)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            parent.push_back(c);
        }
    };
    
    int Find(char c) 
    {
        if (c != parent[c - 'a'])
        {
            return Find(parent[c - 'a']);
        }
        
        return parent[c - 'a'];
    };
    
    void Union(char x, char y)
    {
        char p_x = parent[Find(x) - 'a'];
        char p_y = parent[Find(y) - 'a'];
        if (p_x < p_y)
        {
            parent[Find(y) - 'a'] = p_x;
        }
        else
        {
            parent[Find(x) - 'a'] = p_y;
        }
    };
};

class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        string result = "";
        int n = s1.length();
        UnionFind uf(n);
        for (int i = 0; i < n; i++)
        {
            uf.Union(s1[i], s2[i]);
        }

        for (int i = 0; i < baseStr.size(); i++)
        {
            result.push_back(uf.Find(baseStr[i]));
        }

        return result;
    }
};
