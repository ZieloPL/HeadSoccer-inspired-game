#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/*
    Class that acts like game engine
*/


class Gra
{
private:
    // Variables
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    // Mouse Position
    sf::Vector2i mousePosWindow;

    //Pause
    bool isPaused;

    // Game logic

    //Points
    int points1;
    int points2;
    sf::Text textPoints1;
    sf::Text textPoints2;

    //Players
    bool player1OnGround;
    bool player2OnGround;
    sf::Vector2f player1Velocity;
    sf::Vector2f player2Velocity;

    sf::FloatRect boundsPlayer1;
    sf::FloatRect boundsPlayer2;

    //Ball
    sf::Vector2f ballVelocity;

    // Game Objects
    sf::RectangleShape eniu;

    sf::Texture background;
    sf::Sprite tlo;
    sf::Texture txGoalSide;
    sf::Sprite spriteGoalSideLi;
    sf::Texture txGoalTop;
    sf::Sprite spriteGoalTopL;
    sf::Texture txGoalBack;
    sf::Sprite spriteGoalBackL;

    sf::Sprite spriteGoalSideLo;
    sf::Sprite spriteGoalSideRi;
    sf::Sprite spriteGoalSideRo;
    sf::Sprite spriteGoalTopR;

    sf::ConvexShape crossbarLeft;
    sf::ConvexShape crossbarRight;

    sf::Texture txBall;
    sf::Sprite spriteBall;

    sf::Texture txScorebar;
    sf::Sprite scorebar;

    sf::RectangleShape Box1;
    sf::RectangleShape Box2;

    // Players
    sf::Texture txPlayer1;
    sf::Sprite spritePlayer1;

    sf::Texture txPlayer2;
    sf::Sprite spritePlayer2;

    //Time
    sf::Font czcionka;
    sf::Text licznik;
    sf::Time czasPoczatkowy;
    sf::Clock zegar;
    std::ostringstream strumien;

    //Sound
    sf::SoundBuffer bufferSiu;
    sf::SoundBuffer bufferDone;

    sf::Sound siu;
    sf::Sound done;

    // Private functions
    void initVariables();
    void initWindow();
    void initPlayers();

public:
    // Constructor / Destructor
    Gra();
    virtual ~Gra();

    // Accessors
    const bool running() const;

    // Functions
    void spawnEnemy();
    void pollEvents();
    void updateMousePosition();
    void update();
    void renderBg();
    void render();
    void updateTime();

    void updatePlayer1();
    void updatePlayer2();
    void updatePlayerMovement();
    void handlePlayerCollision();
    void updateBall();
    bool checkBallCollisionWithLine(const sf::Vector2f& ballCenter, float ballRadius,
        const sf::Vector2f& lineStart, const sf::Vector2f& lineEnd);
};