#include<bits/stdc++.h>
using namespace std;

string decode_string(string s){
    stack<string>characters;
    stack<int>numbers;
    string res="";
    int num=0;
    for(char c: s){
        if(isalpha(c)) 
            res=res+c;

        else if(isdigit(c)){
            num=num*10+(c-'0');
        }

        else if(c=='['){
            characters.push(res);
            numbers.push(num);
            res="";
            num=0;
        }

        else if(c==']'){
            string temp=res;
            for(int i=0;i<numbers.top()-1;i++){
                res+=temp;
            }
            res=characters.top()+res;
            characters.pop();
            numbers.pop();
        }
    }
    return res;
}
int main(){
    string s;
    cin>>s;
    cout<< decode_string(s);
    return 0;
}