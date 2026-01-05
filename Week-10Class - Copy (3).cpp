#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("data.txt", ios::in);  // open for reading

    if (!file) {
        cout << "Could not open file." << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {  // read line by line
        cout << line << endl;
    }

    file.close();
    return 0;
}
