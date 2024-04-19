#include "include.h"

#include <algorithm>

struct Product { // структура данных продукта
    int id; // »ƒ
    string name; // название
    double price; // цена
    string descript; // описание
    string imageName; // названи€ картинки
};

class Menu // обь€вление класса меню
{
private:
	vector<Product> menu; // вектор данных
	string path; // путь
	void setExePath(); // получение пути к .EXE файлу 
public:
	Menu(); // конструктор класса

	vector<Product> getProducts(); // получение данных продуктов
	Product getProduct(int id); // получить продукта по »ƒ
	string getProductPath(int id); // получение пути дл€ картинки
};