#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Bunny {
public:
    Bunny(char in_sex, double in_age, double in_weight);
    void operator=(Bunny rv);
    bool operator<(Bunny rv);
    bool operator>(Bunny rv);
    char get_sex();
    double get_age();
    double get_weight();
private:
    char sex;
    double age, weight;
};

void oldest_bunny(vector<Bunny> bunnies);

int main() {
    string path;
    int n = 0, sum = 0, count = 0;
    cout << "Input path" << endl;
    cin >> path;
    ifstream bin_file(path, fstream :: binary);
    if (!bin_file.is_open()) {
        cout << "Incorrect path";
        return 0;
    }
    vector <Bunny> bunnies;
    char sex;
    int age, weight;
    do {
        bin_file >> sex >> age >> weight;
        Bunny bunny_un(sex, age, weight);
        bunnies.push_back(bunny_un);
    } while (!bin_file.eof());
    bin_file.close();
    oldest_bunny(bunnies);
    return 0;
}

Bunny::Bunny(char in_sex, double in_age, double in_weight): sex(in_sex), age(in_age), weight(in_weight) {
}


char Bunny::get_sex() {
    return sex;
}

double Bunny::get_age() {
    return age;
}

double Bunny::get_weight() {
    return weight;
}

bool Bunny::operator<(Bunny rv) {
    if (this->age < rv.age) {
        return true;
    } else if ((this->age == rv.age) && (this->weight < rv.weight)) {
        return true;
    }
    return false;
}

bool Bunny::operator>(Bunny rv) {
    if (this->age > rv.age) {
        return true;
    } else if ((this->age == rv.age) && (this->weight > rv.weight)) {
        return true;
    }
    return false;
}

void Bunny::operator=(Bunny rv) {
    this->sex = rv.sex;
    this->age = rv.age;
    this->weight = rv.weight;
}

void oldest_bunny(vector<Bunny> bunnies) {
    Bunny oldest('-', 0, 0);
    for (int i = 0; i < bunnies.size(); i++) {
        if (bunnies[i] > oldest) {
            oldest = bunnies[i];
        }
    }
    cout << "Oldest bunny is: " << oldest.get_sex() << " its age: "  << oldest.get_age() << " its weight: " << oldest.get_weight();
}