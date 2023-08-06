#include <iostream>
#include <string>
#include "FibLFSR.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void transform(sf::Image& image, FibLFSR* lfsr)
{
    sf::Color p;

    for (int x = 0; x<1441; x++) {
		for (int y = 0; y< 1079; y++) {
			p = image.getPixel(x, y);
			p.r ^= lfsr->generate(8);
			p.g ^= lfsr->generate(8);
			p.b ^= lfsr->generate(8);
			image.setPixel(x, y, p);
		}
	}
}



int main(int argc, char* argv[])
{
    const int border = 40;
    sf::Image in;
    sf::Image out;

    std::string inFile;
    std::string outFile;
    std::string seed = "1011011000110110";

    if (argc < 3)
        return -1;
    else {
        inFile = argv[1];
        outFile = argv[2];
        if (argc > 3)
            seed = argv[3];
    }

    if (!in.loadFromFile(inFile))
        return -1;
    else
        out = in;

    FibLFSR* photo = new FibLFSR(seed);

    transform(out, photo);

    delete photo;

    if (!out.saveToFile(outFile))
        return -1;

    sf::Vector2u size = in.getSize();
    size.x += (border * 2);
    size.y += (border * 2);
    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Original"); 
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output");

    sf::Texture inTexture;
    inTexture.loadFromImage(in);
    sf::Texture outTexture;
    outTexture.loadFromImage(out);

    sf::Sprite inSprite;
	inSprite.setTexture(inTexture);
    sf::Sprite outSprite;
	outSprite.setTexture(outTexture);

    while (window1.isOpen() && window2.isOpen())
	{
		sf::Event event;
        while (window1.pollEvent(event) || window2.pollEvent(event)) 
        {		
			if (event.type == sf::Event::Closed)
				window1.close();
				window2.close();
		}

		window1.clear();
        window2.clear();
        window1.draw(inSprite);
        window2.draw(outSprite);
        window1.display();
        window2.display();

    }
  
    return 0;
}