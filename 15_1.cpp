#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
    string path;
    cout << "Input path" << endl;
    cin >> path;
    ofstream file(path);
    if (!file.is_open()) {
        cout << "Incorrect file path";
        return 0;
    }
    srand(time(0));
    int n = rand() % 100;
    for (int i = 0; i < n; i++) {
        int num = rand() % 1000;
        file << " " << num;
    }
    file.close();
    return 0;
}
