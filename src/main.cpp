#include <iostream>
#include <map>

enum Gem { DIAMOND, RUBY, SAPPHIRE, EMERALD, ONYX, GOLD };

std::string gemTostring(Gem gem)
{
    switch (gem) 
    {
        case DIAMOND: 
            return "Diamond"; //white
        case RUBY:
            return "Ruby"; //red
        case SAPPHIRE:
            return "Sapphire"; //blue
        case EMERALD:
            return "Emerald"; //green
        case ONYX:
            return "Onyx"; //black
        case GOLD:
            return "Gold"; //Yellow
    }
    return "Unknown";
}

class Card {
private:
    int point;
    std::map<Gem, int> cost;
    Gem bonus; //type of Gem provide after bue
    int level;
public:
    Card(int p, std::map<Gem, int> c, Gem b, int lvl) {
        point = p;
        cost = c;
        bonus = b;
        level = lvl;
    }

    int getPoint() {
        return point;
    }
    std::map<Gem, int> getCost() {
        return cost;
    }
    Gem getBonus() {
        return bonus;
    }
    int getLevel() {
        return level;
    }
    void display() {
        std::cout << "Card Level: " << level << ", Points: " << point << ", Bonus: " << gemTostring(bonus) << "\n";
        std::cout << "Cost: ";
        for (auto &pair : cost) { 
            std::cout << "[" << gemTostring(pair.first) << ": " << pair.second << "] ";
        }
        std::cout << std::endl;
    }
};

int main ()
{
    std::cout << "Welcome" << std::endl;
    
    std::map<Gem, int> cost1;
    cost1[DIAMOND] = 4;
    cost1[RUBY] = 3;
    cost1[ONYX] = 1;

    Card card1(2, cost1, EMERALD, 2);
    card1.display();
    return 0;
}