#include "header.h"

// Private Functions

void Gra::initVariables() {
    this->window = nullptr;

    // Game logic

    //Players
    this->player1OnGround = true;
    this->player2OnGround = true;
    this->player1Velocity = sf::Vector2f(0.f, 0.f);
    this->player2Velocity = sf::Vector2f(0.f, 0.f);

    //Points
    this->points1 = 0;
    this->points2 = 0;
    this->textPoints1.setFont(this->czcionka);
    this->textPoints2.setFont(this->czcionka);

    this->textPoints1.setString(std::to_string(this->points1));
    this->textPoints1.setCharacterSize(50);
    this->textPoints1.setFillColor(sf::Color::White);
    this->textPoints1.setPosition(910.f, 105.f);

    this->textPoints2.setString(std::to_string(this->points2));
    this->textPoints2.setCharacterSize(50);
    this->textPoints2.setFillColor(sf::Color::White);
    this->textPoints2.setPosition(1060.f, 105.f);

    //Sounds
    this->bufferSiu.loadFromFile("headds/siuu.wav");
    this->bufferDone.loadFromFile("headds/doneit.wav");

    this->siu.setBuffer(bufferSiu);
    this->done.setBuffer(bufferDone);

    //Time for random numbers
    std::srand(time(nullptr) + clock());

    //Ball
    this->ballVelocity = sf::Vector2f(0.f, 3.f); // Prêdkoœc pocz¹tkowa

}

void Gra::initWindow() {
    this->videoMode.height = 1080;
    this->videoMode.width = 1920;
    this->window = new sf::RenderWindow(this->videoMode, "Siema Eniu", sf::Style::Default);
    this->window->setFramerateLimit(120);

    // Background, goals, etc.
    this->background.loadFromFile("headds/JPG/Game Background/Out Door.jpg");
    this->tlo.setTexture(background);

    //scorebar
    this->txScorebar.loadFromFile("headds/UI and Objects/Window & Objects/Score Bar.png");
    this->scorebar.setTexture(txScorebar);
    this->scorebar.setPosition(850.f, 100.f);

    this->txGoalSide.loadFromFile("headds/UI and Objects/Goal parts/Goal - Side.png");
    this->txGoalTop.loadFromFile("headds/UI and Objects/Goal parts/Goal - Top.png");
    this->txGoalBack.loadFromFile("headds/UI and Objects/Goal parts/Goal - Back.png");

    this->spriteGoalSideLi.setTexture(txGoalSide);
    this->spriteGoalSideLi.setPosition(-25.f, 517.f);
    this->spriteGoalSideLo.setTexture(txGoalSide);
    this->spriteGoalSideLo.setPosition(-105.f, 580.f);

    this->spriteGoalSideRi.setTexture(txGoalSide);
    this->spriteGoalSideRo.setTexture(txGoalSide);
    this->spriteGoalTopR.setTexture(txGoalTop);

    this->spriteGoalTopL.setTexture(txGoalTop);
    this->spriteGoalTopL.setPosition(-13.f, 520.f);

    this->spriteGoalSideRi.setPosition(2010.f, 517.f);
    this->spriteGoalSideRi.setScale(-1.f, 1.f);

    this->spriteGoalSideRo.setPosition(2090.f, 580.f);
    this->spriteGoalSideRo.setScale(-1.f, 1.f);

    this->spriteGoalTopR.setPosition(2000.f, 520.f);
    this->spriteGoalTopR.setScale(-1.f, 1.f);

    //Ball
    this->txBall.loadFromFile("headds/UI and Objects/Ball/Ball 02.png");
    this->spriteBall.setTexture(txBall);

    this->spriteBall.setPosition(960.f, 500.f);
    this->spriteBall.scale(0.5f, 0.5f);

    //Time
    this->czcionka.loadFromFile("headds/comic.ttf");
    this->licznik.setFont(czcionka);
    this->licznik.setCharacterSize(50);
    this->licznik.setFillColor(sf::Color::White);
    this->licznik.setPosition(960.f, 10.f);

    this->czasPoczatkowy = sf::seconds(60);


    //Crossbars

    this->crossbarLeft.setPointCount(4);
    this->crossbarLeft.setPoint(0, sf::Vector2f(0.f, 595.f)); //Lewy dolny 
    this->crossbarLeft.setPoint(1, sf::Vector2f(95.f, 595.f)); //Prawy dolny
    this->crossbarLeft.setPoint(2, sf::Vector2f(170.f, 520.f)); //Prawy Górny
    this->crossbarLeft.setPoint(3, sf::Vector2f(0.f, 520.f)); //Lewy Górny
    this->crossbarLeft.setFillColor(sf::Color::Transparent);

    this->crossbarRight.setPointCount(4);
    this->crossbarRight.setPoint(0, sf::Vector2f(1900.f, 595.f)); //Lewy dolny 
    this->crossbarRight.setPoint(1, sf::Vector2f(1920.f, 595.f)); //Prawy dolny
    this->crossbarRight.setPoint(2, sf::Vector2f(1920.f, 520.f)); //Prawy Górny
    this->crossbarRight.setPoint(3, sf::Vector2f(1815.f, 520.f)); //Lewy Górny
    this->crossbarRight.setFillColor(sf::Color::Transparent);

    //Boxy
    sf::RectangleShape Box1(sf::Vector2f(this->spritePlayer1.getGlobalBounds().width, this->spritePlayer1.getGlobalBounds().height));
    this->Box1.setPosition(this->spritePlayer1.getGlobalBounds().left, this->spritePlayer1.getGlobalBounds().top);
    this->Box1.setFillColor(sf::Color::Transparent);
    this->Box1.setOutlineColor(sf::Color::Transparent);
    this->Box1.setOutlineThickness(5.f);

    sf::RectangleShape Box2(sf::Vector2f(this->spritePlayer2.getGlobalBounds().width, this->spritePlayer2.getGlobalBounds().height));
    this->Box2.setPosition(this->spritePlayer2.getGlobalBounds().left, this->spritePlayer2.getGlobalBounds().top);
    this->Box2.setFillColor(sf::Color::Transparent);
    this->Box2.setOutlineColor(sf::Color::Transparent);
    this->Box2.setOutlineThickness(5.f);
}

