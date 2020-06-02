#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"
#include "comparison.h"

using std::cout;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Отсчет идет с нуля" << endl;
    {
        String s1("123456789");
        String s2("456");
        find(s1, s2, 0);
    }
    {
        String s1("123456 123456 123456");
        String s2("12");
        find(s1, s2, 4);
    }
    {
        String s1("123456 123456 123456");
        String s2("12");
        find(s1, s2, 10);
    }
    {
        String s1("123456789");
        String s2("test");
        find(s1, s2, 0);
    }
}