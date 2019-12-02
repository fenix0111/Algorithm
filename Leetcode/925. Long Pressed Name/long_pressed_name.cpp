// Leetcode 925. Long Pressed Name
// https://leetcode.com/problems/long-pressed-name/
// Runtime: 0ms

// Related:
// 936. Stamping The Sequence
// 1106. Parsing A Boolean Expression
// 1108. Defanging an IP Address

class Solution 
{
public:
    bool isLongPressedName(string name, string typed) 
    {
        int i = 0; // index for name
        int j = 0; // index for typed
        
        while (i < name.size() && j < typed.size())
        {
            if (name[i] != typed[j])
            {
                return false;
            }
            
            char cn = name[i];
            char ct = typed[j];
            
            int ncount = 1;
            int tcount = 1;
            while (i < name.size() && name[i] == cn)
            {
                i++;
                ncount++;
            }
            
            while (j < typed.size() && typed[j] == ct)
            {
                j++;
                tcount++;
            }
            
            if (tcount < ncount)
            {
                return false;
            }
        }
        
        // would only be true when both indices reach the end of the array
        if (i == name.size() && j == typed.size())
        {
            return true;
        }
        
        return false;
    }
};
