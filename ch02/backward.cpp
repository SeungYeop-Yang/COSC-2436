#include <iostream>
#include <string>

using namespace std;
void writeBackward(string, int);

int main()
{
    string word;

    cout << "Enter a string: ";
    cin >> word;

    writeBackward(word, word.length());
    cout << endl;
    return 0;
}

void writeBackward(string w, int length)
{
    // cout << w << last << endl;
    if (length > 0) {
        writeBackward(w.substr(1), (w.substr(1)).length());
        cout << w.substr(0, 1);
    }
    else
        return;
}
