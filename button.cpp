#include "button.h"

Button::Button(const sf::Vector2f &pos, const sf::Vector2f &size, UICommad *cmd) : sf::RectangleShape(size), cmd_(cmd)
{
    this->setPosition(pos);
}

bool Button::is_clicked(const sf::Vector2f &pos)
{
    if (this->getGlobalBounds().contains(pos.x, pos.y)) {
        cmd_->execute();
        return true;
    } else
        return false;
}

