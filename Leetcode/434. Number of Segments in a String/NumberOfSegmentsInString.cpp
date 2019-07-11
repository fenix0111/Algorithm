// Leetcode 434. Number of Segments in a String
// https://leetcode.com/problems/number-of-segments-in-a-string/
// Runtime: 0ms

// segment is defined to be a contiguous sequence of non-space characters, not only alphabets
class Solution
{
public:
    int countSegments(string s) 
    {
        int ret = 0;
        bool new_seg = true;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c != ' ')
            {
                if (new_seg)
                {
                    ret++;
                    new_seg = false;
                }
            }
            else
            {
                new_seg = true;
            }
        }
        
        return ret;
    }
};
