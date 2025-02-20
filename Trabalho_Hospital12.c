#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int identificador;
    char nome[100];
    char especialidade[100];
} Medico;

typedef struct {
    char identidade[20];
    int identificadorPaciente;
    char nome[100];
    char endereco[200];
    char telefone[20];
    char sexo[20];
} Paciente;

typedef struct {
    int numero;
    int medicoId;
    int pacienteId;
    char horario[10];
    int duracao;
    char data[12];
} Consulta;



Medico medicos[20];
Paciente pacientes[50];
Consulta consultas[100];

int indiceMedicos = 0;
int indicePacientes = 0;
int indiceConsultas = 0;

int exibirMenuPrincipal(void);
void submenuMedico(void);
void submenuPaciente(void);
void submenuConsulta(void);
void submenuRelatorios(void);
void processarEscolha(int escolha);


void excluirConsultasPorMedico(int medicoId) {
    for (int i = 0; i < indiceConsultas; i++) {
        if (consultas[i].medicoId == medicoId) {
            for (int j = i; j < indiceConsultas - 1; j++) {
                consultas[j] = consultas[j + 1];
            }
            indiceConsultas--;
            i--; 
        }
    }
    printf("Consultas do medico %d foram excluidas.\n", medicoId);
}

void submenuMedico(void) {
    int escolha;
    while (1) { 
        printf("\nSubmenu Medico:\n");
        printf("1 - Inclusao\n");
        printf("2 - Alteracao\n");
        printf("3 - Exclusao\n");
        printf("4 - Pesquisa\n");
        printf("5 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        fflush(stdin); 

        switch(escolha) {
            case 1: {
                printf("\n=== Digite os dados do Medico ===\n");
                printf("Identificador: ");
                scanf("%d", &medicos[indiceMedicos].identificador);
                fflush(stdin);
                printf("Nome: ");
                fgets(medicos[indiceMedicos].nome, sizeof(medicos[indiceMedicos].nome), stdin);
                medicos[indiceMedicos].nome[strcspn(medicos[indiceMedicos].nome, "\n")] = 0;
                printf("Especialidade: ");
                fgets(medicos[indiceMedicos].especialidade, sizeof(medicos[indiceMedicos].especialidade), stdin);
                medicos[indiceMedicos].especialidade[strcspn(medicos[indiceMedicos].especialidade, "\n")] = 0;
                printf("Cadastro realizado com sucesso!\n");
                indiceMedicos++;
                break;
            }
            case 2: {
                int id, found = 0;
                printf("Digite o identificador do medico para alteracao: ");
                scanf("%d", &id);
                fflush(stdin);
                for (int i = 0; i < indiceMedicos; i++) {
                    if (medicos[i].identificador == id) {
                        found = 1;
                        printf("Novo nome: ");
                        fgets(medicos[i].nome, sizeof(medicos[i].nome), stdin);
                        medicos[i].nome[strcspn(medicos[i].nome, "\n")] = 0;
                        printf("Nova especialidade: ");
                        fgets(medicos[i].especialidade, sizeof(medicos[i].especialidade), stdin);
                        medicos[i].especialidade[strcspn(medicos[i].especialidade, "\n")] = 0;
                        printf("Alteracao realizada com sucesso!\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Medico nao encontrado.\n");
                }
                break;
            }
            case 3: {
                int id, found = 0;
                printf("Digite o identificador do medico para exclusao: ");
                scanf("%d", &id);
                fflush(stdin);
                for (int i = 0; i < indiceMedicos; i++) {
                    if (medicos[i].identificador == id) {
                        found = 1;
                        for (int j = i; j < indiceMedicos - 1; j++) {
                            medicos[j] = medicos[j + 1];
                        }
                        indiceMedicos--;
                        if (found) {
                            excluirConsultasPorMedico(id);
                            printf("Exclusao realizada com sucesso!\n");
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("Medico nao encontrado.\n");
                }
                break;
            }
            case 4: {
                int id, found = 0;
                printf("Digite o identificador do medico para pesquisa: ");
                scanf("%d", &id);
                fflush(stdin);
                for (int i = 0; i < indiceMedicos; i++) {
                    if (medicos[i].identificador == id) {
                        found = 1;
                        printf("Identificador: %d\n", medicos[i].identificador);
                        printf("Nome: %s\n", medicos[i].nome);
                        printf("Especialidade: %s\n", medicos[i].especialidade);
                        break;
                    }
                }
                if (!found) {
                    printf("Medico nao encontrado.\n");
                }
                break;
            }
            case 5:
                return;
            default:
                printf("Opcao invalida!\n");
        }
    }
}

void excluirConsultasPorPaciente(int pacienteId) {
    for (int i = 0; i < indiceConsultas; i++) {
        if (consultas[i].pacienteId == pacienteId) {
            for (int j = i; j < indiceConsultas - 1; j++) {
                consultas[j] = consultas[j + 1];
            }
            indiceConsultas--;
            i--; 
        }
    }
    printf("Consultas do paciente %d foram excluidas.\n", pacienteId);
}

void submenuPaciente(void) {
    int escolha;
    while (1) { 
        printf("\nSubmenu Paciente:\n");
        printf("1 - Inclusao\n");
        printf("2 - Alteracao\n");
        printf("3 - Exclusao\n");
        printf("4 - Pesquisa\n");
        printf("5 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        fflush(stdin); 

        switch(escolha) {
            case 1: {
                printf("\n=== Digite os dados do Paciente ===\n");

                printf("Nome: ");
                fgets(pacientes[indicePacientes].nome, sizeof(pacientes[indicePacientes].nome), stdin);
                pacientes[indicePacientes].nome[strcspn(pacientes[indicePacientes].nome, "\n")] = 0;

                printf("Identificador: ");
                scanf("%d", &pacientes[indicePacientes].identificadorPaciente);
                getchar(); // <- Remove o '\n' do buffer antes de fgets()

                printf("Endereco: ");
                fgets(pacientes[indicePacientes].endereco, sizeof(pacientes[indicePacientes].endereco), stdin);
                pacientes[indicePacientes].endereco[strcspn(pacientes[indicePacientes].endereco, "\n")] = 0;

                printf("Telefone: ");
                fgets(pacientes[indicePacientes].telefone, sizeof(pacientes[indicePacientes].telefone), stdin);
                pacientes[indicePacientes].telefone[strcspn(pacientes[indicePacientes].telefone, "\n")] = 0;

                printf("Sexo: ");
                fgets(pacientes[indicePacientes].sexo, sizeof(pacientes[indicePacientes].sexo), stdin);
                pacientes[indicePacientes].sexo[strcspn(pacientes[indicePacientes].sexo, "\n")] = 0;

                printf("Cadastro realizado com sucesso!\n");
                indicePacientes++;
                break;
            }

                    case 2: {
                    int id, found = 0;
                    printf("Digite o identificador do paciente para alteracao: ");
                    scanf("%d", &id);
                    getchar(); // Limpa o buffer de entrada

                    for (int i = 0; i < indicePacientes; i++) {
                        if (pacientes[i].identificadorPaciente == id) { // Correção na comparação
                            found = 1;
                            printf("Novo nome: ");
                            fgets(pacientes[i].nome, sizeof(pacientes[i].nome), stdin);
                            pacientes[i].nome[strcspn(pacientes[i].nome, "\n")] = 0;

                            printf("Novo endereco: ");
                            fgets(pacientes[i].endereco, sizeof(pacientes[i].endereco), stdin);
                            pacientes[i].endereco[strcspn(pacientes[i].endereco, "\n")] = 0;

                            printf("Novo telefone: ");
                            fgets(pacientes[i].telefone, sizeof(pacientes[i].telefone), stdin);
                            pacientes[i].telefone[strcspn(pacientes[i].telefone, "\n")] = 0;

                            printf("Novo Sexo: ");
                            fgets(pacientes[i].sexo, sizeof(pacientes[i].sexo), stdin);
                            pacientes[i].sexo[strcspn(pacientes[i].sexo, "\n")] = 0;

                            printf("Alteracao realizada com sucesso!\n");
                            break;
                }
            }
            if (!found) {
                printf("Paciente nao encontrado.\n");
            }
            break;
        }

        case 3: {
            int id, found = 0;
            printf("Digite o identificador do paciente para exclusao: ");
            scanf("%d", &id);
            getchar(); // Limpa o buffer de entrada

            for (int i = 0; i < indicePacientes; i++) {
                if (pacientes[i].identificadorPaciente == id) { // Correção na comparação
                    found = 1;
                    for (int j = i; j < indicePacientes - 1; j++) {
                        pacientes[j] = pacientes[j + 1];
                    }
                    indicePacientes--;

                    if (found) {
                        excluirConsultasPorPaciente(id);
                        printf("Exclusao realizada com sucesso!\n");
                    }
                    break;
                }
            }
            if (!found) {
                printf("Paciente nao encontrado.\n");
            }
            break;
        }

        case 4: {
            int id, found = 0;
            printf("Digite o identificador do paciente para pesquisa: ");
            scanf("%d", &id);
            getchar(); // Limpa o buffer de entrada

            for (int i = 0; i < indicePacientes; i++) {
                if (pacientes[i].identificadorPaciente == id) { // Correção na comparação
                    found = 1;
                    printf("Nome: %s\n", pacientes[i].nome);
                    printf("Identificador: %d\n", pacientes[i].identificadorPaciente);
                    printf("Endereco: %s\n", pacientes[i].endereco); // Correção
                    printf("Telefone: %s\n", pacientes[i].telefone);
                    printf("Sexo: %s\n", pacientes[i].sexo);
                    break;
                }
            }
            if (!found) {
                printf("Paciente nao encontrado.\n");
            }
            break;
        }

        case 5:
            return;
        default:
            printf("Opcao invalida!\n");
        }

        }
}


void submenuRelatorios(void) {
    int escolha;
    while (1) { 
        printf("\nSubmenu Relatorios:\n");
        printf("1 - Listar Medicos\n");
        printf("2 - Listar Pacientes\n");
        printf("3 - Listar Consultas\n");
        printf("4 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        fflush(stdin); 

        switch(escolha) {
            case 1: 
                printf("\n=== Lista de Medicos ===\n");
                for (int i = 0; i < indiceMedicos; i++) {
                    printf("Identificador: %d\n", medicos[i].identificador);
                    printf("Nome: %s\n", medicos[i].nome);
                    printf("Especialidade: %s\n", medicos[i].especialidade);
                    printf("\n");
                }
                break;
            
            
            case 2: 
                printf("\n=== Lista de Pacientes ===\n");
                for (int i = 0; i < indicePacientes; i++) {
                    printf("Nome: %s\n", pacientes[i].nome);
                    printf("Identificador: %d\n", pacientes[i].identificadorPaciente);
                    printf("Endereco: %s\n", pacientes[i].identidade);
                    printf("Endereco: %s\n", pacientes[i].endereco);
                    printf("Telefone: %s\n", pacientes[i].telefone);
                    printf("Sexo: %s\n", pacientes[i].sexo);
                    printf("\n");
                }
                break;
            case 3: 
                printf("\n=== Lista de Consultas ===\n");
                for (int i = 0; i < indiceConsultas; i++) {
                    printf("Numero: %d\n", consultas[i].numero);
                    printf("Medico (Identificador): %d\n", consultas[i].medicoId);
                    printf("Paciente (Identificador): %d\n", consultas[i].pacienteId);
                    printf("Horario: %s\n", consultas[i].horario);
                    printf("Duracao: %d minutos\n", consultas[i].duracao);
                    printf("Data: %s\n", consultas[i].data);
                    printf("\n");
                }
                break;

                case 4:
                printf("Voltando...\n");
                return;
            default:
                printf("Opcao invalida!\n");
        }}}


void submenuConsulta(void) {
    int escolha;
    while (1) {
        printf("\nSubmenu Consulta:\n");
        printf("1 - Inclusao\n");
        printf("2 - Alteracao\n");
        printf("3 - Exclusao\n");
        printf("4 - Pesquisa\n");
        printf("5 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        getchar(); // Limpa o buffer de entrada

        switch (escolha) {
            case 1: {
                printf("\n=== Digite os dados da Consulta ===\n");

                printf("Numero: ");
                scanf("%d", &consultas[indiceConsultas].numero);
                getchar();

                printf("Medico (Identificador): ");
                scanf("%d", &consultas[indiceConsultas].medicoId);
                getchar();

                int medicoEncontrado = 0;
                for (int i = 0; i < indiceMedicos; i++) {
                    if (medicos[i].identificador == consultas[indiceConsultas].medicoId) {
                        medicoEncontrado = 1;
                        break;
                    }
                }
                if (!medicoEncontrado) {
                    printf("Identificador do medico nao encontrado.\n");
                    break;
                }

                printf("Paciente (Identificador): ");
                scanf("%d", &consultas[indiceConsultas].pacienteId);
                getchar();

                int pacienteEncontrado = 0;
                for (int i = 0; i < indicePacientes; i++) {
                    if (pacientes[i].identificadorPaciente == consultas[indiceConsultas].pacienteId) { // Correção
                        pacienteEncontrado = 1;
                        break;
                    }
                }
                if (!pacienteEncontrado) {
                    printf("Identificador do paciente nao encontrado.\n");
                    break;
                }

                printf("Horario (HH:MM): ");
                scanf("%9s", consultas[indiceConsultas].horario);
                getchar();

                printf("Duracao (minutos): ");
                scanf("%d", &consultas[indiceConsultas].duracao);
                getchar();

                printf("Data (DD/MM/AAAA): ");
                scanf("%11s", consultas[indiceConsultas].data);
                getchar();

                printf("Consulta agendada com sucesso!\n");
                indiceConsultas++;
                break;
            }

            case 2: {
                int numero, found = 0;
                printf("Digite o numero da consulta para alteracao: ");
                scanf("%d", &numero);
                getchar();

                for (int i = 0; i < indiceConsultas; i++) {
                    if (consultas[i].numero == numero) {
                        found = 1;
                        
                        printf("Novo medico (Identificador): ");
                        scanf("%d", &consultas[i].medicoId);
                        getchar();

                        int medicoEncontrado = 0;
                        for (int j = 0; j < indiceMedicos; j++) {
                            if (medicos[j].identificador == consultas[i].medicoId) {
                                medicoEncontrado = 1;
                                break;
                            }
                        }
                        if (!medicoEncontrado) {
                            printf("Identificador do medico nao encontrado.\n");
                            break;
                        }

                        printf("Novo paciente (Identificador): ");
                        scanf("%d", &consultas[i].pacienteId);
                        getchar();

                        int pacienteEncontrado = 0;
                        for (int j = 0; j < indicePacientes; j++) {
                            if (pacientes[j].identificadorPaciente == consultas[i].pacienteId) { // Correção
                                pacienteEncontrado = 1;
                                break;
                            }
                        }
                        if (!pacienteEncontrado) {
                            printf("Identificador do paciente nao encontrado.\n");
                            break;
                        }

                        printf("Novo horario (HH:MM): ");
                        scanf("%9s", consultas[i].horario);
                        getchar();

                        printf("Nova duracao (minutos): ");
                        scanf("%d", &consultas[i].duracao);
                        getchar();

                        printf("Nova data (DD/MM/AAAA): ");
                        scanf("%11s", consultas[i].data);
                        getchar();

                        printf("Alteracao realizada com sucesso!\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Consulta nao encontrada.\n");
                }
                break;
            }

            case 3: {
                int numero, found = 0;
                printf("Digite o numero da consulta para exclusao: ");
                scanf("%d", &numero);
                getchar();

                for (int i = 0; i < indiceConsultas; i++) {
                    if (consultas[i].numero == numero) {
                        found = 1;
                        for (int j = i; j < indiceConsultas - 1; j++) {
                            consultas[j] = consultas[j + 1];
                        }
                        indiceConsultas--;
                        printf("Exclusao realizada com sucesso!\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Consulta nao encontrada.\n");
                }
                break;
            }

            case 4: {
                int numero, found = 0;
                printf("Digite o numero da consulta para pesquisa: ");
                scanf("%d", &numero);
                getchar();

                for (int i = 0; i < indiceConsultas; i++) {
                    if (consultas[i].numero == numero) {
                        found = 1;
                        printf("Numero: %d\n", consultas[i].numero);
                        printf("Medico (Identificador): %d\n", consultas[i].medicoId);
                        printf("Paciente (Identificador): %d\n", consultas[i].pacienteId);
                        printf("Horario: %s\n", consultas[i].horario);
                        printf("Duracao: %d minutos\n", consultas[i].duracao);
                        printf("Data: %s\n", consultas[i].data);
                        break;
                    }
                }
                if (!found) {
                    printf("Consulta nao encontrada.\n");
                }
                break;
            }

            case 5:
                printf("Voltando...\n");
                return;
            default:
                printf("Opcao invalida!\n");
        }
    }
}



void processarEscolha(int escolha) {
    switch(escolha) {
        case 1:
            submenuMedico();
            break;
        case 2:
            submenuPaciente();
            break;
        case 3:
            submenuConsulta();
            break;
        case 4:
            submenuRelatorios(); 
            break;
        case 5:
            printf("Saindo...\n");
            exit(0); 
        default:
            printf("Opcao invalida! Tente novamente.\n");
    }
}


int exibirMenuPrincipal(void) {
    int escolha;
    printf("__________ Menu __________\n");
    printf("Por favor, escolha uma opcao:\n");
    printf("1 - Medico\n");
    printf("2 - Paciente\n");
    printf("3 - Consulta\n");
    printf("4 - Relatorios\n");
    printf("5 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    fflush(stdin); 
    return escolha;
}



int main() {
    int escolha;

    while (1) {
        escolha = exibirMenuPrincipal();
        processarEscolha(escolha);
    }

    return 0;
}