#include <stdio.h>

void squeeze(char s1[],char s2[]);
int main()
{
    char a[20]="abcdssssw";
    char b[10]="avs";
    squeeze(a,b);
    printf("%s",a);
}

void squeeze(char s1[],char s2[])
{
    int count, p=0;
    for(int i=0;s1[i]!='\0';i++)
    {
        count = 1;
        for(int j=0;s2[j]!='\0';j++)
        {
            if(s1[i]==s2[j])
            {
                count = 0;
                //printf("%d\n",count);
                break;
            }
        }
        //printf("%d\n",count);
        if(count){
            s1[p++] = s1[i];
        }
        //printf("%d\n",count);
        //printf("%d , %d\n",p,i);
    }
    s1[p]='\0';
}
