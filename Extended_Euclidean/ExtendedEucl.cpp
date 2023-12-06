#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y) {
    // Initialize the table header
    cout << "Step   a   b   q   r   x   y" << endl;

    int x1, y1;  // To store results of recursive call
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
    int x, y, a = 161, b = 28;
    cout<<"Two inputs are : "<<a<<" "<<b<<"\n";
    int g = gcdExtended(a, b, &x, &y);
    cout << "GCD(" << a << ", " << b << ") = " << g << endl;
    return 0;
}
