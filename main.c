#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


int main() {
    setlocale(LC_ALL, ""); // Türkçe karakterleri doðru bir þekilde iþlemek için

    FILE* dosya;
    char yol[100], dosya_adi[30],kopya[100], karakter,metin[1000];
    int i = 0;

    printf("dosya yolu: ");
    fgets(yol, sizeof(yol), stdin);
    if (yol[strlen(yol) - 1] == '\n') {
        yol[strlen(yol) - 1] = '\0';
    }

    printf("dosya adi: ");
    fgets(dosya_adi, sizeof(dosya_adi), stdin);
    if (dosya_adi[strlen(dosya_adi) - 1] == '\n') {
        dosya_adi[strlen(dosya_adi) - 1] = '\0';
    }

    //C:\Users\bugra\OneDrive\Resimler\dosya.txt
    //turkce karakterli olanlari algilamiyor 'ü' vs.

    strcat(yol, dosya_adi);
    strcat(yol, ".txt");


    dosya = fopen(yol, "r");

    //C:\Users\bugra\OneDrive\Resimler\belge.txt

    if (dosya != NULL) {
        
        karakter = fgetc(dosya);
        metin[i] = karakter;
        i++;
        while (karakter != EOF) {       //EndOfFile
            printf("%c", karakter);
            karakter = fgetc(dosya);
            metin[i] = karakter;
            i++;
            //bittiginde cikiyor yani satir 68'de bu lazim bana i degeri
        }
        fclose(dosya);   
        printf("\n\n%s\nkopyalama islemi yapilacak ...\n", yol);
        printf("\ndosyanin tasinacagi konum :");
        //tekrar degisken tanimlamicam
        fgets(kopya, sizeof(kopya), stdin);
        if (kopya[strlen(kopya) - 1] == '\n') {
            kopya[strlen(kopya) - 1] = '\0';
        }
        
        strcat(dosya_adi, "_kopya");        // yani dosya neyse kopyasi olustu anlaminda
        strcat(kopya, dosya_adi);    
        strcat(kopya, ".txt");  // tam yol belirtmis oldu

        //yol dogrumu yazsin tasinan yol
        printf("\ntasindigi yol:\n%s", kopya);

        dosya = fopen(kopya, "w");

        if (dosya != NULL) {
            
            for (int k = 0; k < i-1; k++) {     //bir tane fazla basti onu halledelim -1 ile
                fputc(metin[k], dosya);
            }

            fclose(dosya);
        }
        else printf("\nboyle bir yol yok.");
    }
    else {
        printf("Boyle bir dosya yok\n");
    }

    return 0;
}