#include "cpp_utilities.h"

int calc_moves(std::string starting_node,std::string directions,std::unordered_map<std::string,std::vector<std::string>> nav_map){
    int moves=0;
    for(int i=0;true;i++){
        moves++;
        // std::cout<<"move "<<moves<<endl;
        int direction_index=i%directions.length();
        // std::cout<<direction_index<<endl;
        if(directions[direction_index]=='L')
            starting_node=nav_map[starting_node][0];
        else
            starting_node=nav_map[starting_node][1];
        // std::cout<< starting_node<<endl;
        if(starting_node[2]=='Z')
            break;
    }
    return moves;
}
int main(){
    std::string line,starting_node="AAA",directions="";
    std::ifstream myfile ("input_aoc8");
    std::unordered_map<std::string,std::vector<std::string>> nav_map;
    int moves=0;
    if (myfile.is_open()){
        while (getline(myfile,line)){
            if(line !="" && line.find('(') == std::string::npos){
                directions+=line;
            }
            else if (line !=""){
                std::string node=line.substr(0,3);
                std::string left_node=line.substr(7,3);
                std::string right_node=line.substr(12,3);
                nav_map[node].push_back(left_node);
                nav_map[node].push_back(right_node);
            }
        }
        myfile.close();
    }
    else{
        std::cout<<"unable to open file";
    }

    std::vector<int> moves_for_all_nodes;
    for(auto it: nav_map){
        if(it.first[2]=='A'){
            moves_for_all_nodes.push_back(calc_moves(it.first,directions,nav_map));
        }
    }
    // for(auto it: moves_for_all_nodes){
    //     std::cout<< it<< "   ";
    // }
    // int max_moves=*max_element(moves_for_all_nodes.begin(),moves_for_all_nodes.end());
    unsigned long LCM_of_moves;
    // for(LCM_of_moves=max_moves;true;LCM_of_moves++){
    //     int j;
    //     for(j=0;j<moves_for_all_nodes.size();j++){
    //         if(LCM_of_moves % moves_for_all_nodes[j] !=0)
    //             break;
    //     }
    //     if(j==moves_for_all_nodes.size())
    //         break;
    // }
    LCM_of_moves=moves_for_all_nodes[0];
    for(auto it: moves_for_all_nodes)
        LCM_of_moves = std::lcm(LCM_of_moves,it);

    std::cout<<LCM_of_moves;
    return 0;
}
// int main(){
//     std::string line,starting_node="AAA",directions="";
//     std::ifstream myfile ("input_aoc8");
//     std::unordered_map<std::string,std::vector<std::string>> nav_map;
//     int moves=0;
//     if (myfile.is_open()){
//         while (getline(myfile,line)){
//             if(line !="" && line.find('(') == std::string::npos){
//                 directions+=line;
//             }
//             else if (line !=""){
//                 std::string node=line.substr(0,3);
//                 std::string left_node=line.substr(7,3);
//                 std::string right_node=line.substr(12,3);
//                 nav_map[node].push_back(left_node);
//                 nav_map[node].push_back(right_node);
//             }
//         }
//         myfile.close();
//     }

//     else{
//         std::cout<<"unable to open file";
//     }
//     // std::cout<<starting_node<<endl;
//     // std::cout<< directions<<endl;
//     // for(auto it: nav_map){
//     //     std::cout<< it.first<<"   ";
//     //     for(auto jt: it.second)
//     //         std::cout<<jt<<"  ";
//     //     std::cout<<endl;
//     // }
//     // std::cout<<endl;
//     //std::cout<<"directions  "<<directions<<"  length  "<<directions.length()<<endl;
//     for(int i=0;true;i++){
//         moves++;
//         // std::cout<<"move "<<moves<<endl;
//         int direction_index=i%directions.length();
//         // std::cout<<direction_index<<endl;
//         if(directions[direction_index]=='L')
//             starting_node=nav_map[starting_node][0];
//         else
//             starting_node=nav_map[starting_node][1];
//         // std::cout<< starting_node<<endl;
//         if(starting_node=="ZZZ")
//             break;
//     }
//     std::cout<<moves;
//     return 0;
// }