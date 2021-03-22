// faster version
// compare the number of each digit to each power of 2

class Solution 
{
public:
    bool reorderedPowerOf2(int N) 
    {
        int* countN = new int[10];
        memset(countN, 0, 10 * sizeof(int));
        int num = N;
        while (num > 0)
        {
            countN[num % 10]++;
            num /= 10;
        }
        
        int pow2 = 1;
        int* counter = new int[10];
        while (pow2 <= 1000000000)
        {
            memset(counter, 0, 10 * sizeof(int));           
            
            int tmp = pow2;
            while (tmp > 0)
            {
                counter[tmp % 10]++;
                tmp /= 10;
            }
            
            bool is_same = true;
            for (int i = 0; i < 9; i++)
            {
                if (countN[i] != counter[i])
                {
                    is_same = false;
                    break;
                }
            }
            
            if (is_same)
            {
                return true;
            }
            
            pow2 <<= 1;
        }
        
        return false;
    }
};
