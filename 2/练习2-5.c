#include <stdio.h>
int any(char *s1,char *s2);


int main()
{
    char *w = "nihao";
    char *q = "f";
    int c = any(w,q);
    printf("%d",c);

}
int any(char *s1,char *s2)
{
    int a=0,b=0;
    for(*s1;*s1;*s1++,a++)
    {
        char *s3 = s2;
        for(*s3;*s3;*s3++)
        {
            if(*s1 == *s3)
            {
                return a;
            }
        }
    }
    return -1;
}
