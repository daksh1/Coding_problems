#include<bits/stdc++.h>
using namespace std;

int calc_max_profit(vector<int> &prices){
    //kadane algorithm
    int difference=0,result=0;
    for(int i=1;i<prices.size();i++){
        difference=max(0,difference+prices[i]-prices[i-1]);      //pretty straighforward, difference of each pair is being
        result=max(result,difference);                           //calculated here, and if its -ve, reset to 0
    }                                                            //result is storing max difference until present
    return result;
}
int main(){
    int size,element;
    cin>>size;
    vector<int>prices;
    for(int i=0;i<size;i++){
        cin>>element;
        prices.push_back(element);
    }
    cout<<calc_max_profit(prices);
    return 0;
}