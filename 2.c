#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct X {
    char a[256];
    int b;
};

int f (struct X *p, char *s) {
    int t = 0;
    int len = 0;
    if( strlen(s) > strlen(p->a))
        len = strlen(p->a);
    else
        len = strlen(s);
    printf("len=%d\n",len);
    for (int i = 0; i<len ; ++i)
        if (!(p->a[i] == s[i])){
            t++;
        }
    return p->b + t;
}

int f2 (struct X *p, char *s) {
    int t = 0;
    int len = 0;
    if( strlen(s) > strlen(p->a))
        len = strlen(p->a);
    else
        len = strlen(s);
    char local_pa [256];
    char local_s [256];
    printf("len=%d\n",len);
    for (int i = 0; i<len ; ++i)
        if (!(local_pa[i] == local_s[i])){
            t++;
        }
    return p->b + t;
}

int main(){
    struct X * x = malloc(sizeof(struct X));
    char * ss = malloc(256*sizeof(char));
    strcpy(x->a,"palabra");
    //strcpy(ss,  "palabra");
    x->b = 0;
    printf("Resultado f(): %d\n",f(x,x->a));
    printf("Press Enter to Continue\n"); 
    while(getchar() != '\n'); 
    free(x);
    free(ss);
    return 0;
}