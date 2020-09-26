#include<bits/stdc++.h>
using namespace std;

void permute(vector<int> &a,int index,vector<vector<int>> &result){
    if(index==a.size())
        result.push_back(a);

    for(int i=index;i<a.size();i++){
        swap(a[i],a[index]);
        permute(a,index+1,result);
        swap(a[i],a[index]);
    }

}

int main(){
    int n;
    cin>>n;
    int element;
    vector<int>a;
    for(int i=0;i<n;i++){
        cin>>element;
        a.push_back(element);
    }
    vector<vector<int>>result;
    permute(a,0,result);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<n;j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}