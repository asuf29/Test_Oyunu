#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

char kullaniciAdi[50];
int i;
int secim3;

//Berke Erdoğdu & Asude Fışkın Proje Test Oyunu
//Sorular.txt ;Soru metni, abcd şıkları ve doğru cevap metni olmak üzere alt��ar art arda satırdan oluşmalıdır.
//Soru eklenin sorunsuz çalışabilmesi için Sorular.txt'de en sonda fazladan bir satır boşluk olması gerekmektedir.

void rengim(int renk) //renk fonksiyonum 
{ 
  HANDLE hStdout; 
  hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
  SetConsoleTextAttribute(hStdout, renk); 
} 


void hosgeldiniz_ekrani(){
  
  
    rengim(5); printf("            TEST OYUNUNA HOS GELDINIZ                \n\n");
    rengim(2); printf("          Devam etmek icin bir tusa basin            \n");
  
  getchar();
}

int islem_sec;

void ana_menu() {

 
    rengim(5);  printf("|                  ISLEM SECIMI                       |\n");
     
     

	rengim(7); printf("\nAsagidaki islemlerden birini seciniz.\n");
	rengim(5); printf("[1]-Soru ekle\n");
	rengim(5); printf("[2]-Soru sil\n");
	rengim(5); printf("[3]-Sorulari goster ve guncelle\n");
	rengim(5); printf("[4]-Oyun oyna\n");
	rengim(5); printf("[5]-En yuksek skorlari goster\n");
	rengim(5); printf("[6]-Cik\n");
	
	rengim(7); printf("Seciminiz: ");
	scanf("%d",&islem_sec);
	getchar();
}


int S=1;// Soru sayısını tutan değişken
struct sorum{
  char soru[120];
  char option_a[120];
  char option_b[120];
  char option_c[120];
  char option_d[120];
  char correct_option[120];
  int id;
}yeni_soru[BUFSIZ];

struct skor {
    char nick[50];
    int puan;
}yeni_kullanici[50];


void soru_ekle() {
	
	rengim(5); printf("|               SORU EKLEME ALANI                    |\n");
      

  rengim(2); printf("\n%d. Soruyu eklemek icin gerekli bilgileri doldurunuz.\n",S);

FILE *fp;
	if ((fp = fopen("Sorular.txt","a")) == NULL){
	
	printf("Dosya acilamadi.\n");
}
	else{

	struct sorum yeni_soru;

    rengim(5);	printf("  Soru metni giriniz: ");																
        fgets(yeni_soru.soru,180,stdin);
	rengim(5);	printf("\n  A sikkini giriniz: ");
        fgets(yeni_soru.option_a,120,stdin);
	rengim(5);	printf("  B sikkini giriniz: ");
        fgets(yeni_soru.option_b,120,stdin);
	rengim(5);	printf("  C sikkini giriniz: ");
		fgets(yeni_soru.option_c,120,stdin);
	rengim(5);	printf("  D sikkini giriniz: ");
		fgets(yeni_soru.option_d,120,stdin);
	rengim(5);	printf("\n  Dogru cevabi giriniz: "); 
		fgets(yeni_soru.correct_option,120,stdin);
	
	fprintf(fp, "%s%s%s%s%s%s",yeni_soru.soru,yeni_soru.option_a,yeni_soru.option_b,yeni_soru.option_c,yeni_soru.option_d,yeni_soru.correct_option); 
	
	fclose(fp);

  rengim(2); printf("\nSoru eklendi\nAna menuye donmek icin bir tusa basiniz\n");
  getchar();
}
 }

