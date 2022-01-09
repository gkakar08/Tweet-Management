#include"headerA3.h"
#include"myheader.h"

int main(void)
{
  srand(time(0));
  int option=0;
  tweet *tweetList=NULL; //the link listed to be used to store tweets
  while(option!=8)
  {
    printf("1. Create a new tweet\n2. Display tweets\n3. Search a tweet\n4. Find no. of stop words\n5. Delete the nth tweet\n6. Save tweets to a file\n7. Load tweet from a file\n8. Exit\n");
    option=getOption();
    switch (option) {
    case 1:
      ; tweet* node=createTweet(tweetList);
      if(node==NULL){printf("Could not create tweet\n");  return 1; }
      else
        addNodeToList(&tweetList,node);
      break;
    case 2:
      displayTweets(tweetList);
      break;
    case 3:
      searchTweetsByKeyword(tweetList);
      break;
    case 4:
      countStopWords(tweetList);
      break;
    case 5:
      deleteTweet(&tweetList);
      break;
    case 6:
      saveTweetsToFile(tweetList);
      break;
    case 7:
      loadTweetsFromFile(&tweetList);
      break;
    case 8:
      //free all memory
      ;tweet* temp=tweetList;
      while(tweetList!=NULL){
        tweetList=tweetList->next;
        free(temp);
        temp=tweetList;
      }
      return 0;
    }
  }
}


