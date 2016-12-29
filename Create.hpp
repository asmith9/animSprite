#ifndef CREATE_INCLUDE
#define CREATE_INCLUDE
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <cassert>

class Create : public sf::Sprite
{
public:
    Create(char*);
    void drawForest(sf::RenderWindow&);
private:
    int x, y;
    std::ifstream file;
    //sf::Texture berry, bgTile, cone, eye, pine, shrub, small,
    //    tall, wide;
    sf::Sprite sprite(const sf::Texture&, const sf::IntRect&);
    const sf::IntRect rectSourceSprite;
    std::vector<char> vec;
};

#endif // Create_INCLUDE
