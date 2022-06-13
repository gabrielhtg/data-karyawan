#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

struct data {
        char nama[100];
        int jabatan;
        int gaji, menikah, jumlah_anak, jam_lembur, tunjangan;
        double tot_gaji;
    }orang[35];

int main () {
    system(CLEAR);
    int n, i = 0, decision, loop = 1, j;
    char str_jabatan[4][20] = {"Manager", "Supervisor", "Karyawan Biasa", "Cleaning Service"};
    
    
    while (i < 35) {
        system(CLEAR);
        printf("-------------------------------------------------\n");
        printf("Masukkan nama karyawan  : ");
        scanf(" %[^\n]%*c", orang[i].nama);
        printf("-------------------------------------------------\n");
        printf("    1. Manager\n");
        printf("    2. Supervisor\n");
        printf("    3. Karyawan Biasa\n");
        printf("    4. Cleaning Service\n");
        printf("Masukkan jabatan sesuai nomor di atas! (Cth : 1)\n");
        printf("\n--> Input : ");
        scanf("%d", &orang[i].jabatan);

        if ((orang[i].jabatan > 4) && (orang[i].jabatan < 1)) {
            printf("Input yang kamu masukkan tidak tepat!\n");
        }
        printf("-------------------------------------------------\n");
        printf("    1. Menikah\n");
        printf("    2. Jomblo\n");
        printf("Masukkan status pernikahan karyawan tersebut \nsesuai nomor!\n");
        printf("\n--> Input : ");
        scanf("%d", &orang[i].menikah);
        printf("-------------------------------------------------\n");

        if (orang[i].menikah == 1) {
            printf("Masukkan banyak anak karyawan.\n");
            printf("Jika belum ada, masukkan 0!.\n");
            printf("\n--> Input : ");
            scanf("%d", &orang[i].jumlah_anak);
            printf("-------------------------------------------------\n");
        }

        else if (orang[i].menikah != 2) {
            printf("Input yang kamu masukkan tidak tepat!.\n");
        }

        
        printf("Masukkan jumlah jam lembur karyawan tersebut \ndalam satu bulan!\n");
        printf("\n--> Input : ");
        scanf("%d", &orang[i].jam_lembur);

        // Perhitungan gaji

        switch (orang[i].jabatan) {
            case 1 :
                orang[i].gaji = 15000000;
                break;
            case 2 :
                orang[i].gaji = 10000000;
                break;
            case 3 :
                orang[i].gaji = 7000000;
                break;
            case 4 :
                orang[i].gaji = 3000000;
                break;
        }

        if ((orang[i].jumlah_anak <= 2) && (orang[i].jumlah_anak > 0)) {
            orang[i].tunjangan = (orang[i].jumlah_anak * 1000000) + 1000000;
        }
        
        else if (orang[i].jumlah_anak > 2) {
            orang[i].tunjangan = 4000000;
        }

        if ((orang[i].gaji + orang[i].tunjangan + (orang[i].jam_lembur * 100000)) >= 20000000) {
            orang[i].tot_gaji = (orang[i].gaji + orang[i].tunjangan + (orang[i].jam_lembur * 100000)) - ((orang[i].gaji + orang[i].tunjangan + (orang[i].jam_lembur * 100000)) * 0.15);
        } 

        else if ((orang[i].gaji + orang[i].tunjangan + (orang[i].jam_lembur * 100000)) < 20000000) {
            orang[i].tot_gaji = (orang[i].gaji + orang[i].tunjangan + (orang[i].jam_lembur * 100000)) - ((orang[i].gaji + orang[i].tunjangan + (orang[i].jam_lembur * 100000)) * 0.1);
        } 

        printf("-------------------------------------------------\n");
        printf("Masih ingin menginput data karyawan? \n(1 = yes/0 = no)");
        printf("\n\n--> Input : ");
        scanf("%d", &decision);
        printf("-------------------------------------------------\n");
        

        if (decision == 0) {
            break;
        }
        
        else if (decision == 1) {
            loop = loop + 1;
            i++;
            continue;
        }

        else {
            printf("Input yang kamu masukkan tidak tepat!\n");\
            break;
        }
    }

    int count = 0, x;

    system(CLEAR);
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("  No    Nama                         Jabatan                  Jumlah Jam             Gaji Bersih\n");
    printf("                                                                Lembur                per Bulan\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < loop; i++) {
        printf("  ");
        printf("%d", i + 1);

        if (i < 10) {
            x = 1;
        }

        else {
            x = 2;
        }

        for(j = 0; j < (6 - x); j++) {
            printf(" ");
        }

        printf("%s", orang[i].nama);

        for(j = 0; j < (29 - strlen(orang[i].nama)); j++) {
            printf(" ");
        }

        printf("%s", str_jabatan[orang[i].jabatan - 1]);

        for(j = 0; j < (25 - strlen(str_jabatan[orang[i].jabatan - 1])); j++) {
            printf(" ");
        }      

        printf("%d", orang[i].jam_lembur);

        x = orang[i].jam_lembur;
        
        count = 0;

        if (orang[i].jam_lembur == 0) {
            count = 1;
        }    

        while (x != 0) {
            x /= 10;
            count++;
        }

        for(j = 0; j < (23 - count); j++) {
            printf(" ");
        }

        printf("Rp %.2lf\n", orang[i].tot_gaji);
    }
    printf("---------------------------------------------------------------------------------------------------------\n");

    return 0;
}