/*
ALUNOS: Vinicius Dall Olivo Gonçalves
		Yuji Yamada Correa
		Ismael de Toledo Medeiros
		Luís Fernando Torres Gonçalves
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura do Contato
typedef struct{
    int id;
    char nome[30];
    char email[50];
    char telefone[14];
}contato;

//Funções que Trabalham com o vetor contatos
void adicionarContato(contato *contatos,int);
void removerContato(contato *contatos,int *);
void alterarContato(contato *contatos,int);
void mostrarContatos(contato *contatos,int);

//Função que abre o arquivo
FILE* abreArquivo(char a);

//Funções que mexem com o arquivo dos contatos 
int contaContatos();
void buscaContatos(contato *contatos,int);
void salvarContato(contato contatos);
void atualizarContatos(contato *contatos,int,int);

//Funções de validação
int validaId(contato *contatos,int,char *);
int validaNome(char *);
int validaNumero(char *);
int verificaEmail(char *);

//Função que trabalha o nome
void processaNome(char *);

//Inicia o codigo e mostra o menu.
int main(){
    int tamanho = contaContatos();
    int cont = tamanho-10;
    contato *contatos = (contato*) calloc(tamanho,(sizeof(contato)));
    buscaContatos(contatos,cont);

    int opcao = 0;
    do{
        opcao = -1;
        printf("Escolha um das opcoes abaixo:\n1 - Adicionar\n2 - Remover\n3 - Alterar\n4 - Mostrar\n5 - Finalizar\n");
        char id[5];
        gets(id);
        if(validaNumero(id)){
            opcao = atoi(id);
        }
        switch (opcao){
        case 1:
            if(tamanho==cont){
                tamanho+=10;
                realloc(contatos,tamanho);
            } 
            adicionarContato(contatos,cont);
            cont++;
            break;
        case 2:
            removerContato(contatos,&cont);
            break;
        case 3:
            alterarContato(contatos,cont);
            atualizarContatos(contatos,cont,-1);
            break;
        case 4:
            mostrarContatos(contatos,cont);
            break;
        case 5:
            printf("\n\nTchau!");
            break;
        default:
            printf("Valor invalido, digite novamente!\n");
            break;
        }
    }while(opcao!=5);
    return 0;
}

void adicionarContato(contato *contatos,int n){
    int valida= 0;
    char nome[30], email[50],tele[14];
    contatos[n].id = n;
    do{
        printf( "Digite o nome:\n");
        gets(nome);
        
        valida = validaNome(nome);
        
        if(!valida) printf("Os valores: %s. São invalidos",(char[]) {'*',',','"',',',10,',',39});
        else if(strlen(nome)>0) strcpy(contatos[n].nome,nome);
        else valida = 0;
    
    } while (!valida);
    
    do{
        
        printf("Digite o teledone:\n");
        gets(tele);
        
        valida = validaNumero(tele);
        
        if(!valida) printf("Valor digitado invalido\n");
        else if(atoi(tele)<1) valida = 0;
        else if(strlen(tele)!=0) strcpy(contatos[n].telefone,tele);
        else valida = 0;

    } while (!valida);
    
    do{

        printf("Digite o email:\n");
        gets(email);
        
        valida = !(verificaEmail(email));
        
        if(!valida) printf("Email digitado invalido\n");
        else if(strlen(email)!=0) strcpy(contatos[n].email,email);
        else valida = 0;

    } while (!valida);
    salvarContato(contatos[n]);
}

void removerContato(contato *contatos,int *n){
    int alt = validaId(contatos,*n,"remover");
    if(alt>=0){
        atualizarContatos(contatos,*n,alt);
        *n-=1;
        buscaContatos(contatos,*n);

        printf("Contato removido com sucesso!");
    }
}

void alterarContato(contato *contatos,int n){
    int alt = validaId(contatos,n,"alterar");
    int valida = 0;
    if(alt>=0){

        printf("Pressione apenas enter nos que deseja não modificar!\n");
        char nome[30], email[50],tele[14];

        do{
            
            printf("Nome atual: %s.\nDigite o nome:\n",contatos[alt].nome);
            gets(nome);
            
            valida = validaNome(nome);

            if(!valida) printf("Os valores: %s. São invalidos\n",(char[]) {'*',',','"',',',10,',',39});
            else if(strlen(nome)!=0) strcpy(contatos[alt].nome,nome);
            
           
        }while (!valida);
        
        do{
        
            printf("Telefone atual: %s.\nDigite o telefone:\n",contatos[alt].telefone);
            gets(tele);
            
            valida = validaNumero(tele);

            if(!valida) printf("Valor digitado invalido\n");
            else if(strlen(tele)==0) valida = 1;
            else if(atoi(tele)<1) valida = 0;
            else strcpy(contatos[alt].telefone,tele);

        }while (!valida);

        do{

            printf("Email atual: %s.\nDigite o email:\n",contatos[alt].email);
            gets(email);

            valida = !(verificaEmail(email));

            if(strlen(email)==0) valida = 1;
            else if(!valida) printf("Email digitado invalido\n");
            else strcpy(contatos[alt].email,email);
            
        } while (!valida);
        printf("Contato alterado com sucesso!\n\n");
    }
}

void mostrarContatos(contato *contatos,int n){
	if(n>0){
	    for (int i = 0; i < n; i++){
	        printf("\n\n+----------------------------------------+\n");
	        printf("| Id: %d\n",contatos[i].id+1);
	        printf("| Nome: %s\n",contatos[i].nome);
	        printf("| Telefone: %s\n",contatos[i].telefone);
	        printf("| Email: %s\n",contatos[i].email);
	        printf("+----------------------------------------+\n");
	    }
	}else{
		printf("Nao ha contatos cadastrados\n");
	}
}

FILE* abreArquivo(char a){
    FILE *arquivo = NULL;
    if(a=='r'){
        arquivo = fopen("texto.txt","r");
        if(arquivo==NULL){
            arquivo = fopen("texto.txt","w");
            fclose(arquivo);
            arquivo = fopen("texto.txt","r");
        }
    }else if(a=='a'){
        arquivo = fopen("texto.txt","a");
    }else{
        arquivo = fopen("texto.txt","w");
    }
    return arquivo;
}

int contaContatos(){
    FILE* arquivo = abreArquivo('r');
    int cont = 10;
    char texto[50];
    while (!(feof(arquivo))){
        fgets(texto,20,arquivo);
        fgets(texto,20,arquivo);
        if(feof(arquivo)){
            continue;
        }
        fgets(texto,30,arquivo);
        fgets(texto,50,arquivo);
        cont++;
    }
    fclose(arquivo);
    return cont;
}

void buscaContatos(contato *contatos,int n){
    FILE *arquivo = abreArquivo('r');
    int cont = 0;
    while (cont<n){
        char id[20],nome[30],tele[30],email[50];
        
        fscanf(arquivo,"%s",id);
        fscanf(arquivo,"%s",nome); 
        fscanf(arquivo,"%s",tele);
        fscanf(arquivo,"%s",email);

        processaNome(nome);

        contatos[cont].id =  atoi(id);
        strcpy(contatos[cont].nome,nome);
        strcpy(contatos[cont].telefone,tele);
        strcpy(contatos[cont].email,email);

        cont++;
    }
    fclose(arquivo);
}

void salvarContato(contato contatos){
    FILE* arquivo = abreArquivo('a');
    if(contatos.id!=0){
        fprintf(arquivo,"\n");
    }
    fprintf(arquivo,"%d\n",contatos.id);

    char nome[30];
    strcpy(nome,contatos.nome);
    processaNome(nome);

    fprintf(arquivo,"%s\n",nome);
    fprintf(arquivo,"%s\n",contatos.telefone);
    fprintf(arquivo,"%s",contatos.email);
    fclose(arquivo);
}

void atualizarContatos(contato *contatos,int n,int remove){
    FILE* arquivo = abreArquivo('w');
    int cont = 0;
    for (int i = 0; i < n; i++){
        if(remove == i){
            continue;
        }
        if(cont!=0){
            fprintf(arquivo,"\n");
        }
        fprintf(arquivo,"%d\n",cont);
        char nome[30];
        strcpy(nome,contatos[i].nome);
        processaNome(nome);
        fprintf(arquivo,"%s\n",nome);
        fprintf(arquivo,"%s\n",contatos[i].telefone);
        fprintf(arquivo,"%s",contatos[i].email);
        cont++;
    }
    fclose(arquivo);
}

int validaId(contato *contatos,int n,char *referencia){
    int alt;
    char id[4];
    int valida= 0;
    do{        
        alt = 0;
        printf("Digite o id referente ao contato que deseje %s. (0 para cancelar, -1 para mostrar contatos)\n",referencia);
        gets(id);
        if(validaNumero(id)){
            alt = atoi(id);
            if(alt==0){
                return -1;
            }else if(alt==-1){
                printf("\n\n");
                mostrarContatos(contatos,n);
                printf("\n\n");
                continue;
            }
            alt--;
        }else{
            printf("\nDigite um valor valido\n\n");
            continue;
        }
        
        for (int i = 0; i < n; i++){
            if(alt==contatos[i].id){
                valida = 1;
                break;
            }
        }
        if(!valida){
            printf("\nDigite um id valido\n\n");
        }
    } while (!valida);

    return alt;
}

int validaNome(char *nome){
    for (int i = 0; i < strlen(nome); i++){
        if((nome[i] == '*')||(nome[i]=='"')||(nome[i]==39/* ' */)||(nome[i]==10/* \n */)){
            return 0;
        }
    }
    return 1;
}

