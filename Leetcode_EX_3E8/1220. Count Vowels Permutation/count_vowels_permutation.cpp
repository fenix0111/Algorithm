// Leetcode 1220. Count Vowels Permutation
// https://leetcode.com/problems/count-vowels-permutation/
// time complexity: O(n)
// space complexity: O(n)

class Solution 
{
public:
    int countVowelPermutation(int n) 
    {
        int result = 5;
        int MOD = 1000000000 + 7;
        unordered_map<char, vector<char>> M;
        unsigned long long counter[128] = { 0 };
        M['a'].push_back('e');
        
        M['e'].push_back('a');
        M['e'].push_back('i');
        
        M['i'].push_back('a');
        M['i'].push_back('e');
        M['i'].push_back('o');
        M['i'].push_back('u');
        
        M['o'].push_back('i');
        M['o'].push_back('u');
        
        M['u'].push_back('a');
        
        counter['a'] = 1;
        counter['e'] = 1;
        counter['i'] = 1;
        counter['o'] = 1;
        counter['u'] = 1;
        
        while (n > 1)
        {
            unsigned long long counts[128] = { 0 };
            for (auto& it : M)
            {
                for (char c : it.second)
                {
                    counts[c] = (counts[c] + counter[it.first]) % MOD;
                }
            }
            
            counter['a'] = counts['a'];
            counter['e'] = counts['e'];
            counter['i'] = counts['i'];
            counter['o'] = counts['o'];
            counter['u'] = counts['u'];
            
            n--;
        }
        
        result = (counter['a'] + counter['e'] + counter['i'] + counter['o'] + counter['u']) % MOD;
        return result;
    }
};
