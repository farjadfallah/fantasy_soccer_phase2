#include "MatchResult.hpp"
#include "MagicNumbers.hpp"
#include <iostream>
#include <string>
#include "Exceptions.hpp"

using namespace std;



MatchResult::MatchResult(string _first_team, string _second_team, int _first_team_goals,int _second_team_goals,
            vector<string> _injured_players_list, vector<string> _yellow_cards_list, vector<string> _red_card_list,
            vector<string> _first_team_lineup, vector<string> _second_team_linup, vector<string> _scorers,
            vector<string> _assists, vector<string> _own_goals){
    first_team_name = _first_team;
    second_team_name = _second_team;
    first_team_goals = _first_team_goals;
    second_team_goals = _second_team_goals;
    injured_players_list = _injured_players_list;
    yellow_cards_list = _yellow_cards_list;
    red_card_list = _red_card_list;
    first_team_lineup = _first_team_lineup;
    second_team_linup = _second_team_linup;
    scorers = _scorers;
    assists = _assists;
    own_goals = _own_goals;
}

string MatchResult::first_team(){
    return first_team_name;
}

string MatchResult::second_team(){
    return second_team_name;
}

int MatchResult::first_team_points(){
    if(first_team_goals > second_team_goals){
        return WON;
    }
    if(first_team_goals < second_team_goals){
        return LOST;
    }
    return DRAW;
}
int MatchResult::second_team_points(){
    if(first_team_goals > second_team_goals){
        return LOST;
    }
    if(first_team_goals < second_team_goals){
        return WON;
    }
    return DRAW;
}
int MatchResult::first_team_goals_for(){
    return first_team_goals;
}
int MatchResult::second_team_goals_for(){
    return second_team_goals;
}
int MatchResult::first_team_goals_against(){
    return second_team_goals;
}
int MatchResult::second_team_goals_against(){
    return first_team_goals;
}

void MatchResult::print(){
    cout << "first team line up: " << endl;
    for(string tmp : first_team_lineup){
        cout << "  " << tmp ; 
    }
    cout << endl << "second team lineup:" << endl;
    for(string tmp : second_team_linup){
        cout << "  " << tmp ; 
    }
    cout << endl << "red cards: " << endl;
    for(string tmp : red_card_list){
        cout << "  " << tmp ; 
    }
    cout << endl << "yellow cards: " << endl;
    for(string tmp : yellow_cards_list){
        cout << "  " << tmp ; 
    }
    cout << endl << "injured: " << endl;
    for(string tmp : injured_players_list){
        cout << "  " << tmp ; 
    }
    cout << endl << "scorers: " << endl;
    for(string tmp : scorers){
        cout << "  " << tmp ; 
    }
    cout << endl << "assists: " << endl;
    for(string tmp : assists){
        cout << "  " << tmp ; 
    }
    cout << endl << "own_Goals: " << endl;
    for(string tmp : own_goals){
        cout << "  " << tmp ; 
    }
    cout << endl;
}