#include <stdio.h>
#include <stdlib.h>

int main(){
    double cont, QA =13455.66;
    cont = QA;
    double is = 0.051;
    for (int i = 0; i < 8; i++){
        if(i!=7)
        cont = cont*is + cont;
        printf("%d - %lf\n",i+1,cont);
        cont = QA + cont;
    }
    
    return 0;
}
