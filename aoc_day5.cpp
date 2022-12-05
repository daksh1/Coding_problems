#include<bits/stdc++.h>
using namespace std;

vector<stack<char>>input(){
    string line;
    ifstream myfile ("input_aoc5");
    vector<string>input;
    vector<stack<char>>stacks_of_crates(10);
    if (myfile.is_open()){
        while (getline(myfile,line)){
            if(line[0] != 'm' && line.length() != 0 && line[1] != '1' ){
                string s = "";
                for(int i=1;i<line.length();i+=4){
                    s+=line[i];
                }
                input.push_back(s);
            }
            else if (line.length() == 0) break;
        }
        myfile.close();  
    }
    else 
        cout<<"unable to open file";
    
    for(int i=input.size()-1;i>=0;i--){
        for(int j=0;j<input[i].length();j++){
            if(input[i][j] != ' '){ 
                stacks_of_crates[j+1].push(input[i][j]);
            }
        }
    }
    return stacks_of_crates;
}



int main(){
    
    string line;
    ifstream myfile ("input_aoc5");
    vector<stack<char>> stacks_of_crates = input();
    int crates_to_be_moved, stack_number_to_move_from, stack_number_to_move_to,pos;
    stack<char>temp;
    char crate;
    if (myfile.is_open()){
        while (getline(myfile,line)){
            if(line[0] == 'm'){
                pos = line.find_first_of("from");
                crates_to_be_moved = stoi(line.substr(5,pos-6));
                stack_number_to_move_from = stoi(line.substr((line.find("from"))+5,1));
                stack_number_to_move_to = stoi(line.substr((line.find("to"))+3));
                
                if(crates_to_be_moved == 1){
                    for(int i=0;i<crates_to_be_moved;i++){
                        if (!(stacks_of_crates[stack_number_to_move_from]).empty()){
                            crate = stacks_of_crates[stack_number_to_move_from].top();
                            stacks_of_crates[stack_number_to_move_from].pop();
                        }
                        stacks_of_crates[stack_number_to_move_to].push(crate);
                    }    
                }
                //part 2
                else{
                    
                    for(int i=0;i<crates_to_be_moved;i++){
                        crate = stacks_of_crates[stack_number_to_move_from].top();
                        stacks_of_crates[stack_number_to_move_from].pop();
                        temp.push(crate);
                    }

                    for(int i=0;i<crates_to_be_moved;i++){
                        crate = temp.top();
                        temp.pop();
                        stacks_of_crates[stack_number_to_move_to].push(crate);
                    }
                    temp = {};
                }
                
            }    
            
        }  
        myfile.close(); 
           
    }
    else 
        cout<<"unable to open file";

    string s="";
    for(int i=0;i<10;i++){
        if (!(stacks_of_crates[i+1].empty()))
            s+=stacks_of_crates[i+1].top();
    }
    cout<< s;


    return 0;
        
}