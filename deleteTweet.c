#include"headerA3.h"
#include"myheader.h"


void deleteTweet(tweet ** tweetList)
{
  tweet* temp=*tweetList;
  int no_of_tweets=0;
  //counting the current number of tweets in the list
  while(temp!=NULL)  {
    no_of_tweets++;
    temp=temp->next;
  }
  printf("Currently there are %i tweets.\n\n",no_of_tweets);
  if(!no_of_tweets)
    return;

  int value=0, max_digits=0, x=no_of_tweets;
  //getting the number of digits in the value of number_of_tweets
  while(x!=0)  {
    max_digits++;
    x/=10;
  }

  //get a valid number between 1 and no_of_tweets from user and store in value
  char buffer[max_digits+2];
  while(1)
  {
    printf("Which tweet do you wish to delete--enter a value between 1 and %i: ",no_of_tweets);
    if(fgets(buffer,max_digits+2,stdin)!=NULL && buffer[strlen(buffer)-1]=='\n')
    {
      buffer[strlen(buffer)-1]=0;
      value=atoi(buffer);
      if(value>0 && value<=no_of_tweets)
        break;
    }
    printf("Invalid input\n");
    fflush(stdin);//clear stdin buffer
  }

  //the actual deletion process
  tweet *curr=*tweetList;
  if(value==1){
    *tweetList=curr->next;
  }
  else{
    for(int i=0;i<value-2;i++){
      curr=curr->next;
    }
    temp=curr;
    curr=curr->next;
    temp->next=curr->next;
  }
  printf("Tweet %i deleted. There are now %i tweets left.\n", curr->id,no_of_tweets-1);
  free(curr);
  return;
}

