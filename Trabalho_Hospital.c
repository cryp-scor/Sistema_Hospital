#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 100
// Estruturas para armazenar médicos, pacientes e consultas
typedef struct {
    int id;
    char nome[50];
    char especialidade[50];
} Medico;

typedef struct {
    int id;
    char nome[50];
    char identidade[20];
    char endereco[100];
    char telefone[15];
    char sexo[10];
} Paciente;

typedef struct {
    int numero;
    int id_medico;
    int id_paciente;
    char horario[10];
    int duracao;
    char data[12];
} Consulta;

Medico medicos[MAX];
Paciente pacientes[MAX];
Consulta consultas[MAX];

int totalMedicos = 0, totalPacientes = 0, totalConsultas = 0;

// Funções para entrada de usuário
void adicionarMedico() {
    printf("\nAdicionando Medico:\n");
    printf("ID: ");
    scanf("%d", &medicos[totalMedicos].id);
    printf("Nome: ");
    scanf(" %[^"]", medicos[totalMedicos].nome);
    printf("Especialidade: ");
    scanf(" %[^"]", medicos[totalMedicos].especialidade);
    totalMedicos++;
}

void adicionarPaciente() {
    printf("\nAdicionando Paciente:\n");
    printf("ID: ");
    scanf("%d", &pacientes[totalPacientes].id);
    printf("Nome: ");
    scanf(" %[^"]", pacientes[totalPacientes].nome);
    printf("Identidade: ");
    scanf(" %[^"]", pacientes[totalPacientes].identidade);
    printf("Endereco: ");
    scanf(" %[^"]", pacientes[totalPacientes].endereco);
    printf("Telefone: ");
    scanf(" %[^"]", pacientes[totalPacientes].telefone);
    printf("Sexo: ");
    scanf(" %[^"]", pacientes[totalPacientes].sexo);
    totalPacientes++;
}

void adicionarConsulta() {
    printf("\nAgendando Consulta:\n");
    printf("Numero: ");
    scanf("%d", &consultas[totalConsultas].numero);
    printf("ID do Medico: ");
    scanf("%d", &consultas[totalConsultas].id_medico);
    printf("ID do Paciente: ");
    scanf("%d", &consultas[totalConsultas].id_paciente);
    printf("Horario: ");
    scanf(" %[^"]", consultas[totalConsultas].horario);
    printf("Duracao (min): ");
    scanf("%d", &consultas[totalConsultas].duracao);
    printf("Data: ");
    scanf(" %[^"]", consultas[totalConsultas].data);
    totalConsultas++;
}

void visualizarConsultas() {
    printf("\nLista de Consultas:\n");
    for (int i = 0; i < totalConsultas; i++) {
        printf("Consulta %d - Medico: %d, Paciente: %d, Data: %s, Horario: %s\n", 
            consultas[i].numero, consultas[i].id_medico, consultas[i].id_paciente, 
            consultas[i].data, consultas[i].horario);
    }
}

void excluirConsulta() {
    int num;
    printf("\nDigite o numero da consulta para excluir: ");
    scanf("%d", &num);
    for (int i = 0; i < totalConsultas; i++) {
        if (consultas[i].numero == num) {
            for (int j = i; j < totalConsultas - 1; j++) {
                consultas[j] = consultas[j + 1];
            }
            totalConsultas--;
            printf("Consulta excluida com sucesso!\n");
            return;
        }
    }
    printf("Consulta nao encontrada!\n");
}
// Menus
void submenuConsulta() {
    int escolha;
    while (1) {
        printf("\nSubmenu Consulta:\n");
        printf("1 - Agendar Consulta\n");
        printf("2 - Visualizar Consultas\n");
        printf("3 - Excluir Consulta\n");
        printf("4 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: adicionarConsulta(); break;
            case 2: visualizarConsultas(); break;
            case 3: excluirConsulta(); break;
            case 4: return;
            default: printf("Opcao invalida!\n");
        }
    }
}

void processarEscolha(int escolha) {
    switch (escolha) {
        case 1: adicionarMedico(); break;
        case 2: adicionarPaciente(); break;
        case 3: submenuConsulta(); break;
        case 4: visualizarConsultas(); break;
        case 5: printf("Saindo...\n"); exit(0);
        default: printf("Opcao invalida! Tente novamente.\n");
    }
}

int exibirMenuPrincipal() {
    int escolha;
    printf("\nMenu Principal:\n");
    printf("1 - Medico\n");
    printf("2 - Paciente\n");
    printf("3 - Consulta\n");
    printf("4 - Relatorios\n");
    printf("5 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    return escolha;
}


// Função para processar a escolha do usuário
void processarEscolha(int escolha) {
    setlocale(LC_ALL, "portuguese");
    switch (escolha) {
        case 1:
            printf("Você escolheu Consulta.\n");
            // Aqui você pode chamar uma função para processar a consulta
            break;
        case 2:
            printf("Você escolheu Paciente.\n");
            // Aqui você pode chamar uma função para processar o paciente
            break;
        case 3:
            printf("Você escolheu Médico.\n");
            // Aqui você pode chamar uma função para processar o médico
            break;
        case 4:
            printf("Você escolheu Relatórios.\n");
            // Aqui você pode chamar uma função para gerar relatórios
            break;
        case 5:
            printf("Saindo...\n");
            exit(0); // Encerra o programa
        default:
            printf("Opção inválida! Tente novamente.\n");
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int escolha;

    while (1) { // Loop infinito até que o usuário escolha sair
        escolha = exibirMenu();
        processarEscolha(escolha);
    }

    return 0;
}
