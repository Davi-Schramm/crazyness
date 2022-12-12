#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *entrada;

    entrada = fopen("entradaarquivo.txt","r");
    FILE *saida;
    saida = fopen("saidaarquivo.txt","w");
    int keeper = 1;
    if(entrada && saida){
        while(keeper){
            fscanf(entrada,"%d",&keeper);
            int *arr = malloc(keeper*sizeof(int) + 5*sizeof(int));
            if(!keeper){
                free(arr);
                break;
            }
            int positivo = 0;
            int negativo = 0;
            int numero;
            for(int i = 0;i<keeper;i++)
                fscanf(entrada,"%d",&arr[i]);
            for(int i = 0;i<keeper;i++){
                if(arr[i] < 0)
                    negativo++;
                else
                    positivo++;
            }
            int success = fprintf(saida,"%d negativos, %d positivos\n",negativo, positivo);
            if(success)
                printf("Arquivo salvo com sucesso!\n");
            else
                printf("Ocorreu um erro no arquivo!\n");
            free(arr);
        }
        fclose(saida);
        fclose(entrada);
    }
    return 0;
}
