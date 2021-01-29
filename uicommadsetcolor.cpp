#include "uicommadsetcolor.h"

#include <iostream>
UICommadSetColor::UICommadSetColor(const sf::Color &c, sf::Shape *object) : color_(c), object_(object) {

}

void UICommadSetColor::execute()
{
    object_->setFillColor(color_);
    std::cout << "OK" << std::endl;
}

