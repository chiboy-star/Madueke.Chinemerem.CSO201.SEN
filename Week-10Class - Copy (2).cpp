#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
//FILE HANDLING
int main(){
// ofstream ==> write to file(output)
// ifstream ==> Read from a file(input)    
// fstream ==> read and write
    fstream file("data.txt", ios::out | ios::app);
    //ios::out ==> Write mode
    //ios::app ==> append mode(we are adding things to it)
    //ios::trunc ==> This will erase file before adding new things 
    //ios::in ==> read mode
    file<<"Please, add this new line"<<endl;
    file.close();
    cout<<"DONE"<<endl;
return 0;
}