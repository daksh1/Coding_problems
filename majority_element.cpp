#include<bits/stdc++.h>
using namespace std;

int majority_element(vector<int> &v){
    int major=v[0];
    int count=1;
    for(auto i: v){
        if(!count){
            major=i;
            count++;
        }
        else if(major==i) count++;
        else count--;
    }
    return major;
}
int main(){
    vector<int>v;
    int size,element;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>element;
        v.push_back(element);
    }
    cout<<majority_element(v);
    return 0;
}