void Gra::initPlayers() {

    this->txPlayer1.loadFromFile("headds/Characters//Character 01 - Brazil/PNG Sequences/Idle/Idle_000.png");
    this->txPlayer2.loadFromFile("headds/Characters/Character 04 - Japan/PNG Sequences/Idle/Idle_000.png");
    this->spritePlayer1.setTexture(txPlayer1);
    this->spritePlayer2.setTexture(txPlayer2);

    this->spritePlayer1.setPosition(400.f, 630.f);

    this->spritePlayer2.setScale(-1.f, 1.f);
    this->spritePlayer2.setPosition(1600.f, 630.f);
}

// Constructors
Gra::Gra() {
    this->initVariables();
    this->initWindow();
    this->initPlayers();
}

// Destructors
Gra::~Gra() {
    delete this->window;
}

// Accessors
const bool Gra::running() const {
    return this->window->isOpen();
}

// Functions

void Gra::spawnEnemy() {
}

void Gra::pollEvents() {
    // Event polling
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

void Gra::updateMousePosition() {
    // Updates Mouse Position, relative to the window, Vector2i
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    std::cout << "x = " << this->mousePosWindow.x << " " << "y = " << this->mousePosWindow.y << std::endl;
}

void Gra::updateTime() {
    sf::Time pozostalosc = this->czasPoczatkowy - this->zegar.getElapsedTime();

    if (pozostalosc.asSeconds() <= 0) {
        pozostalosc = sf::seconds(0);
        this->isPaused = true; // Pauza
    }

    if (pozostalosc.asSeconds() <= 0) { pozostalosc = sf::seconds(0); }
    int sekundy = static_cast<int>(pozostalosc.asSeconds());
    int minuty = sekundy / 60;
    sekundy %= 60;

    //reset strumienia
    this->strumien.str("");
    this->strumien.clear();
    this->licznik.setPosition(960.f, 10.f);
    this->strumien << minuty << ":" << (sekundy < 10 ? "0" : "") << sekundy;
    this->licznik.setString(strumien.str());

}

// Funkcja pomocnicza do sprawdzania kolizji pi³ki z lini¹
bool Gra::checkBallCollisionWithLine(const sf::Vector2f& ballCenter, float ballRadius,
    const sf::Vector2f& lineStart, const sf::Vector2f& lineEnd) {
    sf::Vector2f line = lineEnd - lineStart;
    sf::Vector2f toBall = ballCenter - lineStart;

    float t = std::max(0.f, std::min(1.f, (toBall.x * line.x + toBall.y * line.y) / (line.x * line.x + line.y * line.y)));
    sf::Vector2f closestPoint = lineStart + line * t;

    float distance = std::sqrt(std::pow(ballCenter.x - closestPoint.x, 2) + std::pow(ballCenter.y - closestPoint.y, 2));
    return distance <= ballRadius;
}


void Gra::updateBall() {
    // Ruch pi³ki
    this->spriteBall.move(this->ballVelocity);

    // Ograniczenie prêdkoœæ pi³ki
    if (this->ballVelocity.y > 12.f) this->ballVelocity.y = 12.f;
    if (this->ballVelocity.x > 12.f) this->ballVelocity.x = 12.f;
    if (this->ballVelocity.y < -12.f) this->ballVelocity.y = -12.f;
    if (this->ballVelocity.x < -12.f) this->ballVelocity.x = -12.f;

    if (this->spriteBall.getPosition().y < 630.f) this->ballVelocity.y += 0.1f;


    // Granice pi³ki
    sf::FloatRect ballBounds = this->spriteBall.getGlobalBounds();

    // SprawdŸ kolizjê z krawêdziami ekranu
    if (ballBounds.left <= 0.f || ballBounds.left + ballBounds.width >= this->window->getSize().x) {
        this->ballVelocity.x = -this->ballVelocity.x * 1.2f; // Odbicie w poziomie
    }
    if (ballBounds.top <= 0.f || ballBounds.top + ballBounds.height >= this->window->getSize().y
        || ballBounds.top + ballBounds.height >= 900.f) {
        this->ballVelocity.y = -this->ballVelocity.y * 1.2f; // Odbicie w pionie
    }

    //Sprawdzenie czy pad³ gol
    if (this->spriteBall.getPosition().x <= 78.f && this->spriteBall.getPosition().y >= 572.f) {
        this->points2 += 1;
        this->textPoints2.setString(std::to_string(this->points2));
        this->spriteBall.setPosition(960.f, 500.f);
        this->ballVelocity.x = 0.f;
        this->ballVelocity.y = 3.f;
        this->siu.play();
    }
    if (this->spriteBall.getPosition().x >= 1850.f && this->spriteBall.getPosition().y >= 572.f) {
        this->points1 += 1;
        this->textPoints1.setString(std::to_string(this->points1));
        this->spriteBall.setPosition(960.f, 500.f);
        this->ballVelocity.x = 0.f;
        this->ballVelocity.y = 3.f;
        this->siu.play();
    }

    // Sprawdzenie kolizjê z graczem 1
    sf::FloatRect player1Bounds = this->spritePlayer1.getGlobalBounds();

    player1Bounds.left += 75.f;
    player1Bounds.width /= 1.75f;
    player1Bounds.top += 75.f;
    player1Bounds.height /= 1.75f;

    //Box - Border
    this->Box1.setSize(sf::Vector2f(player1Bounds.width, player1Bounds.height));
    this->Box1.setPosition(player1Bounds.left, player1Bounds.top);

    if (ballBounds.intersects(player1Bounds)) {
        float ballCenterX = ballBounds.left + ballBounds.width / 2.f;
        float playerCenterX = player1Bounds.left + player1Bounds.width / 2.f;

        // Okreœl, czy pi³ka uderzy³a z lewej czy z prawej strony
        if (ballCenterX < playerCenterX) {
            this->ballVelocity.x -= 4.f; // Odbicie w lewo
        }
        else {
            this->ballVelocity.x += 4.f; // Odbicie w prawo
        }

        //Odbicie w osi Y
        this->ballVelocity.y += (this->player1Velocity.y * 0.5f);
    }

    // Sprawdzenie kolizji z graczem 2
    sf::FloatRect player2Bounds = this->spritePlayer2.getGlobalBounds();

    //Zmiana granic gracza 2
    player2Bounds.left += 75.f;
    player2Bounds.width /= 1.75f;
    player2Bounds.top += 75.f;
    player2Bounds.height /= 1.75f;

    //Box - Border
    this->Box2.setSize(sf::Vector2f(player2Bounds.width, player2Bounds.height));
    this->Box2.setPosition(player2Bounds.left, player2Bounds.top);


    if (ballBounds.intersects(player2Bounds)) {
        float ballCenterX = ballBounds.left + ballBounds.width / 2.f;
        float playerCenterX = player2Bounds.left + player2Bounds.width / 2.f;

        // Okreœlenie, czy pi³ka uderzy³a z lewej czy z prawej strony
        if (ballCenterX < playerCenterX) {
            this->ballVelocity.x -= 4.f; // Odbicie w lewo
        }
        else {
            this->ballVelocity.x += 4.f; // Odbicie w prawo
        }

        // Efekt spinu
        this->ballVelocity.y += (this->player2Velocity.y * 0.5f);

    }


    // Sprawdzanie kolizji pi³ki z poprzeczkami
    sf::Vector2f ballCenter(ballBounds.left + ballBounds.width / 2.f, ballBounds.top + ballBounds.height / 2.f);
    float ballRadius = ballBounds.width / 2.f;

    // Pobierz punkty poprzeczki lewej
    for (int i = 0; i < this->crossbarLeft.getPointCount(); ++i) {
        sf::Vector2f point1 = this->crossbarLeft.getTransform().transformPoint(this->crossbarLeft.getPoint(i));
        sf::Vector2f point2 = this->crossbarLeft.getTransform().transformPoint(this->crossbarLeft.getPoint((i + 1) % this->crossbarLeft.getPointCount()));
        if (this->checkBallCollisionWithLine(ballCenter, ballRadius, point1, point2)) {
            // Odbicie pi³ki
            sf::Vector2f normal = sf::Vector2f(-(point2.y - point1.y), point2.x - point1.x);
            float magnitude = std::sqrt(normal.x * normal.x + normal.y * normal.y);
            normal /= magnitude;

            float dotProduct = ballVelocity.x * normal.x + ballVelocity.y * normal.y;
            this->ballVelocity.x -= 2.f * dotProduct * normal.x;
            this->ballVelocity.y -= 2.f * dotProduct * normal.y;

            this->ballVelocity *= 1.05f; //Przyspieszenie
            break;
        }
    }

    // Pobierz punkty poprzeczki prawej
    for (int i = 0; i < this->crossbarRight.getPointCount(); ++i) {
        sf::Vector2f point1 = this->crossbarRight.getTransform().transformPoint(this->crossbarRight.getPoint(i));
        sf::Vector2f point2 = this->crossbarRight.getTransform().transformPoint(this->crossbarRight.getPoint((i + 1) % this->crossbarRight.getPointCount()));

        if (checkBallCollisionWithLine(ballCenter, ballRadius, point1, point2)) {
            // Odbicie pi³ki
            sf::Vector2f normal = sf::Vector2f(-(point2.y - point1.y), point2.x - point1.x);
            float magnitude = std::sqrt(normal.x * normal.x + normal.y * normal.y);
            normal /= magnitude;

            float dotProduct = ballVelocity.x * normal.x + ballVelocity.y * normal.y;
            this->ballVelocity.x -= 2.f * dotProduct * normal.x;
            this->ballVelocity.y -= 2.f * dotProduct * normal.y;

            this->ballVelocity *= 1.05f; //Przyspieszenie
            break;
        }
    }
}

void Gra::updatePlayer1() {
    this->player1Velocity.x = 0.f;


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->player1Velocity.x = -5.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->player1Velocity.x = 5.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->player1OnGround) {
        this->player1Velocity.y = -4.5f;
        this->player1OnGround = false;
    }
    if (!this->player1OnGround) {
        this->player1Velocity.y += 0.1f; // Grawitacja
    }
    this->spritePlayer1.move(this->player1Velocity);
    this->handlePlayerCollision();

    //Ground
    if (this->spritePlayer1.getPosition().y >= 630.f) {
        this->spritePlayer1.setPosition(this->spritePlayer1.getPosition().x, 630.f);
        this->player1Velocity.y = 0.f;
        this->player1OnGround = true;
    }

    //Wall
    if (this->spritePlayer1.getPosition().x <= 0.f) {
        this->spritePlayer1.setPosition(0.f, this->spritePlayer1.getPosition().y);
        this->player1Velocity.x = 0.f;
    }
    else if (this->spritePlayer1.getPosition().x >= 1600.f) {
        this->spritePlayer1.setPosition(1600.f, this->spritePlayer1.getPosition().y);
        this->player1Velocity.x = 0.f;
    }

}

