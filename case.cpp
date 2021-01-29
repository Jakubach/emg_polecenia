#include "case.h"
#include <iostream>

void Case::randomize_position(float &pos_x, float &pos_y, const float &bounding_width, const float &bounding_height, const bool &overlapping)
{
    if(overlapping == false){
        bool finished = false;

        while(!finished){
            finished = true;
            pos_x = rand() % (int)(this->window_->getView().getSize().x - bounding_width);
            pos_y = rand() % (int)(this->window_->getView().getSize().y - bounding_height);

            //rectangle->setPosition(new_x,new_y);

            for(auto &sprite: sprites_){
                sf::FloatRect new_rect_bounds(pos_x,pos_y,bounding_width, bounding_height);
                bool intersects = sprite->getGlobalBounds().intersects(new_rect_bounds);
                if(intersects){
                    finished = false;
                    break;
                }
            }
        }
    }
}

Case::Case(sf::RenderWindow *w) : window_(w)
{
    /*
    auto circle = std::make_unique<sf::CircleShape>(100.0);
    circle->setPosition(0.0, 0.0);
    circle->setFillColor(sf::Color(100, 250, 50));

    gemoetric_objects_.emplace_back(std::move(circle));
     */
    auto rectangle = std::make_unique<CustomRectangleShape>(sf::Vector2f(100.0,100.0), sf::Vector2f(0.0,0.0), sf::Color::Blue, true, 1000);
    sf::Texture texture = sf::Texture();
    if (!texture.loadFromFile("../tex/bay_bolete1.png")) {
        std::cerr << "Could not load texture" << std::endl;
        throw("Could not load texture");
    }
    auto sprite = std::make_unique<CustomSprite>(texture,sf::Vector2f(100.0,100.0), 1000);
    sprite->setScale(0.25, 0.25);

    sf::Texture texture_mushroom = sf::Texture();
    if (!texture_mushroom.loadFromFile("../tex/mush1.png")) {
        std::cerr << "Could not load texture" << std::endl;
        throw("Could not load texture");
    }
    auto sprite_mushroom = std::make_unique<CustomSprite>(texture_mushroom,sf::Vector2f(300.0,300.0), 1000);
    sprite_mushroom->setScale(0.25, 0.25);


    sprites_.emplace_back(std::move(sprite));
    sprites_.emplace_back(std::move(sprite_mushroom));
    shapes.emplace_back(std::move(rectangle));
}

void Case::check_hover(const float& pos_x, const float &pos_y)
{
    for (auto &shape : shapes) {
        shape->check_hover(sf::Vector2f(pos_x,pos_y));
    }

    for (auto &sprite : sprites_) {
        sprite->check_hover(sf::Vector2f(pos_x,pos_y));
    }
}

void Case::hover_reaction()
{
    for (auto i = 0; i < shapes.size(); ++i)
    {
        int reaction = shapes[i]->hover_reaction();
        if(reaction == 1){
            //hover time activated
            shapes[i]->setFillColor(sf::Color::Red);
            auto new_rect = std::make_unique<CustomRectangleShape>(sf::Vector2f(shapes[i]->getSize().x,shapes[i]->getSize().y), sf::Vector2f(shapes[i]->getGlobalBounds().left + shapes[i]->getGlobalBounds().width, shapes[i]->getGlobalBounds().top + shapes[i]->getGlobalBounds().height), sf::Color::Yellow, true, 1000);
            float new_rect_x = new_rect->getPosition().x;
            float new_rect_y = new_rect->getPosition().y;
            randomize_position(new_rect_x,new_rect_y, new_rect->getGlobalBounds().width, new_rect->getGlobalBounds().height, false);
            new_rect->setPosition(new_rect_x, new_rect_y);
            shapes.emplace_back(std::move(new_rect));
            //++size; // <-- remove this if you want to stop when you reach the new items
        }
        else if(reaction == 0){
            //hover time inactivated
            //shapes[i]->setFillColor(shapes[i]->base_color_);
            shapes.erase(shapes.begin()+i);
        }
        else if(reaction == -1){
            //hover untouched
        }
    }

    for (auto i = 0; i < sprites_.size(); ++i)
    {
        int reaction = sprites_[i]->hover_reaction();
        if(reaction == 1){
            //hover time activated
            //shapes[i]->setFillColor(sf::Color::Red);
            sf::Texture texture = sf::Texture();
            if (!texture.loadFromFile("../tex/bay_bolete.png")) {
                std::cerr << "Could not load texture" << std::endl;
                throw("Could not load texture");
            }
            auto sprite = std::make_unique<CustomSprite>(*sprites_[i]->getTexture(),sf::Vector2f(100.0,100.0), 1000);
            sprite->setScale(0.25, 0.25);
            float new_sprite_x = sprite->getPosition().x;
            float new_sprite_y = sprite->getPosition().y;
            //std::cout << sprite->getGlobalBounds().width << sprite->getGlobalBounds().height << std::endl;
            randomize_position(new_sprite_x,new_sprite_y, sprite->getGlobalBounds().width, sprite->getGlobalBounds().height, false);
            sprite->setPosition(new_sprite_x, new_sprite_y);
            sprites_.emplace_back(std::move(sprite));
            sprites_.erase(sprites_.begin()+i);
            //++size; // <-- remove this if you want to stop when you reach the new items
        }
        else if(reaction == 0){
            //hover time inactivated
            //shapes[i]->setFillColor(shapes[i]->base_color_);
            //sprites_.erase(sprites_.begin()+i);
        }
        else if(reaction == -1){
            //hover untouched
        }
    }

}

void Case::rysuj() const
{
    for (auto &shape : shapes) {
        window_->draw(*shape);
    }
    for (auto &sprite : sprites_) {
        window_->draw(*sprite);
    }
}

