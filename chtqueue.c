#include <stdio.h>
#include<stdlib.h>


#define MAXLIST 10
typedef char ListData;
typedef int position;

typedef struct {

   int count;
   ListData entry[MAXLIST];

} List;


void createList(List*l){

  l->count=0;
}


#define TRUE 1
#define FALSE 0

int isListEmpty(List*l){

return(l->count==0)? TRUE : FALSE;

}

int isListFull(List*l){

return(l->count==MAXLIST)? TRUE : FALSE;

}

int ListSize(const List*l){

   return l->count;
}



void Insert(List*l,ListData x){

   if(isListFull(l)){
    printf("Full\n");
    exit(1);
   }
   else{
    l->entry[l->count++]=x;
   }


}
   void DisplayList(const List*l){

     if(isListEmpty(l)){
        printf("empty\n");
        exit(1);
     }
     else{
        printf("list elements:");
        for(int i=0; i< l->count;i++){
            printf("%c",l->entry[i]);
        }
         printf("\n");
     }

   }


   int main(){

      List myList;
    CreateList(&myList);


int n;
    printf("Enter the number of elements to insert (max %d): ", MAXLIST);
    scanf("%d", &n);


    if (n > MAXLIST || n <= 0) {
        printf("Invalid number of elements! Must be between 1 and %d.\n", MAXLIST);
        return 1;
    }
   for(int i=0;i<n;i++){
    char value;
      printf("Enter element %d: ", i + 1);
        scanf(" %c", &value);  // Space before %c to handle any trailing newline issues
        Insert(&myList, value);
    }
    printf("Before sorting:\n");
    DisplayList(&myList);

    return 0;
   }







