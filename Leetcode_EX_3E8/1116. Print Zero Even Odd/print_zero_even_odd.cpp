// Leetcode 1116. Print Zero Even Odd
// https://leetcode.com/problems/print-zero-even-odd/

class ZeroEvenOdd
{
private:
    int n;
    int num;
    condition_variable cv;
    mutex mtx;
    bool printZero;
    
public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
        this->num = 0;
        this->printZero = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        while (true)
        {
            unique_lock<mutex> lck(mtx);
            cv.wait(lck, [&] { return printZero; });

            num++;  
            if (num > n)
            {
                printZero = false;
                
                // return before the function ends, manually unlock here.
                lck.unlock();
                cv.notify_all();
                return;
            }
            
            printNumber(0);
            printZero = false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber)
    {
        while (true)
        {
            unique_lock<mutex> lck(mtx);
            
            cv.wait(lck, [&] { return !printZero && (num % 2 == 0); });
            
            if (num > n)
            {
                // we need to unlock both even thread and odd thread
                // when num is greater than n, either even thread or odd thread could be unlocked
                // increasing num by one so that another thread could be unlocked, too
                num++;
                lck.unlock();
                cv.notify_all();
                return;
            }
            
            printZero = true;
            printNumber(num);
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber)
    {
        while (true)
        {
            unique_lock<mutex> lck(mtx);
            
            cv.wait(lck, [&] { return !printZero && (num % 2 == 1); });
            if (num > n)
            {
                num++;
                lck.unlock();
                cv.notify_all();
                return;
            }
            
            printZero = true;
            printNumber(num);
            cv.notify_all();
        }
    }
};
