#pragma once


#include <string>

// Структура Pair для хранения слова и его частоты встречаемости
struct Pair {
    std::string first;
    int second;

    // Конструктор для инициализации членов структуры
    Pair() {};
    Pair(const std::string& f, int s);
    
    // Деструктор для освобождения выделенной памяти
    ~Pair();
};

// Функция для чтения слов из файла и подсчета частоты встречаемости
Pair* countWordFrequency(const std::string& filename, int& size);
// Функция для проверки знака пунктуации
bool isPunctuation(char c);
// Функция для сортировки слов по алфавиту
void sortByWord(Pair* wordFreq, int size);
// Функция для правильного считывания слова
std::string cleanWord(const std::string& word);
// Функция для сортировки слов по частоте встречаемости
void sortByFrequency(Pair* wordFreq, int size);

