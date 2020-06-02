#pragma once
#include <iostream>
#include <cstring>
#include <assert.h>

using std::cout;
using std::endl;

class String
{
private:
    char* content;
    int length;

    // Копирование данных
    void copy(const String& source);

public:

    // Конструкторы
    String();
    String(const char* source);
    String(const String& source);

    ~String();

    // Вывод
    void print(void);

    int& len();

    // Оператор присваивания
    String& operator =(const String& source);

    char& operator() (const size_t& position);

    // Вывод через потоковый оператор <<
    friend std::ostream& operator<<(std::ostream& out,
        const String& towrite);
};

// Конструктор без данных
// Оставим символ конца строки чтобы деструктору было что удалять
String::String()
{
    content = new char[1];
    content[0] = '\0';
    length = 0;
}

// Конструктор с данными
String::String(const char* source)
{
    length = strlen(source);
    content = new char[length + 1]; // Доп. символ для конца строки
    strcpy(content, source);
}

// Деструктор
String::~String()
{
    delete[] content;
}

// Копирование данных
void String::copy(const String& source)
{
    length = source.length;
    content = new char[length + 1];
    strcpy(content, source.content);
}

// Конструктор копирования
String::String(const String& source)
{
    copy(source); // use the copy method
}

// Вывод
void String::print(void)
{
    cout << "" << content << endl;
}

// Переопределение оператора присваивания
String& String::operator =(const String& source)
{
    copy(source);
    return *this;
}

// Оператор доступа
char& String::operator ()(const size_t& position)
{
    if ((position <= length - 1) && (position >= 0)) {
        return content[position];
    }
    assert(false);
}

// Вывод через оператор потоков <<
std::ostream& operator<<(std::ostream& out, const String& towrite)
{
    out << towrite.content;
    return out;
}

int& String::len() {
    return this->length;
}