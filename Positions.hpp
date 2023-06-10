#ifndef __POSITIONS__
#define __POSITIONS__
#include "Player.hpp"
#include <string>

class GoalKeeper : public Player {
    public:
        std::string get_position();
        GoalKeeper(std::string _full_name, int _price);
        std::string players_of_the_team_output();
};

class Defender : public Player {
    public:
        std::string get_position();
        Defender(std::string _full_name, int _price);
        std::string players_of_the_team_output();
};

class Midfielder : public Player {
    public:
        std::string get_position();
        Midfielder(std::string _full_name, int _price);
        std::string players_of_the_team_output();
};

class Forward : public Player {
    public:
            std::string get_position();
        Forward(std::string _full_name, int _price);
        std::string players_of_the_team_output();
};

#endif