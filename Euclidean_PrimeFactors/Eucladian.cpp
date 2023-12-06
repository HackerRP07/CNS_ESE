#include <iostream>
using namespace std;

int findGCD(int num1, int num2)
{
    cout << "Step\tNum1\tNum2\tQuotient\tRemainder" << endl;
    int step = 0;
    while (num2 != 0)
    {
        int quotient = num1 / num2;
        int remainder = num1 % num2;
        cout << step << "\t" << num1 << "\t" << num2 << "\t" << quotient << "\t" << remainder << endl;
        num1 = num2;
        num2 = remainder;
        step++;
    }
    return num1;
}

int main()
{
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    int gcd = findGCD(num1, num2);
    cout << "GCD is " << gcd << endl;

    return 0;
}
