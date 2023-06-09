#include "MatchResult.hpp"
#include "MagicNumbers.hpp"
#include <iostream>
#include <string>
#include <memory>
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



void MatchResult::update_teams_stat(vector<shared_ptr<SoccerClub> >& teams_list){
    shared_ptr<SoccerClub> first_team = find_soccer_club_by_name(first_team_name, teams_list);
    shared_ptr<SoccerClub> second_team = find_soccer_club_by_name(second_team_name, teams_list);
    first_team->add_points(first_team_points());
    second_team->add_points(second_team_points());
    first_team->add_goals_for(first_team_goals_for());
    second_team->add_goals_for(second_team_goals_for());
    first_team->add_goals_against(first_team_goals_against());
    second_team->add_goals_against(second_team_goals_against());

}

void MatchResult::update_players_stat(vector<shared_ptr<Player> >& players_list){
    update_injured_players(players_list);
    update_red_cards(players_list);
    update_yellow_cards(players_list);
    update_players_score(players_list);
}


void MatchResult::update_players_score(vector<shared_ptr<Player> >& players_list){
    vector<double> first_team_scores(11), second_team_scores(11);
    fill_raw_scores_list(first_team_scores, second_team_scores);
    for(int i=0; i<first_team_lineup.size(); i++){
        shared_ptr<Player> selected_player = find_player_by_name(first_team_lineup[i], players_list);
        // double selected_score = to_standardized_score(first_team_scores[i]);
        // selected_player->edit_new_score(selected_score);
        cout << "name: |" << first_team_lineup[i] << "| score: " << first_team_scores[i] << endl;
    }
    for(int i=0; i<second_team_linup.size(); i++){
        shared_ptr<Player> selected_player = find_player_by_name(second_team_linup[i], players_list);
        // double selected_score = to_standardized_score(second_team_scores[i]);
        // selected_player->edit_new_score(selected_score);
        cout << "name: |" << second_team_linup[i] << "| score: " << second_team_scores[i] << endl;
    }
}

void MatchResult::add_points_to_all_team_players(std::vector<double>& team_list, double points){
    for(int i=0; i<team_list.size(); i++){
        team_list[i] += points;
    }
}


