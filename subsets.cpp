//Given a set of distinct integers, nums, return all possible subsets (the power set).

#include<bits/stdc++.h>
using namespace std;
void find_subsets(vector<int> &temp, vector<vector<int>> &result, int start, vector<int> &nums){
    result.push_back(temp);
    for(int i=start;i<nums.size();i++){
        temp.push_back(nums[i]);
        find_subsets(temp, result, i+1, nums);
        temp.pop_back();
    }
}
int main(){
    int n,element;
    cin>>n;
    vector<vector<int>>result;
    vector<int> temp,nums;
    for(int i=0;i<n;i++){
        cin>>element;
        nums.push_back(element);
    }
    find_subsets(temp,result,0,nums);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}