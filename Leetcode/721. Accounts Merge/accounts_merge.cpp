// Leetcode 721. Accounts Merge
// https://leetcode.com/problems/accounts-merge/
// time complexity: ?
// space complexity: O(n)

class Solution
{
    typedef struct UnionFind
    {
        vector<int> parent;
        UnionFind() {};
        ~UnionFind() {};
        UnionFind(int size)
        {
            for (int i = 0; i < size; i++)
            {
                parent.push_back(i);
            }
        };
        
        int find(int idx) 
        {
            if (idx != parent[idx])
            {
                return find(parent[idx]);
            }
            
            return parent[idx];
        };
        
        void Union(int x, int y)
        {
            parent[find(x)] = find(y);
        };
    };
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        vector<vector<string>> result;
        UnionFind uf(accounts.size());
        unordered_map<string, int> email_index;
        unordered_map<string, set<string>> interim; // save email address in ascending order
        
        // make up disjoint set
        for (int i = 0; i < accounts.size(); i++)
        {
            vector<string>& account = accounts[i];
            for (int j = 1; j < account.size(); j++)
            {
                string& email = account[j];
                if (email_index.find(email) == email_index.end())
                {
                    email_index[email] = i;
                }
                else
                {
                    uf.Union(email_index[email], i);
                }
            }
        }
        
        // get intermediate result
        // in case of same name, append the index number after underscore
        for (int i = 0; i < uf.parent.size(); i++)
        {
            int parent = uf.find(i);
            string name = accounts[parent][0] + "_" + to_string(parent);
            for (int j = 1; j < accounts[i].size(); j++)
            {
                interim[name].insert(accounts[i][j]);
            }
        }
        
        // construct result array
        for (auto it = interim.begin(); it != interim.end(); it++)
        {
            auto email_set = it->second;
            vector<string> account;
            const string& name = it->first;
            account.push_back(name.substr(0, name.find("_")));
            for (auto sit = email_set.begin(); sit != email_set.end(); sit++)
            {
                account.push_back(*sit);
            }
            
            result.push_back(account);
        }
        
        return result;
    }
};
