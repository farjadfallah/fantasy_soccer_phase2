#ifndef __FILE__READER__
#define __FILE__READER__
#include <vector>
#include <string>
#include <memory>
#include "Player.hpp"
#include "SoccerClub.hpp"
#include "ReadFileUtil.hpp"
#include "WeekMatchResults.hpp"
#include "MatchResult.hpp"
#include "MagicNumbers.hpp"



class FileReader{
    public:
        void get_initial_data(std::vector<std::shared_ptr<SoccerClub> >& teams_list, std::vector<std::shared_ptr<Player> >& players_list);
        void pass_week(int active_week, std::vector<std::shared_ptr<WeekMatchResults> >& weeks_results_list, std::vector<std::shared_ptr<SoccerClub> >& teams_list, std::vector<std::shared_ptr<Player> >& players_list);

    private:
        std::shared_ptr<MatchResult> get_result(ReadFileUtil& read_file_util);
        void get_players_list(std::vector<std::string>& selected_players_list, ReadFileUtil& read_file_util);
        void find_goalkeepers_from_initial_file(std::shared_ptr<SoccerClub> new_team, ReadFileUtil& read_file_util, std::vector<std::shared_ptr<Player> >& players_list);
        void find_defenders_from_initial_file(std::shared_ptr<SoccerClub> new_team, ReadFileUtil& read_file_util, std::vector<std::shared_ptr<Player> >& players_list);
        void find_midfielders_from_initial_file(std::shared_ptr<SoccerClub> new_team, ReadFileUtil& read_file_util, std::vector<std::shared_ptr<Player> >& players_list);
        void find_Forwards_from_initial_file(std::shared_ptr<SoccerClub> new_team, ReadFileUtil& read_file_util, std::vector<std::shared_ptr<Player> >& players_list);

        void get_scorers_assists_own_goals(ReadFileUtil& read_file_util,std::vector<std::string>& scorers, std::vector<std::string>& assists,
            std::vector<std::string>& onw_goals );
        void get_players_price_list(ReadFileUtil& read_file_util, std::vector<std::string>& players_name_list,
                                        std::vector<int>& player_price_list);
};
#endif