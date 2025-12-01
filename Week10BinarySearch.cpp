#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int binarySearch(const int list[], int key, int size) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;  // Check middle element

        if (list[mid] == key) {
            return mid;             // Found i
        }
        else if (key < list[mid]) {
            cout<<"it is less than the middle number so its on the left side "<<endl;
            high = mid - 1;         // Search left half
        }
        else {
            cout<<"it is greater than the middle number so its on the right side "<<endl;
            low = mid + 1;          // Search right half
        }
    }

    return -1;  // Not found
}


int main(){
    int list[] = {2, 3, 4, 10, 40};
    int size = sizeof(list) / sizeof(list[0]);
    /*
sizeof(list) gives the total number of bytes used by the array.
sizeof(list[0]) gives the number of bytes of one element.
Dividing them gives the number of elements in the array.
    */
    int i = binarySearch(list,2,size);
    cout<<"Found it at index "<<i<<" of your list"<<endl;
    return 0;
}
/*
Start by checking the middle element of the array.
If the middle value equals the target → Found!
If the target is smaller → search the left half instead.
If the target is greater → search the right half instead.
Repeat until:
You find the value, or
The search range becomes empty.
*/