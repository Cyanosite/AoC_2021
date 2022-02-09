#include <stdio.h>
#include <math.h>

int main()
{
    FILE *fp = fopen("input.txt", "r");
    int common[12] = {0};
    char line[13];
    while (fscanf(fp, "%s", line) != EOF)
    {
        for (int i = 0; line[i] != '\0'; ++i)
        {
            switch (line[i])
            {
            case '0':
                --common[i];
                break;
            case '1':
                ++common[i];
                break;
            }
        }
    }
    fclose(fp);
    int gamma = 0, epsilon = 0;
    for (int i = 0; i < 12; ++i)
    {
        if (common[i] >= 0)
            gamma += pow(2, 12 - i - 1);
        else
            epsilon += pow(2, 12 - i - 1);
    }
    printf("output = %d", gamma * epsilon);
}