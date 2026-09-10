#include <iostream>

using namespace std;
void message(int);

int main()
{
    int times;

    cout << "How many times? ";
    cin >> times;

    message(times);
    return 0;
}

void message(int times)
{
    if (times > 0) {
        cout << "Pluto is still a planet: " << times << endl;
        message(times - 1);
    }
    return;
}
