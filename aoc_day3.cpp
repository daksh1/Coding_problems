#include<bits/stdc++.h>
using namespace std;

int main(){
    string line;
    ifstream myfile ("input_aoc3");
    int sum = 0;
    string first_half;
    string second_half;
    unordered_map<char,int>weight;
    vector<string>rucksacks;
    int i=1;
    for(char c='a';c<='z';c++){
        weight[c]=i;
        i++;
    }
    for(char c='A';c<='Z';c++){
        weight[c]=i;
        i++;
    }
    if (myfile.is_open()){
        while (getline(myfile,line)){
            /* part 1
            first_half=line.substr(0,line.length()/2);
            second_half=line.substr(line.length()/2,line.length()/2);
            for(int i=0; i<first_half.length();i++){
                if(second_half.find_first_of(first_half[i]) != string::npos){
                    sum+=weight[first_half[i]];
                    break;
                }
            }*/
            rucksacks.push_back(line);        
        }     
    }
    else 
        cout<<"unable to open file";
    
    for (int i=0;i<rucksacks.size();i=i+3){
        for(int j=0;j<rucksacks[i].length();j++){
            if(rucksacks[i+1].find_first_of((rucksacks[i][j])) != string::npos && rucksacks[i+2].find_first_of((rucksacks[i][j])) != string::npos){
                sum+=weight[rucksacks[i][j]];
                break;
            }
        }
    }

    cout <<sum;
    return 0;
        
}
   
