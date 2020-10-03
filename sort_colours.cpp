#include<bits/stdc++.h>
using namespace std;
/* shitty two pass solution that nobody cares about
void sort_colours(vector<int> &nums){
    if(nums.size()==1) return;
        int zeroes=0;
        int ones=0;
        int twos=0;
        for(auto it: nums){
            if(it==0) zeroes++;
            else if(it==1) ones++;
            else twos++;
        }
        int i=0;
        for(;i<zeroes;i++)
            nums[i]=0;
        for(int j=0;j<ones;j++){
            nums[i]=1;
            i++;
        }
        for(int j=0;j<twos;j++){
            nums[i]=2;
            i++;
        }
}*/

//one pass in place solution
void sort_colours(vector<int> &nums){
    int index0=-1, index1=-1, index2=-1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            nums[++index2]=2;
            nums[++index1]=1;
            nums[++index0]=0;
        }
        else if(nums[i]==1){
            nums[++index2]=2;
            nums[++index1]=1;
        }
        else{
             nums[++index2]=2;
        }
    }
}
int main(){
    int size,element;
    cin>>size;
    vector<int>nums;
    for(int i=0;i<size;i++){
        cin>>element;
        nums.push_back(element);
    }
    sort_colours(nums);
    for(auto i:nums)
        cout<<i<<" ";
    return 0;
}