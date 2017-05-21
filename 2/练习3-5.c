#include <stdio.h>
int itob(int n, char s[], int b);
int main()
{
    char s[10];
    itob(13,s,10);
    printf("%s",s);
}

int itob(int n, char s[], int b)
{
    int i,j,sign;
    char c[20];

    if((sign=n)<0)
        n = -n;
    if(b == 16){
        int count16;
        i=0;
        do
        {
            count16 = n%16;
            if(count16>=10)
            {
                count16 = count16 - 10 + 'A';
                c[i++] = count16;
            }else{
                c[i++] = count16 + '0';
            }
        }while(n/=16);
        c[i] = '\0';
        //printf("%s",c);
        atio(s,c,i);
    }else if(b == 8){
        int count8;
        i=0;
        do{
            count8 = n%8;
            c[i++] = count8+'0';
        }while(n/=8);
        c[i]='\0';
        atio(s,c,i);
    }else if(b==10){
        i=0;
        int count10;
        do{
            count10 = n%10;
            c[i++] = count10+'0';
        }while(n/=10);
        c[i]='\0';
        atio(s,c,i);
    }else{
        printf("input ,8,10or16");
    }
}

int atio(char s[],char c[],int i)
{
    for(int j=i-1,q=0;j>=0;j--,q++)
    {
        s[q] = c[j];
        //printf("%c",s[q]);
    }
    s[i] = '\0';
}
