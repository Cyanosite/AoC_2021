#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} list;

list *push_begin(list *first, int i)
{
    if (first == NULL)
    {
        first = (list *)malloc(sizeof(list));
        first->data = i;
        first->next = NULL;
        return first;
    }
    else
    {
        list *new = (list *)malloc(sizeof(list));
        new->data = i;
        new->next = first;
        return new;
    }
}

void free_list(list *first)
{
    while (first != NULL)
    {
        list *temp = first->next;
        free(first);
        first = temp;
    }
}

int main()
{
    list *vector = NULL;
    FILE *input = fopen("input.txt", "r");
    int line;
    while (fscanf(input, "%d", &line) != EOF)
        vector = push_begin(vector, line);
    for (list *i = vector; i->next->next->next != NULL; i = i->next)
        i->data += i->next->data + i->next->next->data;
    int counter = 0;
    for (list *i = vector->next; vector->next->next->next != NULL; i = i->next, vector = vector->next)
        if (vector->data > i->data)
            ++counter;
    printf("Output = %d", counter);
    free_list(vector);
}
