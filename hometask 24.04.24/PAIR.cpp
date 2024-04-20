#include "Pair.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>


Pair::Pair(const std::string& f, int s) : first(f), second(s) {}

Pair::~Pair() {}

Pair* countWordFrequency(const std::string& filename, int& size) {
    Pair* wordFreq = new Pair[100]; // �������������� ��������� ���������� ����
    size = 0;
    std::ifstream file(filename);
    std::string word;

    while (file >> word) {
        // ������� ����� �� ������ ���������� � �������������� � ������ �������
        std::string cleanedWord = cleanWord(word);

        bool found = false;
        for (int i = 0; i < size; ++i) {
            // ��������� ���������� ����� � ������������
            for (int i = 0; i < size && !found; ++i) {
                if (wordFreq[i].first == cleanedWord) {
                    wordFreq[i].second++;
                    found = true;
                }
            }
        }
        if (!found) {
            wordFreq[size] = Pair(cleanedWord, 1);
            size++;
        }
    }

    return wordFreq;
}

// ���������� ���������
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

// ���������� ���������
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

bool isPunctuation(char c) {
    return std::ispunct(c);
}

std::string cleanWord(const std::string& word) {
    std::string clean = word;
    // �������������� ���� �������� � ������ �������
    std::transform(clean.begin(), clean.end(), clean.begin(), ::tolower);
    // �������� ������ ����������
    clean.erase(std::remove_if(clean.begin(), clean.end(), isPunctuation), clean.end());
    return clean;
}