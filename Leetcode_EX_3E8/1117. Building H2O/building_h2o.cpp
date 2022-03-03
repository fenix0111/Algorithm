// Leetcode 1117. Building H2O
// https://leetcode.com/problems/building-h2o/

class H2O
{
    int numO;
    int numH;
    mutex mtx;
    condition_variable cv;
public:
    H2O()
    {
        numO = 0;
        numH = 0;
    }

    void hydrogen(function<void()> releaseHydrogen)
    {    
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [&]{ return numH < 2; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        
        numH++;
        if (numH == 2 && numO == 1)
        {
            numH = 0;
            numO = 0;
        }
        
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen)
    {    
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [&]{ return numO == 0; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        
        numO++;
        if (numH == 2)
        {
            numH = 0;
            numO = 0;
        }
        
        cv.notify_all();
    }
};
