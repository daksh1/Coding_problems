#include<bits/stdc++.h>
using namespace std;

vector<string> split_string_at_given_symbol(string str, string symbol,int start){
    vector<string> list_of_split_strings;
    int end = str.find(symbol,start);
    while(end != string::npos){
        string sub_str = str.substr(start,end-start);
        list_of_split_strings.push_back(sub_str);
        start = end+2;
        end = str.find(symbol,start);
    }
    list_of_split_strings.push_back(str.substr(start));
    return list_of_split_strings;
}

int main(){
    string line;
    ifstream myfile ("input_aoc2");
    unordered_map<string,int> color_count;
    unordered_map<int,int> power_set_of_games;
    int red=12,green=13,blue=14, sum_of_games=0,sum_of_power_set_of_games=0;
    vector<string>string_split_at_semicolon;
    vector<string>string_split_at_comma;
    
    if (myfile.is_open()){
        int game_num=0;
        while (getline(myfile,line)){
            game_num++;
            int round =0;
            int start = line.find(":")+2;
            string_split_at_semicolon = split_string_at_given_symbol(line,";",start);
            bool condition_met=true;
//            color_count["red"]=1;
//            color_count["blue"]=1;
//            color_count["green"]=1;
            for(auto it: string_split_at_semicolon){
                string_split_at_comma = split_string_at_given_symbol(it,",",0);
                for(auto it:string_split_at_comma){
                    color_count["red"]=0;
                    color_count["blue"]=0;
                    color_count["green"]=0;
                    int pos_of_space = it.find(" ");
                    int num_of_cubes = stoi(it.substr(0,pos_of_space));
                    string cube_color = it.substr(pos_of_space+1);
//                    if(num_of_cubes > color_count[cube_color])
//                        color_count[cube_color]=num_of_cubes;
                    color_count[cube_color]=num_of_cubes;
                    if(color_count["red"]>red || color_count["blue"]>blue || color_count["green"]>green){
                        condition_met=false;
                        break;
                    }

                }
                if(!condition_met)
                    break;

                else round++;
            }
            if(round == string_split_at_semicolon.size())
                sum_of_games+=game_num;
//            power_set_of_games[game_num]=color_count["red"]*color_count["blue"]*color_count["green"];
        }
        myfile.close();
    }

    else{
        cout<<"unable to open file";
    }
    cout<< sum_of_games;
//    for(auto it: power_set_of_games){
//        sum_of_power_set_of_games+=it.second;
//    }
//    cout<<sum_of_power_set_of_games;

    return 0;
}
