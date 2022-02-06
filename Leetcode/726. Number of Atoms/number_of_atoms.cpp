// Leetcode 726. Number of Atoms
// https://leetcode.com/problems/number-of-atoms/
// time complexity: O(N^2)
// space complexity: O(N)

// using stack + map

class Solution
{
    int i = 0;
public:
    bool isUpper(char c)
    {
        return c >= 'A' && c <= 'Z';
    }
    
    bool isLower(char c)
    {
        return c >= 'a' && c <= 'z';
    }
    
    map<string, int> count(const string& formula)
    {
        map<string, int> counter;
        
        // using stack since there's case such as ((...)...(...))
        // we should record the number of atoms in the inner parentheses
        // when finishing outer parentheses, pop up all the records then add to the counter
        stack<map<string, int>> st;
        int len = formula.length();
        while (i < len)
        {
            // get element name
            if (isUpper(formula[i]))
            {                
                string element = "";
                element.push_back(formula[i]);
                i++;
                while (i < len && isLower(formula[i]))
                {
                    element.push_back(formula[i]);
                    i++;
                }
                
                int c = 0;
                while (i < len && isdigit(formula[i]))
                {
                    c *= 10;
                    c += (formula[i] - '0');
                    i++;
                }
                
                if (c == 0)
                {
                    counter[element] += 1;
                }
                else
                {
                    counter[element] += c;
                }
            }
            else if (formula[i] == '(')
            {
                i++;
                map<string, int> ret = count(formula);
                int c = 0;
                while (i < len && isdigit(formula[i]))
                {
                    c *= 10;
                    c += (formula[i] - '0');
                    i++;
                }
                
                if (c == 0)
                {
                    c = 1;
                }
                
                for (auto it = ret.begin(); it != ret.end(); it++)
                {
                    it->second *= c;
                }
                
                st.push(ret);
            }
            else if (formula[i] == ')')
            {
                i++;
                break;
            }
        }
        
        while (!st.empty())
        {
            map<string, int> prev = st.top();
            st.pop();

            for (auto it = prev.begin(); it != prev.end(); it++)
            {
                counter[it->first] += it->second;
            }
        }
        
        return counter;
    }
    
    string countOfAtoms(string formula) 
    {
        // solution requires the lexicographically ordered
        // use map instead of unordered_map
        map<string, int> counter = count(formula);
    
        string result = "";
        for (auto it = counter.begin(); it != counter.end(); it++)
        {
            result.append(it->first);
            if (it->second > 1)
            {
                result.append(to_string(it->second));
            }
        }
        
        return result;
    }
};
