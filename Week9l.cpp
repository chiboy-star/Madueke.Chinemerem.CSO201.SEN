#include <iostream>
using namespace std;

/*
 * Reads 'size' number of integers from the user
 * and stores them in the array 'list'.
 */
void readArray(int list[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the value for index " << i << " ==> ";
        cin >> list[i];
    }
}

/*
 * Prints all elements of the array 'list'
 * on a single line separated by tabs.
 */
void printArray(int list[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << "\t";
    }
    cout << endl;
}

/*
 * Calculates and returns the sum of all elements in the array.
 */
int sumArray(int list[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += list[i];     // accumulate values
    }

    cout << "The sum of the array is ==> " << sum << endl;
    return sum;
}

int main() {

    // Example array
    int arr[5] = {1, 2, 3, 4, 5};
    double arr2[5] = {1, 2, 3, 4, 5};
    float arr3[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);   // calculate array length
    cout<<"The size of the array is "<<size<<endl;
    // Example usage of functions
    printArray(arr, size);      // display array
    sumArray(arr, size);        // sum elements

    return 0;
}
