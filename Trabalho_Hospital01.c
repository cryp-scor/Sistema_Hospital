#include <stdio.h>
#include <stdlib.h>

// menu principal e obter a escolha do usuário
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

// exibir o submenu de Médico
void submenuMedico() {
    int escolha;
    while (1) { // operações no submenu
        printf("\nSubmenu Medico:\n");
        printf("1 - Identificador\n");
        printf("2 - Nome\n");
        printf("3 - Especialidade\n");
        printf("4 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            printf("Identificador\n");
            // incluir um médico
        } else if (escolha == 2) {
            printf("Nome:\n");
        } else if (escolha == 3) {
            printf("Especialidade:\n");
            // alterar um médico
        } else if (escolha == 4) {
            printf("Voltando ao Menu Principal...\n");
            break; // sai do loop e retorna ao menu principal
        } else {
            printf("Opcao invalida!\n");
        }
    }
}

// exibir o submenu de Paciente
void submenuPaciente() {
    int escolha;
    while (1) { // operações no submenu
        printf("\nSubmenu Paciente:\n");
        printf("1 - Nome\n");
        printf("2 - Identidade\n");
        printf("3 - Endereco (completo)\n");
        printf("4 - Telefone\n");
        printf("5 - Sexo\n");
        printf("6 - Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            printf("Nome:\n");
            // adicionar o código para incluir um paciente
        } else if (escolha == 2) {
            printf("Identidade:\n");
        } else if (escolha == 3) {
            printf("Endereco (completo):\n");
        } else if (escolha == 4) {
            printf("Telefone:\n");
        } else if (escolha == 5) {
            printf("Sexo:\n");
            // código para alterar um paciente
        } else if (escolha == 6) {
            printf("Voltando ao Menu Principal...\n");
            break; 
        } else {
            printf("Opcao invalida!\n");
        }
    }
}

// submenu de consulta
void submenuConsulta() {
    int escolha;
    while (1) { // operações no submenu
        printf("\nSubmenu Consulta:\n");
        printf("1 - Numero\n");
        printf("2 - Medico (identificador)\n");
        printf("3 - Paciente (Identificador)\n");
        printf("4 - Horario\n");
        printf("5 - Duracao\n");
        printf("6 - Data\n");
        printf("7 - Voltar\n"); 
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            printf("Numero:\n");
            // incluir uma consulta
        } else if (escolha == 2) {
            printf("Medico (identificador):\n");
        } else if (escolha == 3) {
            printf("Paciente (Identificador):\n");
        } else if (escolha == 4) {
            printf("Horario:\n");
        } else if (escolha == 5) {
            printf("Duracao:\n");
        } else if (escolha == 6) {
            printf("Data:\n");
            // alterar uma consulta
        } else if (escolha == 7) {
            printf("Voltando ao Menu Principal...\n");
            break; 
        } else {
            printf("Opcao invalida!\n");
        }
    }
}

// submenu de Relatórios
void submenuRelatorios() {
    int escolha;
    while (1) { // operações no submenu
        printf("\nSubmenu Relatorios:\n");
        printf("1 - Lista de consultas agendadas para o paciente\n");
        printf("2 - Lista de consultas agendadas para o medico\n");
        printf("3 - Lista de pacientes por especialidade\n");
        printf("4 - Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("\nLista de consultas agendadas para o paciente:\n");
                // solicitar o identificador do paciente e exibir suas consultas
                break;
            case 2:
                printf("\nLista de consultas agendadas para o medico:\n");
                break;
            case 3:
                printf("\nLista de pacientes por especialidade:\n");
                break;
            case 4:
                printf("Voltando ao Menu Principal...\n");
                return;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }
}

// escolha do usuário no menu principal
void processarEscolha(int escolha) {
    switch (escolha) {
        case 1:
            printf("Voce escolheu Medico.\n");
            submenuMedico();
            break;
        case 2:
            printf("Voce escolheu Paciente.\n");
            submenuPaciente();
            break;
        case 3:
            printf("Voce escolheu Consulta.\n");
            submenuConsulta();
            break;
        case 4:
            printf("Voce escolheu Relatorios.\n");
            submenuRelatorios();
            break;
        case 5:
            printf("Saindo...\n");
            exit(0); // encerrar
        default:
            printf("Opcao invalida! Tente novamente.\n");
    }
}

int main() {
    int escolha;

    while (1) { // loop infinito até que o usuário escolha sair
        escolha = exibirMenuPrincipal();
        processarEscolha(escolha);
    }

    return 0;
}