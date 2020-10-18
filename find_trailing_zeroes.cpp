#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count=0;
    //number of 0s will be number of 5s in the the expansion of n! as 5*2=10, and 2 is present more times than 5
    //keep dividing a number by 5 until it has no more factors
    //diving once, gives all multiples of 5, again gives mulitples of 25 one 5 from which was counted in previous division
    //again gives multiples of 125, two 5's from which were counted in previous divisions and so on
    while(n>=5){
        n/=5;
        count+=n;
    }
    cout<<count;
    return 0;
}