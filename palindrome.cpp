#include<iostream>
using namespace std;

//without reversing the whole number
//in the below solution, we reverse half the number, and compare it with the original other half
//half will be reached when reverse is greater than or equal to remaining original half
//if number of digits is even, the two halves will be equal
//for odd number of digits, rev/10 will be equal to the reamaining original half
int main(){
    int x,rev=0;
    cin>>x;
    if(x<0 || (!(x%10)) && x) {
        cout<<"not palindrome"<<endl; 
        return 0;
    }
    while(x>rev){
        rev=rev*10 + x%10;
        x/=10;
    }
    if(x==rev || x==rev/10){
        cout<<"palindrome"<<endl;
        return 0;
    }
    cout<<"not palindrome"<<endl;
    return 0;
}