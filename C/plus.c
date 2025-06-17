#include<stdio.h>
int main()
{
	int N,t=-1;
	float sum=0.0;
	scanf("%d",&N);
	for(float i=1;i<=N;i++){
	t=-t;
	sum+=t*i/(2*i-1);
	}
	printf("%0.3f",sum);
	return 0;
 }
