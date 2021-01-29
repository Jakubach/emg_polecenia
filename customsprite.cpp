#include "customsprite.h"

CustomSprite::CustomSprite(const sf::Texture &texture, sf::Vector2f position, sf::Int32 hover_activation_time): texture_(texture), activation_time_(hover_activation_time), sf::Sprite()
{
    this->setPosition(position);
    this->setTexture(texture_);
}

CustomSprite::~CustomSprite()
{

}


int CustomSprite::hover_reaction()
{
    //reaction = nullptr;
    if((this->detect_hover_time_() == true) and (this->hover_reaction_activated_ == true)){
        this->hover_reaction_activated_ = false;
        return 1;

    }
    else if((this->detect_hover_time_() == false) and (this->hover_reaction_activated_ == false)){
        this->hover_reaction_activated_ = true;
        return 0;
    }
    else{
        return -1;
    }
}

void CustomSprite::check_hover(const sf::Vector2f &pos)
{
    if (this->getGlobalBounds().contains(pos.x, pos.y)) {
        this->hover_state_=true;
    }
    else{
        this->hover_state_=false;
    }
}

bool CustomSprite::detect_hover_time_()
{
    if(this->hover_state_){
        sf::Time elapsed = hover_clock_.getElapsedTime();
        if(elapsed.asMilliseconds() > this->activation_time_){
            return true;
        }
    }
    else{
        hover_clock_.restart();
        return false;
    }
}

