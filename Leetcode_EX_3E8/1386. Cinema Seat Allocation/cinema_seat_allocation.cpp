// Leetcode 1386. Cinema Seat Allocation
// https://leetcode.com/problems/cinema-seat-allocation/
// time complexity: O(N)
// space complexity: O(N)

class Solution 
{
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) 
    {
        // using bit operation
        int left   = 0b0111100000;
        int middle = 0b0001111000;
        int right  = 0b0000011110;
        int full   = 0b0111111110;
        
        unordered_map<int, int> tbl;
        
        for (vector<int>& seat : reservedSeats)
        {
            int row = seat[0];
            int col = seat[1];
            
            int pos = 1 << (col - 1);
            
            if (tbl.find(row - 1) == tbl.end())
            {
                tbl[row - 1] = 0xFFFFFFFF ^ pos;
            }
            else
            {
                tbl[row - 1] ^= pos;
            }
        }
        
        // if no reserved seat, then two four-person groups can be assigned to each row
        int result = n << 1;
        
        // if has reserved seats, then we need to count the maximum available seats for four-person groups
        for (auto it = tbl.begin(); it != tbl.end(); it++)
        {
            int nums = 0;
            int val = it->second;
            
            if ((val & full) == full)
            {
                nums = 2;
            }
            else if ((val & left) == left)
            {
                nums = 1;
            }
            else if ((val & right) == right)
            {
                nums = 1;
            }
            else if ((val & middle) == middle)
            {
                nums = 1;
            }
            
            result -= (2 - nums);
        }
        
        return result;
    }
};
