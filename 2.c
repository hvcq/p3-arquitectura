#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct X {
    char a[500000];
    int b;
};

int f (struct X *p, char *s) {
    int t = 0;
    int len = 0;
    if( strlen(s) > strlen(p->a))
        len = strlen(p->a);
    else
        len = strlen(s);
    for (int i = 0; i<len ; ++i)
        if (!(p->a[i] == s[i])){
            t++;
        }
    return p->b + t;
}

int f2 (struct X *p, char *s) {
    int t = 0;
    int len = 0;
    int size_s = strlen(s);
    int size_pa = strlen(p->a);
    char cadena_s [size_s + 1];
    char cadena_pa [size_pa + 1];
    strcpy(cadena_s,s);
    strcpy(cadena_pa,p->a);
    if( size_s > size_pa)
        len = size_pa;
    else
        len = size_s;
    /*Aplicamos loop unrolling */
    for (int i = 1; i<len ; i+=2){
        if (!(cadena_pa[i-1] == cadena_s[i-1])){
            t++;
        }
        if (!(cadena_pa[i] == cadena_s[i])){
            t++;
        }
    }
    if (len%2 != 0){
        if(!(cadena_pa[len - 1] == cadena_s[len - 1])){
            t++;
        }
    }
    return p->b + t;
}

int main(){
    FILE * fichero;
    fichero = fopen("texto1.txt","r");
    char cadena_local[500000];
    if( fgets(cadena_local,500000,fichero) != NULL ){
        int tam =strlen(cadena_local);
        printf("Texto Guardado! con size = %d\n",tam);
    }
    struct X * x = malloc(sizeof(struct X));
    char * ss = malloc(500000*sizeof(char));
    strcpy(x->a,cadena_local);
    strcpy(ss,  cadena_local);
    x->b = 0;
    double time = 0;
    clock_t start1 = clock();
    printf("resultado f():%d",f(x,ss));
    clock_t end1 = clock();
    time = (double)(end1 - start1)/ CLOCKS_PER_SEC;
    printf("tiempo de f = %f segundos\n",time);
    time = 0;
    clock_t start2 = clock();
    printf("resultado f():%d",f2(x,ss));
    clock_t end2 = clock();
    time = (double) (end2 - start2)/ CLOCKS_PER_SEC;
    printf("tiempo de f2 = %f segundos\n",time);
    //printf("Press Enter to Continue\n"); 
    //while(getchar() != '\n'); 

    free(x);
    free(ss);
    return 0;
}