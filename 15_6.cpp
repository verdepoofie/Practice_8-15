#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string path;
    cout << "Input path" << endl;
    cin >> path;
    ifstream file(path);
    if (!file.is_open()) {
        cout << "Incorrect path";
        return 0;
    }
    int buf, n = 0;
    do {
        file >> buf;
        if (buf % 3 == 0) {
            n++;
        }
    } while (!file.eof());
    file.close();
    cout << "the number of numbers that are multiples of three: " << n;
}
