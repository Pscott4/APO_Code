//
//  Menu.hpp
//  multithread
//
//  Created by Quade Kirby on 1/7/17.
//  Copyright © 2017 Quade Kirby. All rights reserved.
//

#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
    Menu(float width, float height);
    ~Menu();
    
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }
    
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Sprite ban;
    
};


