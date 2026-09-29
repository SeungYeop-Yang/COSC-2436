#include <iostream>

using namespace std;

int main()
{
    int num;
    int* intPtr;

    num = 5;
    intPtr = &num;

    cout << "num is " << num << " address is " << &num << endl;
    cout << "intPtr is " << intPtr << " content is " << *intPtr << endl;

    *intPtr = 99;

    cout << "num is " << num << " address is " << &num << endl;
    cout << "intPtr is " << intPtr << " content is " << *intPtr << endl;

    return 0;
}
