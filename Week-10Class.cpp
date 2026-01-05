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

//using ofstream
ofstream outfile("data.txt");//this will be saved in the same folder as the code
//outfile in this case is a varible name that can be changed 
//the above statement will also create a file called data.txt
//To check if the file has been made 
if(!outfile){
    cout<<"Guy the is an error opening this file"<<endl;
    return 0;
}

outfile << "Welcome to COS201"<<endl;
outfile << "This is file handling class"<<endl;
outfile.close();
cout<<"Done";
return 0;
}