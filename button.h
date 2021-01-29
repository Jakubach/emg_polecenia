#ifndef BUTTON_H
#define BUTTON_H


#include <SFML/Graphics.hpp>
#include "uicommad.h"

//Invoker
class Button : public sf::RectangleShape
{
private:
    UICommad *cmd_;
public:
    Button(const sf::Vector2f &pos, const sf::Vector2f &size, UICommad *cmd);
    bool is_clicked(const sf::Vector2f &pos);
};

#endif // BUTTON_H
