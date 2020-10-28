#include<bits/stdc++.h>
using namespace std;
int subarray_sum_k(vector<int> nums,int k){
    unordered_map<int,int>m;
    m[0]++;
    int sum=0,count=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(m[sum-k]) count+=m[sum-k];
        m[sum]++;
    }
    return count;
}
int main(){
    vector<int>v;
    int size,element,target;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>element;
        v.push_back(element);
    }
    cin>>target;
    cout<<subarray_sum_k(v,target);
    return 0;

}