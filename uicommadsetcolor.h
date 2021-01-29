#ifndef UICOMMADSETCOLOR_H
#define UICOMMADSETCOLOR_H

#include "uicommad.h"
#include <SFML/Graphics.hpp>

class UICommadSetColor : public UICommad
{
private:
    sf::Color color_;
    sf::Shape *object_;

public:
    UICommadSetColor(const sf::Color &c, sf::Shape *object);
    void execute() override;
};

#endif // UICOMMADSETCOLOR_H
