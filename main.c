#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>


struct Vacinacao
{
    int codigo;
    char nome[100];
    char cpf[20];
    char vacina[30];
    char data[15];
    char lote[20];
};

int verificarCPF(char CPF[], struct Vacinacao* vacinacao, int nPaciente){
    int i;
    
    if (CPF[3] != '.' || CPF[7] != '.' || CPF[11] != '-')
        return 0;
    
    for (i=0; i<3; i++){
        if (isdigit(CPF[i])==0)
            return 0;
    }
    
    for (i=4; i<7; i++){
        if (isdigit(CPF[i])==0)
            return 0;
    }
    
    for (i=8; i<11; i++){
        if (isdigit(CPF[i])==0)
            return 0;
    }
    for (i=12; i<14; i++){
        if (isdigit(CPF[i])==0)
            return 0;
    }
    for (i=0; i<nPaciente;i++){
        if(strcmp(CPF, vacinacao[i].cpf)==0)
        return 0;
    }
    return 1;
}

int verificaData (char data[]){
    int i=0;
    
    if (data[2] != '/' || data[5] != '/')
        return 0;
    
    for (i=0; i<2; i++){
        if (isdigit(data[i])==0)
            return 0;
    }
    for (i=3; i<5; i++){
        if (isdigit(data[i])==0)
            return 0;
    }
    
    for (i=6; i<8; i++){
        if (isdigit(data[i])==0)
            return 0;
    }
    return 1;
}


int main(int argc, const char * argv[])
{
    setlocale(LC_ALL, "portuguese");
    
    struct Vacinacao vacinacao[9999];
    int opcao, paciente=0, nPaciente=0, i=0;
    char CPF[20], data[9];
    
    printf("========================================================\n");
    printf("   SISTEMA NACIONAL DE CONTROLE DE VACINAÇÃO COVID-19    \n");
    printf("======================================================== \n \n");
    
    do {
        printf ("\n*** Escolha uma opção ***\n\n");
        printf ("1 - Cadastrar paciente \n");
        printf ("2 - Listar registros \n");
        printf ("3 - Consulta por CPF \n");
        printf ("4 - Sair \n\n");
        scanf ("%d",&opcao);
        
        switch (opcao) {
            
            case 1:
                
                do{
                printf("Digite a quantidade de pacientes a serem cadastrados. \n");
                scanf("%d",&paciente);
                } while (paciente == 0);
                fflush(stdin);
                
                do{
                    
                    printf ("Digite o nome do paciente: \n");
                    fgets (vacinacao[nPaciente].nome, 100, stdin);
            
                    fflush(stdin);
                    
                    do{
                        printf("Digite o CPF do usuário (formato 123.123.123-12): \n");
                        fgets (CPF, 15, stdin);
                    } while (verificarCPF (CPF, vacinacao, nPaciente)==0);
                    strcpy(vacinacao[nPaciente].cpf, CPF);
                    fflush(stdin);
                    
                    printf ("Digite o a marca da vacina aplicada: \n");
                    fgets (vacinacao[nPaciente].vacina, 30, stdin);
                    fflush(stdin);
                   
                    do{
                    printf ("Digite a data da dose (formato DD/MM/AA): \n");
                    fgets(data, 9, stdin);
                    } while (verificaData(data)==0);
                    strcpy(vacinacao[nPaciente].data, data);
                    fflush(stdin);
                    
                    printf ("Digite o lote da vacina: \n");
                    scanf("%s", vacinacao[nPaciente].lote);
                    fflush(stdin);
                    vacinacao[nPaciente].codigo = nPaciente +1;
                    nPaciente++;
                    paciente--;
                    
                }
                while (paciente>0);
                break;
            case 2: ;
                for (i = 0; i < nPaciente; i++){
                    printf("-------------------------------------------- \n");
                    printf("Código: %d \n",vacinacao[i].codigo);
                    printf ("Nome: %s \n",vacinacao[i].nome);
                    printf ("CPF: %s \n",vacinacao[i].cpf);
                    printf("Vacina: %s \n",vacinacao[i].vacina);
                    printf("Data da vacinação: %s \n",vacinacao[i].data);
                    printf("Lote: %s \n\n",vacinacao[i].lote);
                    printf("-------------------------------------------- \n\n");
                }
                break;
            case 3:;
                
                    printf("Digite o CPF do paciente (formato 123.123.123-12)\n");
                    scanf("%s", CPF);
                    fflush(stdin);
                
                
                for (i=0; i < nPaciente; i++){
                    
                    if (strcmp(CPF, vacinacao[i].cpf)==0){
                        printf("-------------------------------------------- \n");
                        printf("Código: %d \n",vacinacao[i].codigo);
                        printf ("Nome: %s \n",vacinacao[i].nome);
                        printf ("CPF: %s \n",vacinacao[i].cpf);
                        printf("Vacina: %s \n",vacinacao[i].vacina);
                        printf("Data da vacinação: %s \n",vacinacao[i].data);
                        printf("Lote: %s \n\n",vacinacao[i].lote);
                        printf("-------------------------------------------- \n\n");
                        break;
                    }
                }
                break;
        }
    } while (opcao !=4 || opcao==0  || opcao>4);{
        printf ("Obrigado por utilizar o Sistema de Nacional de Cadastro de Vacinação COVID-19 \n\n");
    }
    return 0;
}
