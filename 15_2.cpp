#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string path;
    cout << "Input path" << endl;
    cin >> path;
    ifstream bin_file(path, fstream :: binary);
    if (!bin_file.is_open()) {
        cout << "Incorrect path";
        return 0;
    }
    int n = 0, sum = 0, buf = 0;
    do {
        bin_file >> buf;
        n++;
        sum += buf;
    } while (!bin_file.eof());
    bin_file.close();
    cout << "Number of integers " << n << " Their sum: " << sum;
    return 0;
}
