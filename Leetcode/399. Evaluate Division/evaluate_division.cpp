// Leetcode 399. Evaluate Division
// https://leetcode.com/problems/evaluate-division/
// time complexity: O(NxN)
// space complexity: O(N)

class Solution
{
public:
    bool calculate(string& str, string& target, unordered_map< string, vector<pair<string, double>> >& G, unordered_set<string>& visited, double val, vector<double>& result)
    {
        if (visited.count(str))
        {
            return false;
        }
        
        visited.insert(str);
        
        if (G.find(str) == G.end())
        {
            visited.erase(str);
            return false;
        }
        else
        {
            vector<pair<string,double>>& paths = G[str];
            for (pair<string,double>& p : paths)
            {
                // found
                if (p.first.compare(target) == 0)
                {
                    result.push_back(val * p.second);
                    visited.erase(str);
                    return true;
                }
                
                if (calculate(p.first, target, G, visited, val * p.second, result))
                {
                    return true;
                }
            }
        }
        
        visited.erase(str);
        return false;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        vector<double> result;
        unordered_map< string, vector<pair<string, double>> > G;
        unordered_set<string> visited;
        
        for(int i = 0; i < equations.size(); i++)
        {
            vector<string>& eq = equations[i];
            auto fp = make_pair(eq[1], values[i]);
            auto bp = make_pair(eq[0], 1.0 / values[i]);
            
            G[eq[0]].push_back(fp);
            G[eq[1]].push_back(bp);
        }
        
        for (vector<string>& query : queries)
        {
            string numerator = query[0];
            string denominator = query[1];
            
            if (numerator.compare(denominator) == 0)
            {
                if (G.count(numerator))
                {
                    result.push_back(1.0);
                }
                else
                {
                    result.push_back(-1.0);
                }
                
                continue;
            }
            
            if (!calculate(numerator, denominator, G, visited, 1.0, result))
            {
                result.push_back(-1.0);
            }
            
            visited.clear();
        }

        return result;
    }
};
