#include<bits/stdc++.h>
using namespace std;

int main(){
    string line;
    ifstream myfile ("input_aoc4");
    int pairs = 0;
    int low1,high1,low2,high2,pos;
    string first_range,second_range;


    if (myfile.is_open()){
        while (getline(myfile,line)){
            pos=line.find(",");
            first_range=line.substr(0,pos);
            second_range=line.substr(pos+1);
            low1=stoi(first_range.substr(0,first_range.find("-")));
            high1=stoi(first_range.substr(first_range.find("-")+1));
            low2=stoi(second_range.substr(0,second_range.find("-")));
            high2=stoi(second_range.substr(second_range.find("-")+1));
            // if((low2 >= low1 and high2 <= high1) or (low1 >= low2 and high1 <= high2))
            //     pairs++;
            pairs++;
            if (low2 > high1 or low1 > high2)
                pairs--;
            
               
        }     
    }
    else 
        cout<<"unable to open file";
    cout<<pairs;

    return 0;
        
}