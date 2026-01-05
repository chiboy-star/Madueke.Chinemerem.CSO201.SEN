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
    ifstream infile("data.txt");

    if(!infile){
        cout<<"Cannot open file.";
        return 0;
    }
    string line;
    int count =0;
    while (getline(infile, line))
    {
        cout<<line<<endl;
        count++;
    }
    cout<<"The number of lines are "<<count;
    infile.close();
 cout<<"DOne"<<endl;
return 0;
}