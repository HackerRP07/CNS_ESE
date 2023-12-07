#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y) {
    // Initialize the table header
    cout << "Step   a   b   q   r   x   y" << endl;

    int x1=0, y1=1;  // To store results of recursive call
    int step = 1; // Initialize step counter
    int gcd;

    while (a != 0) {
        int q = b / a;
        int r = b % a;
        *x = *x - q * x1;
        *y = *y - q * y1;

        // Print the step details
        cout << step << "      " << a << "   " << b << "   " << q << "   " << r << "   " << *x << "   " << *y << endl;

        b = a;
        a = r;
        x1 = *x;
        y1 = *y;
        step++;
    }

    gcd = b; // GCD is stored in 'b'
    return gcd;
}

int main() {
    int x=0, y=1, a = 28, b = 161;
    cout<<"Two inputs are : "<<a<<" "<<b<<"\n";
    int g = gcdExtended(a, b, &x, &y);
    cout << "GCD(" << a << ", " << b << ") = " << g << endl;
    return 0;
}
