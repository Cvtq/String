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

    // ����������� ������
    void copy(const String& source);

public:

    // ������������
    String();
    String(const char* source);
    String(const String& source);

    ~String();

    // �����
    void print(void);

    int& len();

    // �������� ������������
    String& operator =(const String& source);

    char& operator() (const size_t& position);

    // ����� ����� ��������� �������� <<
    friend std::ostream& operator<<(std::ostream& out,
        const String& towrite);
};

// ����������� ��� ������
// ������� ������ ����� ������ ����� ����������� ���� ��� �������
String::String()
{
    content = new char[1];
    content[0] = '\0';
    length = 0;
}

// ����������� � �������
String::String(const char* source)
{
    length = strlen(source);
    content = new char[length + 1]; // ���. ������ ��� ����� ������
    strcpy(content, source);
}

// ����������
String::~String()
{
    delete[] content;
}

// ����������� ������
void String::copy(const String& source)
{
    length = source.length;
    content = new char[length + 1];
    strcpy(content, source.content);
}

// ����������� �����������
String::String(const String& source)
{
    copy(source); // use the copy method
}

// �����
void String::print(void)
{
    cout << "" << content << endl;
}

// ��������������� ��������� ������������
String& String::operator =(const String& source)
{
    copy(source);
    return *this;
}

// �������� �������
char& String::operator ()(const size_t& position)
{
    if ((position <= length - 1) && (position >= 0)) {
        return content[position];
    }
    assert(false);
}

// ����� ����� �������� ������� <<
std::ostream& operator<<(std::ostream& out, const String& towrite)
{
    out << towrite.content;
    return out;
}

int& String::len() {
    return this->length;
}