# include<stdio.h>
# include<stdlib.h>
# include<math.h>

int main()
{
    float a,b,c,g1,g2,tm,p;
    while(1){
        scanf("%f %f %f",&a,&b,&c);
        tm = b*b - 4*a*c;
        if(a != 0){
            if(tm > 0){
                g1 = (-b + sqrt(tm))/(2*a);
                g2 = (-b - sqrt(tm))/(2*a);
                printf("%.2f\n%.2f",g1,g2);
            }
                else if(tm < 0){
                p = -b/(2*a);
                if(p == 0)p = 0;    
                printf("%.2f+%.2fi\n%.2f-%.2fi",p,sqrt(-tm)/(2*a),p,sqrt(-tm)/(2*a));
                }
                else
                printf("%.2f",-b/(2*a));
        }
        if(a == 0 && b == 0 && c == 0)
        printf("Zero Equation");
        if(a == 0 && b == 0 && c != 0)
        printf("Not An Equation");
        if(a == 0 && b != 0)
        printf("%.2f",-c/b);
    }
    return 0;

}