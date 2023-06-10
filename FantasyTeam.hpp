#ifndef __FANTASY__TEAM__
#define __FANTASY__TEAM__

#include <vector>
#include <string>
#include <memory>
#include "Player.hpp"
class FantasyTeam {
    public:
        FantasyTeam(std::string _username, std::string password);
        bool has_certain_password(std::string _password);
        bool has_certain_username(std::string _username);
        void add_player(std::shared_ptr<Player> new_player);
        void delete_player(std::shared_ptr<Player> new_player);
        void set_captain(std::shared_ptr<Player> new_captain);

        void pass_week(int new_week);
        std::vector<std::shared_ptr<Player> > squad();
        bool is_better_than(std::shared_ptr<FantasyTeam> compared_to);
        bool captain_is(std::shared_ptr<Player> being_checked);

        std::string user_ranking_output();
        std::string fantasy_squad_name_output();
        std::string fantasy_squad_points_output();
        std::string show_budget_output();
        std::string fantasy_squad_cost_output();
    private:
        std::string username;
        std::string password;
        std::vector<double> points_each_week;
        double points =0;
        std::vector<std::shared_ptr<Player> >  tmp_squad_players_list;
        std::vector<std::vector<std::shared_ptr<Player> > > players_list_each_week;
        std::shared_ptr<Player> tmp_captain;
        std::vector<std::shared_ptr<Player> > captain_list_each_week;
        int players_bought_this_week =0;
        int players_sold_this_week =0;
        bool once_completed = false;
        int budget = DEAFUALT_BUDGET;


        void new_captain_is_in_team(std::shared_ptr<Player> new_captain);
        void check_if_team_can_sell_player();
        void check_if_team_can_buy_player(std::string post);
        int players_num_in_position(std::string position);
        double calculate_total_score(int week);
        std::shared_ptr<Player> get_next_player_with_position(std::string post, std::vector<std::shared_ptr<Player> >& selected_previously);
        std::vector<std::shared_ptr<Player> > prepare_squad();

};
#endif