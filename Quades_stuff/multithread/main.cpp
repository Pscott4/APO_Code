
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "ResourcePath.hpp"

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "Projectiles.hpp"
#include "Character.cpp"



int main(int, char const**)
{
    int counter = 0;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fake Pokemon");
 
    Menu menu(window.getSize().x, window.getSize().y);
    
    window.setFramerateLimit(30);
    
    sf::Texture mat;
    if (!mat.loadFromFile(resourcePath() + "image.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite pal(mat);
 

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "Pokeball.PNG")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "cute_image.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Heyo", font, 50);
    text.setFillColor(sf::Color::Black);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    music.play();
    
    bool state = false;
    
    
    class Player player1;
    player1.pal.setTexture(mat);
    
    //projectile vector array
    std::vector<Projectile>::const_iterator iter;
    std::vector<Projectile> projectileArray;
    
    class Projectile projectile1;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                //window.close();
                state = false;
            }
        }
        if(!state){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                menu.MoveUp();
            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                menu.MoveDown();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
                
                std::cout << menu.GetPressedItem() << std::endl;
                if(menu.GetPressedItem() == 0){
                    state = true;
                    
                }
                else if(menu.GetPressedItem() == 1){
                    
                }
                else if(menu.GetPressedItem() == 2){
                    window.close();
                    break;
                    
                }
                
            }
            
            
            // Clear screen
            window.clear();
            
            
            menu.draw(window);
            
            window.display();
        }
        if(state){
            
            window.clear();
            
            player1.update();
            
            
            // Draw the sprite
            window.draw(sprite);
            
            window.draw(player1.rect);
            
            window.draw(player1.pal);
            
            
            
           
            //projectile
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                projectile1.rect.setPosition(player1.rect.getPosition());
                projectileArray.push_back(projectile1);
               // window.draw(projectileArray[counter].rect);

                //counter++;
            }
           for(iter = projectileArray.begin(); iter != projectileArray.end(); iter++){
                window.draw(projectileArray[counter].rect);
               //std::cout << counter << std::endl;
               counter++;
               
            }
            counter = 0;
            
            
            
            
            // Draw the string
            window.draw(text);
            
            // Update the window
            window.display();
        }
    }

    return EXIT_SUCCESS;
} 

