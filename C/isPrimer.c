//!这是判断一个整数是不是素数的简单代码，并不高效

# include<math.h>
# include<stdio.h>
# include<stdlib.h>

int main(){
    int a,k,i,flag;
    while(1){
        flag = 1;
        //a = 12;
        scanf("%d",&a);
        k = sqrt(a);
        for(i=2;i <= k;i++){
            if(a % i == 0){
            printf("this isn't a primer\n");
            flag = 0;
            break;
            }
        }
        if(flag)
        printf("it's a primer\n");
    }
    system("pause");
    return 0;



}