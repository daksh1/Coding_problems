//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

#include<bits/stdc++.h>
using namespace std;
void form_combinations_of_size_k(vector<int> &temp,vector<vector<int>> &result,int start,int tot, int n, int k){

    if(tot==k){
        result.push_back(temp);
        return;
    }
    for(int i=start;i<n;i++){
        temp.push_back(i+1);
        form_combinations_of_size_k(temp,result,i+1,tot+1,n,k);
        temp.pop_back();
    }
    return;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>>result;
    vector<int>temp;
    form_combinations_of_size_k(temp,result,0,0,n,k);
    for(int i=0;i<result.size();i++){
        cout<<result[i][0]<<" "<<result[i][1]<<endl;
    }
    
    return 0;
}