# include<stdio.h>
# include<stdlib.h>
# include<math.h>
int main()
{
    int l=0,b=0,d=0,o=0;
    char putin[10];
    for(int i = 0;i < 10;i++)
    scanf("%c",&putin[i]);
    for(int i = 0;i < 10;i++){
        if(putin[i] >= 'A' && putin[i] <= 'Z')
        l++;
        else if(putin[i] >= 'a' && putin[i] <= 'z')
        l++;
        else if(putin[i] == ' ' || putin[i] == '\n')
        b++;
        else if(putin[i] <= '9' && putin[i] >= '0')
        d++;
        else
        o++;
    }
    printf("letter = %d, blank = %d, digit = %d, other = %x",l,b,d,o);
    system("pause");
    return 0;

}