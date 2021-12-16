#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct X{
    char *a;
    int b;
};

int trolla(struct X *p, char *s) {
    int t = 0;
    int len = 0;
    char *z = malloc(1024);
    if(z != NULL){
        p->a = z;
    }else{
        return -1;
    }
    strcpy(z,"otra cadena de caracteres");
    if(strlen(s) > strlen(p->a)){
        len=strlen(p->a);
    }else{
        len=strlen(s);
    }
    int leeeen = strlen(p->a);
    printf("strlen of p->: %d\n",leeeen);
    for(int i = 0; i<len; i++){
        if(!(p->a[i] == s[i])){
            t++;
        }
    }
    free(z);
    return p->b + t;
}

int main(int argc, char const *argv[])
{
    struct X * x = (struct X *)malloc(sizeof(struct X));
    char * ss = (char *)malloc(1024);
    strcpy(ss,  "arania grande");
    x->b = 0;
    printf("resultado f():%d",trolla(x,ss));
    free(x);
    free(ss);
    return 0;
}