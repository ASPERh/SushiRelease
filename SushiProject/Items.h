#include "include.h"
#include "BaseItem.h"

class Item  //обявление Item 
{
public:
	int id; // ИД
	string name; //имя
	double price; //цена
	string descript;//описание
	string imageName; //имя картинки
	int count; //количество
	bool select; //если выбран
};


class Button : public BaseItem
{
private:
	void recalc();//пересчет
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //отрисовка обьектов

public:
	Button(); // конструктор
};


class ProdItem : public BaseItem
{
private:

	Item *itm; //ссылка на обект данных
	
	Vector2i btnSize; // размер по x и y
	Text capobj; //объект заголовка
	Text sumobj; //обьект суммы
	
	Button orderBtn; // кнопка заказа
	Button incBtn; // кнопка увелечения
	Button decBtn; // кнопка уменьшения
	Texture pic; // картинка
	Sprite image; // обьект для картинки

	bool isVisible; // видимый/невидимый
 
	void recalc(); // пересчет

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //отрисовка обьектов

public:
	ProdItem(); // конструктор
	bool checkMouseOn(Vector2i pos); //метод для определения нахождения курсора на объекте
	bool checkClick(); //метод для определения нажатия на объекте
	void setItem(Item &itm); //метод для передачи обьекта данных
	void setVisibe(bool isVisible); //метод для установки видимости
	Item& getItem(); // получение обьекта данных
};

class InfoItem : public BaseItem // 
{
private:
	Text capobj; //объект заголовка
	Text sumobj; //обьект суммы
	void recalc(); // пересчет
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //отрисовка обьектов

public:
	InfoItem(); // конструктор
	void SetSum(double sum); // задать цену
	void SetString(String str); // задать строку
	void SetCaption(String str); // задать загаловок
};

class MenuFrame : public BaseItem
{
private:

	vector <Item> items; // вектор данных
	
	InfoItem info; // отображение суммы

	Button nextBtn; // кнопка следующей страницы
	Button prevBtn; // кнопка предыдущий страницы
	Button orderBtn; // кнопка заказа
	Button closeBtn; // кнопка закрытия

	ProdItem itmobj1; // обьект 1
	ProdItem itmobj2; // обьект 2
	ProdItem itmobj3; // обьект 3
	ProdItem itmobj4; // обьект 4
	ProdItem itmobj5; // обьект 5
	ProdItem itmobj6; // обьект 6
	ProdItem itmobj7; // обьект 7
	ProdItem itmobj8; // обьект 8
	ProdItem itmobj9; // обьект 9
	
	int curPage; // текущая страница
	int numPages; // количество страниц
	
	bool orderStatus; // статус заказа

	void recalc(); // пересчет
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //отрисовка обьектов

public:
	MenuFrame(); // конструктор
	bool checkMouseOn(Vector2i pos); //метод для определения нахождения курсора на объекте
	bool checkClick(); //метод для определения нажатия на объекте
	bool getOrderStatus(); // проверка статуса заказа
	void pushProd(Item &itm); // пушим обьект данных
	void clearProd(); // очищаем данные
	vector <Item> getSelectedItems(); // получаем вектор выбранных данных
};

class OrderFrame : public BaseItem
{
private:

	vector <Item> items; // вектор данных

	InfoItem sumInfo; // информация суммы
	InfoItem orderInfo; // информация заказа
	InfoItem addressInfo; // информация адреса
	Button appruveBtn; // кнопка подтверждения
	Button closeBtn; // кнопка закрытия
	String* txtbuffer; // буфер для ввода текста

	bool orderStatus; // статус заказа

	void recalc(); // пересчет
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //отрисовка обьектов

public:
	OrderFrame(); // конструктор
	bool checkMouseOn(Vector2i pos); //метод для определения нахождения курсора на объекте
	bool checkClick(); //метод для определения нажатия на объекте
	bool getOrderStatus(); // проверка статуса заказа
	void setSelectedItems(vector <Item> itms); // передаем вектор данных
	void setTxtBuffer(String  &buffer); // устанавливаем буфер для ввода текста
	
};