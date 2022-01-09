#include"headerA3.h"
#include"myheader.h"


int searchTweetsByKeyword(tweet * tweetList)
{
  int found=0;
  //asking for keyword; checks for validity of length and only allows non-zero length input
  char keyword[52], copy_keyword[51];
  for(int n=0;;)
  {
    printf("Enter a keyword to search: ");
    if(fgets(keyword, 52, stdin)!=NULL && (n=strlen(keyword))>1)
    {
      if(keyword[n-1]!='\n'){
        fflush(stdin);
        printf("Too long input\n");
        continue;
      }
      keyword[n-1]=0;
      //convert keyword to lowercase and save in copy
      for(int i = 0; i<=n-1; i++) //'='signs ensures that the null char is also copied
        copy_keyword[i] = tolower(keyword[i]);
      break;
    }
    fflush(stdin);
    printf("Invalid input\n");
  }
  char copy_txt[141]; //this will store the lowercase copy of the text
  while(tweetList!=NULL)
  {
    char* txt=tweetList->text;
    //convert text to lowercase and save in copy
    for(int i = 0,n=strlen(txt); i<=n; i++){
    copy_txt[i] = tolower(txt[i]);
    }

    if(strstr(copy_txt,copy_keyword)!=NULL){
      printf("Match found for \'%s\': %s wrote: \"%s\"\n",keyword,tweetList->user,tweetList->text);
      found=1;
    }
    tweetList=tweetList->next;
  }
  return found;
}

