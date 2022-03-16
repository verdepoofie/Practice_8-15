#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    double eps, max, min;
    string path;
    cout << "Input path" << endl;
    cin >> path;
    ofstream file(path);
    if (!file.is_open()) {
        cout << "Incorrect path";
        return 0;
    }
    cout << "Input min value of x, max value of x and epsilon: " << endl;
    cin >> min >> max >> eps;
    for (double x = min; x <= max; x += eps) {
        file << " " << (x * cos(x));
    }
    file.close();
    return 0;
}
