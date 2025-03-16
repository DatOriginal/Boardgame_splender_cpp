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
    Gem bonus; //type of Gem provide after buy
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

class Player {
private:
    std::string name;
    std::map<Gem, int> gems; //Gem own
    std::vector<Card> ownedCards; //Purchased Card
    std::vector<Card> reservedCards; //Pre-book Card
    int points;
public:
    Player(std::string n) : name(n), points(0) {}

    void addGem(Gem gem, int count) {
        gems[gem] += count;
    }
    void buyCards(Card &card) {
        ownedCards.push_back(card);
        points += card.getPoint();
    }
    void reservedCard(Card &card) {
        reservedCards.push_back(card);
    }
    int getPoints() {
        return points;
    }
    void display() {
        std::cout << "Player: " << name << ", Points: " << points << "\n";
        std::cout << "Owned Gems: ";
        for(auto &pair : gems) {
            std::cout << "[" << gemTostring(pair.first) << ": " << pair.second << "] ";
        }
        std::cout << "\nOwned Cards: " << ownedCards.size() << "\n";
        std::cout << "Reserved Cards: " << reservedCards.size() << "\n";
    }
};

class GameManger {
private:
    std::vector<Player> players;
    std::vector<Card> availableCards;

public:
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

    Player player1("test");
    player1.display();

    player1.addGem(DIAMOND, 2);
    player1.addGem(RUBY, 3);
    player1.addGem(ONYX, 1);
    std::cout << "\nAfter add gems\n";
    player1.display();

    player1.buyCards(card1);
    std::cout << "\nAfter buy card\n";
    player1.display();
    return 0;
}