int validaNumero(char *numero){
    for (int i = 0; i < strlen(numero); i++){
        if((i==0) && ((numero[i]=='-') || (numero[i]=='+'))){
            continue;
        }
        if( !( (numero[i]>='0') && (numero[i]<='9') )){
            return 0;
        }
    }
    return 1;
}

int verificaEmail(char *email){
    int valida = 1;
    int cont = 0;
    for (int i = 0; i < strlen(email); i++){
        if(((email[i]!='@')&&(email[i]!='.')&&(email[i]!='-')&&(email[i]!='_'))&&((!((email[i]>='0')&&(email[i]<='9')))&&(!(((email[i]>='a')&&(email[i]<='z'))||((email[i]>='A')&&(email[i]<='Z')))))){
            valida = 1;
            break;
        }else if((email[i]=='@')){
            cont++;//Contador de '@'
            char verifica[2];//String para verificar de depois do '@' tem mais um caracter
            verifica[0] = email[i+1];
            verifica[1] = '\0';
            if(!(strcmp(verifica,""))||(i==0)||(cont>1)){
                valida = 1;
                break;
            }else{
                valida = 0;
            }
        }
    }
    return valida;
}

void processaNome(char *nome){
    for (int i = 0; i < strlen(nome); i++){
        if(nome[i]==' '){
            nome[i] = '*';
        }else if(nome[i]=='*'){
            nome[i] = ' ';
        }
    }   
}
