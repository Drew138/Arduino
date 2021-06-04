#include <bits/stdc++.h>

#define D(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define allgreater(v) v.begin(), v.end(), greater<int>()
#define formap(map) for (const auto &[key, value] : map)
#define ms(ar, val) memset(ar, val, sizeof ar)
typedef long long ll;
typedef long double ld;

using namespace std;

double factorialAt(int i)
{
    double factorial = 1;
    for (double j = 1; j <= i; ++j)
        factorial *= j;
    return factorial;
}

double nAt(int i)
{
    double total = 1;
    for (double j = 1; j <= i; ++j)
    {
        total *= (1.0 / 2.0) - j + 1.0;
    }
    return total;
}

double integralAtN(double i)
{
    double x = pow((1.0 / 2.0), 2.0 * i + 1.0) / (2.0 * i + 1.0);
    x = i == 0 ? x : -x;
    double factorial = factorialAt(i);
    double n = nAt(i);
    // cout << i << ": " << n << endl;
    return (x * n / factorial);
}

double calculatePi(int i)
{
    double total = 0.0;
    for (double j = 0; j <= i; j++)
    {
        double v = integralAtN(j);
        total += v;
        cout << j << ": " << v << endl;
    }
    return (12 * (total - (sqrt(3) / 8.0)));
}

int main()
{

    cout << calculatePi(5);
}