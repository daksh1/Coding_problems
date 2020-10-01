#include<bits/stdc++.h>
using namespace std;
void move_zeroes(vector<int> &nums){

    /* bubble sort O(n^2) solution
     for(int i=0;i<nums.size();i++){
            //if(nums[i]!=0) continue;
            for(int j=0;j<nums.size()-i-1;j++){
                if(nums[j]==0){
                    swap(nums[j],nums[j+1]);
                }  
            }
        }  
    */

   //better O(n) solution, place all non zero elements in the front, then fill zeros in the remaining vector
   int i=0;
   for(auto j:nums){
       if(j!=0)
        nums[i++]=j;
   }
   for(;i<nums.size();i++)
        nums[i]=0;

}
int main(){
    vector<int>v;
    int size,element;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>element;
        v.push_back(element);
    }
    move_zeroes(v);
    for(auto i: v)
        cout<<i<<" ";
    return 0;
}