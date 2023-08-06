/**********************************************************************
 *  Recursive Graphics ((Pythagoras Tree) ps3-readme.txt template
 **********************************************************************/

Name: Hunter Hasenfus and Dan Olen
Hours to complete assignment: 3 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment's objective was the create a primary function that recursively drew a fractal like image. Fractals are dictated by their self-similarity, and in this drawing, at the top of each square the triangle is drawn.
Whereby each triangle can make two more squares. The recursive function has a base case, which allows for setting a finite limit on the number of calls. In our assignment, we were able to first create a function that worked for the 45 degree
triangle, then afterwards we implemented the function for all angles between 1-89. We then added a coloring scheme that spanned the amount of function calls. 

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
A key data structure in the assignment was a vector of rectangles. This was essential because it allowed us to create rectangles for each function call and store them all in a central data structure. 
Afterwards the draw feature could very easily display all the rectangles that were pushed into the vector. 




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
The extra credit feature we implemented was slightly changing the function so that it could operate with any starting angle, not just 45 degrees. 
The was done by fixing some aspects of the first algorithm so that they were more abstract and not specifically catered towards 45 degrees. 
One feature I implemented was forming a mapping from the cartesian coordinates into the video window coordinates. The dx and dy were conceptually born from the understanding of cosine and sin in 
the cartesian plane, so the mapping made the entire problem much easier. 
Lastly the coloring was implemented with two different methods, one of logarithmic and one linear. 



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
NA

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
The coordinate scheme for the video windows is rough. 

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 NA