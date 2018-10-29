// Leetcode 415. Add Strings
// https://leetcode.com/problems/add-strings/
// Runtime: 4ms

class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        list<int> tmplist;
        int ione = num1.size() - 1;
        int itwo = num2.size() - 1;
        
        int max = num1.size() > num2.size() ? num1.size() : num2.size();
        int remain = 0;
        
        bool carry = false;
           
        while (ione >= 0 && itwo >= 0)
        {
            int tmpsum = (num1[ione] - 48) + (num2[itwo] - 48);
            if (carry)
            {
                tmpsum++;
            }
            
            if (tmpsum < 10)
            {
                carry = false;
            }
            else
            {
                carry = true;
                tmpsum = tmpsum % 10;
            }
            
            tmplist.push_front(tmpsum);
            ione--;
            itwo--;
        }
        
        if (ione > itwo)
        {
            remain = ione - itwo;
        }
        else
        {
            remain = itwo - ione;
        }
        
        while (remain > 0)
        {
            if (max == num1.size())
            {
                int tmp = num1[remain - 1] - 48;
                if (carry)
                    tmp++;
                
                if (tmp >= 10)
                {
                    carry = true;
                    tmp = tmp % 10;
                }
                else
                {
                    carry = false;
                }

                tmplist.push_front(tmp);
            }
            
            if (max == num2.size())
            {
                int tmp = num2[remain - 1] - 48;
                if (carry)
                    tmp++;
                
                if (tmp >= 10)
                {
                    carry = true;
                    tmp = tmp % 10;
                }
                else
                {
                    carry = false;
                }
                
                tmplist.push_front(tmp);
            }
            remain--;
        }
        
        if (carry)
        {
            tmplist.push_front(1);
        }
        
        string ret;
        for (auto it = tmplist.begin(); it != tmplist.end(); it++)
        {
            ret.push_back(*it + 48);
        }
        
        return ret;
    }
};
