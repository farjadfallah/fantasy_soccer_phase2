#ifndef __MATCH__RESULT__
#define __MATCH__RESULT__

#include<string>
#include <vector>
#include "SoccerClub.hpp"
#include "Player.hpp"
class MatchResult{
    public:
        MatchResult(std::string _first_team, std::string _second_team, int _first_team_goals,int _second_team_goals,
            std::vector<std::string> _injured_players_list, std::vector<std::string> _yellow_cards_list, std::vector<std::string> _red_card_list,
            std::vector<std::string> _first_team_lineup, std::vector<std::string> _second_team_linup, std::vector<std::string> _scorers,
            std::vector<std::string> _assists, std::vector<std::string> _own_goals);
        void print();
        std::string first_team();
        std::string second_team();
        int first_team_points();
        int second_team_points();
        int first_team_goals_for();
        int second_team_goals_for();
        int first_team_goals_against();
        int second_team_goals_against();

        // void update_teams_stat(std::vector<SoccerClub> teams_list);
    private:
        std::string first_team_name, second_team_name;
        int first_team_goals, second_team_goals;
        std::vector<std::string> injured_players_list, yellow_cards_list, red_card_list;
        std::vector<std::string> first_team_lineup, second_team_linup;
        std::vector<std::string> scorers, assists, own_goals;
};

#endif
