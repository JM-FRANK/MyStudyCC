# include<math.h>
# include<stdio.h>
# include<stdlib.h>

int main(){
    int N,Max=0,max=0,i;
    while(1){
    scanf("%d",&N);
    int a[N],cnt[2][1010]={0};
    for( i=0; i<N; i++){
        scanf("%d",&a[i]);
        if(a[i]>=0){
            cnt[1][abs(a[i])]++;
        }
        else{
            cnt[0][abs(a[i])]++;
        }
    }
    for( i=0; i<N; i++){
        if(cnt[1][abs(a[i])] >= max){
            max = cnt[1][abs(a[i])];
            Max = a[i];
        }
        if(cnt[0][abs(a[i])] >= max){
            max = cnt[0][abs(a[i])];
            Max = a[i];
        }
    }
    printf("%d %d",Max,max);
    }
    system("pause");
    return 0;

}