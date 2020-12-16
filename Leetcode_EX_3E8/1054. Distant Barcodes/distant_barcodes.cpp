// Leetcode 1054. Distant Barcodes
// https://leetcode.com/problems/distant-barcodes/
// time comlexity: O(nlogn)
// space complexity: O(n)

class Solution 
{
public:   
    void swap(vector<int>& barcodes, int left, int right)
    {
        int tmp = barcodes[left];
        barcodes[left] = barcodes[right];
        barcodes[right] = tmp;
    }
    
    vector<int> rearrangeBarcodes(vector<int>& barcodes) 
    {
        sort(barcodes.begin(), barcodes.end());
        vector<int> result;
        int pivot = barcodes.size() / 2;
        int l = 0;
        int r = barcodes.size() - 1;
        
        while (l <= pivot && r > pivot)
        {
            result.push_back(barcodes[l]);
            result.push_back(barcodes[r]);
            l++;
            r--;
        }
        
        while (l <= pivot)
        {
            result.push_back(barcodes[l]);
            l++;
        }
        
        while (r > pivot)
        {
            result.push_back(barcodes[r]);
            r--;
        }
        
        int sz = result.size();
        l = 0;
        r = sz - 1;
        
        // eliminating same adjacent element
        while (l < r)
        {
            if (result[r - 1] == result[r])
            {
                if (l == 0)
                {
                    if (result[l + 1] != result[r - 1])
                    {
                        swap(result, l, r - 1);
                        l++;
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
                else
                {
                    if (result[l + 1] != result[r - 1] && result[l - 1] != result[r - 1])
                    {
                        swap(result, l, r - 1);
                        l++;
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }
            else
            {
                r--;
            }
        }
        
        return result;
    }
};