void MatchResult::fill_raw_scores_list(vector<double>& first_team_scores, vector<double>& second_team_scores){
    //first rule
    if(first_team_goals > second_team_goals){
        add_points_to_all_team_players(first_team_scores, 5);
        add_points_to_all_team_players(second_team_scores, -1);
    }
    if(first_team_goals < second_team_goals){
        add_points_to_all_team_players(first_team_scores, -1);
        add_points_to_all_team_players(second_team_scores, 5);
    }
    if(first_team_goals == second_team_goals){
        add_points_to_all_team_players(first_team_scores, 1);
        add_points_to_all_team_players(second_team_scores, 1);
    }
    
    //cleanshit
    if(second_team_goals == 0){
        first_team_scores[GK] +=5;
        for(int i = LB; i < LM; i++){
            first_team_scores[i] +=2;
        }
        for(int i = LM; i < LW; i++){
            first_team_scores[i] +=1;
        }
    }
    if(first_team_goals == 0){
        second_team_scores[GK] +=5;
        for(int i = LB; i < LM; i++){
            second_team_scores[i] +=2;
        }
        for(int i = LM; i < LW; i++){
            second_team_scores[i] +=1;
        }
    }

    //each goal scored
    for(int i=0 ; i<first_team_lineup.size(); i++){
        if(is_inside(first_team_lineup[i], scorers)){
            second_team_scores[GK] --;
            if(i >= LB && i <= RB){
                first_team_scores[i] +=4;
            }
            if(i >= LM && i <= RM){
                first_team_scores[i] +=3;
            }
            if(i >= LW && i <= ST){
                first_team_scores[i] +=3;
            }
        }
    }
    for(int i=0 ; i<second_team_linup.size(); i++){
        if(is_inside(second_team_linup[i], scorers)){
            first_team_scores[GK] --;
            if(i >= LB && i <= RB){
                second_team_scores[i] +=4;
            }
            if(i >= LM && i <= RM){
                second_team_scores[i] +=3;
            }
            if(i >= LW && i <= ST){
                second_team_scores[i] +=3;
            }
        }
    }

    //each assist done
    for(int i=0 ; i<first_team_lineup.size(); i++){
        if(is_inside(first_team_lineup[i], assists)){
            if(i >= LB && i <= RB){
                first_team_scores[i] +=3;
            }
            if(i >= LM && i <= RM){
                first_team_scores[i] +=2;
            }
            if(i >= LW && i <= ST){
                first_team_scores[i] +=1;
            }
        }
    }
    for(int i=0 ; i<second_team_linup.size(); i++){
        if(is_inside(second_team_linup[i], assists)){
            if(i >= LB && i <= RB){
                second_team_scores[i] +=3;
            }
            if(i >= LM && i <= RM){
                second_team_scores[i] +=2;
            }
            if(i >= LW && i <= ST){
                second_team_scores[i] +=1;
            }
        }
    }

    //each own goal
    for(int i=0 ; i<first_team_lineup.size(); i++){
        if(is_inside(first_team_lineup[i], own_goals)){
            first_team_scores[i] --;
        }
    }
    for(int i=0 ; i<second_team_linup.size(); i++){
        if(is_inside(second_team_linup[i], own_goals)){
            second_team_scores[i] --;
        }
    }

    //forward not scoring a goal
    for(int i=0 ; i<first_team_lineup.size(); i++){
        if(!is_inside(first_team_lineup[i], scorers)){
            if(i >= LW && i <= ST){
                first_team_scores[i] --;
            }
        }
    }
    for(int i=0 ; i<second_team_linup.size(); i++){
        if(!is_inside(second_team_linup[i], scorers)){
            if(i >= LW && i <= ST){
                second_team_scores[i] --;
            }
        }
    }

    //reducing score for goals against
    for(int i=0 ; i<first_team_lineup.size(); i++){
        if(is_inside(first_team_lineup[i], scorers)){
            if(i == RW || i == RB){
                second_team_scores[LB] --;
            }
            if(i == LW || i == LB){
                second_team_scores[RB] --;
            }
            if(i == ST || i == RCB || i == LCB){
                second_team_scores[LCB] --;
                second_team_scores[RCB] --;
            }
            if(i >= LM && i <= RM){
                second_team_scores[LM] --;
                second_team_scores[CM] --;
                second_team_scores[RM] --;
            }
        }
    }
    for(int i=0 ; i<second_team_linup.size(); i++){
        if(is_inside(second_team_linup[i], scorers)){
            if(i == RW || i == RB){
                first_team_scores[LB] --;
            }
            if(i == LW || i == LB){
                first_team_scores[RB] --;
            }
            if(i == ST || i == RCB || i == LCB){
                first_team_scores[LCB] --;
                first_team_scores[RCB] --;
            }
            if(i >= LM && i <= RM){
                first_team_scores[LM] --;
                first_team_scores[CM] --;
                first_team_scores[RM] --;
            }
        }
    }

}

bool MatchResult::is_inside(std::string name, std::vector<std::string> list){
    for(string tmp: list){
        if(name == tmp){
            return true;
        }
    }
    return false;
}

void MatchResult::update_injured_players(vector<shared_ptr<Player> >& players_list){
    for(string tmp : injured_players_list){
        cout << "this is the name: |"<< tmp << "|  " << find_player_by_name(tmp, players_list) << endl;
        find_player_by_name(tmp, players_list)->injured();
    } 
}

void MatchResult::update_yellow_cards(vector<shared_ptr<Player> >& players_list){
    for(string tmp : yellow_cards_list){
            find_player_by_name(tmp, players_list)->add_yellow_card();
    }   
}

void MatchResult::update_red_cards(vector<shared_ptr<Player> >& players_list){
    for(string tmp : red_card_list){
            find_player_by_name(tmp, players_list)->add_red_Card();
    }   
}

shared_ptr<SoccerClub> MatchResult::find_soccer_club_by_name(string fullname, vector<shared_ptr<SoccerClub> >& teams_list ){
    for(shared_ptr<SoccerClub> tmp : teams_list){
        if(tmp->has_certain_name(fullname)){
            return tmp;
        }
    }
    return NULL;
}

shared_ptr<Player> MatchResult::find_player_by_name(string fullname, vector<shared_ptr<Player> >& players_list){
    for(shared_ptr<Player> tmp : players_list){
        if(tmp->has_certain_name(fullname)){
            return tmp;
        }
    }
    return NULL;
}