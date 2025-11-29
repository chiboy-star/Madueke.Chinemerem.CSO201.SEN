#include <iostream>

using namespace std;

int main(){
    int i=0;
    int j=0;
    int k=0;
    int y=0;
    for(int x=0;x<11;x++){
        //post
        j= i++;//The current vaule of i is given to j then it is displayed before the i is incremented
        //pre
        k= ++y;//The vaule of y after the increment is given to k then displayed
        //cout<<"The output for i on run: "<<x<<"is:i ==> "<<j<<endl;
       // cout<<" "<<endl;
        //cout<<"The output for y on run: "<<x<<"is:y ==> "<<k<<endl;
        // cout<<"===================================================="<<endl;
    }

    int age = 18;
if (age = 21)
    cout << "Adult"<<endl;
else
    cout << "Minor";

for(int i=0;i <5; i++){
   for(int j=0;j<5;j++){
            cout<<"The output for i===> "<<i<<"The output for j===> "<<j<<endl;
        if(j == 3){
            cout<<"The loop ended when j==>"<<j<<endl;
            break;
        }
        endl;
   }
}


    return 0;
} 