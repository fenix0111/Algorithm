// Leetcode 870. Advantage Shuffle
// https://leetcode.com/problems/advantage-shuffle/
// time complexity: O(nlogn)
// space complexity: O(n)

// numbers in the input array may not be unique
class Solution 
{
public:    
    vector<int> advantageCount(vector<int>& A, vector<int>& B) 
    {
        // create auxiliary space for storing elements of A in increasing order for binary search
        multiset<int> ms;
        for (int a : A)
        {
            ms.insert(a);
        }
        
        int size = A.size();
        vector<int> result(size, 0);
        
        // if upper bound is found, use it then erase
        // otherwise, use the first element in the set
        for (int i = 0; i < size; i++)
        {
            auto upperbound = ms.upper_bound(B[i]);
            if (upperbound == ms.end())
            {
                result[i] = *(ms.begin());
                ms.erase(ms.begin());
            }
            else
            {
                result[i] = *upperbound;
                ms.erase(upperbound);
            }
        }
        
        return result;
    }
};
