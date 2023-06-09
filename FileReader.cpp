#include "FileReader.hpp"
#include "ReadFileUtil.hpp"
#include "Positions.hpp"
#include "SoccerClub.hpp"
#include "MatchResult.hpp"
#include "WeekMatchResults.hpp"
#include "MagicNumbers.hpp"
#include "Exceptions.hpp"
#include "FantasyTeam.hpp"
#include <string>
#include <iostream>
#include <memory>

using namespace std;



void FileReader::get_initial_data(vector<shared_ptr<SoccerClub> >& teams_list, vector<shared_ptr<Player> >& players_list){
    ReadFileUtil read_file_util(INITIAL_FILEPATH);
    read_file_util.get_header();
    string new_team_name;
    while(read_file_util.get_team_name_from_initial_file(new_team_name)){
        std::shared_ptr<SoccerClub> new_team = make_shared<SoccerClub>(new_team_name);
        teams_list.push_back(new_team);
        find_goalkeepers_from_initial_file(new_team, read_file_util, players_list);
        find_defenders_from_initial_file(new_team, read_file_util, players_list);
        find_midfielders_from_initial_file(new_team, read_file_util, players_list);
        find_Forwards_from_initial_file(new_team, read_file_util, players_list);
        new_team_name.clear();
    }
}

void FileReader::find_goalkeepers_from_initial_file(std::shared_ptr<SoccerClub> new_team, ReadFileUtil& read_file_util,  vector<shared_ptr<Player> >& players_list){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, read_file_util);
    for(string tmp : selected_players_list){
        shared_ptr<Player> new_player = make_shared<GoalKeeper>(tmp);
        new_team->add_player(new_player);
        players_list.push_back(new_player);
    }

}

void FileReader::find_defenders_from_initial_file(std::shared_ptr<SoccerClub> new_team, ReadFileUtil& read_file_util,  vector<shared_ptr<Player> >& players_list){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, read_file_util);
    for(string tmp : selected_players_list){
        shared_ptr<Player> new_player = make_shared<Defender>(tmp);
        new_team->add_player(new_player);
        players_list.push_back(new_player);
    }

}

void FileReader::find_midfielders_from_initial_file(std::shared_ptr<SoccerClub> new_team, ReadFileUtil& read_file_util,  vector<shared_ptr<Player> >& players_list){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, read_file_util);
    for(string tmp : selected_players_list){
        shared_ptr<Player> new_player = make_shared<Midfielder>(tmp);
        new_team->add_player(new_player);
        players_list.push_back(new_player);
    }

}

void FileReader::find_Forwards_from_initial_file(std::shared_ptr<SoccerClub> new_team, ReadFileUtil& read_file_util,  vector<shared_ptr<Player> >& players_list){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, read_file_util);
    for(string tmp : selected_players_list){
        shared_ptr<Player> new_player = make_shared<Forward>(tmp);
        new_team->add_player(new_player);
        players_list.push_back(new_player);
    }

}

void FileReader::get_players_list(vector<string>& selected_players_list, ReadFileUtil& read_file_util){
    bool state = true;
    string player_name;
    while(true){
        if(state == false){
            state = true;
            break;
        }
        player_name.clear();
        state = read_file_util.get_Player_from_file(player_name);
        if(player_name !=""){
           selected_players_list.push_back(player_name);
        }
    }
}



void FileReader::pass_week(int active_week, vector<shared_ptr<WeekMatchResults> >& weeks_results_list, vector<shared_ptr<SoccerClub> >& teams_list, vector<shared_ptr<Player> >& players_list){
    string new_file_path = WEEKS_DATA_FILEPATH + to_string(active_week) + WEEKS_DATA_FILE_EXTENSION;
    ReadFileUtil read_file_util(new_file_path);
    read_file_util.get_header();
    shared_ptr<WeekMatchResults> tmp_week_results = make_shared<WeekMatchResults>();
    for(int i=0 ; i<10; i++){
        shared_ptr<MatchResult> tmp_game_result = get_result(read_file_util); 
        tmp_week_results->add_result(tmp_game_result);
        tmp_week_results->update_teams_stat(teams_list);
        // update_teams_stats(tmp_game_result, teams_list);
        // update_injured_players(read_file_util, players_list);
        // update_players_yellow_card(read_file_util, players_list); 
        // update_players_red_card(read_file_util, players_list);
        // update_players_scores(read_file_util, players_list);
    }
    weeks_results_list.push_back(tmp_week_results);
    
}

