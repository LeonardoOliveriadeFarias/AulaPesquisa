#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void bubble_sort(int a[], int n) {
   int i = 0, j = 0, tmp;
   for (i = 0; i < n; i++) {   
       for (j = 0; j < n - i - 1; j++) {            
            if (a[j] > a[j + 1]) {  
               tmp = a[j];
               a[j] = a[j + 1];
               a[j + 1] = tmp;
           }
       }
   }
}

void insertion_sort(int v[], int size_v){
	if(size_v <= 1){ return; }
			
	int i, j, key;
	
	for(i = 1; i < size_v; i++){
		j = i;
		key = v[i];
		while(j > 0 && v[j - 1] > key){
			v[j] = v[j - 1];
			j--;
		}
		v[j] = key;
	}
}

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}



int main(){
    
    int opcao = -1, size, vet[9999];
    printf("Gerando arquivo: \n1 - Numeros aleatorios\n2 - Inserir numeros\n3 - Inserir datas\n4 - Inserir palavras\n");
    scanf("%i", &opcao);
    switch (opcao){
    case 1:
        printf("Qual o tamanho do vetor que deseja?");
        scanf("%d", &size);
        srand(time(NULL));
        for(int i = 0; i<size; i++){  
            vet[i] = rand() % 100; 
        }
        system("cls");
        printf("Gerando vetor...\n");
        
        printf("Vetor gerado: ");
        for(int i = 0; i<size; i++){ printf("%i,", vet[i]);}
        printf("\n");
        break;
    
    case 2:
        break;
    
    case 3:
        break;
    
    case 4:
        break;
    
    default:
        printf("Opcao inexistente");
        break;
    }
    if(opcao > 4 || opcao < 1){  printf("Encerrando programa..."); }
    else{
        clock_t timer;
        printf("Selecione Ordenacao:\n1 - Bubble Sort\n2 - Insertion Sort\n3 - Quick Sort\n");
        scanf("%i", &opcao);
        switch (opcao){
        case 1:
            timer = clock();
            bubble_sort(vet, size);
            timer = clock() - timer;
            printf("Vetor ordenado: ");
            for(int i=0; i<size; i++){
                printf("%i, ",vet[i]);
            }
            printf("Tempo para a ordenacao: %f", ((double)timer)/((CLOCKS_PER_SEC/1000)));
            break;
        
        case 2:
            timer = clock();
            insertion_sort(vet, size);
            timer = clock() - timer;
            printf("Vetor ordenado: ");
            for(int i=0; i<size; i++){
                printf("%i, ",vet[i]);
            }
            printf("Tempo para a ordenacao: %f", ((double)timer)/((CLOCKS_PER_SEC/1000)));
            break;
        
        case 3:
            
            timer = clock();
            quick_sort(vet, 0, size - 1);
            timer = clock() - timer;
            printf("Vetor ordenado: ");
            for(int i=0; i<size; i++){
                printf("%i, ",vet[i]);
            }
            printf("Tempo para a ordenacao: %f", ((double)timer)/((CLOCKS_PER_SEC/1000)));
            break;

        default:
            printf("Opcao inexistente");
            break;
        }
        if(opcao > 4 || opcao < 1){  printf("Encerrando programa..."); }


    }
}