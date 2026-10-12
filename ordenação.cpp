#include <bits/stdc++.h>

using namespace std;

// Suporte Recursivo para o merge
void merge(int vet[], int esq, int meio, int dir){

    int aux1 = meio - esq + 1;
    int aux2 = dir - esq;

    // criar o vetores esq e dir do tamanho que preciso
    int* left = new int[aux1]; 
    int* right = new int[aux2];
    
    // Preencher os valores de esquerda e direita
    for (int i = 0; i < aux1; i++){
        left[i] = vet[esq + i];
    }
    for (int i = 0; i < aux2; i++){
        right[i] = vet[meio + 1 + i];
    }
    int i = 0,j = 0,k;
    k = esq;

    while (i < aux1 && j < aux2){
        if(left[i] <= right[j]){
            vet[k++] = left[i++];
        }
        else{
            vet[k++] = right[j++];
        }
    }

    while (i < aux1){
        vet[k++] = left[i++];
    }
    
    while (j < aux2){
        vet[k++] = right[j++];
    }
    
    delete[] left;
    delete[] right;
    
}

// Merge Sort em si
void mergeSort(int vetor[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;    
        
        mergeSort(vetor, left, mid);
        mergeSort(vetor, mid+1, right);

        merge(vetor, left, mid, right);

    }


}

void bubleSort(int vetor[], int tam){
    int aux = 0;
    for(int i = 0; i < tam; i++){
        bool trocou = false;
        for(int j = 0; j < tam - i - 1; j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = aux;
                trocou = true;
            }
        }
        if(!trocou) break;
    }
}

// Auxiliar para o Radix
void countingPass(int vet[], int tam, int exp){
    int* output = new int[tam]; //vetor auxiliar do radix 
    int count[10] = {0};

    for (int i = 0; i < tam; i++){
        count[(vet[i] / exp) % 10]++;
    }
    for (int j = 1; j < 10; j++){
        count[j] += count[j-1];
    }
    for (int i = tam - 1; i >= 0; i--){
        int digito = (vet[i] / exp) % 10;
        output[--count[digito]] = vet[i];
    }

    for (int i = 0; i < tam; i++) vet[i] = output[i];
    delete[] output;
}

// Radix Sort de fato
void RadixSort(int vet[], int tam){
    int max = vet[0]; // pego o indice 1 para ser o maior valor
    for (int i = 1; i < tam; i++){
        if(vet[i] > max){max = vet[i];} // percorro de forma linear ate achar o maior valor
    }
    for (int exp = 1; max/exp > 0; exp*=10){
        countingPass(vet,tam, exp);
    }
    
}

void CountingSort(int vet[], int tam){
    int max = vet[0];
    for (int i = 1; i < tam; i++){
        if(vet[i] > max){max = vet[i];} // percorro de forma linear ate achar o maior valor
    }

    int* count = new int[tam]; // vetor para contar as ocorrências
    for (int i = 0; i < tam; i++){
        count[vet[i]]++; // conto quantas vezes o valor aparece no nosso array
    }

    int index = 0;
    for (int i = 0; i < max; i++){
        while (count[i] > 0){
            vet[index++] = i;
            count[i]--;
        }
        
    }
    delete[] count;
    
}

// ---------------------- Medição de tempo ----------------------

void medirTempo(int vetor[], int tam, int escolha){

    auto inicio = chrono::high_resolution_clock::now();

    if(escolha == 1){
        bubleSort(vetor, tam);
    }
    else if(escolha == 2){
        mergeSort(vetor, 0, tam - 1);
    }
    else if(escolha == 3){
        RadixSort(vetor, tam);
    }
    else{
        CountingSort(vetor, tam);
    }

    auto fim = chrono::high_resolution_clock::now();

    auto duracao = chrono::duration_cast<chrono::microseconds>(fim - inicio);

    long long total_microsegundos = duracao.count();

    cout << "\nTempo gasto: ";

    if(total_microsegundos < 1000){

        cout << total_microsegundos << " microssegundos";

    }
    else if(total_microsegundos < 1000000){

        cout << total_microsegundos / 1000.0 << " milissegundos";

    }
    else if(total_microsegundos < 60000000){

        cout << total_microsegundos / 1000000.0 << " segundos";

    }
    else{

        cout << total_microsegundos / 60000000.0 << " minutos";

    }

    cout << endl;
}


// ---------------------- Programa Principal ----------------------

int main() {

    int TAM; // tamanho variável do vetor 

    // Menu
    cout << "=====================================\n";
    cout << "       ALGORITMOS DE ORDENACAO\n";
    cout << "=====================================\n";
    cout << "1 - Bubble Sort\n";
    cout << "2 - Merge Sort\n";
    cout << "3 - Radix Sort\n";
    cout << "4 - CountingSort\n";
    cout << "=====================================\n";

    int escolha;

    cout << "Escolha o algoritmo: ";
    cin >> escolha;

    // Mostra qual algoritmo foi escolhido
    switch (escolha)
    {
    case 1:
        std::cout << "Algoritmo escolhido foi Bubble Sort" << endl;
        break;
    case 2:
        std::cout << "Algoritmo escolhido foi Merge Sort" << endl;
        break;
    case 3:
        std::cout << "Algoritmo escolhido foi Radix Sort" << endl;
        break;
    case 4:
        std::cout << "Algoritmo escolhido foi CountingSort" << endl;
        break;
    default:
        break;
    }

    std::cout << "Escolha um tamanho de vetor :" << endl;
    std::cin >> TAM;

    int* vet = new int[TAM];

    srand(time(0)); // cria uma seed com base no tempo atual, para que os valores sejam os mais aleatórios possíveis dentro do array
    
    for (int i = 0; i < TAM; i++) {
        vet[i] = rand() % TAM;
    }

    // Mede o tempo da ordenacao

    medirTempo(vet, TAM, escolha);


    cout << "\nVetor ordenado\n";

    std::ofstream outputFile("Ordenados.txt"); // vou colocar os valores em um array so pra ter crtz
    if (outputFile.is_open()){
        std::cout << "Aberto, vamos gravar os ordenados" << endl;
        for (int i = 0; i < TAM; i++){
            outputFile << vet[i] << "\n";        
        }
        outputFile.close();
    }
    else {
        std::cout << "ERRO!" << endl;
    }

    delete[] vet;


    return 0;
}