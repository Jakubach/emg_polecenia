#include "customrectangleshape.h"

#include <iostream>
CustomRectangleShape::CustomRectangleShape(sf::Vector2f size, sf::Vector2f position,sf::Color base_color, bool grid, sf::Int32 hover_activation_time): sf::RectangleShape(size),base_color_(base_color), grid_(grid), activation_time_(hover_activation_time)
{
    this->setPosition(position);
    this->setFillColor(base_color_);
    if(this->grid_){
        grid_rec_ = new sf::RectangleShape();
        grid_rec_->setSize(sf::Vector2f (this->getSize().x/grid_size_.x, this->getSize().y/grid_size_.y) );
        grid_rec_->setOutlineColor(sf::Color::Black);
        grid_rec_->setOutlineThickness(2.0);
        grid_rec_->setFillColor(sf::Color::Transparent);
    }
}



void CustomRectangleShape::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= this->getTransform();
    sf::VertexArray rect_shape(sf::Quads, 4);
    sf::Color rect_color = this->getFillColor();
    rect_shape[0].position = this->getPoint(0);
    rect_shape[1].position = this->getPoint(1);
    rect_shape[2].position = this->getPoint(2);
    rect_shape[3].position = this->getPoint(3);
    rect_shape[0].color = rect_color;
    rect_shape[1].color = rect_color;
    rect_shape[2].color = rect_color;
    rect_shape[3].color = rect_color;
    target.draw(rect_shape,states);
    if(this->grid_){
        this->drawGrid(target,states);
    }
}


CustomRectangleShape::~CustomRectangleShape()
{
    delete grid_rec_; // ?
}

bool CustomRectangleShape::is_clicked(const sf::Vector2f &pos)
{
    if (this->getGlobalBounds().contains(pos.x, pos.y)) {
        std::cout << "Clicked "<< std::endl;
        if(this->grid_){
        }
        else{

        }
        return true;
    } else
        return false;
}


bool CustomRectangleShape::detect_hover_time_(){
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

int CustomRectangleShape::hover_reaction()
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


void CustomRectangleShape::check_hover(const sf::Vector2f &pos)
{
    if (this->getGlobalBounds().contains(pos.x, pos.y)) {
        this->hover_state_=true;
    }
    else{
        this->hover_state_=false;
    }
}

void CustomRectangleShape::drawGrid(sf::RenderTarget &target, sf::RenderStates states) const
{

    states.transform = grid_rec_->getTransform().Identity;
    for(int i = 0; i < grid_size_.x; i++){
        for(int j = 0; j < grid_size_.y; j++){
            grid_rec_->setPosition(this->getPosition().x + i * grid_rec_->getSize().x, this->getPosition().y + j * grid_rec_->getSize().y);
            target.draw(*grid_rec_, states);
        }
    }
}

