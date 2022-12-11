#include<bits/stdc++.h>
using namespace std;

int main(){
    string line;
    ifstream myfile ("input_aoc10");
    int v,addend,new_sum;
    vector<int>record;
    record.push_back(1);
    int c=0;


    if (myfile.is_open()){
        while (getline(myfile,line)){
            if(line.substr(0,4) == "addx"){
                addend=stoi(line.substr(5));
                record.push_back(record[record.size()-1]);
                new_sum=record[record.size()-1]+addend;
                record.push_back(new_sum);
            }
            else{
                record.push_back(record[record.size()-1]);
            }        
        } 
        myfile.close();    
    }
    else 
        cout<<"unable to open file";

    cout<< 20*record[19]+60*record[59]+100*record[99]+140*record[139]+180*record[179]+220*record[219];

    for(int j=0;j<240;j++){
        if(record[j]-1==c || record[j] == c || record[j]+1 == c)
            cout<<"#";
        else cout<<".";
        c++;
        if(c==40){
            cout<<endl;
            c=0;
        }

    }

    return 0;
        
}