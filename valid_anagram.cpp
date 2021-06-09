#include<bits/stdc++.h>
using namespace std;

bool valid_anagrams(string s, string t){
    if(s.length() != t.length()) 
        return false;
    unordered_map<char,int> m;
    for(char c:s)
        m[c]++;

    for(char c:t)
        m[c]--;
    
    for(char c:s)
        if(m[c]!=0)
            return false;
    
    return true;

}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<valid_anagrams(s,t);
    return 0;
}