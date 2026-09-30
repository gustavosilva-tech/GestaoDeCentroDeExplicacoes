#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_REGISTOS 100
#define CHAR_MAX 100
enum GrauDeEnsino { CTESP = 1, LICENCIATURA = 2,MESTRADO=3 };

typedef struct {
	char nome[CHAR_MAX];
	enum GrauDeEnsino grau_de_ensino;
	char unidade_curricular[CHAR_MAX];
	float valor;
	int numero_de_horas;

}texplicando;

void MostrarExplicando(texplicando explicando) {
	printf("Dados do explicando: \n");
	printf("Nome: %s\n", explicando.nome);
	printf("Grau de ensino: ");
	switch (explicando.grau_de_ensino) {
	case CTESP: printf("CTESP\n");
		break;
	case LICENCIATURA: printf("LICENCIATURA\n"); break;
	case MESTRADO:printf("MESTRADO\n"); break;
	default:printf("Grau desconhecido\n");
	}
	printf("Unidade Curricular: %s\n", explicando.unidade_curricular);
	printf("Valor por Hora: %f\n", explicando.valor);
	printf("Numero de Horas: %d\n", explicando.numero_de_horas);
}

void InsereExplicandos(texplicando explicandos[], int *numExplicandos) {
	int total;
	do {
		printf("\n Quantos explicandos quer registar :  ");
		scanf("%d", &total);
		if (total > NUM_REGISTOS || total < 1) {
			printf("Numero invalido! \n");
		}
	} while (total > NUM_REGISTOS || total < 1);
	for (int i = 0; i < total; i++) {
		printf("---------Explicando---------\n");
		printf("\nnome:  ");
		scanf("%s", explicandos[*numExplicandos].nome);
		printf("\ngrau de ensino:  ");
		scanf("%d", &explicandos[*numExplicandos].grau_de_ensino);
		printf("\nunidade curricular:   ");
		scanf("%s", explicandos[*numExplicandos].unidade_curricular);
		printf("\nvalor:  ");
		scanf("%f", &explicandos[*numExplicandos].valor);
		printf("\nnumero de horas:  ");
		scanf("%d", &explicandos[*numExplicandos].numero_de_horas);
		(*numExplicandos)++;
	}
}


void ListarExplicandos(texplicando explicandos[], int numExplicandos) {
	for (int i = 0; i < numExplicandos; i++) {
		MostrarExplicando(explicandos[i]);
		printf("\n");
	}
}

void GravarExplicandos(texplicando explicandos[], char nomeFicheiro[], int *numExplicandos) {
	FILE* fp;

	fp = fopen(nomeFicheiro, "wb");

	if(fp != NULL) {
		fwrite(numExplicandos, sizeof(int), 1, fp);
		for (int i = 0; i < *numExplicandos; i++) {
			fwrite(&explicandos[i], sizeof(texplicando), 1, fp);
		}
		fclose(fp);
		printf("OK");
	}
	else printf("ERRO");
}

int LerExplicandos(texplicando explicandos[], char nomeFicheiro[]) {
	FILE* fp;
	int num = 0;
	fp = fopen(nomeFicheiro, "rb");
	if (fp != NULL) {
		fread(&num, sizeof(int), 1, fp);
		for (int i = 0; i < num; i++) {
			fread(&explicandos[i], sizeof(texplicando), 1, fp);
		}
		fclose(fp);

	}

	return num;
}
void OrdenarHorasFreq(texplicando* vetor, int numExplicandos) {
	for (int i = 0; i < numExplicandos; i++) {
		for (int j = i + 1; j < numExplicandos; j++) {
			if (vetor[i].numero_de_horas > vetor[j].numero_de_horas) {
				texplicando temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}
}
void PesquisarPorUC(texplicando* vetor, int numExplicandos, char* uc) {
	int encontrados = 0;
	for (int i = 0; i < numExplicandos; i++) {
		if (strcmp(vetor[i].unidade_curricular, uc) == 0) {
			printf("Explicando encontrado!\n");
			MostrarExplicando(vetor[i]);
			printf("\n");
			encontrados++;
		}
	}
	if (encontrados == 0) {
		printf("Nenhum explicando encontrado com essa unidade curricular.\n");
	}
}
void RemoverExplicando(texplicando* vetor, int* numExplicandos, char* nome) {
	int index = -1;
	for (int i = 0; i < *numExplicandos; i++) {
		if (strcmp(vetor[i].nome, nome) == 0) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		printf("Explicando não encontrado.\n");
	}
	else {
		for (int i = index; i < *numExplicandos - 1; i++) {
			vetor[i] = vetor[i + 1];
		}
		(*numExplicandos)--;
		printf("Explicando removido com sucesso.\n");
	}
}
float ValorPagarLicenciatura(texplicando* vetor, int numExplicandos) {
	float total = 0.0;
	for (int i = 0; i < numExplicandos; i++) {
		if (vetor[i].grau_de_ensino == LICENCIATURA) {
			total += vetor[i].valor * vetor[i].numero_de_horas;
		}
	}
	return total;
}


int main() {
	texplicando explicandos [100];
	int numExplicandos = 0;
	int choice;
	char uc[100];
	char nome[100];
	char nome_ficheiro[] = "explicandos.dat";
	do {
		printf("\n=======================================");
		printf("\n                MENU                   ");
		printf("\n=======================================");
		printf("\n[1] Inserir a Informacao dos Explicandos ");
		printf("\n[2] Gravar a Informacao dos Explicandos no ficheiro ");
		printf("\n[3] Ler do Ficheiro");
		printf("\n[4] Mostrar todos Explicandos ");
		printf("\n[5] Ordenar por numero de horas Frequentadas ");
		printf("\n[6] Pesquisar e Mostrar Explicandos por UC ");
		printf("\n[7] Remover um explicando pelo Nome ");
		printf("\n[8] Calcular o Valor a Pagar pelos Explicandos de Licenciatura ");
		printf("\n[0] Sair ");
		printf("\n=======================================");
		printf("\n                MENU                   ");
		printf("\n=======================================");
		printf("\n Escolha a sua opcao: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("\n Inserir a Informacao dos Explicandos ");
			InsereExplicandos(explicandos, &numExplicandos);
			printf("NUM EXPLICANDOS: %d\n", numExplicandos);
			break;
		case 2:
			printf("\n Gravar a informacao dos Explicandos no ficheiro ");
			GravarExplicandos(explicandos, "\explicandos.dat", &numExplicandos);
			break;
		case 3:
			printf("\n Ler do Ficheiro e Mostrar todos Explicandos ");
			numExplicandos = LerExplicandos(explicandos, "\explicandos.dat");
			break;
		case 4:
			printf("\n Mostrar todos Explicandos ");
			ListarExplicandos(explicandos, numExplicandos);
			break;
		case 5:
			OrdenarHorasFreq(explicandos, numExplicandos );
			ListarExplicandos(explicandos, numExplicandos);
			break;
		case 6:
			printf("Insira a unidade curricular a ser pesquisada: ");
			scanf("%s", uc);
			PesquisarPorUC(explicandos, numExplicandos, uc);
			break;
		case 7:
			printf("Insira o nome do explicando a ser removido\n");
			scanf("%s", nome);
			RemoverExplicando(explicandos, &numExplicandos, nome);
			break;
		case 8:
			printf("Valor a pagar: %f\n", ValorPagarLicenciatura(explicandos, numExplicandos));
			break;
		


		case 0:
			printf("\n Saiu com sucesso ");
		}
	} while (choice != 0);
	






	








}