void FileReader::update_teams_stats(shared_ptr<MatchResult> game, vector<shared_ptr<SoccerClub> >& teams_list){
    shared_ptr<SoccerClub> first_team = find_soccer_club_by_name(game->first_team(), teams_list);
    shared_ptr<SoccerClub> second_team = find_soccer_club_by_name(game->second_team(), teams_list);
    first_team->add_points(game->first_team_points());
    second_team->add_points(game->second_team_points());
    first_team->add_goals_for(game->first_team_goals_for());
    second_team->add_goals_for(game->second_team_goals_for());
    first_team->add_goals_against(game->first_team_goals_against());
    second_team->add_goals_against(game->second_team_goals_against());
}

shared_ptr<SoccerClub> FileReader::find_soccer_club_by_name(string fullname, vector<shared_ptr<SoccerClub> >& teams_list ){
    for(shared_ptr<SoccerClub> tmp : teams_list){
        if(tmp->has_certain_name(fullname)){
            return tmp;
        }
    }
    return NULL;
}

shared_ptr<Player> FileReader::find_player_by_name(string fullname, vector<shared_ptr<Player> >& players_list){
    for(shared_ptr<Player> tmp : players_list){
        if(tmp->has_certain_name(fullname)){
            return tmp;
        }
    }
    return NULL;
}

void FileReader::update_injured_players(ReadFileUtil& read_file_util, vector<shared_ptr<Player> >& players_list){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, read_file_util);
    for(string tmp : selected_players_list){
            find_player_by_name(tmp, players_list)->injured();
    } 
}

void FileReader::update_players_yellow_card(ReadFileUtil& read_file_util, vector<shared_ptr<Player> >& players_list){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, read_file_util);
    for(string tmp : selected_players_list){
            find_player_by_name(tmp, players_list)->add_yellow_card();
    }   
}

void FileReader::update_players_red_card(ReadFileUtil& read_file_util, vector<shared_ptr<Player> >& players_list){
    vector<string> selected_players_list; 
    get_players_list(selected_players_list, read_file_util);
    for(string tmp : selected_players_list){
            find_player_by_name(tmp, players_list)->add_red_Card();
    }
}

void FileReader::update_players_scores(ReadFileUtil& read_file_util, vector<shared_ptr<Player> >& players_list){

    bool state = true;
    string data;
    while(true){
        if(state == false){
            state = true;
            break;
        }
        data.clear();
        state = read_file_util.get_Player_from_file(data);
        if(data !=""){
            string player_name, score_str;
            double score;
            int delimiter_location=0;
            for(int i=0; i<data.size(); i++){
                if(data[i] == ':'){
                    delimiter_location = i;
                }
            }
            player_name = data.substr(0, delimiter_location);
            score_str = data.substr(delimiter_location + 1, data.size());
            score = stod(score_str);
            find_player_by_name(player_name, players_list)->edit_new_score(score);
        }
    }
}

void FileReader::get_scorers_assists_own_goals(ReadFileUtil& read_file_util,vector<string>& scorers,vector<string>& assists,
        vector<string>& own_goals ){
    
    bool state = true;
    string data;
    while(true){
        if(state == false){
            state = true;
            break;
        }
        data.clear();
        state = read_file_util.get_Player_from_file(data);
        if(data !=""){
            string scorer_name, assist_name;
            int delimiter_location=0;
            for(int i=0; i<data.size(); i++){
                if(data[i] == ':'){
                    delimiter_location = i;
                }
            }
            scorer_name = data.substr(0, delimiter_location);
            assist_name = data.substr(delimiter_location + 1, data.size());
            if(assist_name == "OWN_GOAL"){
                own_goals.push_back(scorer_name);
                continue;
            }else{
                scorers.push_back(scorer_name);
                assists.push_back(assist_name);
            }
            
        }
    }
}
shared_ptr<MatchResult>  FileReader::get_result(ReadFileUtil& read_file_util){
    string first_team_str, second_team_str;
    int first_goal, second_goal;
    vector<string> injured_players_list, yellow_cards_list, red_card_list;
    vector<string> first_team_lineup, second_team_linup;
    vector<string> scorers, assists, own_goals;
    read_file_util.get_team_names_from_week_file(first_team_str, second_team_str);
    read_file_util.get_team_goals_from_week_file(first_goal, second_goal);
    get_players_list(injured_players_list, read_file_util);
    get_players_list(yellow_cards_list, read_file_util);
    get_players_list(red_card_list, read_file_util);
    get_scorers_assists_own_goals(read_file_util, scorers, assists, own_goals);
    get_players_list(first_team_lineup, read_file_util);
    get_players_list(second_team_linup, read_file_util);
    shared_ptr<MatchResult> tmp_game_result = make_shared<MatchResult>(first_team_str, second_team_str, first_goal, second_goal,
        injured_players_list,yellow_cards_list, red_card_list,first_team_lineup, second_team_linup, scorers, assists, own_goals);
    tmp_game_result->print();
    return tmp_game_result;
}