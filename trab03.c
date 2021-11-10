#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <string.h>



typedef struct {
    char palavra[30];
} dados;

void ordenaDatas(struct tm* a[], int n) {
   int i = 0, j = 0;
   long tmp;
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

void ordenarString(dados vet[], int size){

    char aux[30];

    for(int i = 1; i < size; i++){
         for(int j = 0; j < size-1; j++){
                       
              if(strcmp(vet[j].palavra,vet[j+1].palavra) > 0){
                strcpy(aux,vet[j].palavra);
                 strcpy(vet[j].palavra,vet[j+1].palavra);
                 strcpy(vet[j+1].palavra,aux);}                               
           }      
         }

}

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

    dados vetString[9999];
    int opcao = -1, size, vet[9999];
    struct tm data[999];
    
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
        
        printf("Vetor: \n");
        for(int i = 0; i<size; i++){ printf("%i,", vet[i]);}
        printf("\n");
        break;
    
    case 2:
        printf("Qual o tamanho do vetor que deseja?");
        scanf("%d", &size);
        for(int i = 0; i<size; i++){  
            int aux;
            printf("Digite o %i numero: ", i);
            scanf("%i", &aux);
            vet[i] = aux; 
        }

        printf("Vetor: \n");
        for(int i = 0; i<size; i++){
            printf("%d ", vet[i]);
        }
        printf("\n");
        break;
    
    case 3:
        printf("Qual o tamanho do vetor que deseja? ");
        scanf("%d", &size);

        for(int i = 0; i<size; i++){
            printf("Digite a data desejada: ");
            scanf("%d", &data[i].tm_mday);
            scanf("%d", &data[i].tm_mon);
            scanf("%d", &data[i].tm_year);
            
        }

        printf("Datas: \n");
        for(int i = 0; i<size; i++){
            printf("%d %d %d", data[i].tm_mday, data[i].tm_mon, data[i].tm_year);
            printf("\n");
        }

        break;
    
    case 4:
        printf("Qual o tamanho do vetor que deseja? ");
        scanf("%d", &size);
        for(int i = 0; i<size; i++){  
            printf("Digite a %i palavra: ", i);
            scanf("%s", &vetString[i].palavra); 
        }
        printf("Strings: \n");
        for(int i = 0; i<size; i++){
            printf("%s ", vetString[i].palavra);
        }
        printf("\n");
        break;
    
    default:
        printf("Opcao inexistente");
        break;
    }
    if(opcao > 4 || opcao < 1){  printf("Encerrando programa..."); }
    else if(opcao == 1 || opcao == 2){
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
    
    }else if(opcao == 3){
        clock_t timer;
        timer = clock();
        ordenaDatas(data, size);
        timer = clock() - timer;
        for(int i=size - 1; i>-1; i--){
                printf("%d %d %d", data[i].tm_mday, data[i].tm_mon, data[i].tm_year);
                printf("\n");
        }
        printf("Tempo para a ordenacao: %f", ((double)timer)/((CLOCKS_PER_SEC/1000)));

    }else if(opcao == 4){
        clock_t timer;
        printf("Ordenando Strings\n");
        timer = clock();
        ordenarString(vetString, size); 
        timer = clock() - timer;
        printf("Strings Ordenados: \n");
        for(int i = 0; i<size; i++){
            printf("%s ", vetString[i].palavra);
        }
        printf("Tempo para a ordenacao: %f", ((double)timer)/((CLOCKS_PER_SEC/1000)));
    }
}