#include<bits/stdc++.h>
using namespace std;


void next_permutation(vector<int> &my_vector){
    int i,j,k;
    for(i=my_vector.size()-1;i>=1;i--){
        if(my_vector[i-1]>=my_vector[i]){
            continue;
        }
        else break;
    }
    if(i==0){
        sort(my_vector.begin(),my_vector.end());
        return;
    } 
    int c=i-1;
    //cout<<c;

    for(j=c+1;j<my_vector.size();j++){
        if(my_vector[c]<my_vector[j])
            continue;
        else break;
    }

    k=j-1;

    //cout<<k;

    int temp=my_vector[c];
    my_vector[c]=my_vector[k];
    my_vector[k]=temp;

    sort(my_vector.begin()+c+1,my_vector.end());
    return;
    
}
int main(){
    int n;
    cin>>n;
    vector<int>my_vector(n,0);
    for(int i=0;i<n;i++)
        cin>>my_vector[i];

    next_permutation(my_vector);

    for(int i=0;i<n;i++)
        cout<<my_vector[i]<<" ";
    
return 0;
}


