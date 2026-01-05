#include <iostream>
#include <fstream>
using namespace std;
//find the max number
//find the min number 
//find sum the numebrs 
//read the numbers from the file into an array 
//use binary search to find a number

int main() {
    ifstream infile("C:/Users/CHIGOZIE/Downloads/Madueke.Chinemerem.CSO201.SEN/data 1.txt"); // your file with numbers
    if (!infile) {
        cout << "Error opening file\n";
        return 1;
    }

    const int MAX_SIZE = 100; 
    int numbers[MAX_SIZE];
    int count = 0;
    int num;

    while (infile >> num && count < MAX_SIZE) {
        numbers[count] = num;
        count++;
    }

    `````````

    infile.close();

    // Display numbers
    cout << "Numbers read from file:\n";
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
    }

    return 0;
}
