#include<bits/stdc++.h>
using namespace std;

void merge_sorted_array(vector<int> &num1, int m, vector<int> &num2, int n){
    int i=m-1;
    int j=n-1;
    int k=m+n-1;
    while(i>=0 && j>=0){
        if(num1[i]>=num2[j])
            num1[k--]=num1[i--];
        
        else num1[k--]=num2[j--];
    }
    while(j>=0){
        num1[k--]=num2[j--];
    }
}
int main(){
    int m,n,element;
    cin>>m>>n;
    vector<int>num1(m+n,0);
    vector<int>num2(n,0);
    for(int i=0;i<m;i++){
        cin>>element;
        num1[i]=element;
    }
    for(int i=0;i<n;i++){
        cin>>element;
        num2[i]=element;
    }
    merge_sorted_array(num1,m,num2,n);
    
    for(auto i:num1)
        cout<<i;
    
    return 0;
}