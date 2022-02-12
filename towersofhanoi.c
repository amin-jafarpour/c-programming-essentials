#include<stdio.h>
#include<stdlib.h>

char pop(char* rod);
void push(char* rod, char disk);
void printRods(int diskNum, char* from, char* aux, char* to);
void hanoi(int diskNum, char* from, char* aux, char* to);

//global variables
char gfrom[] = "ABCD";
char gaux[] = "****";
char gto[] = "****";
int disks = 4;


int main(int argc, char* argv[])
{

    printRods(disks, gfrom, gaux, gto);

    hanoi(disks, gfrom, gaux, gto);
    return 0;
}

char pop(char* rod)
{
    char temp;
    for (int i = 0; rod[i]; ++i)
    {
        if (rod[i] != '*')
        {
            temp = rod[i];
            rod[i] = '*';
            return temp;
        }
    }

    printf("Error: cannot pop an empty rod\n");

    return '*';
}

void push(char* rod, char disk)
{
    int index = -1;
    for (int i = 0; rod[i]; ++i)
    {
        if (rod[i] != '*')
        {
            break;
        }
        else
        {
            index = i;
        }
    }

    if (index != -1)
    {
        rod[index] = disk;
        return;
    }
    printf("Error: cannot push onto a full rod\n");
}


void printRods(int diskNum, char* from, char* aux, char* to)
{

    if (*from == '\0' || *aux == '\0' || *to == '\0')
    {
        printf("Error: invalid rod detected\n");
        return;
    }
    if (diskNum <= 0)
    {
        printf("Error: invalid disk number\n");
        return;
    }

    for (int i = 0; i < diskNum + 1; ++i)
    {
        printf("%c  %c  %c\n", from[i], aux[i], to[i]);
    }

    printf("\n\n");
}

void hanoi(int diskNum, char* from, char* aux, char* to)
{
    if (diskNum == 1)
    {
        push(to, pop(from));
        printRods(disks, gfrom, gaux, gto);
        return;
    }
    hanoi(diskNum - 1, from, to, aux);
    push(to, pop(from));
    printRods(disks, gfrom, gaux, gto);
    hanoi(diskNum - 1, aux, from, to);

}