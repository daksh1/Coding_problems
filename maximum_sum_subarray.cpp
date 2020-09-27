#include<bits/stdc++.h>
using namespace std;


int max_sub_array(vector<int> &v){
    // Kadane's algorithm
    int sum=0;
    int result=INT_MIN;
    for(auto i: v){
        sum+=i;
        result=max(result,sum);
        sum=max(sum,0);//no need to include the sum if it was negative, assign it 0 and keep adding futher
    }
    return result;
}
int main(){
    int n,element;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>element;
        v.push_back(element);
    }
    cout<< max_sub_array(v);
    return 0;
}

