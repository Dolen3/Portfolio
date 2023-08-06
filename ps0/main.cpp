//Daniel Olen
//Comp 2040
//PS0 Hello World with SFML
//Professor Rykalova
//Date of Completion: 1/21/23
//Short description of the problem the program was written to solve: 
// Program was written to make a sprite in SFML perform various tasks such as moving, rotating, scaling, and more with keyboard input.
//Sprite rotates with A and D keys,and scales with S and W keys

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

     sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);


    float speed = 0.5;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

       // sf::Keyboard::isKeyPressed	(	Key 	key	)	
       // object.setRotation(object.getRotation() + angle);
        float angle = -0.5;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sprite.setRotation(sprite.getRotation() + angle);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            angle = 0.5;
            sprite.setRotation(sprite.getRotation() + angle);
        }

        

        sf::Vector2f scale = sprite.getScale();
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            sprite.setScale(scale.x + 0.001, scale.y + 0.001);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sprite.setScale(scale.x - 0.001, scale.y - 0.001);
        }
       
        sf::Vector2f pos = sprite.getPosition();
        //sprite.setPosition(pos.x + 0.5, pos.y);

        if(pos.x > 200)
        {
            speed = -0.5;

        }
        else if(pos.x < 20)
        {
            speed = 0.5;
        }
        sprite.setPosition(pos.x + speed, pos.y);

        window.clear();
        window.draw(shape);
        window.draw(sprite);

        window.display();
        
    }

    return 0;
}