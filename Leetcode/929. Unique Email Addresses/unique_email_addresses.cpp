// Leetcode 929. Unique Email Addresses
// https://leetcode.com/problems/unique-email-addresses/
// time complexity: O(len of word * # of words)
// space complexity: O(len of longest word)

class Solution
{
public:
    int numUniqueEmails(vector<string>& emails)
    {
        unordered_set<string> buf;
        for (string& email : emails)
        {
            string addr = "";
            int i = 0;
            while (i < email.size() && email[i] != '+' && email[i] != '@')
            {
                if (email[i] != '.')
                {
                    addr.push_back(email[i]);
                }
                i++;
            }

            if (email[i] == '+')
            {
                while (email[i] != '@')
                {
                    i++;
                }
            }

            while (i < email.size())
            {
                addr.push_back(email[i]);
                i++;
            }

            buf.insert(addr);
        }
        return buf.size();
    }
};
