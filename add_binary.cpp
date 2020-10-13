#include<bits/stdc++.h>
using namespace std;
// a very elegant solution without using a bunch of if -else
string add(string a, string b){
    int i=a.size()-1, j=b.size()-1,c=0;
    string result="";
    while(i>=0 || j>=0 || c){
        c+= i>=0 ?a[i--]-'0':0;
        c+= j>=0 ?b[j--]-'0':0;
        result=char(c%2 + '0') + result;  // using airthmetic with char uses its ASCII value
        c=c/2;
    }
    return result;
}
int main(){
    string a,b;
    cin>>a>>b;
    cout<< add(a,b);
    return 0;
}