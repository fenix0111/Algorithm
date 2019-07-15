// Leetcode 1115. Print FooBar Alternately
// https://leetcode.com/problems/print-foobar-alternately/
// Runtime: 300ms

class FooBar 
{
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool ready = false;
    
public:
    FooBar(int n) 
    {
        this->n = n;
    }

    void foo(function<void()> printFoo) 
    {  
        for (int i = 0; i < n; i++) 
        {
            unique_lock<mutex> lck(mtx);
            while (ready) 
                cv.wait(lck);
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            ready = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) 
    {
        
        for (int i = 0; i < n; i++) 
        {
            unique_lock<mutex> lck(mtx);
            while (!ready) 
                cv.wait(lck);
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            ready = false;
            cv.notify_all();
        }
    }
};
