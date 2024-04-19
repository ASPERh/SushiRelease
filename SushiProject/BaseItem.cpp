//���������� ��� �������� ��������
#include "BaseItem.h"

void BaseItem::recalc() //��������
{
	Vector2f sizef(size.x, size.y); //������� ������
	rectobj.setSize(sizef); //������ ������ ��� rectobj
	rectobj.setPosition(position.x, position.y); //������ ������� ��� rectobj
	rectobj.setOutlineColor(borderColor); //������ ���� ������ ��� rectobj
	rectobj.setOutlineThickness(borderThicknes); //������ ������ ������ ��� rectobj
	rectobj.setFillColor(color); //������ ���� ��� rectobj
	
	
	if (isPushed) //������������ isPushed
		rectobj.setFillColor(pushedColor); //������ �� pushedColor ���� ��� rectobj
	else if (isSelected)  //������������ isSelected
		rectobj.setFillColor(selectedColor); //������ �� selectedColor ���� ��� rectobj
	else
		rectobj.setFillColor(color); //������ �� ����������� ���� ��� rectobj

	textobj.setFont(font); //������ ����� ��� textobj
	textobj.setString(text); //������ ����� ��� textobj
	textobj.setCharacterSize(characterSize); //������ ������ ������ ��� textobj
	textobj.setOutlineColor(textBorderColor); //������ ������ ������ ��� textobj
	textobj.setOutlineThickness(borderThicknes); //������ ���� ������ ������ textobj
	textobj.setPosition(position.x + textOffSet.x, position.y + textOffSet.y); //������ �������  textobj �� ��������� �� rectobj
}

void BaseItem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectobj, states); //��������� rectobj
	target.draw(textobj, states); //��������� textobj
}


BaseItem::BaseItem()
{
	//�������� �� ���������
	font.loadFromFile("CyrilicOld.ttf"); //������� �����
	characterSize = 20; //������ ������
	size.x = 10; //������ �
	size.y = 10; //������ �
	position.x = 0; //������� �
	position.y = 0; //������� �

	textOffSet.x = 10; //�������� ������ �
	textOffSet.y = -5; //�������� ������ �

	text = "Base"; //�����

	color = Color::Magenta; //����
	selectedColor = Color::Cyan; //���� ��������� 
	pushedColor = Color::White; //���� �������
	textBorderColor = Color::Black; //���� ������ ������
	borderThicknes = 3;  //������� ������
	borderColor = Color::Black; //���� ������
	recalc(); //��������
}


//���������� ������ ��� ���������� �������
void BaseItem::setPosition(Vector2i position) 
{
	this->position = position;
	recalc();
}

//���������� ������ ��� ���������� �������
void BaseItem::setSize(Vector2i size)
{
	this->size = size;
	recalc();
}

//���������� ������ ��� ���������� ������
void BaseItem::setTextOffSet(Vector2i textOffSet)
{
	this->textOffSet = textOffSet;
	recalc();
}

//���������� ������ ��� ���������� ������� ������
void BaseItem::setText(string text)
{
	this->text = text;
	recalc();
}

//���������� ������ ��� ���������� ������� ������
void BaseItem::setBorderThicknes(int borderThicknes)
{
	this->borderThicknes = borderThicknes;
	recalc();
}

//���������� ������ ��� ���������� ����� ������
void BaseItem::setBorderColor(Color borderColor)
{
	this->borderColor = borderColor;
	recalc();
}

//���������� ������ ��� ���������� ����� ������ ������
void BaseItem::setTextBorderColor(Color textBorderColor)
{
	this->textBorderColor = textBorderColor;
}

//���������� ������ ��� ���������� ������
void BaseItem::setFont(Font font)
{
	this->font = font;
	recalc();
}

//���������� ������ ��� ���������� ������� ������
void BaseItem::setCharacterSize(int characterSize)
{
	this->characterSize = characterSize;
}

//���������� ������ ��� ���������� �����
void BaseItem::setColor(Color color)
{
	this->color = color;
	recalc();
}

//���������� ������ ��� ���������� ����� ���������
void BaseItem::setSelectedColor(Color selectedColor)
{
	this->selectedColor = selectedColor;
	recalc();
}

//���������� ������ ��� ����������� ���������� ������� �� �������
bool BaseItem::checkMouseOn(Vector2i pos)
{
	bool res = rectobj.getGlobalBounds().contains(pos.x, pos.y); //���������� ���������� ������ �� ������� ��� ���
	if (res)
	{
		//�������� ���� ����������
		isSelected = true;
	}
	else
	{
		//�������� ���� �� ����������
		isSelected = false;
	}
	recalc(); //��������
	return res;
}

//���������� ������ ��� ��������� ���������� ������� �� �������
void BaseItem::setIsSelected(bool isSelected)
{
	this->isSelected = isSelected;
	recalc();
}

//���������� ������ ��� ��������� ���������� ������� �� �������
bool BaseItem::getIsSelected()
{
	return isSelected;
}

//���������� ������ ��� ����������� ������� �� �������
bool BaseItem::checkClick()
{
	return isSelected;
}

//���������� ������ ��� ��������� ��������� �������
void BaseItem::setIsPushed(bool isPushed)
{
	this->isPushed = isPushed;
	recalc();

}

//���������� ������ ��� ��������� ��������� �������
bool BaseItem::getIsPushed()
{
	return isPushed;
}

//���������� ������ ��� ��������� ������
string BaseItem::getText()
{
	return this->text;
}