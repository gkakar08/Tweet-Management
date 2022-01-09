#include"headerA3.h"
#include"myheader.h"


tweet* createTweet(tweet* tweetList)
{
  tweet* node=malloc(sizeof(tweet));
  if(node==NULL)
    return NULL;

  //asking for username; checks for validity of length and only allows non-zero length input
  char buffer[52];
  for(int n=0;;)
  {
    printf("Enter a username: ");
    if(fgets(buffer, 52, stdin)!=NULL && (n=strlen(buffer))>1)
    {
      if(buffer[n-1]!='\n'){
        fflush(stdin);
        printf("Too long input\n");
        continue;
      }
      buffer[n-1]=0;
      strcpy(node->user,buffer);
      break;
    }
    fflush(stdin);
    printf("Invalid input\n");
  }

  //asking for tweet; checks for validity of length; only allows non-zero length input
  char tbuffer[142];
  for(int n=0;;)
  {
    printf("Enter the user's tweet: ");
    if(fgets(tbuffer, 142, stdin)!=NULL && (n=strlen(tbuffer))>1)
    {
      if(tbuffer[n-1]!='\n'){
        fflush(stdin);
        printf("Too long input\n");
        continue;
      }
      tbuffer[n-1]=0;
      strcpy(node->text,tbuffer);
      break;
    }
    fflush(stdin);
    printf("Invalid input\n");
  }

  node->next=NULL;

  //generating the id
  int id=strlen(node->text); //initiailizing the id with length of the user tweet
  for(int i=0,n=strlen(node->user);i<n;i++)
    id+=node->user[i];
  //check if the id exists else keep adding random numbers from 1 to 999
  tweet *temp=tweetList;
  while(temp!=NULL){
    if(id==temp->id){
      id+=(1+(rand()%999));
      temp=tweetList;
    }
    else
      temp=temp->next;
  }
  node->id=id;
  printf("Your computer-generated userid is %d\n",id);
  return node;
}

