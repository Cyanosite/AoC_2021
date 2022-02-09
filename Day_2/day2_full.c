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

list *push_end(list *first, direction dir, int data)
{
    list *new = (list *)malloc(sizeof(list));
    new->dir = dir;
    new->val = data;
    new->next = NULL;
    if (first == NULL)
        return new;
    else
    {
        list *i = first;
        for (; i->next != NULL; i = i->next)
            ;
        i->next = new;
        return first;
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
    FILE *fp = fopen("input.txt", "r");
    char word[8];
    int value;
    while (fscanf(fp, "%s %d", word, &value) != EOF)
    {
        vector = push_end(vector, match_dir(word), value);
    }
    fclose(fp);
    int horizontal = 0, depth = 0, aim = 0;
    for (list *i = vector; i != NULL; i = i->next)
    {
        switch (i->dir)
        {
        case forward:
            horizontal += i->val;
            depth += i->val * aim;
            break;
        case up:
            aim -= i->val;
            break;
        case down:
            aim += i->val;
            break;
        }
    }
    printf("output = %d", horizontal * depth);
    free_list(vector);
}