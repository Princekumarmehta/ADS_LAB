#include <bits/stdc++.h>
using namespace std;

int extended_gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd((extended_gcd(b, a % b, x1, y1)));
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}
int main()
{
    int a, b;
    cout << "Enter two number for gcd calculation: ";
    cin >> a >> b;
    int x, y;
    int gcd = extended_gcd(a, b, x, y);
    cout << "Extended gcd value :\n";
    cout << "Gcd of " << a << " and " << b << " is " << gcd << endl;
    cout << "X and Y coefficient satisying ax+by are x:" << x << " y:" << y;
    return 0;
}