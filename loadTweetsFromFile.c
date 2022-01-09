#include"headerA3.h"
#include"myheader.h"


void loadTweetsFromFile(tweet ** tweetList)
{
  //asking for filename; checks for validity of length and only allows non-zero length input
  char filename[52];
  for(int n=0;;)
  {
    printf("Enter a filename to load from: ");
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
  FILE* fp=fopen(filename,"r");
  if(fp==NULL){printf("Error opening file\n"); fclose(fp); return;}

  //reading line by line input
  char buffer[250];
  while(fgets(buffer,250,fp)!=NULL)
  {
    tweet* node=malloc(sizeof(tweet));
    if(node==NULL){printf("Error creating tweet\n");fclose(fp); return;}
    node->next=NULL;

    char* token;
    token=strtok(buffer,", "); //token stores id
    node->id=atoi(token);     //id is stored

    token=strtok(NULL,", "); //token stores username
    strcpy(node->user,token);//username is stored

    token=strtok(NULL,"\n"); //token stores text
    strcpy(node->text,token);//txt is stored

    addNodeToList(tweetList,node);
  }
  printf("Tweets imported\n");
}

