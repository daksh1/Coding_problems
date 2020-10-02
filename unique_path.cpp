#include<bits/stdc++.h>
using namespace std;
int unique_paths(int m,int n){
    vector<vector<int>>dp(m,vector<int>(n,1));
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
    return dp[m-1][n-1];
}
int main(){
    int m,n;
    cin>> m>>n;
    cout<< unique_paths(m,n);
    return 0;
}
