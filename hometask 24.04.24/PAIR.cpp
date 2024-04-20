#include "Pair.h"
#include <fstream>
#include <iostream>
#include <string>

Pair::Pair(const std::string& f, int s) : first(f), second(s) {}

Pair::~Pair() {}

Pair* countWordFrequency(const std::string& filename, int& size) {
    Pair* wordFreq = new Pair[100]; // Предполагаемое начальное количество слов
    size = 0;
    std::ifstream file(filename);
    std::string word;

    while (file >> word) {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (wordFreq[i].first == word) {
                wordFreq[i].second++;
                found = true;
                break;
            }
        }
        if (!found) {
            wordFreq[size] = Pair(word, 1);
            size++;
        }
    }

    return wordFreq;
}

// Сортировка пузырьком
void sortByWord(Pair* wordFreq, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (wordFreq[j].first > wordFreq[j + 1].first) {
                Pair temp = wordFreq[j];
                wordFreq[j] = wordFreq[j + 1];
                wordFreq[j + 1] = temp;
            }
        }
    }
}

// Сортировка пузырьком
void sortByFrequency(Pair* wordFreq, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (wordFreq[j].second > wordFreq[j + 1].second) {
                Pair temp = wordFreq[j];
                wordFreq[j] = wordFreq[j + 1];
                wordFreq[j + 1] = temp;
            }
        }
    }
}
