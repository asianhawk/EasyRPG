#ifndef __enemy__
#define __enemy__
#include "rpg_e_action.h"
#include <string>
#include <vector>

namespace RPG {
class Enemy {
    public:
        Enemy();
        
        int id;
        std::string name;
        std::string battler_name;
        int battler_hue;
        int maxhp;
        int maxmp;
        int str;
        int agi;
        int iint;
        int pdef;
        bool transparent;
        int exp;
        int gold;
        int item_id;
        char treasure_prob;
        bool crit_hits;
        char crit_hits_chance;
        bool miss;
        bool flying;
        std::vector<char> conditions;
        std::vector<char> attributes;
        std::vector<E_Action*> actions;
};

}
#endif