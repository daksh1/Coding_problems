#include<bits/stdc++.h>
using namespace std;

bool jump(vector<int> &nums){
    int starting_point=nums.size()-1;
    for(int i=nums.size()-1;i>=0;i--){
        if(i+nums[i]>=starting_point)
            starting_point=i;
    }
    if(!starting_point) return true;
    return false;
}

int main(){
    int size,element;
    cin>>size;
    vector<int>nums;

    for(int i=0;i<size;i++){
        cin>>element;
        nums.push_back(element);
    }
    bool result=jump(nums);
    cout<< result;
    return 0;
}