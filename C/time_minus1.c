#include<stdio.h>
#include<stdlib.h>
int main()
{
int hour1,hour2,min1,min2;
int im,ih;
printf("please enter first time:");
scanf("%d %d",&hour1,&min1);
printf("please enter second time:");
scanf("%d %d",&hour2,&min2);
ih = abs(hour1-hour2);
im = abs(min1-min2);
printf("时间差的绝对值是%d小时%d分钟",ih,im);
system("pause");
return 0;

}