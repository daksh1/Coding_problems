#include<bits/stdc++.h>
using namespace std;




int main(){
    string line;
    ifstream myfile ("input_aoc4");
    vector<string> string_split,stpring_split1,string_split2;
    unordered_set<int>p,q;
    map<int,int>part2;
    map<int,int>card_matches;
    int sum=0,game=0;
    if (myfile.is_open()){
        while (getline(myfile,line)){
            game++;
            int start_pos= line.find(":",0);
            while(!(isdigit(line[start_pos])))
                start_pos++;
            string sub_str = line.substr(start_pos);
            int pos = sub_str.find("|");
            string lottery_nums = sub_str.substr(0,pos);
            string nums_have = sub_str.substr(pos+2, sub_str.length()-pos-2);
            //cout<< lottery_nums << "    "<<nums_have<<endl;
            for(int i=0;i<lottery_nums.length();i++){
                string s="";
                while(isdigit(lottery_nums[i])){
                    s+=lottery_nums[i];
                    i++;
                }
                if(s!=""){
                    int num = stoi(s); 
                    p.insert(num);
                }
            }
            
            for(int i=0;i<nums_have.length();i++){
                string s="";
                while(isdigit(nums_have[i])){
                    s+=nums_have[i];
                    i++;
                }
                if(s!=""){
                    int num = stoi(s); 
                    q.insert(num);
                }

            }
            int k=0;
            for(auto it:q){
                if(p.find(it) != p.end()){
                    //cout<<it<<endl;
                    k++;
                }
            }                
            card_matches[game]=k;
            cout<< "game"<<game<<"  matches"<<k<<endl;
            sum+=pow(2,k-1);
            cout<<sum<<endl;
            p.clear();
            q.clear();
        }

        myfile.close();
    }

    else{
        cout<<"unable to open file";
    }
    for(int i=0;i<game;i++){
        part2[i+1]=1;
    } 
    for(auto it: card_matches){
        for(int i=0;i<it.second;i++){
            part2[it.first+i+1]+=part2[it.first];
        }
    }
    int part2_sum=0;
    for(auto it: part2){
       part2_sum+=it.second; 
    }

    cout<<part2_sum; 
    //cout<< sum;
    return 0;
}