#include <stdio.h>
#include <stdlib.h>
int printarr(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {

        printf(" array is[%d] is %d\n", i, *(arr + i));
    }
}
int insertele(int *arr, int size, int position, int element)
{

    int i, newsize;

    printf("enter the position where u want to insert");
    scanf("%d", &position);
    printf("enter the element u want to insert");
    scanf("%d", &element);

    arr = realloc(arr, ((size + 1) * sizeof(int)));
    for (i = size; i > position; i--)
        arr[i] = arr[i - 1];
    arr[position] = element;
    newsize = ++size;
    return newsize;
}
int delelement(int *arr, int size, int index)
{
    int i;
    printf("enter the index you want to delete");
    scanf("%d", &index);
    for (i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1]; //we store the next element after the position into the pevious position
    }
}
int search(int *arr, int query, int size)
{

    int i;

    for (i = 0; i < size + 1; ++i)
        if (arr[i] == query)
            break;

    if (i < size + 1)
        printf("Element found at index %d", i);
    else
        printf("Element not found");
}

int main()
{

    int i;
    int size;
    int *arr;
    int position, element, index, query;

    printf("size of array: \n");
    scanf(" %d", &size);
    arr = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; ++i)
    {
        printf("Enter the arrays:arr[%d]\n", i);
        scanf(" %d", (arr + i));
    }
    size = printarr(arr, size);

    arr = realloc(arr, ((size + 1) * sizeof(int)));

    size = insertele(arr, size, position, element);
    printf(" After Insertion: ");
    for (i = 0; i < size; ++i)
    {
        printf(" showing the arrays : arr[%d] = %d\n", i, *(arr + i));
    }

    size = delelement(arr, size, index);
    printf(" After deletion: ");
    for (i = 0; i < size; ++i)
    {
        printf(" showing the arrays : arr[%d] = %d\n", i, *(arr + i));
    }
    printf("Enter element to search:");
    scanf("%d", &query);
    size = search(arr, query, size);
    
  
 


    return 0;
}
