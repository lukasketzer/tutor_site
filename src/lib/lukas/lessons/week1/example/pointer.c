#include <stdio.h>


void foo() {

    int v = 5;
    int *a;
    a = &v;
    int q = *a;
    *a = 2;
}

int main(){
    int v = 5;
    printf("int v = %d (&v = %p)\n", v, &v);
    int *a;
    printf("int *a = %p\n", a);
    printf("============================\n");

    a = &v;
    printf("a = &v\n\n");
    printf("Adresse bei a = %p\n", a);
    printf("Wert an der Adresse von a = %d\n", *a);
    printf("============================\n");

    int q = *a;
    printf("int q = *a\n\n");
    printf("Wert an der Adresse von a = %d\n", *a);
    printf("Wert bei q = %d\n", q);

    printf("============================\n");
    *a = 2;
    printf("*a = 2\n\n");
    printf("Adresse bei a = %p\n",a);
    printf("Wert an der Adresse von a = %d\n", *a);



}
