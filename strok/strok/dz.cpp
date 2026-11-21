#include <iostream>
#include <string>
#include <cwctype>
#include <clocale>
#include <fcntl.h>
#include <Windows.h>
#include <io.h> 

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    std::setlocale(LC_ALL, "Russian");

    std::wcout << L"Введите предложение: ";
    std::wstring s;
    std::getline(std::wcin, s);

    if (s.find_first_not_of(L' ') == std::wstring::npos)
    {
        std::wcout << L"Строка пустая!\n";
        return 0;
    }

    s.erase(s.find_last_not_of(L' ') + 1);

    bool newWord = true;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == L' ')
            newWord = true;
        else if (newWord)
        {
            s[i] = std::towupper(s[i]);
            newWord = false;
        }
        else
            s[i] = std::towlower(s[i]);
    }

    if (s.back() != L'.')
        s += L'.';

    std::wcout << L"Результат: " << s << L'\n';
    return 0;
}