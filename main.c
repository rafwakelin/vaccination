/*printf("CENTRO UNIVERSITÁRIO CESUMAR \n");
printf ("Curso: Bacharelado em Engenharia de Software \n");
printf ("Discilplina: Algorítmos e Lógica de Programação 2 \n");
printf ("Atividade: MAPA Modulo 52/22 \n");
printf ("Aluno: Wellitom Rafael Queiroz dos Santos \n");
printf ("RA: 22032770-5 \n"); */

#include <stdio.h>
#include <stdlib.h>

typedef struct vacinacao
{
    int codigo;
    char nome[100];
    char cpf[14];
    char vacina[30];
    char data[10];
    int lote;
    struct vacinacao *proximo;
    
}Vacinacao;

typedef struct{
    Vacinacao *inicio;
    int tam;
}Lista;

void inserirInicio (Lista *lista, int codigo){
    Vacinacao *no, *novo = (Vacinacao*)malloc(sizeof(Vacinacao));
    novo->codigo = codigo;
    novo -> proximo = NULL;
    
    if (lista-> inicio ==NULL){
        lista->inicio=novo;
    } else{
        no = lista->inicio;
        while (no->proximo != NULL)
            no = no->proximo;
        no->proximo=novo;
    }
    lista->tam++;
}

void imprimir (Lista *lista){
    Vacinacao *inicio = lista -> inicio;
    while (inicio != NULL){
        printf ("%d", inicio -> codigo);
        inicio = inicio -> proximo;
    }
    printf ("\n\n");
}




int main() {
    Vacinacao vacinacao;
    int opcao, codigo=0, i=0;
    Lista lista;
    
    lista.inicio = NULL;
    lista.tam = 0;
    
    printf("========================================================\n");
    printf("SISTEMA NACIONAL DE CONTROLE DE VACINAÇÃO COVID-19 \n");
    printf("======================================================== \n \n");
    
    do {
        printf ("Escolha uma opção: \n\n");
        printf ("1 - Cadastrar paciente \n");
        printf ("2 - Listar registros \n");
        printf ("3 - Consulta por CPF \n");
        printf ("4 - Sair \n\n");
        scanf ("%d",&opcao);
        
        switch (opcao) {
            
            case 1:
                printf ("Digite o CPF (formato 123.123.123-12): \n");
                fgets(vacinacao.cpf, 14, stdin);
                fflush (stdin);
                printf ("Informe o nome do paciente: \n");
                fgets (vacinacao.nome,100,stdin);
                printf ("Informe a vacina: \n");
                fgets (vacinacao[i].vacina, 30, stdin);
                fflush (stdin);
                printf ("Informe a data da vacinação (formato DD/MM/AAAA): \n");
                fgets (vacinacao[i].data, 10, stdin);
                fflush (stdin);
                printf ("Informe o lote da vacina (formato 123123123): \n");
                scanf ("%d",&vacinacao[i].lote);
                fflush (stdin);
                inserirInicio (&lista, codigo);
                break;

            case 2:
                imprimir(&lista);
                printf ("================================================= \n");
                break;
            
            case 4:
        printf ("Obrigado por utilizar o Sistema Nacional de Controle de Vacinação contra COVID-19. \n");
                break;
            
            default:
                printf ("Opção inválida \n\n");
                break;
        }
    }
    while (opcao !=4 || opcao > 4);
    
    /*if (opcao == 1){
        printf ("Informe a quantidade de pacientes a serem cadastrados: \n");
        scanf ("%d",&count);
        
        while (i <= count){
            cadastro[i].codigo = i;
            fflush (stdin);
            printf ("Digite o CPF (formato 123.123.123-12): \n");
            fgets(cadastro[i].cpf, 14, stdin);
            fflush (stdin);
            printf ("Informe o nome do paciente: \n");
            fgets (cadastro[i].nome,100,stdin);
            printf ("Informe a vacina: \n");
            fgets (cadastro[i].vacina, 30, stdin);
            fflush (stdin);
            printf ("Informe a data da vacinação (formato DD/MM/AAAA): \n");
            fgets (cadastro[i].data, 10, stdin);
            fflush (stdin);
            printf ("Informe o lote da vacina (formato 123123123): \n");
            scanf ("%d",&cadastro[i].lote);
            fflush (stdin);
            i++;
        }
        
        
    }
    else{
        if (opcao == 2){
        
                printf ("Código: %d \n",cadastro[i].codigo);
                printf ("Nome: %s \n",cadastro[i].nome);
                printf ("CPF: %s \n",cadastro[i].cpf);
                printf ("Vacina: %s \n",cadastro[i].vacina);
                printf ("Data da vacinação: %s \n",cadastro[i].data);
                printf ("Lote: %d \n",cadastro[i].lote);
                printf ("================================================= \n\n");
           
        }
    }*/
    return 0;
}

/*switch (opcao) {
    
    case 1:
        printf ("Informe a quantidade de pacientes a serem cadastrados: \n");
        scanf ("%d",&count);
        
        for (i=1; i<=count; i++){
            cadastro[i].codigo = i;
            fflush (stdin);
            printf ("Digite o CPF (formato 123.123.123-12): \n");
            fgets(cadastro[i].cpf, 14, stdin);
            fflush (stdin);
            printf ("Informe o nome do paciente: \n");
            fgets (cadastro[i].nome,100,stdin);
            printf ("Informe a vacina: \n");
            fgets (cadastro[i].vacina, 30, stdin);
            fflush (stdin);
            printf ("Informe a data da vacinação (formato DD/MM/AAAA): \n");
            fgets (cadastro[i].data, 10, stdin);
            fflush (stdin);
            printf ("Informe o lote da vacina (formato 123123123): \n");
            scanf ("%d",&cadastro[i].lote);
            fflush (stdin);
        }
        break;

    case 2:
        printf ("Código: %d \n",cadastro[i].codigo);
        printf ("Nome: %s \n",cadastro[i].nome);
        printf ("CPF: %s \n",cadastro[i].cpf);
        printf ("Vacina: %s \n",cadastro[i].vacina);
        printf ("Data da vacinação: %s \n",cadastro[i].data);
        printf ("Lote: %d \n",cadastro[i].lote);
        printf ("=================================================");
        break;
    
    case 3:
        break;
    
    case 4:
        break;
    
    default:
        printf ("Opção inválida \n\n");
        break;
}*/

