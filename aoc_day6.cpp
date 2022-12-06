#include<bits/stdc++.h>
using namespace std;

int main(){
    string input,message;
    int search_window;
    cin>>input>>search_window;
    unordered_set<char>temp;

    for(int i=0;i<input.length();i++){
        message=input.substr(i,search_window);
        for(int j=0;j<search_window;j++){
            if(temp.find(message[j]) == temp.end() && j==search_window-1){
                cout<< i+search_window;
                return 0;
            }
            else if (temp.find(message[j]) != temp.end())
                break;

            else temp.insert(message[j]);
        }
        temp.clear();
    }
    cout << "message not found";
    return 0;
}