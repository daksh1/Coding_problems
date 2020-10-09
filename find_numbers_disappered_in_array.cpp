#include<bits/stdc++.h>
using namespace std;

//O(n) time, O(1) space not considering returned vector
vector<int>find_missing_elements(vector<int> nums){
    vector<int>result;
    for(int i=0;i<nums.size();i++){         
        int index=abs(nums[i])-1;
        nums[index]=(nums[index]>0)? -nums[index]:nums[index]; //if the index or element-1 exists, make associated value -ve
    }
    for(int i=0;i<nums.size();i++){                       //the indexes(+1) with +ve elements are the missing elements
        if(nums[i]>0)
            result.push_back(i+1);
    }
    return result;
}
int main(){
    int size,element;
    cin>>size;
    vector<int>v,result;
    for(int i=0;i<size;i++){
        cin>>element;
        v.push_back(element);
    }
    result=find_missing_elements(v);
    for(auto i:result)
        cout<<i<<" ";
    return 0;
}