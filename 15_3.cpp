#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string path;
    cout << "Input path" << endl;
    cin >> path;
    ofstream file(path);
    if (!file.is_open()) {
        cout << "Incorrect path";
        return 0;
    }
    int n;
    cout << "Input number of bunnies: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int age, weight;
        char sex;
        cout << "Input sex (m/f), age (months) and weight (kilos) of bunny:" << endl;
        cin >> sex >> age >> weight;
        file << sex << endl << age << endl << weight << endl;
    }
    file.close();
    return 0;
}
