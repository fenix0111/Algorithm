// Leetcode 405.Convert a Number to Hexadecimal
// https://leetcode.com/problems/convert-a-number-to-hexadecimal/
// Runtime: 0ms

class Solution 
{
public:
    string toHex(int num) 
    {
        if (num == 0)
            return "0";
        
        string hexarray[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f" };
        
        int tmpnum = num;
        if (num < 0)
        {
            // two's complement
            tmpnum = -tmpnum;
            tmpnum = ~tmpnum + 1; 
        }
            
        int mask8 = 0xF0000000;
        int mask7 = 0x0F000000;
        int mask6 = 0x00F00000;
        int mask5 = 0x000F0000;
        int mask4 = 0x0000F000;
        int mask3 = 0x00000F00;
        int mask2 = 0x000000F0;
        int mask1 = 0x0000000F;
        
        string ret = "";
        
        ret += hexarray[(tmpnum & mask8) >> 28 & 0xF];
        ret += hexarray[(tmpnum & mask7) >> 24 & 0xF];
        ret += hexarray[(tmpnum & mask6) >> 20 & 0xF];
        ret += hexarray[(tmpnum & mask5) >> 16 & 0xF];
        ret += hexarray[(tmpnum & mask4) >> 12 & 0xF];
        ret += hexarray[(tmpnum & mask3) >> 8 & 0xF];
        ret += hexarray[(tmpnum & mask2) >> 4 & 0xF];
        ret += hexarray[tmpnum & mask1];
        
        // strip out heading zero(s)
        int i = 0;
        while (ret[i] == '0')
        {
            i++;
        }
        
        return ret.substr(i, ret.size() - i);
    }
};
