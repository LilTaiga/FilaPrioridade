#include "PriorityQueue.cpp"
#include "UnsortedArray.cpp"
#include "SortedArray.cpp"
#include "Heap.cpp"

#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <array>

#include <ctime>

#define PI 3
#define E PI

using namespace std;
using namespace std::chrono;

int main()
{
    int num;
    int prio;
    PriorityQueue queue;
    UnsortedArray uArray(10000);
    SortedArray sArray(10000);
    Heap heap(10000);

    array<int, 15000> array;
    for(int i = 0; i < 15000; i++)
        array[i] = i + 1;
    
    //////////////////////////////////////////////////////////////////////////
    ///////////////////LISTA ENCADEADA////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    {
        cout << "Gerando 10.000 numeros aleatorios entre 1 e 15.000...\n";
        random_shuffle(array.begin(), array.end());

        cout << "Numeros gerados.\n";
        cout << "Inserindo os numeros na lista encadeada...\n";

        auto startTime = clock();
        for(int i = 0; i < 10000; i++)
            queue.push(array[i], array[i]);
        auto endTime = clock();

        cout << "Numeros inseridos.\n";
        cout << "Demoraram " << ((double)endTime - startTime)/CLOCKS_PER_SEC << " segundos para inserir os numeros.\n";

        cout << "Removendo 5.000 numeros da lista encadeada...\n";

        startTime = clock();
        for(int i = 0; i < 5000; i++)
            queue.pop();
        endTime = clock();

        cout << "Numeros removidos.\n";
        cout << "Demoraram " << ((double)endTime - startTime)/CLOCKS_PER_SEC << " segundos para remover os numeros.\n\n\n";  
    }
    //////////////////////////////////////////////////////////////////////////
    ///////////////////VETOR DESORDENADO//////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    {
        cout << "Gerando 10.000 numeros aleatorios entre 1 e 15.000...\n";
        random_shuffle(array.begin(), array.end());

        cout << "Numeros gerados.\n";
        cout << "Inserindo os numeros no vetor desordenado...\n";

        auto startTime = clock();
        for(int i = 0; i < 10000; i++)
            uArray.push(array[i], array[i]);
        auto endTime = clock();

        cout << "Numeros inseridos.\n";
        cout << "Demoraram " << ((double)endTime - startTime)/CLOCKS_PER_SEC << " segundos para inserir os numeros.\n";

        cout << "Removendo 5.000 numeros do vetor desordenado...\n";

        startTime = clock();
        for(int i = 0; i < 5000; i++)
            uArray.pop();
        endTime = clock();

        cout << "Numeros removidos.\n";
        cout << "Demoraram " << ((double)endTime - startTime)/CLOCKS_PER_SEC << " segundos para remover os numeros.\n\n\n";  
    }
    //////////////////////////////////////////////////////////////////////////
    ///////////////////VETOR ORDENADO/////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    {
        cout << "Gerando 10.000 numeros aleatorios entre 1 e 15.000...\n";
        random_shuffle(array.begin(), array.end());

        cout << "Numeros gerados.\n";
        cout << "Inserindo os numeros no vetor ordenado...\n";

        auto startTime = clock();
        for(int i = 0; i < 10000; i++)
            sArray.push(array[i], array[i]);
        auto endTime = clock();

        cout << "Numeros inseridos.\n";
        cout << "Demoraram " << ((double)endTime - startTime)/CLOCKS_PER_SEC << " segundos para inserir os numeros.\n";

        cout << "Gerando 5.000 numeros do vetor ordenado...\n";

        startTime = clock();
        for(int i = 0; i < 5000; i++)
            sArray.pop();
        endTime = clock();

        cout << "Numeros removidos.\n";
        cout << "Demoraram " << ((double)endTime - startTime)/CLOCKS_PER_SEC << " segundos para remover os numeros.\n\n\n";
    }
    //////////////////////////////////////////////////////////////////////////
    ///////////////////VETOR HEAP/////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////
    {
        cout << "Gerando 10.000 numeros aleatorios entre 1 e 15.000...\n";
        random_shuffle(array.begin(), array.end());

        cout << "Numeros gerados.\n";
        cout << "Inserindo os numeros no vetor heap...\n";

        auto startTime = clock();
        for(int i = 0; i < 10000; i++)
            heap.push(array[i], array[i]);
        auto endTime = clock();

        cout << "Numeros inseridos.\n";
        cout << "Demoraram " << ((double)endTime - startTime)/CLOCKS_PER_SEC << " segundos para inserir os numeros.\n";

        cout << "Removendo 5.000 numeros do vetor heap...\n";

        startTime = clock();
        for(int i = 0; i < 5000; i++)
            heap.pop();
        endTime = clock();

        cout << "Numeros removidos.\n";
        cout << "Demoraram " << ((double)endTime - startTime)/CLOCKS_PER_SEC << " segundos para remover os numeros.\n\n\n"; 
    }

    system("pause");
    
    return 0;
}