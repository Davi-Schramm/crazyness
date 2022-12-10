#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *entrada;

    entrada = fopen("entradaarquivo.bin","rb");
    FILE *saida;
    saida = fopen("saidaarquivo.txt","w");
    int keeper = 1;
    int start = 0;
    if(entrada && saida){
        while(keeper){
            fread(&keeper,sizeof(int),1,entrada);
            printf("%d ",keeper);
            int *arr = malloc(keeper*sizeof(int));
            if(!keeper){
                free(arr);
                break;
            }
            int positivo = 0;
            int negativo = 0;
            int numero;
            for(int i = 0;i<keeper;i++)
                fread(arr,sizeof(int),keeper,entrada);
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
            while(feof(entrada)){
                int b;
                fread(&b,sizeof(int),1,entrada);
                printf("%d ",b);
                break;
            }
            
            free(arr);
            break;
        }
        fclose(saida);
        fclose(entrada);
    }
    return 0;
}
