// Leetcode 134. Gas Station
// https://leetcode.com/problems/gas-station/description/
// Runtime: 168ms (terrible...need aggressive optimization)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // if (gas == nullptr || cost == nullptr) {
        //     return 0;
        // }
        
        int len = gas.size();
        int remain = 0;
        int num = 0;
        int res = -1;
        
        for (int i = 0; i < len; i++) {
            if (gas[i] >= cost[i]) {
                int k = i;
                remain = 0;
                num = 0;
                while (num <= len) {
                    if (remain + gas[k] >= cost[k]) {
                        num++;
                        remain = remain + gas[k] - cost[k];
                        k = (k + 1) % len;
                    } else {
                        break;
                    }
                }
                
                if (num == len + 1) {
                    return i;
                }
            }
 
        }
        
        return -1;
    }
};
