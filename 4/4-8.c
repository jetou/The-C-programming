#include <stdio.h>

int buf = EOF;

int getch(void)
{
    int temp;

    if(buf != EOF){
        temp = buf;
        buf = EOF;
    } else {
        temp = getchar();
    }
    return temp;
}

void ungetch(int c)
{
    if(buf != EOF)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}

int main(void)
{
    int c;

    while((c = getch())!=EOF){
        if( c == '/'){
            putchar(c);
            if((c = getch()) == '*'){
                ungetch('!');
            }
        }
        putchar(c);
    }
    return 0;
}
