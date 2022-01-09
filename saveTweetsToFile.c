#include"headerA3.h"
#include"myheader.h"


void saveTweetsToFile(tweet * tweetList)
{
  if(!tweetList){printf("No tweets to save\n"); return;}
  //asking for filename; checks for validity of length and only allows non-zero length input
  char filename[52];
  for(int n=0;;)
  {
    printf("Enter the filename where you would like to store your tweets: ");
    if(fgets(filename, 52, stdin)!=NULL && (n=strlen(filename))>1)
    {
      if(filename[n-1]!='\n'){
        fflush(stdin);
        printf("Too long input\n");
        continue;
      }
      filename[n-1]=0;
      break;
    }
    fflush(stdin);
    printf("Invalid input\n");
  }
  FILE* fp=fopen(filename,"w");
  if(fp==NULL){printf("Error saving tweets\n"); fclose(fp); return;}

  while(tweetList!=NULL){
    //convert id(int) to string
    int no_of_digits=0;
    for(int x=tweetList->id;x!=0;x=x/10, no_of_digits++){;}
    char buffer[no_of_digits+1];
    sprintf(buffer,"%d",tweetList->id);

    fputs(buffer,fp);
    fputs(", ",fp);
    fputs(tweetList->user,fp);
    fputs(", ",fp);
    fputs(tweetList->text,fp);
    fputs("\n",fp);
    tweetList=tweetList->next;
  }
  fclose(fp);
  printf("Output succesful!\n");
  return;
}

