#include <stdio.h>
#include <stdlib.h>

int main(){
    float salario = 0,INSS = 0,porcen = 0,salarioF = 0,aliquota = 0,IRRF = 0,desconto = 0;
    do{
        printf("Qual o seu salario:\n");
        scanf("%f",&salario);
    } while (salario<0);
    
    if (salario<=1039){
        porcen = 7.5;
    }else if (salario<=2089.60){
        porcen = 9;
    }else if(salario<=3134.40){
        porcen = 12;

    }else if (salario<=6101.06){
        porcen = 14;
    }else{
        INSS = 671.11;
    }
    if(porcen!=0)
        INSS = salario*porcen/100;
    salarioF = salario - INSS;

    if(salario>4664.68){
        aliquota = 27.5;
        desconto = 869.36;
    }else if(salario>3751.06){
        aliquota = 22.5;
        desconto = 636.13;
    }else if(salario>2826.66){
        aliquota = 15;
        desconto = 354.80;
    }else if(salario>1903.98){
        aliquota = 7.5;
        desconto = 142.80;
    }
    IRRF = salarioF*aliquota/100 - desconto;
    salarioF = salarioF - IRRF;
    printf("Salario inicial: %.2f\n",salario);
    if (porcen!=0){
        printf("Porcentagem do INSS: %.2f",porcen);
    }
    printf("\nValor do INSS: %.2f",INSS);
    if(aliquota!=0)
        printf("\nAliquota: %.2f",aliquota);
    printf("\nValor do IRRF: %.2f\nSalario final: %.2f\n",IRRF,salarioF);
}
/*
Até 1.903,98      aliquota	 descont
De 1.903,99 	    7,5	    142,80
De 2.826,66 	    15,0	354,80
De 3.751,06 	    22,5	636,13
Acima De 4.664,68	27,5	869,36

Tabela 1 - INSS - Atualizada março 2020
Até R$ R$1.039	7.5 %
Até R$2.089,60	9 %
Até R$3.134,40	12 %
Até R$6.101,06	14 %
Acima R$ 6.101,06	R$ 671,11*/