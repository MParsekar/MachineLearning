// Code:        Version Space Machine learning 
// Coder:       Mahadev Parsekar
// Major:       Computer Science
// University:  Goa University
// year:        Third(final)
//Subject:      Machine Learning
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZEWORD 10

//versionSpace.h start here
char ***acceptVersionSpace(int numberExample, int numberVar);
void printVersionSpace(char ***versionSpace, int numberExample, int numberVar);

// first.c starts here
int main(int argc, char *args)
{
    int numberExample, numberVar;
    char ***versionSpace;
    printf("\nEnter the total number of examples:\t");
    scanf("%d", &numberExample);
    printf("\nEnter the total number of variables:\t");
    scanf("%d", &numberVar);
    
    versionSpace = acceptVersionSpace(numberExample, numberVar);
    printVersionSpace(versionSpace, numberExample, numberVar);
    
    return 0;
}

// versionSpace.c starts here
char ***acceptVersionSpace(int numberExample, int numberVar)
{
    int col, row;
    char ***versionSpace;
    if (((versionSpace = (char ***)malloc(numberExample * sizeof(char **))) != NULL))
    {
        printf("***\n");
        for (row = 0; row < numberExample; row++)
        {
            if (((versionSpace[row] = (char **)malloc(numberVar * sizeof(char *))) != NULL))
            {
                printf("Enter example %d\n", row+1);
                for (col = 0; col < numberVar; col++)
                {
                    if (((versionSpace[row][col] = (char *)malloc(MAXSIZEWORD * sizeof(char))) != NULL))
                    {
                        printf("* Memory allocation complete");
                        printf("Enter the name: %d * %d\n", row, col);
                        scanf("%s", versionSpace[row][col]);
                    }
                    else
                    {
                        perror("Malloc at *");
                    }
                }
            }
            else
            {
                perror("Malloc at **");
            }
        }
    }
    else
    {
        perror("Malloc at ***");
    }
    return versionSpace;
}

void printVersionSpace(char ***versionSpace, int numberExample, int numberVar)
{
    int col, row;
    for (row = 0; row < numberExample; row++)
    {
        for (col = 0; col < numberVar; col++)
            printf("%s\t", versionSpace[row][col]);
        printf("\n");
    }
}