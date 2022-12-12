#include <stdio.h>
#define INTMAX 1073741823
 
int main(){
    FILE *entrada;
 
    printf("insira a quantia de testes: ");
 
    int ntestes;
    scanf("%d",&ntestes);
 
    entrada = fopen("entradaarquivo.txt","w");
    if(entrada){
        srand(time(NULL));
    
        while(ntestes--){
            int testlen = rand() % 100000;
            if(testlen){
                fprintf(entrada,"%d ",testlen);
                for(int i = 0;i<testlen;i++){
                    int numb = (rand() - 15000);
                    fprintf(entrada,"%d ",numb);
                    }
                fprintf(entrada,"\n");
            }
            else{
                ntestes++;
            }
        }
        fprintf(entrada,"0");
        fclose(entrada);
    }
    return 0;
}
