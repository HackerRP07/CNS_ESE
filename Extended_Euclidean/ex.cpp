#include <bits/stdc++.h>
using namespace std;
int S, T;
int extendedGCD(int r1, int r2, int s1, int s2, int t1, int t2){
// Base Case
if (r2 == 0){
S = s1;
T = t1;
return r1;
}
int q = r1 / r2;
int r = r1 % r2;
int s = s1 - q * s2;
int t = t1 - q * t2;
cout << q <<"\t" << r1 <<"\t" << r2 <<"\t" << r <<"\t" << s1
<<"\t" << s2 <<"\t" << s <<"\t" << t1 <<"\t" << t2 <<"\t"<< t << endl;
return extendedGCD(r2, r, s2, s, t2, t);
}
int main(){
int num1, num2, s, t;
cout << "Enter 2 numbers to find GCD" << endl;
cin >> num1 >> num2;
int gcd = extendedGCD(num1, num2, 1, 0, 0, 1);
cout << "\nGCD = " << gcd << endl;
cout <<"S = "<< S<<endl;
cout<< "T = " << T << endl;
return 0;
}