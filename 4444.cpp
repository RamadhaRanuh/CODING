#include <stdio.h>
#include <string.h>

struct mhs{
	char nama[21];
};


int main(){
	
	int n,counter=0;
	scanf("%d",&n);
	struct mhs siswa[n]; //INPUT N SEBAGAI PARAMETER TEST CASE
	
	for(int i=0; i<n;i++){
		scanf("%s",siswa[i].nama); //INPUT NAMA
	}
	
	for(int i=0;i<n-1;i++){
		if (strcmp(siswa[i].nama, siswa[i+1].nama) > 0) counter ++; //ALGORITMA UNTUK MENGECEK 1 PASANG NAMA BERSEBELAHAN YANG TIDAK TERSORTING
		
	}
	
	if(counter==0) printf("SORTED\n"); //SORTED JIKA SEMUA PASANG NAMA BERSEBELAHAN TERSORTING
	if(counter==1) printf("ALMOST SORTED\n"); //ALMOST SORTED JIKA DAN HANYA JIKA 1 PASANG BERSEBELAHAN TIDAK TERSORTING
	if(counter>1) printf("STILL MESSI ;)\n"); //STILL MESSY JIKA LEBIH DARI 1 PASANG BERSEBELAHAN TIDAK TERSORTING
	return 0;
}