void Gra::updatePlayer2() {
    this->player2Velocity.x = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->player2Velocity.x = -5.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->player2Velocity.x = 5.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->player2OnGround) {
        this->player2Velocity.y = -4.5f;
        this->player2OnGround = false;
    }
    if (!this->player2OnGround) {
        this->player2Velocity.y += 0.1f; // Grawitacja
    }
    this->spritePlayer2.move(this->player2Velocity);
    this->handlePlayerCollision();

    //Ground
    if (this->spritePlayer2.getPosition().y >= 630.f) {
        this->spritePlayer2.setPosition(this->spritePlayer2.getPosition().x, 630.f);
        this->player2Velocity.y = 0.f;
        this->player2OnGround = true;
    }

    //Wall
    if (this->spritePlayer2.getPosition().x <= 350.f) {
        this->spritePlayer2.setPosition(350.f, this->spritePlayer2.getPosition().y);
        this->player1Velocity.x = 0.f;
    }
    else if (this->spritePlayer2.getPosition().x >= 2000.f) {
        this->spritePlayer2.setPosition(2000.f, this->spritePlayer2.getPosition().y);
        this->player2Velocity.x = 0.f;
    }

}

void Gra::handlePlayerCollision() {

    // Borders
    this->boundsPlayer1 = this->spritePlayer1.getGlobalBounds();
    this->boundsPlayer2 = this->spritePlayer2.getGlobalBounds();

    //Change Borders
    boundsPlayer1.left -= 10.f;
    boundsPlayer1.width -= 220.f;
    //boundsPlayer1.top += 10.f;  
    //boundsPlayer1.height -= 20.f;

    boundsPlayer2.left -= 10.f;
    boundsPlayer2.width -= 380.f;
    //boundsPlayer2.top += 10.f;
    //boundsPlayer2.height -= 20.f;

    // Check Collision
    if (boundsPlayer1.intersects(boundsPlayer2)) {
        // Oblicz ró¿nicê pozycji miêdzy graczami
        float deltaX = (boundsPlayer1.left + boundsPlayer1.width / 2) - (boundsPlayer2.left + boundsPlayer2.width / 2);
        float overlapX = (boundsPlayer1.width / 2 + boundsPlayer2.width / 2) - std::abs(deltaX);


        if (overlapX > 0.f) {
            if (deltaX > 0.f) { // Player1 is right
                this->spritePlayer1.move(overlapX / 2, 0.f);
                this->spritePlayer2.move(-overlapX / 2, 0.f);
            }
            else { // Player1 is left
                this->spritePlayer1.move(-overlapX / 2, 0.f);
                this->spritePlayer2.move(overlapX / 2, 0.f);
            }
        }
    }
}


