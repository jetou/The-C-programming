#include <stdio.h>
#define max 1000

int main()
{
    char c;
    int i=0;
    char s[max];
    while((c = getchar())!= EOF)
    {
        switch(c){
        case '\t':
            s[i++] = '\\';
            s[i++] = 't';
            break;
        case '\\':
            s[i++] = '\\';
            //s[i++] = '\\';
            break;
        case '\b':
            s[i++] = '\\';
            s[i++] = 'b';
            break;
        default:
            s[i++] = c;
            break;
        }
    }
    printf("%s",s);
}
