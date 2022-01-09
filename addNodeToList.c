#include"headerA3.h"

#include"myheader.h"


void addNodeToList(tweet**tweetList,tweet * node)
{
  tweet* curr=*tweetList;
  if(curr==NULL){
    *tweetList=node;
    return;
  }
  //add the node to the list
  while(curr->next!=NULL)
    curr=curr->next;
  curr->next=node;
  return;
}
