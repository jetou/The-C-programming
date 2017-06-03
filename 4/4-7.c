#include <string.h>
#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(const char *s)
{
    size_t i = strlen(s);

    while(i > 0)
        ungetch(s[--i]);
}

int main(void)
{
    char *s = "hello, world!.this is a test.";
    int c;

    ungets(s);
    while((c = getch()) != EOF)
        putchar(c);
    return 0;
}
