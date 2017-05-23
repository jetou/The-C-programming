#include <stdio.h>
#include <string.h>
int strrindex(char s[],char t[]);
int main()
{
    char a[30] = "qwertyusfesqweasda";
    char c[20] = "qwe";
    int s;
    s = strrindex(a,c);
    printf("%d",s);

}

int strrindex(char s[],char t[])
{
    int strT = strlen(t)-1;
    int strS = strlen(s)-1;
    //printf("%d %d",strT, strS);
    int i,j,k;

    for(i = strS;i >= 0;i--)
    {
        for(j=i,k=strT;k>0&&s[j]==t[k];j--,k--)
            ;
        if(k==0)
            return i;
    }
    return -1;

}
