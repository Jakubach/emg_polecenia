#ifndef CUSTOMRECTANGLESHAPE_H
#define CUSTOMRECTANGLESHAPE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "uicommad.h"

/*
struct RectangleGrid {
  bool grid_;
  sf::RectangleShape* grid_rec_;
  sf::Vector2i grid_size_;
} ;
*/
class CustomRectangleShape : public sf::RectangleShape
{

public:
    CustomRectangleShape(sf::Vector2f size, sf::Vector2f position, sf::Color base_color, bool grid, sf::Int32 hover_activation_time);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual ~CustomRectangleShape(); // virutal? https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors
    bool is_clicked(const sf::Vector2f &pos);
    int hover_reaction();
    void check_hover(const sf::Vector2f &pos);
    const sf::Color base_color_ = sf::Color::Blue;

private:
    bool grid_ = false;
    sf::Vector2i grid_size_= sf::Vector2i(3,3);
    sf::RectangleShape* grid_rec_;
    void drawGrid(sf::RenderTarget &target, sf::RenderStates states) const;
    sf::Clock hover_clock_;
    bool detect_hover_time_();
    bool hover_reaction_activated_ = true; // it prevent from multiple activation of hover_reaction function
    bool hover_state_ = false;
    sf::Int32 activation_time_ = 1000;





};

#endif // CUSTOMRECTANGLESHAPE_H
