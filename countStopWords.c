#include"headerA3.h"
#include"myheader.h"

void countStopWords(tweet * tweetList)
{
  int no_of_tweets=0, count=0;
  for(tweet *temp=tweetList;temp!=NULL;temp=temp->next, no_of_tweets++){;} //counting the number of tweets
  char stopwords[25][5]={"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its","of","on","that","the","to","was","were","will","with"};
  for(int i=0;i<25;i++){
    char* word=stopwords[i];
    //going through each tweet
    tweet *temp=tweetList;
    while(temp!=NULL){
      //storing the tweet in lowercase in text
      int n=strlen(temp->text);
      char text[1+n]; strcpy(text, temp->text);
      for(int j=0;j<n;j++){text[i]=tolower(text[i]);}

      //breaking the string into individual words and checking if it is a stopword
      char *token=strtok(text," ,.-!?");
      while(token!=NULL){
        if(strcmp(token,word)==0){count++;}
        token=strtok(NULL," ,.-!?");
      }
      temp=temp->next;
    }
  }
  printf("Across %d tweets, %d stop words were found.\n",no_of_tweets,count);
}

