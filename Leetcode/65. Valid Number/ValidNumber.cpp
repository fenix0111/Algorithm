// Leetcode 65. Valid Number
// https://leetcode.com/problems/valid-number/
// Runtime: 0ms

// some test cases below
//"0"
//"95a54253"
//"--6"
//"00"
//"-90e3"
//"1 a"
//"e"
//"3e3"
//"-+3"
//"1 2  3"
//"1 "
//"-.1"
//"+.1"
//".1"
//"."
//"-"
//"3."
//"3.."
//".-4"
//"32.e-80123"

// the solution is awkward..
class Solution 
{
public:
    bool isNumber(string s) 
    {
        if (s.size() == 0)
            return false;
        
        // exponential was appeared once, it should not appear again therafter
        bool exp_over = false;
        
        // could accept number
        bool be_num = true;
        bool be_op = true;
        bool be_point = true;
        bool be_exp = false;
        bool point_over = false;
        bool zero_over = false;
       
        bool valid_e = true;
        bool valid_p = true;
        bool valid_op = true;
        bool valid_num = false;
        
        // skip the space in both sides
        int beg = 0;
        int end = s.size() - 1;
        while (beg < end)
        {
            if (s[beg] != ' ' && s[end] != ' ')
                break;
            
            if (s[beg] == ' ')
                beg++;
            
            if (s[end] == ' ')
                end--;
        }
        
        for (int i = beg; i <= end; i++)
        {
            char c = s[i];
            switch(c)
            {
                case '+':
                case '-':
                {
                    if (!be_op)
                    {
                        return false;
                    }
                    be_num = true;
                    be_op = false;
                    be_point = true;
                    
                    valid_op = false;
                    break;
                }
                    
                case 'e':
                {
                    if (exp_over || !be_exp)
                    {
                        return false;
                    }
                    
                    exp_over = true;
                    be_num = true;
                    be_op = true;
                    be_point = false;
                    
                    valid_e = false;
                    break;
                }
                case '.':
                {
                    if (point_over || !be_num)
                    {
                        return false;
                    }
                    
                    if (!be_point)
                    {
                        return false;
                    }
                    point_over = true;
                    be_op = false;
                    valid_p = false;
                    break;
                }
                    
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                {
                    be_op = false;
                    be_num = true;
                    
                    valid_e = true;
                    valid_p = true;
                    valid_op = true;
                    
                    be_exp = true;
                    
                    valid_num = true;
                    break;
                }
                    
                default:
                    return false;
            }
        }
        
        if (valid_e && valid_num && valid_op)
            return true;
        
        return false;
    }
};
