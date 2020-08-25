#include<bits/stdc++.h>
using namespace std;

vector<int> binary_search(int start,int end,vector<int> &v,int target,vector<int> &result ){

    if(v.size()==0)
        return {-1,-1};
    
    result={-1,-1};
    while(start<end){
        int mid=(start+end)/2;
        if(v[mid]<target)
            start=mid+1;
        else end=mid;       
    }
    
    if(v[start]!=target) return {-1,-1};
    result[0]=start;
    end=v.size()-1;
    while(start<end){ 
        int mid=(start+end)/2 +1;           //if not +1, then for the last two elements in the terminating condition, mid doesn't move forward
        if(target<v[mid])
            end=mid-1;
        else start=mid;
    }
    if(v[end]!=target) return {-1,-1};
    result[1]=end;
    return result;

}
int main(){
    int n,target;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cin>>target;
    vector<int> result(2,0);
    result=binary_search(0,n-1,v,target,result);
    cout<<result[0]<<" "<<result[1];
    return 0;
}