//Хедер файл для бвзового елемента
#include "include.h"


class BaseItem :
    public Drawable //обявление BaseItem наследуем от Drawable
{
private:
protected:
	Vector2i position; // позиция элемента задается Vector2i по x и y
	Vector2i size; // размер по x и y
	Vector2i textOffSet; //отступ текста по x и y
	string text; //текст
	Color color; //цвет 
	Color selectedColor; //цвет при наведении мыши
	Color pushedColor; //цвет нажатой кнопеи
	int borderThicknes; //толщина кромки
	Color borderColor; //цвет кромки
	Color textBorderColor; //цвет кромки шрифта
	Font font; //шрифт
	int characterSize; //размер шрифта
	RectangleShape rectobj; //объект прямоугольник
	Text textobj; //объект текст
	
	bool isSelected = false; //объект выделен 
	bool isPushed = false; //объект нажат

	virtual void recalc(); //метод для пересчета rectobj и textobj
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //отрисовка обьектов
public:
	BaseItem();

	void setPosition(Vector2i position); //метод для назначения позиции
	void setSize(Vector2i  size); //метод для назначения размера
	void setText(string  text); //метод для назначения текста
	void setTextOffSet(Vector2i  textOffSet); //метод для назначения отступа текста
	void setBorderThicknes(int borderThicknes); //метод для назначения толщины кромки
	void setBorderColor(Color borderColor); //метод для назначения цвета кромки
	void setTextBorderColor(Color borderColor); //метод для назначения цвета кромки шрифта
	void setFont(Font font); //метод для назначения шрифта
	void setCharacterSize(int characterSize); //метод для назначения размера шрифта
	void setColor(Color color); //метод для назначения цвета
	void setSelectedColor(Color selectedColor); //метод для назначения цвета выделения
	virtual bool checkMouseOn(Vector2i pos); //метод для определения нахождения курсора на объекте
	virtual bool checkClick(); //метод для определения нажатия на объекте
	void setIsSelected(bool isSelected); //метод для устоновки нахождения курсора на объекте
	bool getIsSelected(); //метод для получения нахождения курсора на объекте
	void setIsPushed(bool isPushed); //метод для устоновки состояния объекта
	bool getIsPushed(); //метод для получения состояния объекта
	string getText(); //метод для получения текста

};