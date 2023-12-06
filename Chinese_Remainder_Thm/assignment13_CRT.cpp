#include <bits/stdc++.h>
using namespace std;

// Function to calculate the modular inverse using extended Euclidean algorithm
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Modular inverse doesn't exist
}

// Function to find the solution to the system of congruences using CRT
int chineseRemainderTheorem(vector<int>& num, vector<int>& rem) {
    int product = 1;
    int n = num.size();

    for (int i = 0; i < n; i++) {
        product *= num[i];
    }

    vector<int> partialProducts(n);
    vector<int> inverse(n);

    int x = 0;

    cout << "Step\tPartial Product\tInverse\tProduct So Far\tIntermediate Result" << endl;

    for (int i = 0; i < n; i++) {
        partialProducts[i] = product / num[i];
        inverse[i] = modInverse(partialProducts[i], num[i]);
        int intermediateResult = partialProducts[i] * inverse[i] * rem[i];
        x += intermediateResult;

        cout << i + 1 << "\t" << partialProducts[i] << "\t" << inverse[i] << "\t" << product << "\t" << intermediateResult << endl;
    }

    x = x % product;

    return x < 0 ? x + product : x;
}

int main() {
    int n;
    cout << "Enter the number of congruences: ";
    cin >> n;

    vector<int> num(n);
    vector<int> rem(n);

    cout << "Enter the moduli: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cout << "Enter the remainders: ";
    for (int i = 0; i < n; i++) {
        cin >> rem[i];
    }

    int result = chineseRemainderTheorem(num, rem);

    cout << "The solution to the system of congruences is: " << result << endl;

    return 0;
}
