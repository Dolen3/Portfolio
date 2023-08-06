/**********************************************************************
 *                                                  
 *  PS2a: Sokoban
 **********************************************************************/

Name: Daniel Olen

Hours to complete assignment: 7-8

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes I completed the whole assignment successfully.
-My >> operator takes in the file and reads it to the board with the correct size because I instream the first 2 numbers into rows and cols.
-My draw function reads the board that was created from the file and depending on the character read it prints the sprite to the screen at it's location on the board
-My main function correctly takest the file as a command line argument and reads it.
-Fully passes cpplint

!!!!READ PLEASE!!!!
Use ctrl C when exiting out of the program, do not hit the X button on xlaunch window

linked is a video of it running on my desktop
https://streamable.com/m1uot8


/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  
 **********************************************************************/
I did not attempt, I don't know how I would approach it, could you tell me how in the feedback?


/**********************************************************************
 *  Did your code pass cpplint?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
Yes, except for the error pasted below.
Sokoban.hpp:27:  Is this a non-const reference? If so, make const or use a pointer: sf::RenderTarget & target  [runtime/references] [2]

I did it through simply reading the list of errors and fixing them, errors were 95% white spaces and bracket {} positioning erros

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
My classmate danny and TA


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
-Well I forgot to start the xlaunch.exe program so i was wondering why my program wasnt appearing in the window
-I had some trouble deciding how I wanted to make the board, a 1d array with math, a 2d array, or a vector of vectors. This one seemed easy to make
-I was doing the draw function the wrong way for a while just making a void draw() when I had to use inheritance to get the SFML draw function

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/