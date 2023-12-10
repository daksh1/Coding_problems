#include<bits/stdc++.h>
using namespace std;

void calc_rank(string str,unordered_map<string,int>& hand_to_rank){
    
}
void sort_hands_of_same_type(vector<char> order,vector<string> &hand_type_to_hands){
    for(int i=0;i<5;i++){
        for(int j=0;j<hand_type_to_hands.size();j++){
            for(int k=j+1;k<hand_type_to_hands.size();k++){
                int p1=find(order.begin(),order.end(),hand_type_to_hands[j][i])-order.begin();
                int p2=find(order.begin(),order.end(),hand_type_to_hands[k][i])-order.begin();
                if(p2>p1 && hand_type_to_hands[j].substr(0,i)== hand_type_to_hands[k].substr(0,i)){
                    swap(hand_type_to_hands[j],hand_type_to_hands[k]);
                }
            }
        }
    }
}

// int main(){
//     string line;
//     ifstream myfile ("input_aoc7");
//     string hand;
//     unordered_map<string,int> hand_to_bid,hand_to_rank;
//     unordered_map<string,vector<string>> hand_type_to_hands;
//     vector<char> order= {'A','K','Q','J','T','9','8','7','6','5','4','3','2','1'};
//     int bid,rank=1,total_winnings=0;
//     if (myfile.is_open()){
//         while (getline(myfile,line)){
//             hand=line.substr(0,5);
//             string sorted_hand=hand;
//             sort(sorted_hand.begin(),sorted_hand.end());
//             bid=stoi(line.substr(6,line.length()-6)); 
//             hand_to_bid[hand]=bid;
//             if(sorted_hand[0]==sorted_hand[4]){
//                 hand_type_to_hands["Five of a kind"].push_back(hand);
//                 continue;
//             }
            
//             int identical_cards,pairs=0,three_alike=0;
//             for(int i=0;i<sorted_hand.length();i++){
//                 identical_cards=1;
//                 while(sorted_hand[i]==sorted_hand[i+1]){
//                     identical_cards++;
//                     i++;
//                 }
//                 if(identical_cards==4){
//                     hand_type_to_hands["Four of a kind"].push_back(hand);
//                     break;
//                 }
//                 else if (identical_cards==3){
//                     three_alike++;
//                 }
//                 else if(identical_cards==2){
//                     pairs++;
//                 }
//             }
//             if(identical_cards==4)
//                 continue; 
//             if(three_alike==1 && pairs==1){
//                 hand_type_to_hands["Full house"].push_back(hand);
//             }
//             else if(three_alike ==1){
//                 hand_type_to_hands["Three of a kind"].push_back(hand);   
//             }
//             else if(pairs==2){
//                 hand_type_to_hands["Two pair"].push_back(hand);
//             }
//             else if(pairs==1){
//                 hand_type_to_hands["One pair"].push_back(hand);
//             }
//             else hand_type_to_hands["High card"].push_back(hand);
//             // cout<< hand<< "   "<< bid<<endl;

//         }
//         myfile.close();
//     }

//     else{
//         cout<<"unable to open file";
//     }
//     for(auto it: hand_type_to_hands){
//         sort_hands_of_same_type(order,it.second);
//         hand_type_to_hands[it.first]=it.second;
//     }

//     for(auto jt: hand_type_to_hands["High card"])
//         hand_to_rank[jt]=rank++;
//     for(auto jt: hand_type_to_hands["One pair"])
//         hand_to_rank[jt]=rank++;
//     for(auto jt: hand_type_to_hands["Two pair"])
//         hand_to_rank[jt]=rank++;
//     for(auto jt: hand_type_to_hands["Three of a kind"])
//         hand_to_rank[jt]=rank++;
//     for(auto jt: hand_type_to_hands["Full house"])
//         hand_to_rank[jt]=rank++;
//     for(auto jt: hand_type_to_hands["Four of a kind"])
//         hand_to_rank[jt]=rank++;
//     for(auto jt: hand_type_to_hands["Five of a kind"])
//         hand_to_rank[jt]=rank++;

//     // for(auto it: hand_type_to_hands){
//     //     cout<< it.first<<"  ";
//     //     for(auto jt:it.second){
//     //         cout<< jt<< "  ";
//     //     }
//     //     cout<<endl;
//     // }
    
//     for(auto it: hand_type_to_hands){
//         for(auto jt:it.second){
//             total_winnings+=hand_to_bid[jt]*hand_to_rank[jt];
//         }
//     }
//     cout<< total_winnings;
//     return 0;
// }
//part 2
int find_num_of_jokers_in_hand(string hand){
    int num_of_jokers_in_hand=0;
    for(auto it:hand){
        if(it=='J')
            num_of_jokers_in_hand++;
    }
    return num_of_jokers_in_hand;
}

