#ifndef SCENA_H
#define SCENA_H

#include "scenaabstract.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "button.h"
#include "customrectangleshape.h"
#include "uicommadsetcolor.h"

#include <memory>
class Scena : public ScenaAbstract
{
private:
    sf::RenderWindow window_;
    CaseAbstract *case_;
    std::vector<Button> buttons;
    sf::RectangleShape rect_ ;
    UICommadSetColor *setBlue;
    UICommadSetColor *setRed;
    UICommadSetColor *setRed_gridbox;
    //CustomRectangleShape custom_rect_= CustomRectangleShape(sf::Vector2f(100.0,100.0), sf::Vector2f(0.0,0.0), true);
    //std::vector<sf::Drawable> shapes;

    //CustomRectangleShape my_rectangle(sf::Vector2f(100.0,100.0), sf::Vector2f(0.0,0.0), false, setRed);
public:
    Scena(int W, int H);
    CaseAbstract *create(int level);
    void rysuj();
    void loop();

};

#endif // SCENA_H
