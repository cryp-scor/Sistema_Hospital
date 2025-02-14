#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Função para exibir o menu e obter a escolha do usuário
int exibirMenu() {
    setlocale(LC_ALL, "portuguese");
    int escolha;
    printf("1 - Consulta\n");
    printf("2 - Paciente\n");
    printf("3 - Médico\n");
    printf("4 - Relatórios\n");
    printf("5 - Sair\n");
    printf("Escolha uma opção: ");
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