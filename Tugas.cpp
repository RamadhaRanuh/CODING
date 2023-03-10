#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct data{
	char code[5];
//	char nama[30];
	int jumlah;
	int harga;
	
};

struct nama{ //Kalau char nama ditaruh di struct data, char code juga keisi nama. Gatau cara fixnya gimana. misalnya code = CK1, nama = blueCake. kalau print code, hasilnya = CK1blueCake.
	char nama[30];
};


void cetak(struct data kue[], struct nama name[]){
	
	printf(" BLUE CAKE SHOP CASHIER\n");
	printf(" ======================\n\n");
	printf(" No. | Cake Code | Cake Name            | Available | Price\n");
	printf(" ---------------------------------------------------------------\n");
	
	for(int i=0;i<4;i++){
		
    	printf(" 0%d. | %-9s | %-20s | %-9d | Rp.%6d,-\n", i+1, kue[i].code, name[i].nama, kue[i].jumlah, kue[i].harga);

    }
    
    printf(" ----------------------------------------------------------------\n");
}


void sell(struct data kue[], struct nama name[]){
	
	bool cek = false;
	int temp,quantity;
	char kode[5];
	
	do{
		
		printf(" Input Cake Code [5 chars]: ");
        scanf("%s",kode);
        
        for (int i=0;i<4;i++){
            if(strcmp(kue[i].code, kode) == 0){
                cek = true;
                temp = i;
                break;
            }
        }
        
        if(!cek) printf(" --- The Cake Code doesn't exist ---\n");
        
    }while(!cek);
    
    cek = false;

	do{
		
		fflush(stdin);
        printf(" Input Quantity [0..%d]: ", kue[temp].jumlah);
        scanf("%d", &quantity);
        
        if(quantity >= 0 && quantity <= kue[temp].jumlah){
            kue[temp].jumlah -= quantity;
            cek = true;
        }
        
		else{
            printf(" --- The quantity of cake is not enough ---\n");
        }
        
    }while(!cek);
    
    int hargaTotal = kue[temp].harga * quantity;
    
    printf("\n\n Total Price is : Rp. %d,- x %d = Rp. %d,-\n", kue[temp].harga, quantity, hargaTotal);
	printf("\n --- Thank You ---\n");
	
   cetak(kue,name);
	
}


void addStock(struct data kue[], struct nama name[]){
	
	bool cek = false;
    char kode[5];
    int temp, quantity;

    do{
  
        printf(" Input Cake Code [5 chars]: ");
        scanf("%s", kode);
        
        for (int i=0;i<4;i++){
            if(strcmp(kue[i].code, kode) == 0){
                cek = true;
                temp = i;
                break;
            }
        }
        
        if(!cek) printf(" --- The Cake Code doesn't exist ---\n");
        
    }while(!cek);
    
    cek = false;

    do{
    	
        fflush(stdin);
        printf(" Input Quantity [1..10]: ");
        scanf("%d", &quantity);
        
        if(quantity >= 1 && quantity <= 10){
            kue[temp].jumlah += quantity;
            cek = true;
        }
		
    }while(!cek);
    
    printf("\n --- Adding Stock Success ---\n");
    
  	cetak(kue,name);
}

int main(){
	
	struct data kue[4];
	struct nama name[4];   
	 
	strcpy(kue[0].code, "CK001"); strcpy(name[0].nama, "Blueberry Cake");       kue[0].jumlah = 13; kue[0].harga = 25000;
    strcpy(kue[1].code, "CK009"); strcpy(name[1].nama, "Chocochip Cake");       kue[1].jumlah = 5;  kue[1].harga = 20000;
    strcpy(kue[2].code, "CK017"); strcpy(name[2].nama, "Mayonaise Cake");       kue[2].jumlah = 24; kue[2].harga = 30000;
    strcpy(kue[3].code, "CK023"); strcpy(name[3].nama, "Strawberry ShortCake"); kue[3].jumlah = 7;  kue[3].harga = 17500;
    
    int pilihan;
    
    cetak(kue,name);
    
    do{
    	
    	fflush(stdin);
        printf(" Menu :\n 1. Sell\n 2. Add Stock\n 3. Exit\n");
        printf(" Input Choice: ");
        scanf("%d",&pilihan);
        
        switch(pilihan){
        case 1:
            sell(kue,name);
            break;
        
        case 2:
            addStock(kue,name);
            break;
        
        default:
            break;
        }
        
    }while(pilihan != 3);
	
	return 0;
}
