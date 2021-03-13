#include<bits/stdc++.h>
using namespace std;
int word_machine(string s){
    int i=0,pos;
    stack<int>st;
    while(i<s.length() && pos>0){
        string word="";
        pos=s.find(" ",i);
        if(pos==-1) word=s.substr(i);
        else word=s.substr(i,pos-i);
        cout<<word<<" ";
        if(word=="DUP"){
            if(st.empty()) return -1;
            st.push(st.top());
        }
        else if(word=="POP"){
            if(st.empty()) return -1;
            st.pop();
        }
        else if(word=="+"){
            if(st.size()<2) return -1;
            int a=st.top(); st.pop();
            int b=st.top(); st.pop();
            st.push(a+b);
        }
        else if(word=="-"){
            if(st.size()<2) return -1;
            int a=st.top(); st.pop();
            int b=st.top(); st.pop();
            st.push(a-b);
        }  

        else st.push(stoi(word));  
        i=pos+1;
    }

    return st.top();
}

int main(){
    string s="13 DUP 4 POP 5 DUP + DUP + -";
    //getline(cin,s);
    int result=word_machine(s);
    cout<<result;
    return 0;
}

