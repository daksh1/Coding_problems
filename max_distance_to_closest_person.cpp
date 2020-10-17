#include<bits/stdc++.h>
using namespace std;
int max_dist_closest_person(vector<int> seats){
    int previous=-1,result=0;
    for(int i=0;i<seats.size();i++){
        if(seats[i]){
            //if previous is less than 0, then max distance is the distance from start to the current person i.e. i
            //otherwise, max of result and (current person -previous person)/2
            result= previous<0?i:max(result,(i-previous)/2);
            previous=i;
        }
    }
    int last_index=seats.size()-1;
    //if last seat is vacant, calculate its distance from last occupied position, compare with result and return max
    return max(result,last_index-previous);
}
int main(){
    int size,element;
    vector<int>seats;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>element;
        seats.push_back(element);
    }
    cout<< max_dist_closest_person(seats);
    return 0;
}