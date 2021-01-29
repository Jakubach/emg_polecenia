#include "scena.h"
#include "case.h"

#include <iostream>
Scena::Scena(int W, int H) : window_(sf::VideoMode(W, H), "SFML app")
{
    //Client. Parameterize an invoker with commands
    case_ = create(0);
    //The Receiver is rect
    rect_.setPosition(300, 300);
    rect_.setSize(sf::Vector2f(100, 100));

    setBlue = new UICommadSetColor(sf::Color::Blue, &rect_);
    setRed = new UICommadSetColor(sf::Color::Red, &rect_);
    buttons.emplace_back(sf::Vector2f(0, 400), sf::Vector2f(50, 50), setBlue);
    buttons.emplace_back(sf::Vector2f(100, 400), sf::Vector2f(50, 50), setRed);
    srand(time(NULL));
}

CaseAbstract* Scena::create(int level)
{
    if (level == 0)
        return new Case(&window_);
    else
        return new Case(&window_);
}

void Scena::rysuj()
{
    window_.clear(sf::Color::Black);
    case_->rysuj();
    window_.draw(rect_);
    for (auto &button : buttons) {
        window_.draw(button);
    }
    window_.display();
}

void Scena::loop()
{
    while (window_.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window_.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window_.close();
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Space) {
                    std::cout << "Space released" << std::endl;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mouse_position = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
                    for (auto &obj : buttons) {
                        bool click = obj.is_clicked(mouse_position);
                    }
                }
            }
            if (event.type == sf::Event::MouseMoved){
                sf::Vector2f mouse_position = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
                case_->check_hover(mouse_position.x, mouse_position.y);
            }
        }
        case_->hover_reaction();
        sf::sleep(sf::milliseconds(1));
        this->rysuj();
    }
}
