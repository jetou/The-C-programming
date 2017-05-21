#include <stdio.h>
int main()
{

    int c;
    int inspace;

    inspace = 0;
    while((c = getchar())!=EOF)
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            if(inspace = 0)
            {
                inspace = 1;
                putchar('\n');
            }
        }
        else
        {
            inspace = 0;
            putchar(c);
        }
    }
    return 0;
}
