// Radix Sort.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>

std::ifstream arquivo;
std::vector<int> vetor;
std::vector<int> ordenado;

void imprime() {
	int i;
	std::cout << "ordenado:";
	for (i = 0; i < ordenado.size(); i++) {
		std::cout << ordenado[i] << " " << std::endl;
	}
	std::cout << "vetor:";
	for (i = 0; i < vetor.size(); i++) {
		std::cout << vetor[i] << " " << std::endl;
	}
}

void countingSort(int expoente) {
	int i,dividido,divisor;
	int counting[10];
	for (i = 0; i < 10; i++) {
		counting[i] = 0;
	}
	dividido = pow(10, expoente);
	divisor = pow(10, expoente -1);


	for (i = 0; i < vetor.size(); i++) {
		counting[(vetor[i]%dividido) / divisor]++;
	}
	for (i = 1; i <= 10; i++) {
		counting[i] = counting[i] + counting[i - 1];
	}

	for (i = vetor.size() - 1; i >= 0; i--) {
		ordenado[counting[(vetor[i]%dividido)/divisor] - 1 ] = vetor[i];		
		counting[(vetor[i]%dividido)/divisor]--;
	}
	for (i = 0; i < vetor.size(); i++) {
		vetor[i] = ordenado[i];
	}
}

void radixSort() {
	int maior, i , maxDigitos , aux;
	maior = vetor[0];
	for (i = 0; i < vetor.size(); i++) {
		if (maior < vetor[i]) {
			maior = vetor[i];
		}
	}
	maxDigitos = 0;
	aux = maior;
	while (aux > 0) {
		aux = aux / 10;
		maxDigitos++;
	}
	for (i = 1; i <= maxDigitos; i++) {
		countingSort(i);
	}
}

int main() {
	std::string arquivoname;
	std::cout << "Radix Sort:" << std::endl << "Digite o nome do arquivo(ex. exemplo.txt): ";
	std::cin >> arquivoname;

	arquivo.open(arquivoname.data());
	if (!arquivo.is_open()) {
		system("pause");
		return -1;
	}
	int i;
	std::string stringer;
	while (!arquivo.eof()) {
		std::getline(arquivo, stringer);
		int num = std::stoi(stringer);
		vetor.push_back(num);
		ordenado.push_back(num);
	}

	radixSort();

	for (i = 0; i < ordenado.size(); i++) {
		std::cout << ordenado[i] << " " << std::endl;
	}
	system("pause");
	return 0;
}
