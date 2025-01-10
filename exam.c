
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Contiguous Implementation of List

// Link Definition

#define MAXLIST 10
#define EMPTY 0
#define FULL MAXLIST

typedef enum { FALSE, TRUE } Boolean;
typedef char ListData;
typedef int Position;

typedef struct {
    int count;
    ListData entry[MAXLIST];
} List;

// CREATE LIST
void CreateList(List *l) {
    l->count = 0;
}

// IsListEmpty
Boolean IsListEmpty(const List *l){
    return (l->count == EMPTY);
}

// IsListFull
Boolean IsListFull(const List *l) {
    return (l->count == FULL);
}

//ListSize
int ListSize(const List *l)
{
    return(l->count);
}


// InsertLast
void InsertLast(ListData x, List *l)
{
    if (IsListFull(l)) {
        printf("Attempt to insert at the end of a full list");
        exit(1);
    }
    l->entry[l->count++] = x;
}

/*

//InsertList
void InsertList(Position p,ListData x,List *1)
{
    int i;
    if(IsListFull(l))
    {
        print("Attempt to insert an entry into a list");
    }
    else if(p < 0 || p > ListSize(l))
    {
        print("Attempt to insert a position not in the list")
    }
    else
    {
        for(i ListSize(l) - 1;i>= p;i--)
            l -> entry[i+1] = l-> entry[i];
            l ->entry[p] = x;
            l -> count++;
    }
}


//DeleteList
void DeleteList(Position p,ListData *x,List *1)
{
    int i;
    if(IsListEmpty(l))
    {
        print("Attempt to delete an entry from an empty list")
    }
    else if(p<0 || p>ListSize(l))
        print("Attempt to delete a position not in the list");

    else
    {
        *x = l->entry[p];
        for(i=p;i<ListSize(l);i++)
            l->entry[i] = l->entry[i+1];
        l->count--;
    }
}

//RetrieveList
void RetrieveList(Position p,ListData *x,const List *1)
{
    if(IsListEmpty(l))
    {
        print("Attempt to insert an entry into a full list");
    }else if(p < 0 || p >= ListSize(1))
    {
        print("Attempt to insert a position not in the list");
    }else
    {
        *x = 1->entry[p];
    }
}
*/


// Bubble Sort function
void BubbleSort(List *l) {
    int i, j;
    ListData temp;
    for (i = 0; i < l->count - 1; i++) {
        for (j = 0; j < l->count - 1 - i; j++) {
            if (l->entry[j] < l->entry[j + 1]) {
                // Swap the elements
                temp = l->entry[j];
                l->entry[j] = l->entry[j + 1];
                l->entry[j + 1] = temp;
            }
        }
    }
}

// DisplayList function
void DisplayList(const List *l) {
    if (IsListEmpty(l)) {
        printf("The list is empty.\n");
        return;
    }
    printf("List elements: ");
    for (int i = 0; i < l->count; i++) {
        printf("%c ", l->entry[i]);
    }
    printf("\n");
}

float avg(const List *l)
{
    int sum = 0;

    for(int k = 0; k < 4; k++)
    {
        sum = sum + l->entry[k];
    }

    float mean = (float)sum/4 - '0' ;
    printf("Mean is:%.2f ",mean);


    int *ptr = &mean;
    return mean;
}

float var(const List *l,float mean)
{
    float sd = 0;
    for(int g = 0; g < 4; g++)
    {
        float b = (l->entry[g]) - '0';
        sd = sd + ((b - mean) * (b - mean));
    }

    float sdd = (float)sd/4 ;
    printf("Variance is:%.2f ",sdd);

    return sdd;


}




// Main function
int main() {

    List myList;
    CreateList(&myList);

    int n;
    printf("Enter the number of elements to insert (max %d): ", MAXLIST);
    scanf("%d", &n);

    if (n > MAXLIST || n <= 0) {
        printf("Invalid number of elements! Must be between 1 and %d.\n", MAXLIST);
        return 1;
    }

    // Insert values into the list
    for (int i = 0; i < n; i++) {
        char value;
        printf("Enter element %d: ", i + 1);
        scanf(" %c", &value);  // Space before %c to handle any trailing newline issues
        InsertLast(value, &myList);
    }

    // Display the unsorted list
    printf("Before sorting:\n");
    DisplayList(&myList);

    // Sort the list using Bubble Sort
    BubbleSort(&myList);

    // Display the sorted list
    printf("After sorting:\n");
    DisplayList(&myList);

    float mean = avg(&myList);
    var(&myList,mean);

    return 0;
}
