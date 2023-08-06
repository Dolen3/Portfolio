#ifndef PTREE_H
#define PTREE_H

#include <SFML/Graphics.hpp>
#include <vector>

class PTree : public sf::Drawable {
public:
    // Constructor with two arguments, takes in the length of a rectangle and the number of iterations
    PTree(double L, int N, double startingAngle);

private:
    // Override the draw function from sf::Drawable to draw the rectangles in the window
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    // Recursive function to generate the Pythagoras Tree
    void pTree(double L, int N, double x, double y, double angle, double startingAngle);
    
    // Vector to store the rectangles that make up the tree
    std::vector<sf::RectangleShape> m_rectangles;

    double logColor;
    double linColor;
};

#endif
