// Task4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>


int main()
{
    wchar_t const* myTitle{ L"My title!" };

    SetConsoleTitle(myTitle);

    std::cout << "Change console's header!\n";

    system("pause");

    return 0;
}

