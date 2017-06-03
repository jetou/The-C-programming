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
#define VARIABLE '2'


typedef struct variable_s{
    char a[3];
    int num;
    struct variable_s * next;
}Variable;

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int c);
void dealWithName(char s[]);
void variable_evl(char s[]);
Variable *init_link(Variable * k);


Variable *variable;



int main(){

    int type;
    double op2;
    char s[MAXOP];

    variable = init_link(variable);
    while((type = getop(s)) != EOF){
        switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case IDENTIFIER:
            dealWithName(s);
            break;
        case VARIABLE:
            variable_evl(s);
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

void clearStack(void)
{
    sp = 0;
}

void showTop(void)
{
    if(sp > 0)
        printf("Top of stack contains : %8g\n", val[sp-1]);
    else
        printf("The stack is empty!\n");
}

void duplicate(void)
{
    double temp = pop();

    push(temp);
    push(temp);
}

void swapItems(void)
{
    double temp1 = pop();
    double temp2 = pop();

    push(temp1);
    push(temp2);
}

Variable *init_link(Variable *k)
{
    k = (Variable *)malloc(sizeof(Variable));
    k->num = 0;
    k->next = NULL;
    return k;

}

int serach_link(char s[])
{
    for(variable;variable;variable=variable->next)
        if(0==strcmp(variable->a,s))
            return variable->num;
    return 0;
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

void variable_evl(char s[])
{
    int op2,c;
    Variable *link;
    //printf("%s   qqqqqqqqqqq\n",s);
    op2 = serach_link(s);

    if(op2!=0){
        push(op2);
    }else{

        link = init_link(link);
        strcpy(link->a,s);
        while((s[0] = c = getch()) == ' ' || c == '\t')
            ;
        if(c == '='){
            int i=0;
            while((s[0] = c = getch()) == ' ' || c == '\t')
                ;
            while(isdigit(c)){
                s[i++] = c;
                c=getch();
            }
            s[i] = '\0';
            //printf("%s\n",s);
            for(int j=0;j<i;j++)
            {
                if(isdigit(s[j])){
                    //printf("%c\n",s[j]);
                    link->num = link->num*10 + (s[j] - '0');
                    //printf("num = %d",link->num);
                }else{
                    printf("input error");
                    break;
                }
            }

            //printf("dsada");
            link->next = variable;
            variable = link;
            //if((c = getch())=='\n');
        }
        else
            printf("null\n");
    }

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
        //printf("%d\n",i);
        if (i>2)
            return IDENTIFIER;
        else
            return VARIABLE;
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
