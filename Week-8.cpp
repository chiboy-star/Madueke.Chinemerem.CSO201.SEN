#include <iostream>
using namespace std;
#include <string>
//A function that gives the bigger number between the two
int max(int num1, int num2){
    int max_numb;

    if(num1 > num2){
        max_numb = num1;
    }else if(num2 > num1){
        max_numb = num2;
    }else{
        cout<<"The numbers are equal";
    }

    return max_numb;
}

//Void function 
void nprint(string name){
    cout<<name;
}

int add(int a, int b){
    int sum = a + b;
    return sum;
}
//classwork
void welcome(string welcome, int count){
    for(count = 1;count <=5;count++){
        cout<<welcome<<endl;
    }
}
int main(){
    //using for loop for adding numbers 
    int sum = 0;
    int i,j;
    for(i=1;i<=2;i++){
        for(j=1;j<=3;j++){
            sum+= (j+i);
        }
    }
    cout<<"The sum is "<<sum<<endl;
    //using for loop to draw a square
    int newi,newj;
    for(newi=1; newi<=5;newi++){
        for(newj=1; newj<=5;newj++){
            cout<<"*";
        }
        cout<<endl;
    }
    //using for loops to draw a right angle triangle 
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }

    //Functions 
    int result;
     result = max(120,160);
     cout<<"The max number is "<<result<<endl;
    //calling the void function 
    nprint("Madueke");
    cout<<endl;
    int result2 = add(12,18);
    welcome("Welcome to C++ class",5);
   
    return 0;
}