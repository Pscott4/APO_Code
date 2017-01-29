//
//  Projectiles.hpp
//  multithread
//
//  Created by Quade Kirby on 1/28/17.
//  Copyright © 2017 Quade Kirby. All rights reserved.
//

#ifndef Projectiles_hpp
#define Projectiles_hpp

#include <stdio.h>
#include "Entity.hpp"





class Projectile: public Entity{
public:
    int speed = 3;
    int dmg = 5;
    Projectile();
};

#endif /* Projectiles_hpp */
