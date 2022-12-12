#include<bits/stdc++.h>
using namespace std;

int main(){
    string line,dir_name;
    ifstream myfile ("input_aoc7");
    stack<string>last_dir;
    unordered_map<string,vector<string>>dir_tree;
    unordered_map<string,int>dir_size;
    int file_size;
    bool first_entry=true;
    ofstream debg ("output_file");

    if (myfile.is_open()){
        while (getline(myfile,line)){
            if(line.substr(0,4) == "$ cd" && line.substr(0,7) != "$ cd .."){
                
                if(first_entry){ 
                    dir_name=line.substr(5);
                    first_entry=false;
                }
                else dir_name=last_dir.top()+line.substr(5);

                //if(dir_tree.find(dir_name) == dir_tree.end() )
                //dir_tree[dir_name];             
                last_dir.push(dir_name);
                //debg<<last_dir.top();
                //file_size=0;
            }
            else if(line.substr(0,3) == "dir"){

                dir_name= last_dir.top()+line.substr(4);
                dir_tree[last_dir.top()].push_back(dir_name);
                //cout<<dir_name<<endl;
                //debg<<dir_name<<endl;

            }
            else if (line.substr(0,7) == "$ cd .."){
                last_dir.pop();
                //debg<<last_dir.top()<<endl;
            }

            else if(line.substr(0,4)=="$ ls") file_size=0;
            
            else {
                file_size = stoi(line.substr(0,line.find(" ")));
                dir_size[last_dir.top()]+=file_size;
            }
               
        } 
        myfile.close();    
    }

    else 
        cout<<"unable to open file";

    for(auto i: dir_tree){
        //cout<< i.first<<endl;
        for(int j=0;j<dir_tree[i.first].size();j++){
            dir_size[i.first]+=dir_size[dir_tree[i.first][j]];
        }
    }
    
    int sum=0;
    for(auto i:dir_size){
        //cout<< i.first <<endl;
        if(i.second <=100000)
            sum+=i.second;
    }

    cout<<sum<<endl;
    return 0;
        
}