#include "PTree.h"
#include <cmath>
#include <iostream>


// Constant value to convert degrees to radians
const double DEG_TO_RAD = M_PI / 180.0;

PTree::PTree(double L, int N, double startingAngle) {
    logColor = pow(255.0 ,(1.0/N));  
    linColor = 255.0/N;  
    // pTree(L, N, 3 * L - L/2, 3 * L, 0);
    pTree(L, N, 3 * L - L/2, 3 * L, 0, startingAngle);
}

void PTree::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Iterates through the vector of rectangles and draws each rectangle on the target
    for (const auto& rect : m_rectangles) {
        target.draw(rect, states);
    }
}

// Recursive function that generates the Pythagoras Tree
void PTree::pTree(double L, int N, double x, double y, double angle, double startingAngle) {
    // Base case: if N is 0, return from the function
    if (N == 0) {
        return;
    }

    

    // Create a rectangle with size L x L
    sf::RectangleShape rect(sf::Vector2f(L, L));
    rect.setPosition(x, y);
    rect.setRotation(-1 * angle);
    rect.setFillColor(sf::Color(255 - pow(logColor, (double)N), pow(logColor, (double)N), linColor * N));
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1.0f);

    // Add the rectangle to the vector of rectangles
    m_rectangles.push_back(rect);

    

    // Convert the angle from degrees to radians
    double angleRad = startingAngle * DEG_TO_RAD;

    // Calculate the new length of the rectangles for the next iteration
    double newL1 = L * sin(angleRad);
    double newL2 = L * cos(angleRad);  
    std:: cout << N << " " << angle << " " << newL2 << std::endl;

    // Convert the angle for the second rectangle from degrees to radians
    double angle2Rad = (angle + startingAngle) * DEG_TO_RAD;

    // Calculate the new x and y coordinates for the first rectangle in the next iteration
    double dx = (newL1 + newL2) * cos(angle2Rad);
    // std:: cout << dx << std::endl;
    double dy = (newL1 + newL2) * sin(angle2Rad);
    // std:: cout << dy << std::endl;

    double newX1, newY1, newX2, newY2;
    if(dx >= 0 && dy >= 0) {
        newX1 = x + abs(dx);
        newY1 = y - abs(dy);
    }
    else if( dx <= 0 && dy <= 0){
        newX1 = x - abs(dx);
        newY1 = y + abs(dy);
    }
    else if( dx <= 0 && dy >= 0){
        newX1 = x - abs(dx);
        newY1 = y - abs(dy);
    }
    else if( dx >= 0 && dy <= 0){
        newX1 = x + abs(dx);
        newY1 = y + abs(dy);
    }
    // std:: cout << dx << " " << dy << std::endl;
    // std:: cout << N << " " << x - newX1 << " " << y - newY1 << std::endl;
    

    

    angle2Rad = (angle + startingAngle + 90) * DEG_TO_RAD;

    // Calculate the new x and y coordinates for the second rectangle in the next iteration
    dx = newL2 * cos(angle2Rad);
    dy = newL2 * sin(angle2Rad);
   
    if(dx >= 0 && dy >= 0) {
        newX2 = x + abs(dx);
        newY2 = y - abs(dy);
    }
    else if( dx <= 0 && dy <= 0){
        newX2 = x - abs(dx);
        newY2 = y + abs(dy);
    }
    else if( dx <= 0 && dy >= 0){
        newX2 = x - abs(dx);
        newY2 = y - abs(dy);
    }
    else if( dx >= 0 && dy <= 0){
        newX2 = x + abs(dx);
        newY2 = y + abs(dy);
    }
    




    // Recursively call the pTree function for the first rectangle with the new parameters
    pTree(newL1, N - 1, newX1, newY1, angle - (90 - startingAngle), startingAngle);
    pTree(newL2, N - 1, newX2, newY2, angle + startingAngle, startingAngle);
}
