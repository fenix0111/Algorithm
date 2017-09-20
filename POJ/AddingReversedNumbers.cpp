// POJ 1504 Adding Reversed Numbers
// http://poj.org/problem?id=1504

// 第一道POJ。别人眼中的水题，本小白的一大步
// 关键看如何翻转整数。

#include <iostream>

using namespace std;

int reverse_int(int x) 
{
    int rev = 0;
    while (x != 0) 
    {
        rev = rev * 10 + x % 10;
        x = x / 10;
    }
    return rev;
}

int main(int argc, char **argv)
{
    int cases;
    cin >> cases;
    while (cases)
    {
        int num1 = 0;
        int num2 = 0;
        cin >> num1 >> num2;

        num1 = reverse_int(num1);
        num2 = reverse_int(num2);

        int sum = num1 + num2;
        cout << reverse_int(sum) << endl;
        cases--;
    }
}