void Gra::updatePlayerMovement() {
    this->updatePlayer1();
    this->updatePlayer2();

    //Obs³uga kolizji
    this->handlePlayerCollision();
}

void Gra::update() {
    this->pollEvents();
    this->updateMousePosition();

    if (!this->isPaused) {
        this->updateTime();
        this->updatePlayerMovement();
        this->updateBall();
    }
}

void Gra::renderBg() {
    this->window->draw(tlo);
    this->window->draw(scorebar);
    this->window->draw(textPoints1);
    this->window->draw(textPoints2);
    this->window->draw(licznik);

    this->window->draw(spriteGoalSideLi);
    this->window->draw(spriteGoalTopL);
    this->window->draw(spriteGoalSideRi);
    this->window->draw(spriteGoalTopR);

    this->window->draw(Box1);
    this->window->draw(Box2);
    this->window->draw(spritePlayer1);
    this->window->draw(spritePlayer2);

    this->window->draw(spriteBall);

    this->window->draw(spriteGoalSideLo);
    this->window->draw(spriteGoalSideRo);

    this->window->draw(crossbarLeft);
    this->window->draw(crossbarRight);
}

void Gra::render() {
    /* - clear the old frame; render objects - display frame in window Renders the game objects */

    // Clear
    this->window->clear();

    // Draw Game Objects
    this->renderBg();

    this->window->display();
}





