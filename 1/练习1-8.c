#include <stdio.h>

int main()
{
    int nl=0,sp=0,tb=0;

    int c;
    while((c = getchar())!=EOF)
    {
        switch(c){
        case ' ':
            sp++;
            break;
        case '\t':
            tb++;
            break;
        case '\n':
            nl++;
            break;
        }
    }
    printf("Blanks :%d\n Tabs: %d\n Lines: %d\n",sp,tb,nl);

}


