#include"headerA3.h"
#include"myheader.h"

void displayTweets(tweet * tweetList)
{
  while(tweetList!=NULL){
    printf("%i: Created by %s: %s\n",tweetList->id,tweetList->user,tweetList->text);
    tweetList=tweetList->next;
  }
}

