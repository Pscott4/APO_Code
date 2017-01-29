//
//  Projectiles.cpp
//  multithread
//
//  Created by Quade Kirby on 1/28/17.
//  Copyright © 2017 Quade Kirby. All rights reserved.
//

#include "Projectiles.hpp"
#include <SFML/Graphics.hpp>


Projectile::Projectile(){
    rect.setSize(sf::Vector2f(10,10));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::Green);
}
