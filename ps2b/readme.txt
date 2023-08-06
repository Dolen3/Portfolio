/**********************************************************************
 *                                                  
 *  PS2b: Sokoban
 **********************************************************************/

Name: Daniel Olen

Hours to complete assignment : 12 - 15

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
-I completed everything except the lambda expression
-Every part is working properly because I have tested every level and scenario made changes to my functions accordingly 

/*********************************************************************
*1 point: Describes the algorithms or data structures used.
*1 point: Describes how the features were implemented.
**********************************************************************/
-movePlayer() uses std::find to find the '@' symbol for the players positions and stores the columns and rows in placeholder variables
-I don't use any data structures except for my array if that counts(?)

Implementation:
-The move player function uses a lot of logic to check various things such as;
What are you moving into?
Can you move into it?
What is the new tile you need to make when moving into it?
What does the old tile become?
etc...

-The board is updated in real time throughout the movePlayer function

-User input is done simply in the main function with "while player is pressing 'key'" loops
-isWon function counts the number of victory conditions on the board at a given time and uses logic to determine if the game is won
-Draw function makes 3 sprites because I created a new tile for when the player is on an empty storage space, other than that the max number of
sprites needed is 2, for player on tile and box on tile.

-Also 1 more sprite for victory with all textures declared in the constuctor so they are only initialized once

-Victory features, the game stops, a new sprite 'vSprite' is drawed to the screen if isWon() == textures
-Music plays by inheriting the music class, #including SFML/Audio, and putting -lsfml-audio in the makefile
-Checks before the next loop if the game isWon, if it is, it plays musi

/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  
 **********************************************************************/
-I addeda victory image and sound
-Yes successful because the sound plays on victory and when the level is reset it stops
-Same applies to image^


/**********************************************************************
 *  Did your code pass cpplint?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
-Yes, I had to "make lint" a lot and slowly fix simply linting errors such as white spaces, blank lines, and bracket {} notation

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
-Classmate danny
-Professor Daly


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
-Getting music to play, tried to play it in the draw functin and in the window while loop
didn't realize the music was constantly going out of scope and being deleted

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 CITATIONS
 Image:
 Victory Royale. Epic Games, https://www.epicgames.com/site/en-US/home. 

Fortnite Fair Use Policy: Allows for the use of copyrighted material for specific purposes such as education, criticism, news reporting, research, and scholarship. 
Using a small and limited amount of Fortnite images for your schoolwork is ok.

 Song:
 “Leviathan - Chug Jug With You (Lyrics) | number one victory royale yeah fortnite we bout to get down
” YouTube, uploaded by TikTokTunes, 16/2/2021, https://www.youtube.com/watch?v=QqRLVFRe9AU