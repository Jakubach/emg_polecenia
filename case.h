#ifndef CASE_H
#define CASE_H
#include "caseabstract.h"

#include <vector>
#include <memory>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "customrectangleshape.h"
#include "customsprite.h"

class Case : public CaseAbstract
{
private:
    std::vector<std::unique_ptr<CustomRectangleShape>> shapes;
    std::vector<std::unique_ptr<CustomSprite>> sprites_;


    sf::RenderWindow *window_;
    void randomize_position(float &pos_x, float &pos_y, const float &bounding_width, const float &bounding_height, const bool &overlapping);
public:
    Case(sf::RenderWindow *w);
    void check_hover(const float &pos_x, const float &pos_y);
    void hover_reaction();
    void rysuj() const;

};

#endif // CASE_H
