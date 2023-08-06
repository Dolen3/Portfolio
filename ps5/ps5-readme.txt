/**********************************************************************
 *  readme 
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Dan Olen and Hunter M Hasenfus

Hours to complete assignment: 4 hours

/**********************************************************************
 * Explain which approach you decided to use when implementing
 * (either recursive with memoization, recursive without memoization,
 * dynamic programming or Hirschberg’s algorithm). Also describe why
 * you chose this approach and what its pros and cons are.
 **********************************************************************/

-The dynamic programming approach is used to calculate the edit distance between two strings. 
The choice of this approach is based on its efficiency and relative ease of implementation. 
-The method stores intermediate results in a two-dimensional vector, thus avoiding redundant computations
-This approach is more efficient than the recursive method without memoization, which can have exponential time complexity. 
-Although recursive with memoization and Hirschberg's algorithm can also be efficient, dynamic programming is often simpler to 
implement and understand. The main disadvantage of dynamic programming is that it can consume more memory than other methods, 
particularly when working with very long strings.



/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: atattat
        tattata

Expected output:
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2
What happened:
The program added gaps to the beginning and end of the strings which allowed for allignment of every character except for the first and last. 


/**********************************************************************
 * Look at your computer’s specs in the settings. 
 * How much RAM does your computer have and explain what this means? 
 **********************************************************************/
-My computer has 32g of RAM 
-It means that I have 32g of temporary memory that can be used by my CPU
-More ram = my pc can run a larger amount of data and run multiple applications simultaneously


/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 4 
b = N/2 
largest N = 2M

/**********************************************************************
 * Run valgrind if you can and attach the output file to your submission. 
 * If you cannot run it, explain why, and list all errors you’re seeing. 
 * If you can run it successfully, does the memory usage nearly match that 
 * found in the question above? 
 * Explain why or why not. 
/**********************************************************************
105,581 bytes allocated 
    -


/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt       120             12.245              44,261.103
ecoli5000.txt       162             47.287              175,922.671
ecoli7000.txt       196             95.603              344,241.293
ecoli10000.txt      225             195.63              701,749.818
ecoli20000.txt      3135            748.059             2,819,717.812
ecoli28284.txt      Too long runtime

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 0.1
b = 0.8
largest N = ?


**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where 
 * (describe a method or provide a lines numbers)
 **********************************************************************/
N/A



**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
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