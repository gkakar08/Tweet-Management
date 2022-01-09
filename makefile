a3: main.o countStopWords.o loadTweetsFromFile.o saveTweetsToFile.o deleteTweet.o searchTweetsByKeyword.o addNodeToList.o displayTweets.o createTweet.o getOption.o
	gcc -Wall -std=c99 main.o countStopWords.o loadTweetsFromFile.o saveTweetsToFile.o deleteTweet.o searchTweetsByKeyword.o addNodeToList.o displayTweets.o createTweet.o getOption.o -o a3

loadTweetsFromFile.o: loadTweetsFromFile.c headerA3.h
	gcc -Wall -std=c99 -c loadTweetsFromFile.c

saveTweetsToFile.o: saveTweetsToFile.c headerA3.h
	gcc -Wall -std=c99 -c saveTweetsToFile.c

deleteTweet.o: deleteTweet.c headerA3.h
	gcc -Wall -std=c99 -c deleteTweet.c

getOption.o: getOption.c headerA3.h
	gcc -Wall -std=c99 -c getOption.c

countStopWords.o: countStopWords.c headerA3.h
	gcc -Wall -std=c99 -c countStopWords.c

searchTweetsByKeyword.o: searchTweetsByKeyword.c headerA3.h
	gcc -Wall -std=c99 -c searchTweetsByKeyword.c

addNodeToList.o: addNodeToList.c headerA3.h
	gcc -Wall -std=c99 -c addNodeToList.c

displayTweets.o: displayTweets.c headerA3.h
	gcc -Wall -std=c99 -c displayTweets.c

createTweet.o: createTweet.c headerA3.h
	gcc -Wall -std=c99 -c createTweet.c

main.o: main.c headerA3.h
	gcc -Wall -std=c99 -c main.c

clean:
	rm *.o a3

