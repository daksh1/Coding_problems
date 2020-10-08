#include<bits/stdc++.h>
using namespace std;

// this is template for most dp problems and seems like a very intuitive and easy to understand
//like this

int max_loot(vector<int> &nums){
    vector<int> dp(nums.size()+1,0);
    dp[0]=0;
    dp[1]=nums[0];          //dp stores max lot up till present
    for(int i=1;i<nums.size();i++){
        dp[i+1]=max(dp[i],dp[i-1]+nums[i]);
    }
    return dp[nums.size()];
}
int main(){
    int n,element;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>element;
        v.push_back(element);
    }
    cout<< max_loot(v);
    return 0;
}