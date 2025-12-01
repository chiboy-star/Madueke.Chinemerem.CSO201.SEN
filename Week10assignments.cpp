//Max number in an array 
//min number in an array
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    //MAX number
    int list[] = {2, 3, 4, 10, 40};
    int size = sizeof(list) / sizeof(list[0]);
    int max_number;
    for(int i = 0, i<=size;i++){
        int current_index = list[i];
        int perv_index = list[i-1];
        if(perv_index > current_index){
            max_number = perv_index
        }else if(perv_index < current_index){
            max_number = current_index;
        }
    }
    return 0;
}