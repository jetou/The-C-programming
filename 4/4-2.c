#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

double atof(char s[]);

char *strings[] = {
    "1.0e43",
    "999.999",
    "123.456e-9",
    "-1.2e-3",
    "1.2e-3",
    "-1.2E3",
    "-1.2e03",
    "cat",
    "",
    0
};

int main(void)
{
    int     i=0;
    for(;*strings[i];i++)
        printf("atof(%s) = %g\n",strings[i],atof(strings[i]));
    //printf("%g",atof("-1.2e-3"));
    return 0;

}

double atof(char s[])
{
    double val, power;
    int i, sign;
    double ten = 10.0;
    double one_tenth = 0.1;

    for(i=0;isspace(s[i]);i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]);i++)
        val = 10.0 * val + (s[i]- '0');
    if(s[i]=='.')
        i++;
    for(power = 1.0;isdigit(s[i]);i++)
    {
        val = 10.0 * val + (s[i]-'0');
        power *= 10.0;
    }
    double retval = val / power;
    if(s[i] == 'e'||s[i] == 'E'){
        int neg_exponent = 0;
        int get_out = 0;
        long exponent = 0;
        double getting_too_big = DBL_MAX * one_tenth;
        double getting_too_small = DBL_MIN * ten;
        i++;
        if(s[i] == '-'){
            neg_exponent = 1;
            i++;
        }else if(s[i] == '+'){
            i++;
        }

        if(!(isdigit(s[i])))
        {

            return sign * retval;
        }

        while(isdigit(s[i])&&(exponent < LONG_MAX / 10)){
            exponent = exponent*10;
            exponent += s[i] - '0';
            i++;
        }
        if(neg_exponent){
            for(int index = 1; index <=exponent&&!get_out;index++){
                if(retval<getting_too_small){
                    get_out = 1;
                    retval = DBL_MIN;
                }else{
                    retval *= one_tenth;
                }
            }
        }else {
            for(int index = 1; index<=exponent&&!get_out;index++){
                if(retval > getting_too_big){
                    get_out = 1;
                    retval = DBL_MAX;
                }else {
                    retval *= ten;
                }
            }
        }

        return sign * retval;
    }
    return sign * retval;
}
