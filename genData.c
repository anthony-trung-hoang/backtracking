#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void genData(char *filename, int n, int MAX_VALUE)
{
    FILE *f = fopen(filename, "w");
    fprintf(f, "%d\n", n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x = rand() % MAX_VALUE + 1;
            if (i == j)
                x = 0;
            fprintf(f, "%5d", x);
        }
        fprintf(f, "\n", i);
    }
    fclose(f);
}

int main()
{
    char *fileName = "tsp.txt";
    genData("tsp.txt", 5, 25);
    return 0;
}