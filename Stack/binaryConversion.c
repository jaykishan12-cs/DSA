#include<stdio.h>

int convert(int num,int base)
{
    int res[100],i=0;

    while(num > 0)
    {
        res[i] = num%base;
        num = num / base;
        i++;
    }
     for (int j = i - 1; j >= 0; j--) {
        if (res[j] < 10)
            printf("%d", res[j]);
        else
            printf("%c", 'A' + res[j] - 10);  // For 10–15: A–F
    }

}
int main()
{
    int decimal,base;
    printf("Enter A Decimal Number : ");
    scanf("%d",&decimal);

    printf("Enter Base : ");
    scanf("%d",&base);

    if (base < 2 || base > 16) {
        printf("Base not supported!");
    } else {
        printf("Result: ");
        convert(decimal, base);
    }


}