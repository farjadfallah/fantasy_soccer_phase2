#ifndef __MATCH__RESULT__
#define __MATCH__RESULT__

#include<string>
#include <vector>
#include <memory>
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

        void update_players_stat(std::vector<std::shared_ptr<Player> >& players_list);
        void update_teams_stat(std::vector<std::shared_ptr<SoccerClub> >& teams_list);
    private:
        std::string first_team_name, second_team_name;
        int first_team_goals, second_team_goals;
        std::vector<std::string> injured_players_list, yellow_cards_list, red_card_list;
        std::vector<std::string> first_team_lineup, second_team_linup;
        std::vector<std::string> scorers, assists, own_goals;
        


        std::shared_ptr<SoccerClub> find_soccer_club_by_name(std::string fullname, std::vector<std::shared_ptr<SoccerClub> >& teams_list );
        std::shared_ptr<Player> find_player_by_name(std::string fullname, std::vector<std::shared_ptr<Player> >& players_list);
        
        void update_injured_players(std::vector<std::shared_ptr<Player> >& players_list);
        void update_yellow_cards(std::vector<std::shared_ptr<Player> >& players_list);
        void update_red_cards(std::vector<std::shared_ptr<Player> >& players_list);
        void update_players_score(std::vector<std::shared_ptr<Player> >& players_list);

        void fill_raw_scores_list(std::vector<double>& first_team_scores, std::vector<double>& second_team_scores);
        void first_rule(std::vector<double>& first_team_scores, std::vector<double>& second_team_scores);
        void add_clean_sheet_scores(std::vector<double>& first_team_scores, std::vector<double>& second_team_scores);
        void give_points_on_goal_scores(std::vector<std::string> attacking_team_lineup, std::vector<double>& attaking_taem_scores,
                                             std::vector<double>& defending_taem_scores);
        void give_points_on_goal_assist(std::vector<std::string> attacking_team_lineup, std::vector<double>& attaking_taem_scores);
        void reduce_points_on_own_goal(std::vector<std::string> attacking_team_lineup, std::vector<double>& attaking_taem_scores);
        void reduce_points_forward_not_scoring(std::vector<std::string> attacking_team_lineup, std::vector<double>& attaking_team_scores);
        void reduce_points_on_recieving_goal(std::vector<std::string> attacking_team_lineup, std::vector<double>& defending_team_scores);

        void update_players_stats(std::vector<std::shared_ptr<Player> >& players_list);
        void update_players_clean_sheet(std::vector<std::shared_ptr<Player> >& players_list);
        void update_players_goals(std::vector<std::shared_ptr<Player> >& players_list);
        void uodate_players_assists(std::vector<std::shared_ptr<Player> >& players_list);

        bool is_inside(std::string name, std::vector<std::string> list);
        void add_points_to_all_team_players(std::vector<double>& team_list, double points);
        double to_standardized_score(double raw_score);
};  

#endif
