/* Marco Antônio Rós Fachinetti - 8160500 */
/* Exercício programa 1 caixa eletrônico */
/* Programação Avançada 2024 - Professor: Bruno Perillo */
/* Compilador: gcc */

#include <stdio.h>

void saque(int notas[], int valor);
void deposito(int notas[], int qtd_depositada[]);
void mostrar_notas(int notas[]);

int cedulas[7] = {100, 50, 20, 10, 5, 2, 1}; /* este é o valor das cédulas*/

int main() {
    int notas[7];      
    int operacao, valor;  

    /* Analisa a quantidade inicial de cédulas */
    printf("Digite a quantidade inicial de cedulas (100, 50, 20, 10, 5, 2, 1):\n");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &notas[i]);
    }

    /* Loop que realiza as operações */
    while (1) {
        printf("Digite a operacao (0 = saque, 1 = deposito, -1 = sair): ");
        scanf("%d", &operacao);

        if (operacao == -1) {
            break; // Finaliza o programa
        } else if (operacao == 0) { // Saque
            printf("Digite o valor que deseja sacar: ");
            scanf("%d", &valor);
            saque(notas, valor);  
        } else if (operacao == 1) { // Depósito
            int qtd_depositada[7]; 
            printf("Digite a quantidade de cedulas que deseja depositar (100, 50, 20, 10, 5, 2, 1):\n");
            for (int i = 0; i < 7; i++) {
                scanf("%d", &qtd_depositada[i]);
            }
            deposito(notas, qtd_depositada); 
        }

        /* Mostra as cédulas após a operação */
        mostrar_notas(notas);
    }

    return 0;
}

// Função do saque
void saque(int notas[], int valor) {
    int temp_notas[7]; 

    for(int i = 0; i < 7; i++) {
        temp_notas[i] = notas[i];
    }

    // Este for tenta relizar a operação com o menor número de notas possivel
    for (int i = 0; i < 7; i++) {
        while (valor >= cedulas[i] && temp_notas[i] > 0) {
            valor -= cedulas[i];
            temp_notas[i]--;
        }
    }

    if (valor == 0) {
        printf("Saque realizado.\n");
        for (int i = 0; i < 7; i++) {
            notas[i] = temp_notas[i]; // Atualiza as cédulas após o saque
        }
    } else {
        printf("Nao ha cedulas suficientes para realizar o saque.\n");            
    }
}

// Função do depósito
void deposito(int notas[], int qtd_depositada[]) {
    for (int i = 0; i < 7; i++) {
        notas[i] += qtd_depositada[i]; 
    }
    printf("Deposito realizado.\n");
}

// Mostra as notas restantes 
void mostrar_notas(int notas[]) {
    printf("Quantidade de cedulas:\n");
    for (int i = 0; i < 7; i++) {
        printf("R$ %d: %d\n", cedulas[i], notas[i]);
    }
}
