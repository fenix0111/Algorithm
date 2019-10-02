// Leetcode 811. Subdomain Visit Count
// https://leetcode.com/problems/subdomain-visit-count/
// Runtime: 16ms

class Solution 
{
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) 
    {
        unordered_map<string, int> counter;
        vector<string> ret;
        string domain;
        for (string s : cpdomains)
        {
            int l = 0;
            int r = s.size() - 1;
            while (s[l] != ' ')
            {
                l++;
            }
            
            int num = stoi(s.substr(0, l), nullptr);
            l++;
            
            domain = s.substr(l, r - l + 1);
            if (counter.find(domain) == counter.end())
            {
                counter.insert(make_pair(domain, num));
            }
            else
            {
                counter.find(domain)->second += num;
            }
            
            while (l < r)
            {
                if (s[l] == '.')
                {
                    l++;
                    domain = s.substr(l, r - l + 1);
                    if (counter.find(domain) == counter.end())
                    {
                        counter.insert(make_pair(domain, num));
                    }
                    else
                    {
                        counter.find(domain)->second += num;
                    }
                }
                else
                {
                    l++;
                }
            }
        }
        
        for (auto it = counter.begin(); it != counter.end(); it++)
        {
            string result = to_string(it->second);
            result.append(" ");
            result.append(it->first);
            ret.push_back(result);
        }
        
        return ret;
    }
};