void soru_sil(){	
	
	int sorusayisi=0;
	int noSilinen;
	
	FILE* ptr = fopen("Sorular.txt","r+");
        char satir[256]; 
	int j=1;
	rengim(5); printf("                     				|SORU SILME ALANI|                      \n\n"); 
    while(fgets(satir,sizeof(satir),ptr)){
    	
    	if(j%6==1){
		 ++sorusayisi;	rengim(3);	printf("%d. Soru:  %s \n",sorusayisi,satir); 
    	}
    	else{
		}
				
   		j++; 
   		
    	}
	
	fclose(ptr);

		FILE* ptr2 = fopen("Sorular.txt","r"); 
        FILE* ptr3 = fopen("Sorular2.txt","w");

		rengim(2); printf("\nSilmek istediginiz sorunun numarasini giriniz: ");
		scanf("%d",&noSilinen);
	
	printf(" \033[32m Isleminiz onaylanmistir ... \033[0m");
		
		j=0;
		
	while(fgets(satir,sizeof(satir),ptr2)){
		
		if(j >= (noSilinen-1)*6 && j < noSilinen*6)
		{
		
		}
		else{
			
		fprintf(ptr3,"%s",satir);
	   
          
    	}
		j++;
			
    }	
        fclose(ptr2);
        fclose(ptr3);
  	
	remove("Sorular.txt");  
	rename("Sorular2.txt","Sorular.txt"); 
	system("CLS");
	getchar();
}

soru_silmesaj(){ 
system("CLS");
rengim(5);	printf("  Isleminiz onaylanmistir ... ");
rengim(2);	printf("  Ana menuye donmek icin bir tusa basiniz. ");
getchar();
system("cls");

}
	
void soru_goruntule() {
	
	int sorusayisi=0;
	
	FILE* ptr = fopen("Sorular.txt","r");
        char satir[100]; 
	int j=1; 
    while(fgets(satir,sizeof(satir),ptr)){
    	
    	if(j%6==0){
      	 rengim(2);	printf("Dogru yanit:	%s\n\n",satir); 
    	}
		else if(j%6==1){
			
      	 ++sorusayisi;	rengim(5);	printf("%d. Soru:  %s \n",sorusayisi,satir); 
    	}

		else if(j%6==2){
      	 rengim(8);	printf("A:%s\n",satir); 
    	}
		else if(j%6==3){
      	 rengim(8);	printf("B:%s\n",satir); 
    	}
		else if(j%6==4){
      	 rengim(8);	printf("C:%s\n",satir); 
    	}
		else {
      	 rengim(8);	printf("D:%s\n",satir); 
      	 
    	}
				
   		j++; 
   		
    	}
    
    fclose(ptr);

	rengim(5); printf("Soru guncellemek icin '1' \n");
	rengim(5); printf("Ana menu icin '0'  \n");
	scanf("%d",&secim3);
	system("cls");
    getchar();
	}

	
void soru_guncelleme() {
	
	soru_goruntule();
		
		 FILE* ptr = fopen("Sorular.txt","r"); 
 		 FILE* ptr2 = fopen("sorular2.txt","w");
   
   char satir[256];
   int j=1;
   int secim;

	rengim(5); printf("Kacinci soruyu guncellemek istersiniz?  ");
	scanf("%d",&secim);
		
	while(fgets(satir,sizeof(satir),ptr)){
		
		if(j == (secim-1)*6 + 1)
		{
			
		getchar();
        system("cls");
        
        struct sorum yeni_soru;
        
        rengim(2);	printf("  Soru metni : ");																
        fgets(yeni_soru.soru,150,stdin);
        strcpy(satir,yeni_soru.soru);
        fprintf(ptr2,"%s",satir);
    }
        
        else if(j == (secim-1)*6 + 2)
		{
        
        struct sorum yeni_soru;
		rengim(2);	printf("\n  A: ");
        fgets(yeni_soru.option_a,150,stdin);
        strcpy(satir,yeni_soru.option_a);
        fprintf(ptr2,"%s",satir);
 }
 		else if(j == (secim-1)*6 + 3)
		{
        
        struct sorum yeni_soru;
	    
		rengim(2);	printf("  B: ");
        fgets(yeni_soru.option_b,150,stdin);
        strcpy(satir,yeni_soru.option_b);
        fprintf(ptr2,"%s",satir);
}
		else if(j == (secim-1)*6 + 4)
		{

        struct sorum yeni_soru;

		rengim(2);	printf("  C: ");
		fgets(yeni_soru.option_c,150,stdin);
		strcpy(satir,yeni_soru.option_c);
		fprintf(ptr2,"%s",satir);
}
		else if(j == (secim-1)*6 + 5)
		{
       
        struct sorum yeni_soru;
		rengim(2);	printf("  D: ");
		fgets(yeni_soru.option_d,150,stdin);
		strcpy(satir,yeni_soru.option_d);
		fprintf(ptr2,"%s",satir);
}

		else if(j == (secim-1)*6 + 6)
		{
       
        struct sorum yeni_soru;
		rengim(2);	printf("\n  Dogru cevabi giriniz: ");
		fgets(yeni_soru.correct_option,150,stdin);
		strcpy(satir,yeni_soru.correct_option);
		fprintf(ptr2,"%s",satir);
}
		else{
		
		fprintf(ptr2,"%s",satir);
		
          	}	
		j++;	  		
	}
	
        fclose(ptr);
        fclose(ptr2);
	remove("Sorular.txt");
	rename("Sorular2.txt","Sorular.txt");
    system("cls");	
	soru_silmesaj();
}

