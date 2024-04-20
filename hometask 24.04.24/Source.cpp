#include <iostream>
#include "Pair.h"

int main() {
    setlocale(LC_ALL, "Ru");
    int size;
    Pair* wordFreq = countWordFrequency("text.txt", size);

    // Сортируем по словам и выводим
    sortByWord(wordFreq, size);
    std::cout << "Слова и их частотность (отсортированные по слову):" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << wordFreq[i].first << ": " << wordFreq[i].second << std::endl;
    }

    // Сортируем по частоте и выводим
    sortByFrequency(wordFreq, size);
    std::cout << "\nСлова и их частотность (отсортированные по частоте):" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << wordFreq[i].first << ": " << wordFreq[i].second << std::endl;
    }

    delete[] wordFreq; // Освобождаем память, выделенную для массива объектов Pair
    system("pause");
    return 0;
}
