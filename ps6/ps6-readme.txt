/**********************************************************************
 *  readme.txt template                                                   
 *  Random Writer 
 **********************************************************************/

Name: Daniel Olen
Hours to complete assignment: 6

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment is about implementing a random text generator
called RandWriter. The program creates a text based on a given
input text by analyzing the frequency of characters and k-grams
(substrings of length k) in the input text. The program generates
a new text of specified length based on these frequencies.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
An unordered_map to store the k-grams and their frequencies
A random number generator for selecting the next character
An implementation of the RandWriter class

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
Constructor: Initializes the RandWriter object with the given
Functions to get the frequency of k-grams and characters
kRand function: Returns a random character based on the
generate function: Generates a new text of specified length

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
The whole assignment was completed successfully.
All the implemented features are working as expected.
Test cases in the test.cpp file confirm the correctness of the
implemented features.

/**********************************************************************
 *  Does your implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes, the implementation passes the unit tests provided in the
test.cpp file.

 /**********************************************************************
 *  Describe where you used exceptions. 
 *  Provide files and lines of the code.
 ***********************************************************************/
Exceptions were used in the kRand function in RandWriter.cpp
(Line 52) to handle the case when an invalid k-gram is provided.

 /**********************************************************************
 *  Describe where you used lambda expression if any
 *  Provide files and lines of the code.
 ***********************************************************************/
I introduced the use of a lambda expression in the kRand method of the RandWriter class. 
The lambda expression is used as a default argument for the dist_func parameter, which allows 
for custom random distribution functions to be passed to the method. If no custom distribution 
function is provided, the method will use a default uniform random distribution function.

RandWriter.h
Line 21: Added a new parameter std::function<int(const std::vector<char>&)> dist_func with a default value of an empty lambda {}.

RandWriter.cpp
Line 46: Updated the kRand method definition to include the new dist_func parameter with a default value.
Lines 62-65: Added a check to see if the dist_func is empty and assigned it a default uniform random distribution function if needed.
Line 67: Used the dist_func to obtain a random index from the chars vector.

/**********************************************************************
 *  Did you implemented program for extra poits? If yes, describe your 
 *  If yes, describe your implementation.
 ***********************************************************************/
N/A


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
N/A


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
N/A


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A