class Solution 
{
public:
    bool isIdealPermutation(vector<int>& A) 
    {
        if (A.size() < 2)
            return true;
        
        int maxval = A[0];
        for (int i = 0; i < A.size() - 2; i++)
        {
            if (A[i] > maxval)
            {
                maxval = A[i];
            }
            
            if (maxval > A[i + 2])
            {
                return false;
            }
        }
        
        return true;
    }
};
