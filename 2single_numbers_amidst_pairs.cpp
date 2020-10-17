#include<bits/stdc++.h>
using namespace std;

vector<int>single_number(vector<int>nums){
    int XorY=0,X=0,Y=0;
    for(auto i:nums)
        XorY^=i;

    //for finding last set bit of a number, say x:
    //& x with x-1, this inverts the last set bit, then xor with x to get the last set bit
    int last_set_bit=XorY^(XorY & (XorY-1));

    //last set bit being 1 means, X and Y are different at that place
    //so group numbers  by their bit at last_set_bit place being 1 or 0 by ANDing it with last_set_bit 
    //XOR all numbers in each group with each other and we'll be left with single numbers respectively
    for(auto i:nums){
        if(last_set_bit & i) X^=i;
        else Y^=i;
    }
    return {X,Y};
}
int main(){
    vector<int>nums;
    int size,element;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>element;
        nums.push_back(element);
    }
    vector<int>result=single_number(nums);
    for(auto i: result)
        cout<<i;
    
    return 0;
}