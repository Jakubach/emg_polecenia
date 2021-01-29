#ifndef CUSTOMSPRITE_H
#define CUSTOMSPRITE_H

#include <SFML/Graphics.hpp>

class CustomSprite : public sf::Sprite
{
public:
    CustomSprite(const sf::Texture &texture, sf::Vector2f position, sf::Int32 hover_activation_time);
    virtual ~CustomSprite();
    int hover_reaction();
    void check_hover(const sf::Vector2f &pos);

private:
    sf::Int32 activation_time_ = 1000;
    sf::Clock hover_clock_;
    bool detect_hover_time_();
    bool hover_reaction_activated_ = true;
    bool hover_state_ = false;
    sf::Texture texture_;
};

#endif // CUSTOMSPRITE_H
