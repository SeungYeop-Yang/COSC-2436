#include <iostream>

using namespace std;
int factorial(int);

int main()
{
    int n;
    cout << "What factorial of ? ";
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}

int factorial(int n)
{
    int p;

    p = 1;
    for (int i = n; i > 0; i--)
        p *= i;

    return p;
}
