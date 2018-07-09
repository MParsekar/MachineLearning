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
char **initialiseS_set(char ***versionSpace,  int numberExample, int numberVar);
void printsSet(char **sSet,int numberVar);
char ***initialiseG_set( int numberVar);
void printGset(char ***gSet, int numberVar);
void processVersionSpace(char ***versionSpace, char ***gSet,char **sSet,int numberExample, int numberVar );
// first.c starts here
int main(int argc, char *args)
{
    int numberExample, numberVar;
    char ***versionSpace, ***gSet=NULL, **sSet;
    printf("\nEnter the total number of examples:\t");
    scanf("%d", &numberExample);
    printf("\nEnter the total number of variables:\t");
    scanf("%d", &numberVar);
    
    versionSpace = acceptVersionSpace(numberExample, numberVar);
    // printVersionSpace(versionSpace, numberExample, numberVar);
    
    // iniitalise sSet
    sSet=initialiseS_set(versionSpace, numberExample, numberVar);
    printsSet(sSet, numberVar);
    //inititialise gSet
    gSet=initialiseG_set(numberVar);
    printGset(gSet, numberVar);

    //version space processing

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

char **initialiseS_set(char ***versionSpace,  int numberExample, int numberVar){
    int i=0,j;
    while(i<numberExample){
        printf("%s\n", versionSpace[i][0]);
        if(!strcmp(versionSpace[i][numberVar-1],"positive")){
            return versionSpace[i];
        }else{
            i++;
        }
    }
    return NULL;
}

void printsSet(char **sSet,int numberVar){
     int j;
     if(sSet){
        for(j=0;j<numberVar;j++)
            printf("%s\t", sSet[j]);
     }else{
         perror("S set is null");
     }
     
}


char ***initialiseG_set( int numberVar){
   
    char snum[5];
    char *constX="x";
    
    int col, row;
    char ***gSet;
    if (((gSet = (char ***)malloc(numberVar * sizeof(char **))) != NULL))
    {
        for (row = 0; row < numberVar; row++)
        {
            if (((gSet[row] = (char **)malloc(numberVar * sizeof(char *))) != NULL))
            {
                for (col = 0; col < numberVar; col++)
                {
                    if (((gSet[row][col] = (char *)malloc(MAXSIZEWORD * sizeof(char))) != NULL))
                    {
                         itoa(col+1, snum, 10);
                         strcpy(gSet[row][col], snum);
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
    return gSet;
}

void printGset(char ***gSet, int numberVar)
{
    int col, row;
    for (row = 0; row < numberVar; row++)
    {
        for (col = 0; col < numberVar; col++)
            printf("%s\t", gSet[row][col]);
        printf("\n");
    }
}

void processVersionSpace(char ***versionSpace, char ***gSet,char **sSet,int numberExample, int numberVar ){ 
    int row, col, row1;
    for(row=0;row<numberExample;row++){
        if(!strcmp(versionSpace[row][numberVar-1],"positive")){
            // for(col=0;col<numberVar;col++){
                //sSet
                // if(versionSpace[row][col])
            //  }//elimination over here
        }
        else{
            for(row1=0;row1<numberVar;row1++){
                    if(strcmp(versionSpace[row][row1],sSet[row1])){
                        strcpy(gSet[row1][row1], sSet[row1]);
                    }
            }
        }
    }
}