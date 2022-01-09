#include"headerA3.h"
#include"myheader.h"

int getOption(void)
{
  int option=0;
  char buffer[3]; //one for '\n' and other for '\0'
  while(1)
  {
    printf("Choose a menu option: ");
    if(fgets(buffer,3,stdin)!=NULL && buffer[strlen(buffer)-1]=='\n')
    {
      buffer[strlen(buffer)-1]=0;
      option=atoi(buffer);
      if(option>=1 && option<=8)
        return option;
    }
    printf("Invalid input\n");
    fflush(stdin);//clear stdin buffer
  }
}
