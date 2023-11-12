#include<bits/stdc++.h>
using namespace std;



int main(){
    string line,dir_name;
    ifstream myfile ("input_aoc7");
    stack<string>current_dir,dir_stack;
    unordered_map<string,vector<string>>dir_tree;
    unordered_map<string,int>dir_size;
    int file_size;
    int sum=0;
    bool first_entry=true;

    if (myfile.is_open()){
        while (getline(myfile,line)){
            if(line.substr(0,4) == "$ cd" && line.substr(0,7) != "$ cd .."){
                
                if(first_entry){ 
                    dir_name=line.substr(5);
                    first_entry=false;
                }
                else {
                    dir_name=current_dir.top()+line.substr(5);
                }
                dir_name = dir_name.substr(0,dir_name.length()-1);  //removing carriage return (\r) at the end 
                current_dir.push(dir_name);
                dir_stack.push(dir_name);
            }
            else if(line.substr(0,3) == "dir"){
                dir_name= current_dir.top()+line.substr(4);
                dir_name= dir_name.substr(0,dir_name.length()-1);
                dir_tree[current_dir.top()].push_back(dir_name);

            }
            else if (line.substr(0,7) == "$ cd .."){
                current_dir.pop();
            }

            else if(line.substr(0,4)=="$ ls") file_size=0;
            
            else {
                file_size = stoi(line.substr(0,line.find(" ")));
                dir_size[current_dir.top()]+=file_size;
            }
               
        } 
        myfile.close();    
    }

    else 
        cout<<"unable to open file";
    
    while(dir_stack.size() != 0){
        for(int i=0; i < dir_tree[dir_stack.top()].size();i++){
            dir_size[dir_stack.top()]+= dir_size[dir_tree[dir_stack.top()][i]];
        }
        dir_stack.pop();
    }

    // variables for part 2
    int unused_space = 70000000 - dir_size["/"]; 
    int additional_space_needed = 30000000 - unused_space;
    int smallest_dir_size_to_delete_for_update = 700000001;

    for(auto i:dir_size){
        /* part 1
        if(i.second <=100000)
            sum+=i.second; */
        if(i.second >= additional_space_needed){
            smallest_dir_size_to_delete_for_update = min(smallest_dir_size_to_delete_for_update,i.second);
       }
    }
    //cout<<sum<<endl;
    cout<<smallest_dir_size_to_delete_for_update;
    return 0;
        
}
