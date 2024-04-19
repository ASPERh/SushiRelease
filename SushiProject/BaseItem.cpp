//реализайия для бвзового елемента
#include "BaseItem.h"

void BaseItem::recalc() //пересчет
{
	Vector2f sizef(size.x, size.y); //создаем размер
	rectobj.setSize(sizef); //задаем размер для rectobj
	rectobj.setPosition(position.x, position.y); //задаем позицию для rectobj
	rectobj.setOutlineColor(borderColor); //задаем цвет кромки для rectobj
	rectobj.setOutlineThickness(borderThicknes); //задаем размер кромки для rectobj
	rectobj.setFillColor(color); //задаем цвет для rectobj
	
	
	if (isPushed) //обрабатываем isPushed
		rectobj.setFillColor(pushedColor); //меняем на pushedColor цвет для rectobj
	else if (isSelected)  //обрабатываем isSelected
		rectobj.setFillColor(selectedColor); //меняем на selectedColor цвет для rectobj
	else
		rectobj.setFillColor(color); //меняем на стандартный цвет для rectobj

	textobj.setFont(font); //задаем шрифт для textobj
	textobj.setString(text); //задаем текст для textobj
	textobj.setCharacterSize(characterSize); //задаем размер шрифта для textobj
	textobj.setOutlineColor(textBorderColor); //задаем размер шрифта для textobj
	textobj.setOutlineThickness(borderThicknes); //задаем цвет кромки шрифта textobj
	textobj.setPosition(position.x + textOffSet.x, position.y + textOffSet.y); //задаем позицию  textobj со смещением от rectobj
}

void BaseItem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectobj, states); //отрисовка rectobj
	target.draw(textobj, states); //отрисовка textobj
}


BaseItem::BaseItem()
{
	//Значения по умолчанию
	font.loadFromFile("CyrilicOld.ttf"); //создаем шрифт
	characterSize = 20; //размер шрифта
	size.x = 10; //размер х
	size.y = 10; //размер у
	position.x = 0; //позиция х
	position.y = 0; //позиция у

	textOffSet.x = 10; //смещение текста х
	textOffSet.y = -5; //смещение текста у

	text = "Base"; //текст

	color = Color::Magenta; //цвет
	selectedColor = Color::Cyan; //цвет выделения 
	pushedColor = Color::White; //цвет нажатия
	textBorderColor = Color::Black; //цвет кромки шрифта
	borderThicknes = 3;  //толщина кромки
	borderColor = Color::Black; //цвет кромки
	recalc(); //пересчет
}


//реализация метода для назначения позиции
void BaseItem::setPosition(Vector2i position) 
{
	this->position = position;
	recalc();
}

//реализация метода для назначения размера
void BaseItem::setSize(Vector2i size)
{
	this->size = size;
	recalc();
}

//реализация метода для назначения текста
void BaseItem::setTextOffSet(Vector2i textOffSet)
{
	this->textOffSet = textOffSet;
	recalc();
}

//реализация метода для назначения отступа текста
void BaseItem::setText(string text)
{
	this->text = text;
	recalc();
}

//реализация метода для назначения толщины кромки
void BaseItem::setBorderThicknes(int borderThicknes)
{
	this->borderThicknes = borderThicknes;
	recalc();
}

//реализация метода для назначения цвета кромки
void BaseItem::setBorderColor(Color borderColor)
{
	this->borderColor = borderColor;
	recalc();
}

//реализация метода для назначения цвета кромки шрифта
void BaseItem::setTextBorderColor(Color textBorderColor)
{
	this->textBorderColor = textBorderColor;
}

//реализация метода для назначения шрифта
void BaseItem::setFont(Font font)
{
	this->font = font;
	recalc();
}

//реализация метода для назначения размера шрифта
void BaseItem::setCharacterSize(int characterSize)
{
	this->characterSize = characterSize;
}

//реализация метода для назначения цвета
void BaseItem::setColor(Color color)
{
	this->color = color;
	recalc();
}

//реализация метода для назначения цвета выделения
void BaseItem::setSelectedColor(Color selectedColor)
{
	this->selectedColor = selectedColor;
	recalc();
}

//реализация метода для определения нахождения курсора на объекте
bool BaseItem::checkMouseOn(Vector2i pos)
{
	bool res = rectobj.getGlobalBounds().contains(pos.x, pos.y); //определяем нахождится курсор на объекте или нет
	if (res)
	{
		//помечаем если нахождится
		isSelected = true;
	}
	else
	{
		//помечаем если не нахождится
		isSelected = false;
	}
	recalc(); //пересчет
	return res;
}

//реализация метода для устоновки нахождения курсора на объекте
void BaseItem::setIsSelected(bool isSelected)
{
	this->isSelected = isSelected;
	recalc();
}

//реализация метода для получения нахождения курсора на объекте
bool BaseItem::getIsSelected()
{
	return isSelected;
}

//реализация метода для определения нажатия на объекте
bool BaseItem::checkClick()
{
	return isSelected;
}

//реализация метода для устоновки состояния объекта
void BaseItem::setIsPushed(bool isPushed)
{
	this->isPushed = isPushed;
	recalc();

}

//реализация метода для получения состояния объекта
bool BaseItem::getIsPushed()
{
	return isPushed;
}

//реализация метода для получения текста
string BaseItem::getText()
{
	return this->text;
}