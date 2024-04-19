#include "include.h"
#include "Windows.h"
#include "MainWindow.h"



int main() {
    
    SetConsoleCP(1251); // установка режима ввода консоли
    SetConsoleOutputCP(CP_UTF8); // установка режима вывода консоли

    system("title Сакура суши!"); // добавление заголовка приложения

    MainWindow window; // создаем обьект MainWindow

    window.show(); // запуск отображения приложения

    return 0;
}