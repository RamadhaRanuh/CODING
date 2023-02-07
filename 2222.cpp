#include <stdio.h>

void calculate(int a, int b, int c, int d){
	int e = a*1000+b;
	int f = c*1000+d;
	
	if(e>f) printf("%d\n",e-f); 
	else printf("%d\n",f-e);
}


int main(){
	int AK, AG, BK, BG;
	scanf("%d;%d %d;%d",&AK,&AG,&BK,&BG);
	
	calculate(AK,AG,BK,BG);
	return 0;
}
