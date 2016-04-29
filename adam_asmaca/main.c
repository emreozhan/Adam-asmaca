#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> //srand için
#include <string.h> //strcpy fonksiyonun kullanmak için

int karakter_say(char karakter[])
{
    int adet=0;
    int i;
    for(i=0;karakter[i]!='\0';i++)
        {
           adet++;
        }
        return adet;
}

void soru_yazdir(int k_sayi,char cevap[])
{
        int i;
        for(i=0;i<k_sayi;i++)
        {
            cevap[i]='_';
            printf("%c",cevap[i]);
            printf(" ");

        }
        printf("\n\nHarf tahmin ediniz: ");
}

void cevap_yazdir(int k_sayi,char cevap[],int score,char cop_adam[])
{
        system("cls");
        int i;

        for(i=0;i<k_sayi;i++)
        {
            printf("%c",cevap[i]);
            printf(" ");

        }

        printf("\nKalan Can %d",7-score);



    printf("\n\n\n %c \n",cop_adam[1]);
   printf("%c%c%c\n",cop_adam[2],cop_adam[3],cop_adam[4]);
   printf(" %c \n",cop_adam[5]);
   printf("%c %c",cop_adam[6],cop_adam[7]);

printf("\n\nHarf tahmin ediniz: ");
}

int dogruluk_kontrol(char soru[],char cevap[],int k_sayi)
{
    int i=0;
    for(i=0;i<k_sayi;i++)
    {
       if(soru[i]!=cevap[i])
        return 0;
    }
    return 1;
}



int main()
{
        char cop_adam[12]={' ','0','/','|','\\','|','/','\\','\0'};

        char cumle[100][10]={"ankara","amasya","yozgat","istanbul","malatya","isparta","samsun","izmir","kocaeli","izmit","konya",};
        char soru_cumlesi[100]="";  //boþ string dizisi
        char cevap[100]="";
        int k_sayi;
        int i;
        int score=0;
        char tahmin;

         printf("Uari !!:yanlizca kucuk harf kullanin\n tek seferde birden fazla karakter yazmayin\n");
        srand(time(NULL));

        int k=rand()%4;
        strcpy( soru_cumlesi , cumle[k]);  //cumleyi  soru_cumlesi ne atar  rastgele yap

        k_sayi=karakter_say(soru_cumlesi);   //sorulacak sorunun harf sayisini hesaplar   k_sayi na atar
        soru_yazdir(k_sayi,cevap);
        int kontrol=0;
        int bitis_kontrol=0;


while(score!=7){

         scanf(" %c", &tahmin);
        for(i=0;i<k_sayi;i++)
        {
            if(soru_cumlesi[i]==tahmin)
                {cevap[i]=tahmin;
                 kontrol=1;  //score kontrol etmek amacli
                }

        }
        if(kontrol==0)
           {score++;
            cop_adam[score]=' ';
           }

        kontrol=0;

        cevap_yazdir(k_sayi,cevap,score,cop_adam);
        bitis_kontrol=dogruluk_kontrol(soru_cumlesi,cevap,k_sayi);

        if(bitis_kontrol==1)
            printf("\n\n\nTEBRIKLER :)");
        if(score==7 && bitis_kontrol==0)
           {printf("\n\n\nmalesef oldunuz\n\n");
            printf("Dogru Cevap: %s\n\n\n",soru_cumlesi);
           }

        }

        return 0;
}
