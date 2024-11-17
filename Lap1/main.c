#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 60;
    float f = 5.65;
    double d = 6.677;
    char c = 'm';
    char name[20] = "mustafa";

    printf("num = %d\n",num);
    printf("float number is %f\n",f);
    printf("double number is %lf\n",d);
    printf("character is  %c\n",c);
    printf("my name is %s\n",&name);

    char input;
    printf("Please input char to covert it to ASCII Code\n");
    scanf("%c",&input);
    printf("The char in ASCII is %d\n",c);

    int number = 144;
    printf("Number in octal is %o\n",number);
    printf("Number in hexadecimal is %x",number);





    return 0;
}