int main(){
    string line;
    ifstream myfile ("input_aoc7");
    string hand;
    unordered_map<string,int> hand_to_bid,hand_to_rank;
    unordered_map<string,vector<string>> hand_type_to_hands;
    vector<char> order= {'A','K','Q','T','9','8','7','6','5','4','3','2','1','J'};
    int bid,num_of_jokers_in_hand,rank=1,total_winnings=0;
    if (myfile.is_open()){
        while (getline(myfile,line)){
            hand=line.substr(0,5);
            bid=stoi(line.substr(6,line.length()-6)); 
            hand_to_bid[hand]=bid;
            num_of_jokers_in_hand=find_num_of_jokers_in_hand(hand);
            string sorted_hand=hand;
            sort(sorted_hand.begin(),sorted_hand.end());
            if(sorted_hand[0]==sorted_hand[4]){
                hand_type_to_hands["Five of a kind"].push_back(hand);
                continue;
            }
            
            int identical_cards,pairs=0,three_alike=0;
            for(int i=0;i<sorted_hand.length();i++){
                identical_cards=1;
                while(sorted_hand[i]==sorted_hand[i+1]){
                    identical_cards++;
                    i++;
                }
                if(identical_cards==4){
                    if(num_of_jokers_in_hand==1 || num_of_jokers_in_hand==4){
                        hand_type_to_hands["Five of a kind"].push_back(hand);
                        break;
                    }
                    hand_type_to_hands["Four of a kind"].push_back(hand); 
                    break;
                }
                else if (identical_cards==3){
                    three_alike++;
                }
                else if(identical_cards==2){
                    pairs++;
                }
            }
            if(identical_cards==4)
                continue; 
            if(three_alike==1 && pairs==1){
                if(num_of_jokers_in_hand==3 || num_of_jokers_in_hand==2)
                    hand_type_to_hands["Five of a kind"].push_back(hand);

                else hand_type_to_hands["Full house"].push_back(hand);
            }
            else if(three_alike ==1){
                if(num_of_jokers_in_hand==3 || num_of_jokers_in_hand==1)
                    hand_type_to_hands["Four of a kind"].push_back(hand);

                else hand_type_to_hands["Three of a kind"].push_back(hand);   
            }
            else if(pairs==2){
                if(num_of_jokers_in_hand==2)
                    hand_type_to_hands["Four of a kind"].push_back(hand);
                else if(num_of_jokers_in_hand==1)
                    hand_type_to_hands["Full house"].push_back(hand);
                else hand_type_to_hands["Two pair"].push_back(hand);
            }
            else if(pairs==1){
                if(num_of_jokers_in_hand==2 || num_of_jokers_in_hand==1)
                    hand_type_to_hands["Three of a kind"].push_back(hand);
                else hand_type_to_hands["One pair"].push_back(hand);
            }
            else {
                if(num_of_jokers_in_hand==1)
                    hand_type_to_hands["One pair"].push_back(hand);
                else hand_type_to_hands["High card"].push_back(hand);
            }
            // cout<< hand<< "   "<< bid<<endl;

        }
        myfile.close();
    }

    else{
        cout<<"unable to open file";
    }
    for(auto it: hand_type_to_hands){
        sort_hands_of_same_type(order,it.second);
        hand_type_to_hands[it.first]=it.second;
    }

    for(auto jt: hand_type_to_hands["High card"])
        hand_to_rank[jt]=rank++;
    for(auto jt: hand_type_to_hands["One pair"])
        hand_to_rank[jt]=rank++;
    for(auto jt: hand_type_to_hands["Two pair"])
        hand_to_rank[jt]=rank++;
    for(auto jt: hand_type_to_hands["Three of a kind"])
        hand_to_rank[jt]=rank++;
    for(auto jt: hand_type_to_hands["Full house"])
        hand_to_rank[jt]=rank++;
    for(auto jt: hand_type_to_hands["Four of a kind"])
        hand_to_rank[jt]=rank++;
    for(auto jt: hand_type_to_hands["Five of a kind"])
        hand_to_rank[jt]=rank++;

    // for(auto it: hand_type_to_hands){
    //     cout<< it.first<<"  ";
    //     for(auto jt:it.second){
    //         cout<< jt<< "  ";
    //     }
    //     cout<<endl;
    // }
    
    for(auto it: hand_type_to_hands){
        for(auto jt:it.second){
            total_winnings+=hand_to_bid[jt]*hand_to_rank[jt];
        }
    }
    cout<< total_winnings;
    return 0;
}