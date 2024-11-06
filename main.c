#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse_content (FILE *filepointer)
{
    char D[100];
    if(fgets(D, sizeof(D), filepointer) == NULL)
    {
        return;
    }
    else
    {
        reverse_content(filepointer);
        printf("%s",D);
    }
}

int main()
{
    char D[100];
    char stack[10][100];
    int top = -1;

    FILE *filepointer = fopen("Recursion.txt","a");

    //step1:Create file with some data
    if(filepointer == NULL)
    {
        puts("Cannot open file");
        exit(1);
    }
    printf("Enter few lines :\n");
    while(strlen(gets(D)) > 0)
    {
        fputs(D,filepointer);
        fputs("\n",filepointer);
    }
    fclose(filepointer);

    //step2:Read and Display file content
    printf("\nFile contents are being read now....\n",D);
    filepointer = fopen("Recursion.txt","r");
    if(filepointer == NULL)
    {
        puts("cannot open file");
        exit(2);
    }
    while(fgets(D,99,filepointer) != NULL)
    {
        printf("%s",D);
    }
    fclose(filepointer);

    //Reverse file content using Recursion
    printf("Reversed content:\n");
    filepointer = fopen("Recursion.txt","r");
    if(filepointer == NULL)
    {
        puts("cannot open file");
    }
    else
    {
        reverse_content(filepointer);
        fclose(filepointer);
    }

    return 0;
}

