#include <iostream>
#include "Pair.h"

int main() {
    setlocale(LC_ALL, "Ru");
    int size;
    Pair* wordFreq = countWordFrequency("text.txt", size);

    // ��������� �� ������ � �������
    sortByWord(wordFreq, size);
    std::cout << "����� � �� ����������� (��������������� �� �����):" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << wordFreq[i].first << ": " << wordFreq[i].second << std::endl;
    }

    // ��������� �� ������� � �������
    sortByFrequency(wordFreq, size);
    std::cout << "\n����� � �� ����������� (��������������� �� �������):" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << wordFreq[i].first << ": " << wordFreq[i].second << std::endl;
    }

    delete[] wordFreq; // ����������� ������, ���������� ��� ������� �������� Pair
    system("pause");
    return 0;
}
