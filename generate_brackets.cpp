#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void generate_paranthesis(int open, int close, int max, vector<string> &array_of_strings, string string_of_brackets){
    if(string_of_brackets.length()==max*2){
        array_of_strings.push_back(string_of_brackets);
        //cout<<string_of_brackets<<endl;
        return;
    }
    
    if(open<max)
        generate_paranthesis(open+1,close,max,array_of_strings,string_of_brackets+"(");
    
    if(close<open)
        generate_paranthesis(open,close+1,max,array_of_strings,string_of_brackets+")");
            
}


int main(){
    int n;
    cin>>n;
    vector<string>array_of_strings;
    string string_of_brackets="";
    generate_paranthesis(0,0,n,array_of_strings,string_of_brackets);
    for(int i=0;i<array_of_strings.size();i++)
        cout<<array_of_strings[i]<<endl;

        
    return 0;

}

