#include <stdio.h>
#include <stdlib.h>
#define INTMAX 1073741823
 
int main(){
    FILE *entrada;
    FILE *SAIDA;
 
    printf("insira a quantia de testes: ");
 
    int ntestes;
    scanf("%d",&ntestes);
 
    entrada = fopen_s(&SAIDA,"entradaarquivo.bin","wb");
 
    srand(time(NULL));
    while(ntestes--){
        int testlen = rand() % 100000;
        printf("%d ",testlen);
        if(testlen){
            int *arr = malloc(sizeof(int)*testlen);
            fwrite(&testlen,sizeof(int),1,SAIDA);
            for(int i = 0;i<testlen;i++){
                int numb = (rand() - 15000);
                arr[i] = numb;
            }
            fwrite(arr,testlen*sizeof(int),1,SAIDA);
        }
        else{
            ntestes++;
        }
    }
    fclose(entrada);
    fclose(SAIDA);
    return 0;
}
