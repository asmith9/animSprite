#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include "Create.hpp"
#include <Box2D/Box2D.h>
#include <iostream>

int main()
{
    // setup window
    sf::Vector2i screenDimensions(800,600);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Animations!");
    window.setFramerateLimit(60);
    sf::View view1(sf::FloatRect(200, 200, 300, 200));


    // load texture (spritesheet)
    sf::Texture texture, bg;

    if (!bg.loadFromFile("bg.png"))
    {
        std::cout << "Failed to load background spritesheet!" << std::endl;
    }

    sf::Sprite background(bg);

    if (!texture.loadFromFile("simeon.png"))
    {
        std::cout << "Failed to load player spritesheet!" << std::endl;
        return 1;
    }
    //sf::Texture obj1;
     Create canvas("forest_layout");
    //obj1.loadFromFile("spritesheet.png");
    //sf::Sprite sprite(texture,sf::IntRect(115,132,29,26));
    // set up the animations for all four directions (set spritesheet and push frames)
    Animation walkingAnimationDown;
    walkingAnimationDown.setSpriteSheet(texture);
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect( 0, 0, 32, 32));


    Animation walkingAnimationLeft;
    walkingAnimationLeft.setSpriteSheet(texture);
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect( 0, 32, 32, 32));

    Animation walkingAnimationRight;
    walkingAnimationRight.setSpriteSheet(texture);
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));

    Animation walkingAnimationUp;
    walkingAnimationUp.setSpriteSheet(texture);
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect( 0, 96, 32, 32));

    Animation* currentAnimation = &walkingAnimationDown;

    // set up AnimatedSprite
    AnimatedSprite animatedSprite(sf::seconds(0.2), true, false);
    animatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));
    animatedSprite.setOrigin(16.0, 32.0);
    animatedSprite.setPosition(300, 200);

    sf::Clock frameClock;

    float speed = 480.f;
    bool noKeyWasPressed = true;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        sf::Time frameTime = frameClock.restart();

        // if a key was pressed set the correct animation and move correctly
        sf::Vector2f movement(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            currentAnimation = &walkingAnimationUp;
            movement.y -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            currentAnimation = &walkingAnimationDown;
            movement.y += speed;
            noKeyWasPressed = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            currentAnimation = &walkingAnimationLeft;
            movement.x -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            currentAnimation = &walkingAnimationRight;
            movement.x += speed;
            noKeyWasPressed = false;
        }
        animatedSprite.play(*currentAnimation);
        animatedSprite.move(movement * frameTime.asSeconds());

        // if no key was pressed stop the animation
        if (noKeyWasPressed)
        {
            animatedSprite.stop();
        }
        noKeyWasPressed = true;

        // update AnimatedSprite
        animatedSprite.update(frameTime);
        view1.reset(sf::FloatRect(animatedSprite.getPosition().x-300,
        animatedSprite.getPosition().y-200, 600, 400));
        window.setView(view1);
        animatedSprite.setColor(sf::Color(140, 140, 140, 255));
        background.setColor(sf::Color(140, 140, 140, 255));
        // draw
        window.clear();
        canvas.drawForest(window);
        window.draw(animatedSprite);

        window.display();
    }


    return 0;
}
