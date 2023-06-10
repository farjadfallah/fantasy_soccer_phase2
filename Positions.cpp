#include "Positions.hpp"
#include "MagicNumbers.hpp"
#include <string>
#include "Exceptions.hpp"
#include <sstream>

using namespace std;



std::string GoalKeeper::get_position(){
    return GOALKEEPER;
}
GoalKeeper::GoalKeeper(string _full_name, int _price):
    Player(_full_name, _price){
}

string GoalKeeper::players_of_the_team_output(){
    stringstream stream;  
    stream.precision(MAX_PERCISION_IN_DOUBLES);
    stream << fixed;
    stream << this->average_points();  
    
    return "name: " + full_name + " | role: " + this->get_position() + " | score: " + stream.str() + 
            " | cost: " + to_string(price)  +  " | clean sheets: " + to_string(clean_sheets);
}







std::string Defender::get_position(){
    return DEFENDER;
}
Defender::Defender(string _full_name, int _price):
    Player(_full_name, _price){

}
string Defender::players_of_the_team_output(){
    stringstream stream;  
    stream.precision(MAX_PERCISION_IN_DOUBLES);
    stream << fixed;
    stream << this->average_points();  
    
    return "name: " + full_name + " | role: " + this->get_position() + " | score: " + stream.str() + " | cost: " + to_string(price)  + " | goals: " + to_string(goals) + " | assists : " + to_string(assists) + " | clean sheets: " + to_string(clean_sheets);
}






std::string Midfielder::get_position(){
    return MIDFIELDER;
}
Midfielder::Midfielder(string _full_name, int _price):
    Player(_full_name, _price){
}
string Midfielder::players_of_the_team_output(){
    stringstream stream;  
    stream.precision(MAX_PERCISION_IN_DOUBLES);
    stream << fixed;
    stream << this->average_points();  
    
    return "name: " + full_name + " | role: " + this->get_position() + " | score: " + stream.str() + " | cost: " + to_string(price)  + " | goals: " + to_string(goals) + " | assists : " + to_string(assists) + " | clean sheets: " + to_string(clean_sheets);
}





std::string Forward::get_position(){
    return FORWARD;
}
Forward::Forward(string _full_name, int _price):
    Player(_full_name, _price){
}

string Forward::players_of_the_team_output(){
    stringstream stream;  
    stream.precision(MAX_PERCISION_IN_DOUBLES);
    stream << fixed;
    stream << this->average_points();  
    
    return "name: " + full_name + " | role: " + this->get_position() + " | score: " + stream.str() + " | cost: " + to_string(price)  + " | goals: " + to_string(goals) + " | assists: " + to_string(assists);
}