int soruata(){
  
  	int soruSayisi = 0;
	FILE *file ;
  
  	if((file = fopen("Sorular.txt","r") )!= NULL){
  		while(!feof(file)){ 
			fgets(yeni_soru[soruSayisi].soru,1024,file);
			fgets(yeni_soru[soruSayisi].option_a,1024,file);
			fgets(yeni_soru[soruSayisi].option_b,1024,file);
			fgets(yeni_soru[soruSayisi].option_c,1024,file);
			fgets(yeni_soru[soruSayisi].option_d,1024,file);
			fgets(yeni_soru[soruSayisi].correct_option,1024,file);
		
			soruSayisi++; 			
		  }
  		
	  }else{
	  	
	  }
	  return soruSayisi;
	  fclose(file);
  }


int i=0;
int yeni_puan=0;

void oyun_oyna() {
	
	char cevap_anahtari[5];
    char kullanici_cevaplari[5];
	int soruSayisi = soruata(); 
  	int sayac,tur=1;
  	int puan=0;
  	char answer;
	int z;   
  	
  	for(sayac=0;sayac<5;sayac++){
  	srand(time(NULL));
  	z= 0 + rand() %(soruSayisi-1);
    
	system("cls");
	    
  	rengim(5); printf("\n%d. soru: %s\n",sayac+1,yeni_soru[z].soru);
  	rengim(8); printf("A-) %s",yeni_soru[z].option_a);
  	rengim(8); printf("B-) %s",yeni_soru[z].option_b);
  	rengim(8); printf("C-) %s",yeni_soru[z].option_c);
  	rengim(8); printf("D-) %s",yeni_soru[z].option_d);
  	rengim(2); printf("\nCevabinizi giriniz: ");
  	getchar();
  	scanf("%s", &answer);
  	
  	if(answer == 'a'){ 
	  	if(strcmp(yeni_soru[z].correct_option,yeni_soru[z].option_a)==0){  
	  		puan+=1;
	  		yeni_puan++;
			rengim(2); printf("Dogru Cevap! \n");                                         
		  }
	  	
		else{
		
			rengim(4); printf("Yanlis Cevap \n");
			}
		}
	  
	else if(answer == 'b'){
	  	if(strcmp(yeni_soru[z].correct_option,yeni_soru[z].option_b)==0){
	  		puan+=1;
	  		yeni_puan++;
			rengim(2); printf("Dogru Cevap! \n");                                         
		  }
		  else{rengim(4); printf("Yanlis Cevap \n");}
	  }
	  
	else if(answer == 'c'){
	  	if(strcmp(yeni_soru[z].correct_option,yeni_soru[z].option_c)==0){
	  		puan+=1;
	  		yeni_puan++;
			rengim(2); printf("Dogru Cevap! \n");                                         
		  }
		  else{rengim(4); printf("Yanlis Cevap \n");}
	  }
	  
	else if(answer == 'd'){
	  	if(!strcmp(yeni_soru[z].correct_option,yeni_soru[z].option_d)){
	  		puan+=1;
	  		yeni_puan++;
			rengim(2); printf("Dogru Cevap! \n");                                         
		  }
		  else{rengim(4); printf("Yanlis Cevap \n");}
	  }

	  
  	tur++;
	getch();	
  	
  }
  
  printf("%d\n",yeni_puan);
  skoryazdir();

  rengim(5); printf("Ana menuye donmek icin bir tusa basiniz.\n");
  getchar();
  getchar();

}
void skoryazdir(){
  	system("CLS");
  	FILE *f;
    int a1 =0;
    int puan;
  	if((f= fopen(" Skorlar.txt ","a"))!=NULL){
	rengim(5); printf("Tebrikler %s!\n",kullaniciAdi);
  	rengim(6); printf("Puaniniz %d.\n",yeni_puan);
    yeni_kullanici[a1].puan=yeni_puan;
    fprintf(f,"%d\n%s\n",yeni_kullanici[a1].puan,kullaniciAdi); 
	puan=0;
	yeni_puan=0;
	  } 
	  
	  else{
  		
	  }
  	
  	fclose(f);
  	
  }
  
  int skorata(){
 	
  	int kullanici1 = 0;
  
  	FILE *fs ;
  
  	if((fs = fopen(" Skorlar.txt ","r"))!=NULL){
  		while(!feof(fs)){
			fscanf(fs,"%d\n%s\n",&yeni_kullanici[kullanici1].puan,yeni_kullanici[kullanici1].nick);
			kullanici1++; 		
		  }
  		
	  }
	  else{
	  	
	  }
	  fclose(fs);
	  return kullanici1;
	  
  }
  
 void sirala( ){
  	
  	int q =skorata();
  	
	char tempName[50];
  	int temp;
  
  	int i = 0;
	int a = 0;

	for(i=0;i<q-1;i++){
		
		for(a=0;a<q-1;a++){
		
			if(yeni_kullanici[a].puan > yeni_kullanici[a+1].puan){
				int temp = yeni_kullanici[a].puan;
				char tempName[50] ;
				strcpy (tempName,yeni_kullanici[a].nick);
				yeni_kullanici[a].puan = yeni_kullanici[a+1].puan;
				strcpy (yeni_kullanici[a].nick,yeni_kullanici[a+1].nick);
				strcpy (yeni_kullanici[a+1].nick,tempName);
				yeni_kullanici[a+1].puan = temp;
			}
		}
	}
	

rengim(7);	printf("   ================================================>\ SKOR TABLOSU  <============================================ \n");
rengim(7);  printf("                                                    |-------------|\n\n\n");
rengim(2);  printf("                                                       1- %s\n                                                           %d\n",yeni_kullanici[q-1].nick,yeni_kullanici[q-1].puan);
rengim(2);  printf("                                                       2- %s\n                                                           %d\n",yeni_kullanici[q-2].nick,yeni_kullanici[q-2].puan);
rengim(2);  printf("                                                       3- %s\n                                                           %d\n",yeni_kullanici[q-3].nick,yeni_kullanici[q-3].puan);
rengim(7);  printf("\n\n ===============================================================================================================  \n\n\n");
rengim(5);  printf("Ana menuye donmek icin bir tusa basiniz.\n");
  getchar();
  system("CLS"); 
	
	
}

