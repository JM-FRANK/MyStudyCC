# include<stdio.h>
# include<stdlib.h>
int main()
{
    int N,i,j=0,o=0;
    scanf("%d",&N);
    int num[N];
    for(i=0;i<N;i++)
    scanf("%d",&num[i]);
    for(i=0;i<N;i++){
        if(num[i] % 2 == 0)
        o++;
        else j++;
    }
    printf("%d %d",j,o);
    system("pause");
    return 0;

}