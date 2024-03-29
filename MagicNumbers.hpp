#ifndef __MAGIC__NUMBERS__
#define __MAGIC__NUMBERS__
#include <map>
#include <string>
#include <vector>

const double EulersNumber = 2.7182818284590452;


const std::string GOALKEEPER = "gk";
const std::string DEFENDER = "df";
const std::string MIDFIELDER = "md";
const std::string FORWARD = "fw";

const std::vector<std::string> POSITIONS_LIST = {"gk", "df", "md", "fw" };

const int THISWEEK = -1;
const std::string ALL_POSTS = "";

const std::map<std::string, int> MAX_POSITION_NUMBER { { GOALKEEPER, 1}, { DEFENDER, 2 }, {MIDFIELDER , 1}, {FORWARD, 1} };


const std::string INITIAL_FILEPATH = "./data/premier_league.csv";
const std::string WEEKS_DATA_FILEPATH = "./data/weeks_stats/week_";
const std::string WEEKS_DATA_FILE_EXTENSION = ".csv";

const int WON = 3;
const int LOST = 0;
const int DRAW =1;

const int NO_WEEK_SELECTED_FOR_WEEK_RESULT = -1;

const std::string NO_TEAM_SELECTED = "";

const int NOT_INJURED =0;

//commands list
const std::vector<std::string>  COMMAND_TYPES_LIST = { "POST", "GET", "PUT", "DELETE"};

const std::vector<std::string>GET_COMMANDS_LIST = { "team_of_the_week", "players", "league_standings", "users_ranking", "matches_result_league", "squad", "show_budget"};

const std::vector<std::string> POST_COMMANDS_LIST = {"signup", "login", "register_admin", "logout", "sell_player", "buy_player", "close_transfer_window", 
                            "open_transfer_window", "pass_week", "set_captain"};

enum {
    POST,
    GET,
    PUT,
    DELETE
};

enum {
    SIGNUP,
    LOGIN,
    REGISTE_ADMIN,
    LOGOUT,
    SELL_PLAYER,
    BUY_PLAYER,
    CLOSE_TRANSFER_WINDOW,
    OPEN_TRANSFER_WINDOW,
    PASS_WEEK,
    SET_CAPTAIN
};

enum {
    TEAM_OF_THE_WEEK,
    PLAYERS,
    LEAGUE_STANDINGS,
    USER_RANKING,
    MATHCES_RESULT_LEAGUE,
    SQUAD,
    SHOW_BUDGET
};

//headers position
const int COMMAND_TYPE_POSITION = 0;
const int COMMAND_NAME_POSITION = 1;


//feilds name
const std::string WEEK_NUMBER_FIELD = "week_num";
const std::string TEAM_NAME_FIELD = "team_name";
const std::string RANKED_FIELD = "ranks";
const std::string FANTASY_TEAM_FIELD = "fantasy_team";
const std::string PASSWORD_FEILD = "password";
const std::string USERNAME_FEILD = "username";
const std::string PLAYER_NAME_FEILD = "name";
const int DEFAULT_INT_FEILD = -1;

//messages
const std::string SUCCESS_MESSAGE = "OK";

//maxes
const int MAX_PLAYER_SOLD_EACH_WEEK = 2;
const int MAX_PLAYER_BOUGHT_EACH_WEEK = 1;
const int FANTASY_TEAM_SIZE = 5;
const int MAX_PERCISION_IN_DOUBLES = 1;
const int INJURY_PERIOD = 3;
const int YELLOW_CARD_TRESHOLD = 3;
const int DEAFUALT_BUDGET = 2500;
//admin info
const std::string DEFAULT_ADMIN_USER = "admin";
const std::string DEFAULT_ADMIN_PASS = "123456"; 

//posts
enum{
    GK,
    LB,
    LCB,
    RCB,
    RB,
    LM,
    CM,
    RM,
    LW,
    ST,
    RW
};
#endif