void ekran_temizle() {

system("CLS"); 
system("CLS");	

}

int puan_sayisi;

int main() {

	ekran_temizle();
	hosgeldiniz_ekrani();
	ekran_temizle();
	ana_menu();
	
	while(1) {


		switch(islem_sec) {

			case 1:
				ekran_temizle();
      			soru_ekle();
				ekran_temizle();
				ana_menu();
				break;

			case 2:
				ekran_temizle();
				soru_sil();
				ekran_temizle();
				soru_silmesaj();
				ana_menu();
				break;


			case 3:
				ekran_temizle();
				soru_goruntule();
				if(secim3==1){
					soru_guncelleme();
					ekran_temizle();
					ana_menu();
				}
				else if(secim3==0){
					ekran_temizle();
					ana_menu();
				}
				
				break;



			case 4:
				ekran_temizle();
				printf("\n\nAdinizi giriniz: ");
				scanf("%s",&kullaniciAdi);
				oyun_oyna(kullaniciAdi);
				ekran_temizle();
				ana_menu();
				break;



			case 5:
				ekran_temizle();
				sirala();
				ana_menu();
				break;

			case 6:
				break;



			default:

				rengim(4); printf("Gecersiz deger girdiniz.Ana menuye donmek icin bir tusa basin\n");
				getchar();
				ekran_temizle();
				ana_menu();
				break;


		}
		
		if (islem_sec==6) {
		  remove("Skorlar.txt");
		  remove("dosya.txt");
		  remove("a.out");
		  
		    rengim(5); printf("|                   PROGRAM SONLANDI                   |\n");
		    
			break;
		}
	
}

	return 0;
}

