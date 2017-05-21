#include <stdio.h>
#define max 1000

int main()
{
    char last,c;
    char s[max];
    int i=0;
    while((c=getchar())!=EOF)
    {
        if(c!=' ')
            s[i++] = c;
        else if(last!=' ')
            s[i++] = c;

        last = c;
    }
    printf("%s",s);
}
