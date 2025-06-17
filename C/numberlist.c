# include<stdio.h>
# include<stdlib.h>
# include<time.h>

int main(){
    int g[4],i,j,k,flag=0;
    scanf("%d",&g[0]);
    int t1 = clock();
    g[1] = g[0] + 1;
    g[2] = g[1] + 1;
    g[3] = g[2] + 1;
    for(i=0;i < 4;i++){
        for(j=0; j<4; j++){
            for(k=0; k<4; k++){
                if(i!=j && j!=k && i!= k){
                    printf("%d%d%d",g[i],g[j],g[k]);
                    flag++;
                    if(flag % 6 == 0)
                    printf("\n");
                    else
                    printf(" ");
        
                }
            }
        }   
    }
    int t2 = clock();
    printf("\nit is %d ms\n",t2-t1);
    system("pause");
    return 0;
}
// x    y    N                      
// 1    3    55 
//            
// 2    
//
//