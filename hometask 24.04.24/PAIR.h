#pragma once


#include <string>

// ��������� Pair ��� �������� ����� � ��� ������� �������������
struct Pair {
    std::string first;
    int second;

    // ����������� ��� ������������� ������ ���������
    Pair() {};
    Pair(const std::string& f, int s);

    // ���������� ��� ������������ ���������� ������
    ~Pair();
};

// ������� ��� ������ ���� �� ����� � �������� ������� �������������
Pair* countWordFrequency(const std::string& filename, int& size);

// ������� ��� ���������� ���� �� ��������
void sortByWord(Pair* wordFreq, int size);

// ������� ��� ���������� ���� �� ������� �������������
void sortByFrequency(Pair* wordFreq, int size);

