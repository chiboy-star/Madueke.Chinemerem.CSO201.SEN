#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int linearSearch(const int list[], int key, int arraySize){
    for(int i=0;i<arraySize;i++){
        if(key==list[i]){
            return i;
        }
    }
    return -1;//The key was NOT found in the list
}

int main(){
    int list[] = {1,4,4,2,5,-3,6,2};
    int size = sizeof(list) / sizeof(list[0]);
    /*
sizeof(list) gives the total number of bytes used by the array.
sizeof(list[0]) gives the number of bytes of one element.
Dividing them gives the number of elements in the array.
    */
    int i = linearSearch(list,4,size);// 4 exists → returns index
    int j = linearSearch(list,-4,size);// -4 does NOT exist → returns -1
    int k = linearSearch(list,-3,size);// // -3 exists → returns index
    cout<<"Locations of 4,-4 and -3 are "<<i<<","<<j<<", and "<<k;
    return 0;
}

/*
Start from the first element.
Compare it with the target value.
If it matches → return its position.
If not → move to the next element.
Repeat until:
You find the target, or
You reach the end of the list (target not found).
*/