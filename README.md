# Tweet-Management
SECTION 1
NAME: Gautam Kakar
USERNAME: gkakar@uoguelph.ca
DATE OF LAST REVISION: Mar 22 2021
SECTION 2
To compile the program, simply type "make" and hit enter on terminal and then type "./a3" and hit enter to run the program.
SECTION 3
 Explanation for every function:
createTweet:
The function starts off by creating a new pointer of type "tweet" and allocates memory of size "tweet" to the pointer. The struct variable's pointer will point to NULL. Now the scanf begins. Scanf will only scan uptil a certain amount of characters. In our case it'd be 50 for the username and 140 for the text. Getchar will check if the last character is a newline. If not, then the scanf will repeat itself until the character length is not exceeded. This function will now calculate the id#. In order to do this, strlen will indicate the length of the username, and the ASCII value will add together. Strlen of the username will also get added to the id#. Along with this, the id will be sent to a function to confirm that this id is unique. If not, then the function will add a random number from 1 to 999. (check function will be explained below)
displayTweets:
If the linked list is empty, the function will return back to main. If the linked list is not empty, then the function will put the list into a while loop until it reaches the last tweet (when tweetList = NULL). It will printf the id, username and text in the required format.
searchTweetsByKeyword:
This function begins by initializing some variables that will be used in the function farther on. The code will scan characters until a newline is entered (using dynamic allocation). This function will now go through every post in the linked list and find its character. It will do this by comparing each character. If the character matches from both characters, the next character of the search word will be compared. If the characters don't match, then the search index will reset and look through the remaining string. Once a match is found, the for loop will break and go to the next linked list element. At the end, the search word will be freed and a 0 or 1 will be returned depending on if a match was found.

CountStopWords:
This function was simply used to count the number of stop words as given by the professor in an attached link. It began simply by going through each tweet and then storing the tweet in lowercase in text and then breaking the string into individual words and checking if it is a stop word.
deleteTweet:
This function is split into cases. First of all, the function will go through a while loop to calculate how many elements the linked list contains. A message will pop up asking the user which element he/she wants to delete. According to the number inputted, the corresponding action will occur. A pointer named transfer will point to the list item that the user wishes delete. Once the list is rearranged, the transfer pointer will be freed.
saveTweetsToFile:
If the linked list is empty, nothing will be saved to the file(function will return), which will save time and allow the function to waste less time. If the linked list isn't empty, then the function will ask the user for the filename it wants to save the list to. After doing that, a file will be opened in write mode. In a while loop, an fprintf will be looped until the linked list doesn’t equal NULL. Once this happened, the file will be closed, and the function will finish.
loadTweetsFromFile:
This function is fairly self-explanatory since the file will scan the same way it printed.
SECTION 4
Although I noticed some error cases in my code, I was successful in fixing each problem in order to make my code run.
SECTION 5
 I personally like creating my code as compact and neat as possible, and in my opinion my code is pretty neat. I hope to make it more compact next time.
