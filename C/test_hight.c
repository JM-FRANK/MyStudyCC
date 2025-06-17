# include<stdio.h>
# include<stdlib.h>
# include<math.h>
int main()
{
    int sex,derta;
    double hf,hm,h,Th;
    scanf("%d %lf %lf %lf",&sex,&hf,&hm,&Th);
    switch(sex){
        case 1 : h = (int)(((hf+hm)*1.08/2)+0.5);break;
        case 2 : h = (int)(((hf*0.923+hm)/2)+0.5);break;
        default : printf("性别错误\n");goto end; 
    }
    printf("%.0lf\n",h);
    derta = abs(Th-h);
    if(derta <= 3)
    printf("符合");
    else printf("不合格");
    system("pause");
    end:
    return 0;
}

