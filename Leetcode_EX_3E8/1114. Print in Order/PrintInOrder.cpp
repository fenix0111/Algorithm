// Leetcode 1114. Print in Order
// https://leetcode.com/problems/print-in-order/
// Runtime: 888ms (slow..)

class Foo 
{
private:
    volatile bool first_finished = false;
    volatile bool second_finished = false;
    volatile bool third_finished = false;
    
public:
    Foo() { }

    void first(function<void()> printFirst) 
    {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        this->first_finished = true;
    }

    void second(function<void()> printSecond) 
    {
        while (!this->first_finished);
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        this->second_finished = true;
    }

    void third(function<void()> printThird) 
    {
        while (!this->first_finished || !this->second_finished);
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();   
        this->third_finished = true;
    }
};
