#include <stdio.h>

struct id{
	char nama[1001];
	double weight_kg;
	double height_cm;
	double bmi;
};


double calculate_bmi(double berat, double tinggi_cm){ //KALKULASI BMI
	double tinggi_m = tinggi_cm * 0.01; //MENGUBAH CM JADI M
	return (berat)/(tinggi_m*tinggi_m); //MENGEMBALIKAN VALUE BMI YANG SUDAH DIKALKULASI KE DALAM MAIN MODULE
}

void sort(struct id pasien[], int len){ //SORTING MENGGUNAKAN SELECTION SORT
	struct id temp;
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;j++){
			if(pasien[i].bmi < pasien[j].bmi){
				temp = pasien[i];
				pasien[i] = pasien[j];
				pasien[j]= temp;
			}
		}
	}
}

int main(){
	FILE *data = fopen("testdata.in", "r");
	int tsc;
	fscanf(data, "%d",&tsc); //AMBIL TESTCASE
//	printf("%d\n",tsc);
	struct id pasien[tsc];
	for(int i=0;i<tsc;i++){
		fscanf(data, "\n%[^\@]@%lf |%lf\n",pasien[i].nama,&pasien[i].weight_kg,&pasien[i].height_cm); //AMBIL DATA PASIEN SESUAI TESTCASE
//		printf("%s %lf %lf\n",pasien[i].nama,pasien[i].weight_kg,pasien[i].height_cm);
		pasien[i].bmi = calculate_bmi(pasien[i].weight_kg,pasien[i].height_cm); //VALUE YG SUDAH DIKALKULASI DIMASUKKAN KE DALAM DATA STRUCT PASIEN
	}
	
	sort(pasien, tsc); //SORT PASIEN BERDASARKAN BMI DI VOID SORT
	
	for(int i=0;i<tsc;i++){
		printf("Patient #%d : %s %.2lf\n",i+1,pasien[i].nama,pasien[i].bmi); //PRINT PASIEN YANG SUDAH TERSORTING		
	}

	fclose(data);
	return 0;
}
