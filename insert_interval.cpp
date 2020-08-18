#include<iostream>
using namespace std;
#include<bits/stdc++.h>


vector<vector<int>> merge_intervals(vector<vector<int>>input_intervals,vector<int>new_interval){
    int i=0;
    vector<vector<int>>output;
    while(i<input_intervals.size() && input_intervals[i][1]<new_interval[0]){
        output.push_back(input_intervals[i]);
        i++;
    }

    while(i<input_intervals.size() && input_intervals[i][0]<=new_interval[1]){
        new_interval[0]=min(input_intervals[i][0],new_interval[0]);
        new_interval[1]=max(input_intervals[i][1],new_interval[1]);
        i++;
    }
    output.push_back(new_interval);

    while(i<input_intervals.size()){
        output.push_back(input_intervals[i]);
        i++;
    }
    return output;
}
int main(){
     int n;
    cin>>n;
    vector<vector<int>>input_intervals(n, vector<int>(2, 0));
    vector<int>new_interval(2,0);
    for(int i=0;i<n;i++){
        cin>>input_intervals[i][0]>>input_intervals[i][1];
    }
    cin>>new_interval[0]>>new_interval[1];
    vector<vector<int>>output=merge_intervals(input_intervals,new_interval);

    for(int i=0;i<output.size();i++){
        cout<<output[i][0]<<" "<<output[i][1]<<endl;
    }
    
    return 0;
    
}