#include<bits/stdc++.h>
using namespace std;

string mulitply_strings(string num1,string num2){
    if(num1=="0" || num2=="0") return "0";
    int l1=num1.length(),l2=num2.length();
    vector<int>res(l1+l2-1,0);
    string s="";
    for(int i=l1-1;i>=0;i--)
        for(int j=l2-1;j>=0;j--)
            res[i+j]+=(num1[i]-'0') * (num2[j]-'0');

    for(int i=res.size()-1;i>0;i--){
        res[i-1]+=res[i]/10;
        res[i]=res[i]%10;
    }

    if(res[0]/10){
        s+=char('0'+res[0]/10);
        res[0]=res[0]%10;
    }
    for(auto i:res)
        s+=char('0'+i);

    return s;

}
int main(){
    string num1,num2;
    cin>>num1>>num2;
    string result= mulitply_strings(num1,num2);
    cout<<result;
    return 0;
}