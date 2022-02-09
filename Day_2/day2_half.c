#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum direction
{
    up,
    down,
    forward
} direction;

direction match_dir(char *data)
{
    int diff = strcmp(data, "forward");
    if (diff == 0)
        return forward;
    else if (diff < 0)
        return down;
    else
        return up;
}

typedef struct list
{
    direction dir;
    int val;
    struct list *next;
} list;

list *push_begin(list *first, direction dir, int data)
{
    list *new = (list *)malloc(sizeof(list));
    new->dir = dir;
    new->val = data;
    if (first == NULL)
        new->next = NULL;
    else
        new->next = first;
    return new;
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
    FILE *fp = fopen("input.txt", "r");
    char word[8];
    int value;
    while (fscanf(fp, "%s %d", word, &value) != EOF)
    {
        vector = push_begin(vector, match_dir(word), value);
    }
    fclose(fp);
    int horizontal = 0, depth = 0;
    for (list *i = vector; i != NULL; i = i->next)
    {
        switch (i->dir)
        {
        case forward:
            horizontal += i->val;
            break;
        case up:
            depth -= i->val;
            break;
        case down:
            depth += i->val;
            break;
        }
    }
    printf("output = %d", horizontal * depth);
    free_list(vector);
}