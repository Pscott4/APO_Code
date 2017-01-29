//
//  Menu.cpp
//  multithread
//
//  Created by Quade Kirby on 1/7/17.
//  Copyright © 2017 Quade Kirby. All rights reserved.
//

#include "Menu.h"
#include "ResourcePath.hpp"


Menu::Menu(float width, float height)
{
    if (!font.loadFromFile( resourcePath() + "sansation.ttf"))
    {
        return EXIT_FAILURE;
    }
    
   
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 6, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
    
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::Black);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width / 6, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
    
    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::Black);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 6, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
    
    selectedItemIndex = 0;
    
    
    

}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    sf::Texture back;
    if (!back.loadFromFile(resourcePath() + "intro.jpg")) {
        return EXIT_FAILURE;
    }
    
    sf::Sprite ban(back);
    
    ban.setScale(0.48f, 0.55f);
    window.draw(ban);
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
    
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::Black);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::Black);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
