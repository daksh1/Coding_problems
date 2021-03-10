#include<bits/stdc++.h>
using namespace std;

int find_smallest_missing_positive(vector<int> &v){
    for(int i=0;i<v.size();i++){
        while(v[i]>0 && v[i]<=v.size() && v[i]!=v[v[i]-1])
            swap(v[i],v[v[i]-1]);
    }
    for(int i=0;i<v.size();i++)
        if(v[i]!=i+1)
            return i+1;   
    
    return v.size()+1;
}

int main(){
    int size,element;
    cin>>size;
    vector<int> v;
    for(int i=0;i<size;i++){
        cin>>element;
        v.push_back(element);
    }
    cout<< find_smallest_missing_positive(v);
    return 0;
}