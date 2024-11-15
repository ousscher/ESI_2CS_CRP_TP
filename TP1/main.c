// #include <stdio.h>
// #include <stdbool.h>
// #include <time.h>
// #include <math.h>

// bool algo1(long long N) {
//     if (N <= 1) return false;
//     for (long long i = 2; i < N; i++) {
//         if (N % i == 0){
//              return false;
//         }
//     }
//     return true;
// }

// bool algo2(long long N) {
//     if (N <= 1) return false;
//     for (long long i = 2; i <= N / 2; i++) {
//         if (N % i == 0) return false;
//     }
//     return true;
// }

// bool algo3(long long N) {
//     if (N <= 1) return false;
//     for (long long i = 2; i <= sqrt(N); i++) {
//         if (N % i == 0) return false;
//     }
//     return true;
// }

// // int main() {
// //     long long valeurs[] = {1000003, 2000003, 4000037, 8000009, 16000057, 32000011, 
// //                            64000031, 128000003, 256000001, 512000009, 10240000009, 2018000011};
// //     int taille = sizeof(valeurs) / sizeof(valeurs[0]);
// //     FILE *f = fopen("resultats.csv", "w");
// //     printf("+-------------+---------+-----------+-----------+-----------+--------------+\n"); 
// //     printf("|   Nombre    | Premier |  Texec 1  |  Texec 2  |  Texec 3  | Amelioration |\n"); 
// //     printf("+-------------+---------+-----------+-----------+-----------+--------------+\n"); 
// //     for (int i = 0; i < taille; i++) {

// //         clock_t debut1 = clock();
// //         bool resultat1 = algo1(valeurs[i]);
// //         clock_t fin1 = clock();
// //         double temps_execution1 = (double)(fin1 - debut1) / CLOCKS_PER_SEC;
        
// //         clock_t debut2 = clock();
// //         bool resultat2 = algo2(valeurs[i]);
// //         clock_t fin2 = clock();
// //         double temps_execution2 = (double)(fin2 - debut2) / CLOCKS_PER_SEC;
// //         clock_t debut3 = clock(); 
// //         bool resultat3 = algo3(valeurs[i]); 
// //         clock_t fin3 = clock(); 
// //         double temps_execution3 = (double)(fin3 - debut3) / CLOCKS_PER_SEC; 

// //         long long am =( temps_execution1 - temps_execution3) / temps_execution1 * 100; 
// //         printf("| %11lld |    %s    | %9f | %9f | %9f |    %4lld%%     |\n", valeurs[i],resultat3 ? "Y" : "N",temps_execution1, temps_execution2, temps_execution3, am ); 
// //         fprintf(f, "%lld,%f,%f,%f\n", valeurs[i], temps_execution1, temps_execution2, temps_execution3);


// //     }

// //     return 0;
// // }

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

bool algo1(long long N) {
    if (N <= 1) return false;
    for (long long i = 2; i < N; i++) {
        if (N % i == 0) return false;
    }
    return true;
}

bool algo2(long long N) {
    if (N <= 1) return false;
    for (long long i = 2; i <= N / 2; i++) {
        if (N % i == 0) return false;
    }
    return true;
}

bool algo3(long long N) {
    if (N <= 1) return false;
    for (long long i = 2; i <= sqrt(N); i++) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    long long valeurs[] = {1000003, 2000003, 32000011, 4000037, 512000009, 64000031, 
                       12800003, 16000057, 2018000011, 256000001, 10240000009, 8000009};

    int taille = sizeof(valeurs) / sizeof(valeurs[0]);
    FILE *f = fopen("resultats.csv", "w");
    
    // Écrire les en-têtes dans le fichier CSV
    fprintf(f, "Nombre,Premier,Texec1,Texec2,Texec3,Amelioration\n");

    printf("+-------------+---------+-----------+-----------+-----------+--------------+\n"); 
    printf("|   Nombre    | Premier |  Texec 1  |  Texec 2  |  Texec 3  | Amelioration |\n"); 
    printf("+-------------+---------+-----------+-----------+-----------+--------------+\n"); 

    for (int i = 0; i < taille; i++) {
        clock_t debut1 = clock();
        bool resultat1 = algo1(valeurs[i]);
        clock_t fin1 = clock();
        double temps_execution1 = (double)(fin1 - debut1) / CLOCKS_PER_SEC;

        clock_t debut2 = clock();
        bool resultat2 = algo2(valeurs[i]);
        clock_t fin2 = clock();
        double temps_execution2 = (double)(fin2 - debut2) / CLOCKS_PER_SEC;

        clock_t debut3 = clock(); 
        bool resultat3 = algo3(valeurs[i]); 
        clock_t fin3 = clock(); 
        double temps_execution3 = (double)(fin3 - debut3) / CLOCKS_PER_SEC; 

        long long am = (temps_execution1 - temps_execution3) / temps_execution1 * 100; 

        printf("| %11lld |    %s    | %9f | %9f | %9f |    %4lld%%     |\n", valeurs[i], resultat3 ? "Y" : "N", temps_execution1, temps_execution2, temps_execution3, am); 
        
        // Enregistrement des résultats avec les détails dans le fichier CSV
        fprintf(f, "%lld,%s,%f,%f,%f,%lld%%\n", valeurs[i], resultat3 ? "Y" : "N", temps_execution1, temps_execution2, temps_execution3, am);
    }

    fclose(f);
    return 0;
}


// int main(){
//     int i = 0; 
//     clock_t start_t = clock(); 
//     i = i+1; 
//     clock_t end_t = clock(); 
//     double temps_execution3 = (double)(end_t - start_t) / CLOCKS_PER_SEC;
//     printf("%f", temps_execution3); 
//     }
