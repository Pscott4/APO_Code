//
//  Character.cpp
//  multithread
//
//  Created by Quade Kirby on 1/9/17.
//  Copyright © 2017 Quade Kirby. All rights reserved.
//
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourcePath.hpp"
#include "Character.hpp"
#include "Entity.hpp"
class Player: public Entity{
public:
    
    sf::Texture texture;
    sf::Sprite pal;
    int counter1 = 0;
    int counter = 0;
    
    Player(){
        rect.setSize(sf::Vector2f(10,10));
        
    }
    
    void update(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            // left key is pressed: move our character
            pal.move(-6, 0);
            rect.move(-6,0);
            pal.setTextureRect(sf::IntRect(31.5 * counter1, 32, 32, 32));
            counter++;
        }
        
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            // left key is pressed: move our character
            pal.move(6, 0);
            rect.move(6,0);
            pal.setTextureRect(sf::IntRect(32*counter1, 64, 32, 32));
            counter++;
        }
        
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            // left key is pressed: move our character
            pal.move(0,-6);
            rect.move(0,-6);
            pal.setTextureRect(sf::IntRect(31.5 * counter1, 96, 32, 32));
            counter++;
        }
        
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            // left key is pressed: move our character
            pal.move(0, 6);
            rect.move(0, 6);
            pal.setTextureRect(sf::IntRect(31.5 * counter1, 0, 32, 32));
            counter++;
        }
        if(counter > 3){
            counter = 0;
            counter1++;
        }
        if(counter1 > 2){
            counter = 0;
            counter1 = 0;
        }
        
    }
    
};
