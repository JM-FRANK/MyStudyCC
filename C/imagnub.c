#include<stdio.h>
#include<malloc.h>
typedef struct{
    double real;
    double img;
}ComplexNumber;
//初始化复数
void CreateComplexNumber(ComplexNumber *c,double a,double b){
    c->real=a;
    c->img=b;
};
//显示复数
void Display(double c1,double c2){
    if(c1==0&&c2==0) printf("\t结果运算为0;\n");
    if(c1==0&&c2!=0) printf("\t运算结果为：i%g\n",c2);
    if(c1!=0&&c2==0) printf("\t结果：%g\n",c1);
    if(c1!=0&&c2!=0) printf("\t结果为%g i%g\n",c1,c2);
}
//求和
void AddComplexNumber(ComplexNumber *c,ComplexNumber c1,ComplexNumber c2){
    c->real=c1.real+c2.real;
    c->img=c1.img+c2.img;
    return;
};
//求差
void SubComplexNumber(ComplexNumber*c,ComplexNumber c1,ComplexNumber c2){
    c->real=c1.real-c2.real;
    c->img=c1.img-c2.img;
    return;
};
//求积
void MultiComplexNumber(ComplexNumber*c,ComplexNumber c1,ComplexNumber c2){
    c->real=c1.real*c2.real-c1.img*c2.img;
    c->img=c1.real*c2.img+c1.img*c2.real;
    return;
};
//共轭
void ConComplexNumber(ComplexNumber*c,ComplexNumber c1){
    c->real=c1.real;
    c->img=c1.img*(-1);
    return;
};

int main(){
    int choice;
    double a1,b1,b2,a2;
    ComplexNumber *c1,*c2,*result;
    c1=(ComplexNumber *)malloc(sizeof(ComplexNumber));
    c2=(ComplexNumber *)malloc(sizeof(ComplexNumber));
    result=(ComplexNumber *)malloc(sizeof(ComplexNumber));
    printf("\t\t1生成一个复数（输入）\n");
    printf("\t\t2--求2个复数的和\t\n");
    printf("\t\t3--求两个复数的差\t\n");
    printf("\t\t4--求两个复数的积\t\n");
    printf("\t\t5--求共轭复数\t\n");
    printf("\t\t0--退出程序\t\n");
    printf("请输入你想经行的运算的代号\n");
    while(scanf("%d",&choice)!=EOF){
        if(choice==0)break;
        switch(choice){
            case 1:goto A;break;
            case 2:goto B;break;
            case 3:goto C;break;
            case 4:goto D;break;
            case 5:goto E;break;
        }
        A:{
            printf("输入实部和虚部");
            scanf("%lf%lf",&a1,&b1);
            CreateComplexNumber(c1,a1,b1);
            Display(c1->real,c1->img);
        }
        continue;
        B:{
             printf("输入2个数的实部和虚部");
             scanf("%lf%lf%lf%lf",&a1,&b1,&a2,&b2);
             CreateComplexNumber(c1,a1,b1);
             CreateComplexNumber(c2,a2,b2);
             AddComplexNumber(result,*c1,*c2);
             Display(result->real,result->img);
        }
        continue;
        C:{
           printf("输入2个数的实部和虚部");
           scanf("%lf%lf%lf%lf",&a1,&b1,&a2,&b2);
           CreateComplexNumber(c1,a1,b1);
           CreateComplexNumber(c2,a2,b2);
           SubComplexNumber(result,*c1,*c2);
           Display(result->real,result->img);
        }continue;
        D:{
           printf("输入2个数的实部和虚部");
           scanf("%lf%lf%lf%lf",&a1,&b1,&a2,&b2);
           CreateComplexNumber(c1,a1,b1);
           CreateComplexNumber(c2,a2,b2);
           MultiComplexNumber(result,*c1,*c2);
           Display(result->real,result->img);
        }continue;
        E:{
            printf("输入实部和虚部");
            scanf("%lf%lf",&a1,&b1);
            CreateComplexNumber(c1,a1,b1);
            ConComplexNumber(result,*c1);
            Display(result->real,result->img);
        }
    }


return 0;
}

