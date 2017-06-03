#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXVAL 100
#define MAXOP 100
#define NUMBER '0'
#define IDENTIFIER '1'

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int c);
void dealWithName(char s[]);

int main(){

    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case IDENTIFIER:
            dealWithName(s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if(op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if(op2)
                push(fmod(pop(),op2));
            else
                printf("\nError:   Division by zero");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n",s);
            break;
        }
    }
    return 0;
}

int sp = 0;
double val[MAXVAL];

void push(double c)
{
    if(sp<MAXVAL)
        val[sp++] = c;
    else
        printf("error: stack full, can't push %g\n",c);
}

double pop(void)
{
    if(sp > 0){
        return val[--sp];
    }else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

void dealWithName(char s[])
{
    double op2;

    if(0 == strcmp(s, "sin"))
        push(sin(pop()));
    else if(0 == strcmp(s, "exp"))
        push(exp(pop()));
    else if(0 == strcmp(s,"pow")){
        op2 = pop();
        push(pow(pop(),op2));
    }else
        printf("%s is not a supported function \n",s);
}

int getop(char s[])
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if(isalpha(c))
    {
        i=0;
        while(isalpha(s[i++] = c))
            c = getch();
        s[i - 1] = '\0';
        if(c != EOF)
            ungetch(c);
        return IDENTIFIER;
    }

    if(!isdigit(c) && c != '.'){
        return c;
    }
    i = 0;
    if(isdigit(c)){
        while(isdigit(s[++i] = c = getch()))
            ;
    }
            ;
    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i]='\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

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
