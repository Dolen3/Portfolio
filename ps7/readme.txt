/**********************************************************************
 *  readme.txt template                                                   
 *  PS7 Kronos 
 **********************************************************************/

Name: Daniel Olen


Hours to complete assignment: 5


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, the whole assignment has been completed successfully. The provided code reads the input 
log file, parses the necessary information, and generates the output file with the desired format.

Reading the input log file and writing to the output file - This is working as the code successfully 
reads the log file provided as an argument and creates the output file with the ".rpt" extension.

Parsing the log file using regular expressions - This is working as the code is able to extract the 
necessary information, such as timestamps, boot start, and boot complete messages, using regular expressions.

Calculating the boot time - This is working as the code uses the Boost date_time library to calculate the time 
difference between the boot start and boot complete messages and report the boot time in milliseconds.

/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
std::regex timestamp_pattern(R"((\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}))");
This regex pattern is designed to match timestamps in the log file. It captures the following format: 
YYYY-MM-DD HH:mm:ss. Each part of the timestamp is a sequence of digits separated by hyphens, colons, and spaces.

std::regex boot_start_pattern(R"(\((log\.c\.166)\) server started)");
This regex pattern matches lines in the log file that indicate the server has started. It looks for the 
string (log.c.166) server started. This pattern helps to identify the boot start events in the log file.

std::regex boot_complete_pattern(R"(oejs\.AbstractConnector:Started SelectChannelConnector@\d+\.\d+\.\d+\.\d+:\d+)");
This regex pattern matches lines in the log file that indicate the server has completed booting. It looks for strings that 
start with oejs.AbstractConnector:Started SelectChannelConnector@ followed by an IP address and port number separated by colons. 
This pattern helps to identify the boot complete events in the log file.

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
The overall approach for solving this problem involves reading the log file line by 
line, parsing the necessary information using regular expressions, and writing the 
output in the desired format to an output file. The Boost date_time library is used 
to handle time-related calculations.


/**********************************************************************
 *  Did you use lambda expression? If yes describe there.
 **********************************************************************/
N/A




/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
N/A



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
<regex> was CPP lint erroring so I got the config file from Daly's class to fix it



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A
