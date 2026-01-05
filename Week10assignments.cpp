//Max number in an array 
//min number in an array
// Generating random numbers into an array 
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    //MAX number
    int list[] = {2, 3, 4, 10, 40};
    int size = sizeof(list) / sizeof(list[0]);
    int max_number = list[0]; // start with the first element
    int min_number = list[0]; // start with the first element
    for(int i = 0; i<size;i++){
        if(list[i] > max_number) {
            max_number = list[i];
        }
        cout<<"The max number in the list is "<<max_number<<endl;
        cout<<"================================="<<endl;
    }
    //MIN number 
    for(int i = 0; i<size;i++){
        if(list[i] < min_number) {
            min_number = list[i];
        }
        cout<<"The min number in the list is "<<min_number<<endl;
        cout<<"================================="<<endl;
    }
    //Generating random numbers into an array 
    srand(time(0)); 
    const int SIZE = 10;
    int nums[SIZE];
    for(int i = 0; i < SIZE; i++) {
        nums[i] = rand() % 100;
    }
    cout << "Random numbers: ";
    for(int i = 0; i < SIZE; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}