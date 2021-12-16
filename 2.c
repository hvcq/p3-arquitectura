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
    if( strlen(s) > strlen(p->a)){
        len = strlen(p->a);
    }else{
        len = strlen(s);
    }
    /*Aplicamos loop unrolling */
    for (int i = 1; i<len ; i+=2){
        if (!(p->a[i-1] == s[i-1])){
            t++;
        }
        if (!(p->a[i] == s[i])){
            t++; 
        }
    }
    if (len%2 != 0){
        if(!(p->a[len - 1] == s[len - 1])){
            t++;
        }
    }
    return p->b + t;
}

int f3 (struct X *p, char *s) {
    int t = 0;
    int len = 0;
    if( strlen(s) > strlen(p->a)){
        len = strlen(p->a);
    }else{
        len = strlen(s);
    }
    /*Aplicamos loop unrolling */
    int i = 2;
    for (i; i<len ; i+=3){
        if (!(p->a[i-2] == s[i-2])){
            t++;
        }
        if (!(p->a[i-1] == s[i-1])){
            t++;
        }
        if (!(p->a[i] == s[i])){
            t++;
        }
    }
    if(i < len){
        for( i ; i < len ; i++){
            if (!(p->a[i] == s[i])){
            t++;
            }
        }
    }
    return p->b + t;
    
}

int f4 (struct X *p, char *s) {
    int t = 0;
    int len = 0;
    int len_s = strlen(s);
    int len_pa = strlen(p->a);
    if( len_s > len_pa){
        len = len_pa;
    }else{
        len = len_s;
    }
    /*Aplicamos loop unrolling */
    for (int i = 1; i<len ; i+=2){
        if (!(p->a[i-1] == s[i-1])){
            t++;
        }
        if (!(p->a[i] == s[i])){
            t++; 
        }
    }
    if (len%2 != 0){
        if(!(p->a[len - 1] == s[len - 1])){
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
    clock_t start = clock();
    printf("resultado f():%d",f(x,ss));
    clock_t end = clock();
    time = (double)(end - start)/ CLOCKS_PER_SEC;
    printf("tiempo de f = %f segundos\n",time);
    time = 0;
    start = clock();
    printf("resultado f():%d",f2(x,ss));
    end = clock();
    time = (double) (end - start)/ CLOCKS_PER_SEC;
    printf("tiempo de f2 = %f segundos\n",time);
    time = 0;
    start = clock();
    printf("resultado f():%d",f3(x,ss));
    end = clock();
    time = (double) (end - start)/ CLOCKS_PER_SEC;
    printf("tiempo de f3 = %f segundos\n",time);
    time = 0;
    start = clock();
    printf("resultado f():%d",f4(x,ss));
    end = clock();
    time = (double) (end - start)/ CLOCKS_PER_SEC;
    printf("tiempo de f4 = %f segundos\n",time);
    //printf("Press Enter to Continue\n"); 
    //while(getchar() != '\n'); 
    free(x);
    free(ss);
    return 0;
}