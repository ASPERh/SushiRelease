#include "Menu.h"
#include "Windows.h"
#include <algorithm>


void Menu::setExePath() // Функция для получения пути к исполняемому файлу (.EXE)
{
    TCHAR buffer[MAX_PATH] = { 0 }; // Создание буфера для хранения пути к файлу
    GetModuleFileName(NULL, buffer, MAX_PATH); // Получение пути к исполняемому файлу и сохранение его в буфере
    wstring::size_type pos = wstring(buffer).find_last_of(L"\\/"); // Находим последний слэш или обратный слэш в строке
    wstring wpath = wstring(buffer).substr(0, pos); // Выделяем подстроку от начала до последнего слэша это будет путь к директории
    size_t size; // Переменная для хранения размера
    path.resize(wpath.length()); // Изменяем размер вектора path для хранения пути
    wcstombs_s(&size, &path[0], path.size() + 1, wpath.c_str(), wpath.size()); // Преобразование широкой строки в многобайтовую и сохранение в вектор path
}

Menu::Menu() // класс меню
{
    setExePath(); // получение пути .EXE файлу
    
    ifstream file(path + "\\Menu\\Menu.txt"); // открываем файл меню.тхт
    if (!file) // проверяем на открытие файла
    {
        cout << "Ошибка загрузки меню\n"; // отображаем ошибку
        exit(1); // выход с ошибкой 1
    }


    string line = ""; // обьявлем переменную
    while (getline(file, line)) { // получение строки из файла

        stringstream iString(line); // преобразуем строку String в Stringstream

        int id; // айди
        string name; // имя
        double price; // цена
        string descript; // описание
        string iname; // имя картинки
        string tempString; // временная строка

        getline(iString, tempString, '#'); // до первого разделителя
        id = atoi(tempString.c_str()); // сохраняем/преборазуваем в id 
        getline(iString, name, '#'); // до второго разделителя получаем имя
        getline(iString, tempString, '#'); // до третьего разделителя
        price = atof(tempString.c_str()); // получаем цену

        getline(iString, descript, '#'); // до четвертого разделителя получаем описание

        getline(iString, iname, '#'); // до пятого разделителя получаем название картинки


        Product tSushi{ id, name, price, descript, iname }; // создаем обьект данных

        menu.push_back(tSushi); // пушим в вектор
        line = ""; // обнуляем строку 

    }

    file.close(); // закрываем файл
}

vector<Product> Menu::getProducts() // получение вектора данных
{
    return this->menu; // вернуть вектор меню
}

Product Menu::getProduct(int id) // получение продукта по индексу из вектора
{
    Product p{ 0, "", 0.0, "", "" }; // пустой обьект
    for (const Product& tprod : menu) // пробегаем по вектору меню
    {
        if (tprod.id == id) // проверяем айди
        {
            return tprod; // возращаем найденный обьект
        }
        
    }
    return p; // возращаем пустой обьект
}

string Menu::getProductPath(int id) // получение пути к картинке
{
    return  path + "\\Menu\\" + getProduct(id).imageName; // формирование пути к картинке
}