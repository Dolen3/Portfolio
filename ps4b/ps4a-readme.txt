/**********************************************************************
 *  Checkers ps4b-readme.txt template
 **********************************************************************/

Name: Daniel Olen
Hours to complete assignment: 10-15

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
Assignment is to add gameplay elements to the checkers program such as:
-Moving pieces
-Jumping pieces
-Capturing pieces
-Detecting victory

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
-The program follows object-oriented design principles by encapsulating the checkers game logic within a Checkers class. 
This class contains private member functions, such as loadTextures, setupBoard, isValidMove, and movePiece, which are responsible 
for managing the game state and handling player actions. The class also contains private member variables, such as the pieces 
vector and the selectedPiece pointer, which store the current state of the game.

std::vectorsf::Sprite pieces: This vector stores all the checkers pieces currently on the board as sf::Sprite objects. 
Each piece has an associated texture and position on the board.

-The algorithm used is the "find_if" algorithm which searches for the first element in the given range that satisfies
the condition. In this case its used to check if the position is within the piece's global bounds.

-A lambda expression is used as a function parameter for the findPiece function.
The findPiece function expects a parameter of type std::function<bool(const sf::Sprite&)>
The lambda expression passed as the argument to findPiece captures the position variable by reference, 
takes a const sf::Sprite& parameter, and returns a bool. The lambda checks if the given sprite's bounding 
rectangle contains the position. If it does, it returns true; otherwise, it returns false.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
-Drawing the board and pieces:
The draw function is responsible for drawing the board squares and pieces on the screen. 
It uses a nested loop to draw the squares and iterates through the pieces vector to draw each piece.

-Handling user input:
The click function is called when a mouse button is pressed. It determines if a piece is being selected 
or moved based on the selectedPiece variable. It also validates moves and switches turns between players.

-Validating moves:
The isValidMove function checks if the move being attempted is valid based on the piece type, 
destination square, and whether or not it is a jump move.

No smart pointers were used

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
My friend Danny

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Sometimes the capture piece function captures other pieces or replaces pieces(?)
It doesnt work properly some of the time

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
I wanna explain the the bugs and show my expected grade:
-The only bug I have has to do with capturing pieces
- THE JUMPING WORKS PROPERLY, if you take out the capture pieces, the jumping NEVER performed wrong.
So for my grade I think something like this(?)

1/1 Compiles and displays the current game state 
2/2 Can select and move pieces to open spaces
2/2 Pieces can move one space
2/2 Pieces can jump another piece
0.5/1 Captured pieces are removed (works atleast 50% of the time)
1/1 Pawns are crowned at the last row
1/1 Direction restrictions are observed
0/1 Detects and announces victory (could not get this to work without seg faulting)
1/1 Passes a lambda expression as a function parameter
1/1 Invokes a function from the <algorithm> library

1/1 cpp lint

dolen@DESKTOP-N6SLAQ4:/mnt/d/Comp4/ps4$ make lint
cpplint *.cpp *.h
Done processing Checkers.cpp
Done processing Checkers.h
Done processing main.cpp

2/2 readme

2/2 makefile

1 extra credit (highlighted moves)

?/1 jumps are recquired (im not sure what it means by jumps are recquired)

screenshots ✓

total ~17.5 