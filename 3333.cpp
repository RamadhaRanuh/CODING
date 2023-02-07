#include <stdio.h>

//BRUTE FORCE
long long fib(int n){
	
	
	if (n==1) return 1;
	if (n==2) return 2;
	if (n==3) return 3;
	if (n==4) return 4;
	else return fib(n-2) + fib(n-4);
}


long long fib2(int n){ //BUAT 2 RECURSION SOALNYA KALO N>60 TIME LIMIT 
	
	
	if (n==51) return 271443;
	if (n==52) return 392836;
	if (n==53) return 439204;
	if (n==54) return 635622;
	else return fib2(n-2) + fib2(n-4);
}



int main(){
	int n;
	scanf("%d",&n);
	
	if(n>50) printf("%ld",fib2(n));
	else printf("%ld",fib(n));
	return 0;
}
