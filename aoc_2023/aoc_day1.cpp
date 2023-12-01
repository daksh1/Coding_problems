#include<bits/stdc++.h>
using namespace std;

int main(){
    string line;
    ifstream myfile ("input_aoc1");
    int sum_i,sum_j,i,j;
    int final_sum=0;
    int val,max_pos,min_pos;
    unordered_map<string,int>number_list;
    number_list["one"]=1;
    number_list["two"]=2;
    number_list["three"]=3;
    number_list["four"]=4;
    number_list["five"]=5;
    number_list["six"]=6;
    number_list["seven"]=7;
    number_list["eight"]=8;
    number_list["nine"]=9;
    
    if (myfile.is_open()){
        while (getline(myfile,line)){
                max_pos=-1,min_pos=1000;
                for(i=0;i<line.length();i++){
                    if(isdigit(line[i])){
                        sum_i= (int(line[i])-48);
                        break;
                    }
                }
                for(auto it:number_list){
                    int pos = line.find(it.first);
                    if(pos != string::npos){
                        if(pos<min_pos){
                            min_pos=pos;
                            val=it.second;
                        }
                    }
                }
                if(min_pos<i)
                    sum_i = val;

                for(j=line.length()-1;j>=0;j--){
                    if(isdigit(line[j])){
                        sum_j=int(line[j])-48;
                        break;
                    }
                }
                for(auto it:number_list){
                    int pos = line.rfind(it.first);
                    if(pos != string::npos){
                        if(pos>max_pos){
                            max_pos=pos;
                            val=it.second;
                        }
                    }
                }
                if(max_pos>j)
                    sum_j=val;
                //cout<<sum_i*10+sum_j<<endl;
               final_sum+= sum_i*10 + sum_j; 
        }
        
        myfile.close();
    }
    else{
        cout<<"unable to open file";
    }

    cout<<final_sum;
    return 0;
    

}