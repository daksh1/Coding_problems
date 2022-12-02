#include<bits/stdc++.h>
using namespace std;

int main(){
    string line;
    ifstream myfile ("input_aoc2");
    unordered_map<char,char>strategy;
    unordered_map<char,char>strategy2;
    unordered_map<char,int>val;
    // part 1
    // val['X']=1;
    // val['Y']=2;
    // val['Z']=3;
    // strategy['A']='Y';
    // strategy['B']='Z';
    // strategy['C']='X';
    // strategy2['X']='A';
    // strategy2['Y']='B';
    // strategy2['Z']='C';
    val['A']=1;
    val['B']=2;
    val['C']=3;
    strategy['A']='B';
    strategy['B']='C';
    strategy['C']='A';
    strategy2['A']='C';
    strategy2['B']='A';
    strategy2['C']='B';
    int sum =0;
    if(myfile.is_open()){
        while (getline(myfile,line)){
        //part 1
        //    if(strategy[line[0]]==line[2]){
        //         sum+=val[line[2]]+6;
        //    }
        //    else if (line[0]==strategy2[line[2]]){
        //         sum+=val[line[2]]+3;
        //    }
        //    else sum+=val[line[2]];  
            if(line[2]=='X'){
                sum+=val[strategy2[line[0]]];
            }
            else if(line[2]=='Y'){
                sum+=val[line[0]]+3;
            }
            else sum+=val[strategy[line[0]]]+6;

        }
        
        myfile.close();
    }
    else cout<<"unable to open file";
    cout<<sum;
    return 0;
}