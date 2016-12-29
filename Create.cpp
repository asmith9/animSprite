#include "Create.hpp"


Create::Create(char* e):file(e)
    {
        sf::Texture texture;
        texture.loadFromFile("spritesheet.png");
        sprite(texture,sf::IntRect(0,0,300,400));
        assert(file.is_open());
        if (!file.eof() && !file.fail())
        {
            file.seekg(0, std::ios_base::end);
            std::streampos fileSize = file.tellg();
            vec.resize(fileSize);

            file.seekg(0, std::ios_base::beg);
            file.read(&vec[0], fileSize);
        }


    }
void Create::drawForest(sf::RenderWindow& window)
    {
        window.draw(sprite);
    }
