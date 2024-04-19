#include "Items.h"

string doubleToString(double number, int precision) {
	ostringstream stream; // ������� ������ ������ ��� ����������� ������ � ������
	stream.precision(precision); // ������������� �������� (���������� ������ ����� �������) ��� ������ �����
	stream << fixed << number; // �������� ����� � ����� � ������������� ������ ��� �������� ������������� ���������� ������ ����� ���������� �������
	return stream.str(); // ���������� ���������� ������ � ���� ������
}

void Button::recalc() // ��������
{
	this->BaseItem::recalc(); // ����� ��������� �������� ������
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const //��������� ��������
{
	this->BaseItem::draw(target, states); // ����� ��������� �������� ������
}


Button::Button() // ����������� ������
{
	characterSize = 30; // ������ ������
	size.x = 100; // ������ �� �
	size.y = 30; // ������ �� Y
	position.x = 0; // ������� �� X
	position.y = 0; //������� �� Y
	text = "Button"; // �����
	color = Color(0, 102, 102); // ���� ������ �� ��������� 
	selectedColor = Color::Cyan; // ���� ��� ������� �� ������
	pushedColor = Color(100, 100, 100); // ���� ������� �� ������
	borderThicknes = 3; // ������� �������
	borderColor = Color::Black; // ���� �������
	recalc(); // ��������
}

void MenuFrame::recalc() //��������� ��������
{
	itmobj1.setVisibe(false); // ��������� ����������� ������� 1
	itmobj2.setVisibe(false); // ��������� ����������� ������� 2
	itmobj3.setVisibe(false); // ��������� ����������� ������� 3
	itmobj4.setVisibe(false); // ��������� ����������� ������� 4
	itmobj5.setVisibe(false); // ��������� ����������� ������� 5
	itmobj6.setVisibe(false); // ��������� ����������� ������� 6
	itmobj7.setVisibe(false); // ��������� ����������� ������� 7
	itmobj8.setVisibe(false); // ��������� ����������� ������� 8
	itmobj9.setVisibe(false); // ��������� ����������� ������� 9
	
	float s = items.size(); // ��������� ���������� ������ ��������
	numPages = ceil (s / 9); // ���������� �������
	int numProd = items.size() % 9; // ���������� ��������� �� ��������� ��������
	int minProd = 0; // ��������� ������� �����������
	int maxProd = 9; // ��������� ������� �����������
	if (curPage > 1)
		minProd = minProd + 9 * (numPages - 1); // ��������� ��������� ������� ��� ��������
	if (curPage == numPages) // �������� ��������
		maxProd = minProd + numProd; // ��������� ��������� ������� ��� ��������

	if (items.size() > 0) // ���� ������ ������ ������ ���� �� ���������� ����������
	{
		if (minProd < maxProd && items.size() > minProd) // ����������
			itmobj1.setItem(items[minProd]); // ����������
		if (minProd + 1 < maxProd && items.size() > minProd+1) // ����������
			itmobj2.setItem(items[minProd + 1]); // ����������
		if (minProd + 2 < maxProd && items.size() > minProd+2) // ����������
			itmobj3.setItem(items[minProd + 2]); // ����������
		if (minProd + 3 < maxProd && items.size() > minProd+3) // ����������
			itmobj4.setItem(items[minProd + 3]); // ����������
		if (minProd + 4 < maxProd && items.size() > minProd+4) // ����������
			itmobj5.setItem(items[minProd + 4]); // ����������
		if (minProd + 5 < maxProd && items.size() > minProd+5) // ����������
			itmobj6.setItem(items[minProd + 5]); // ����������
		if (minProd + 6 < maxProd && items.size() > minProd+6) // ����������
			itmobj7.setItem(items[minProd + 6]); // ����������
		if (minProd + 7 < maxProd && items.size() > minProd+7) // ����������
			itmobj8.setItem(items[minProd + 7]); // ����������
		if (minProd + 8 < maxProd && items.size() > minProd+8) // ����������
			itmobj9.setItem(items[minProd + 8]); // ����������
	}

	if (curPage == 1) // ���� ������� ������ ��������
		prevBtn.setIsPushed(true); // ������ ���������� �������� ��������������� �������
	else
		prevBtn.setIsPushed(false); // ��� ������ ���������� �������� ��������������� �� �������

	if (curPage == numPages) // ���� ������� �������� �������� ���������
		nextBtn.setIsPushed(true); // ������ ��������� �������� ��������������� �������
	else
		nextBtn.setIsPushed(false); // ��� ������ ��������� �������� ��������������� �� �������

	double sum = 0.0; // ���� �� ���������
	for (const Item& tp : items) // ��������� ����� ���� ��������� ���������
	{
		if (tp.select) // ���� ������� ������
			sum = sum + tp.price * tp.count; // ��������� � �����
	}
	info.SetSum(sum); // �������� � ������ Info
	if (sum > 0.0) // ���� ���� ������ ����
		orderBtn.setIsPushed(false); // ������ ������ ��������������� �� �������
	else
		orderBtn.setIsPushed(true); // ������ ������ ��������������� �������


	this->BaseItem::recalc(); // ����� ��������� �������� ������
	textobj.setPosition(position.x + 20, position.y + 10 ); // ��������� ������
}

void MenuFrame::draw(sf::RenderTarget& target, sf::RenderStates states) const //��������� ��������
{
	this->BaseItem::draw(target, states); // ����� ��������� �������� ������

	target.draw(itmobj1, states); //��������� ������� 1
	target.draw(itmobj2, states); //��������� ������� 2
	target.draw(itmobj3, states); //��������� ������� 3
	target.draw(itmobj4, states); //��������� ������� 4
	target.draw(itmobj5, states); //��������� ������� 5
	target.draw(itmobj6, states); //��������� ������� 6
	target.draw(itmobj7, states); //��������� ������� 7
	target.draw(itmobj8, states); //��������� ������� 8
	target.draw(itmobj9, states); //��������� ������� 9

	target.draw(prevBtn, states); //��������� ������ �����
	target.draw(nextBtn, states); //��������� ������ ������
	target.draw(orderBtn, states); //��������� ������ ������
	target.draw(closeBtn, states); //��������� ������ ��������
	
	target.draw(info, states); // ��������� ������� Info
	
}

MenuFrame::MenuFrame() // �����������
{
	//�������� �� ���������
	curPage = 1; // ������� ��������
	orderStatus = false; // ������ ������
	info.setPosition(Vector2i(720, 845)); // ��������� �������

	prevBtn.setText("����."); // ����� ������ ����.
	prevBtn.setPosition(Vector2i(1090, 865)); // ��������� �������

	nextBtn.setText("����."); // ����� ������ ����.
	nextBtn.setPosition(Vector2i(1210, 865)); // ��������� �������
	nextBtn.setIsPushed(true); // ������������� ������ ����. �������

	orderBtn.setSize(Vector2i(150, 30)); // ��������� ������� ������ ��������
	orderBtn.setText("��������!"); // ����� ������ ��������
	orderBtn.setPosition(Vector2i(1480, 865)); // ��������� �������
	orderBtn.setIsPushed(true); // ������������� ������ �������� �������

	closeBtn.setSize(Vector2i(25, 25)); // ��������� ������� ������ �������
	closeBtn.setText("X"); // ����� ������ �������
	closeBtn.setCharacterSize(25); // ��������� ������� ������ ������ �������
	closeBtn.setTextOffSet(Vector2i(4,-5)); // ��������� �������� ������ ������������ ������
	closeBtn.setPosition(Vector2i(1655, 40)); // ��������� �������
	


	itmobj1.setPosition(Vector2i(720, 100)); // ��������� �������
	itmobj2.setPosition(Vector2i(1050, 100)); // ��������� �������
	itmobj3.setPosition(Vector2i(1380, 100)); // ��������� �������
	itmobj4.setPosition(Vector2i(720, 350)); // ��������� �������
	itmobj5.setPosition(Vector2i(1050, 350)); // ��������� �������
	itmobj6.setPosition(Vector2i(1380, 350)); // ��������� �������
	itmobj7.setPosition(Vector2i(720, 600)); // ��������� �������
	itmobj8.setPosition(Vector2i(1050,600)); // ��������� �������
	itmobj9.setPosition(Vector2i(1380, 600)); // ��������� �������
	
	
	characterSize = 30; // ��������� ������� ������
	size.x = 1000; //������ �� �
	size.y = 910; // ������ �� Y
	position.x = 0; //������� �� X
	position.y = 0; //������� �� Y
	text = "����"; //����� ����
	textBorderColor = Color::Magenta; // ���� ������� ������
	color = Color::Black; // ����
	borderThicknes = 3; // ������� �������
	borderColor = Color::White; // ���� �������
	recalc(); // ��������
}

bool MenuFrame::checkMouseOn(Vector2i pos) // �������� ������� ��������� �������
{
	prevBtn.checkMouseOn(pos); // �������� �������� �������
	nextBtn.checkMouseOn(pos); // �������� �������� �������
	orderBtn.checkMouseOn(pos); // �������� �������� �������
	closeBtn.checkMouseOn(pos); // �������� �������� �������

	itmobj1.checkMouseOn(pos); // �������� �������� �������
	itmobj2.checkMouseOn(pos); // �������� �������� �������
	itmobj3.checkMouseOn(pos); // �������� �������� �������
	itmobj4.checkMouseOn(pos); // �������� �������� �������
	itmobj5.checkMouseOn(pos); // �������� �������� �������
	itmobj6.checkMouseOn(pos); // �������� �������� �������
	itmobj7.checkMouseOn(pos); // �������� �������� �������
	itmobj8.checkMouseOn(pos); // �������� �������� �������
	itmobj9.checkMouseOn(pos); // �������� �������� �������


	return false; // ������������ false
}

bool MenuFrame::checkClick() // �������� ������� �������
{
	if (prevBtn.checkClick() && curPage > 1) // �������� �� ����������� ���������� ��������
		curPage--; // ���������� ��������
	if (nextBtn.checkClick() && curPage < numPages) // �������� �� ����������� ���������� ��������
		curPage++; // ���������� ��������

	itmobj1.checkClick(); // �������� �������� �������
	itmobj2.checkClick(); // �������� �������� �������
	itmobj3.checkClick(); // �������� �������� �������
	itmobj4.checkClick(); // �������� �������� �������
	itmobj5.checkClick(); // �������� �������� �������
	itmobj6.checkClick(); // �������� �������� �������
	itmobj7.checkClick(); // �������� �������� �������
	itmobj8.checkClick(); // �������� �������� �������
	itmobj9.checkClick(); // �������� �������� �������
	
	recalc(); // ��������
	bool ans=false; // ������
	ans = closeBtn.checkClick(); // �������� �� ������� ������ close
	if (orderBtn.getIsPushed()==false && orderBtn.checkClick()) // ��������� �� ������� ������ order
	{
		orderStatus = true; // ���������� ������� ������
		ans = true; // ���������� �������
	}
	
	return ans; // ����������� ������
}
bool MenuFrame::getOrderStatus() // ��������� ������� ������
{

	return orderStatus; // ����������� ������� ������
}

vector<Item> MenuFrame::getSelectedItems() // ��������� ������� ������ ��������� ���������
{
	vector<Item> tv; // �������� ������������� �������
	for (const Item& tp : items) // ��������� ��� ��������
	{
		if (tp.select) // ���� ������� ������
			tv.push_back(tp); // ��������� �
	}
	return tv; // ����������� ������
}

void MenuFrame::pushProd(Item &itm) // ��������� ������� ������ � ������
{
	items.push_back(itm); // ��������� ������� ������ � ������
}

void MenuFrame::clearProd() // ������� ������ ������
{
	items.clear(); // ������� ������ ������
}


void ProdItem::recalc() // ��������
{
	if (itm == NULL) // �������� �� ������������� ������� ������
		return; // ������� �� ���������
	Vector2f sizef(size.x, size.y); // ������� ������
	rectobj.setSize(sizef); // �������� ������
	rectobj.setPosition(position.x, position.y); // �������� �������
	rectobj.setOutlineColor(color); // �������� ���� �������
	rectobj.setOutlineThickness(borderThicknes); // �������� ������� �������
	rectobj.setFillColor(color); // �������� ���� ����������

	capobj.setFont(font); // �������� �����
	capobj.setFillColor(Color::Black); // �������� ���� ����������
	capobj.setCharacterSize(20); // �������� ������ ������
	capobj.setString(getItem().name); // �������� ��������
	capobj.setPosition(position.x + 5, position.y); // �������� �������
	
	sumobj.setFont(font); // �������� �����
	sumobj.setFillColor(Color::Black); // �������� ���� ����������
	sumobj.setCharacterSize(20); // �������� ������ ������
	
	
	sumobj.setString(doubleToString(getItem().count, 0) + " ��  ����: " + doubleToString(getItem().price,2) + "���."); // ��������� ������ � ������ � �����������
	sumobj.setPosition(position.x + 10, position.y + 190); // �������� �������
	if (getItem().imageName != "") // �������� ������� �������� ��������
	{
		pic.loadFromFile("Menu/" + getItem().imageName); // �������� �������� �� �����
		image.setTexture(pic); // ��������� ��������
		image.setScale(0.5, 0.5); // ��������� ����������� ��������
	}

	orderBtn.setPosition(Vector2i(position.x + 10, position.y + 100)); // ��������� ������� ������ ������
	incBtn.setPosition(Vector2i(position.x + 10, position.y + 130)); // ��������� ������� ������ ����������
	decBtn.setPosition(Vector2i(position.x + 10, position.y + 160)); // ��������� ������� ������ ����������
	image.setPosition(position.x + 110, position.y + 30); // ��������� ������� ��������

	if (getItem().select == true) // ���� ������� ������
	{
		incBtn.setIsPushed(false); // ������������� ������ ���������� �� �������
		decBtn.setIsPushed(false); // ������������� ������ ��������� �� �������
		orderBtn.setText("V"); // �������� �������
	}
	else // ���
	{
		incBtn.setIsPushed(true); // ������������� ������ ���������� �������
		decBtn.setIsPushed(true); // ������������� ������ ��������� �������
		orderBtn.setText(""); // ������ �������
	}


	if (isSelected) // ���� ������� ������
		rectobj.setOutlineColor(selectedColor); // ������������ �������
	else
		rectobj.setOutlineColor(color); // �� ������������ �������
}

void ProdItem::draw(sf::RenderTarget& target, sf::RenderStates states) const //��������� ��������
{
	if (isVisible)
	{
		target.draw(rectobj, states); //��������� �����
		target.draw(capobj, states); //��������� ���������
		target.draw(sumobj, states); //��������� �����
		target.draw(orderBtn, states); //��������� ������
		target.draw(incBtn, states); //��������� ����������
		target.draw(decBtn, states); //��������� ����������
		target.draw(image, states); //��������� ��������
	}
}

ProdItem::ProdItem() // �����������
{
	btnSize.x = 20; // ������ �� �
	btnSize.y = 20; // ������ �� Y

	capobj.setString("Caption"); // ���������
	capobj.setCharacterSize(20); // ������ ������
	
	sumobj.setString("����: 200"); // ����
	sumobj.setCharacterSize(20); // ������ ������
	
	orderBtn.setSize(btnSize); // ������ ������ ������ ������
	orderBtn.setCharacterSize(15); // ������ ������
	orderBtn.setText(""); // ��� �������
	orderBtn.setTextOffSet(Vector2i(4, 0)); // �������� ������ ������������ ������

	incBtn.setSize(btnSize); // ������ ������ ����������
	incBtn.setCharacterSize(40); // ������ ������
	incBtn.setText("+"); // +
	incBtn.setIsPushed(true); // ��������� ������ �������
	incBtn.setTextOffSet(Vector2i(0, -20)); // �������� ������ ������������ ������

	decBtn.setSize(btnSize); // ������ ������ ����������
	decBtn.setCharacterSize(40); // ������ ������
	decBtn.setText("-"); // -
	decBtn.setIsPushed(true); // ��������� ������ �������
	decBtn.setTextOffSet(Vector2i(4,-20)); // �������� ������ ������������ ������
	
	


	characterSize = 180; // ������ ������
	size.x = 300; // ������ �� �
	size.y = 220; // ������ �� Y
	position.x = 0; // ������� �� �
	position.y = 0; // ������� �� Y
	color = Color::White; // ����
	borderThicknes = 5; // ������� �������
	borderColor = Color::Black; // ���� �������
	recalc(); // ��������
}

bool ProdItem::checkMouseOn(Vector2i pos) // �������� ��������� �������
{
	bool ischeck; // ���������� ��������
	ischeck = orderBtn.checkMouseOn(pos); // �������� �������� �� ������ ������ ������
	ischeck = incBtn.checkMouseOn(pos); // �������� �������� �� ������ ����������
	ischeck = decBtn.checkMouseOn(pos); // �������� �������� �� ������ ����������
	if (ischeck) // ���� ���� ��������� �������
		recalc(); // ��������
	return this->BaseItem::checkMouseOn(pos); // ����� �������� �������� ������
}
bool ProdItem::checkClick() // �������� �������
{
	bool check = false; // ���������� ��������
	if (orderBtn.getIsSelected() == true ) // ���� ��������� �� �������
	{
		if (getItem().select == false) // ���� ������� �� ������
		{
			getItem().count = 1; // ������ 1
			getItem().select = true; // � ��������
			
		}
		else
		{
			getItem().count = 0; // ������ 0
			getItem().select = false; // � �� ��������
		}
		check = true; // �������������
	}

	if (decBtn.checkClick() && getItem().select && getItem().count > 1) // �������� �� ������� ����������
	{
		getItem().count--; // ���������
		check = true; // �������������
	}
	if (incBtn.checkClick() && getItem().select) // �������� �� ������� ����������
	{
		getItem().count++; // �����������
		check = true; // �������������
	}
	if (check) // ���� �������������
		recalc(); // ��������
	return check; // ���������� ��������������
}
void ProdItem::setItem(Item &itm) // �������� �������� ������
{
	this->itm = &itm; // �������� ������ �������� ������
	isVisible = true; // ���������
}

void ProdItem::setVisibe(bool isVisible) // �������� �������� ������
{
	this->isVisible = isVisible; // �������� ������ �������� ������
}

Item& ProdItem::getItem() // ����������� �������� ������
{
	return *itm; // ������������ �������� ������
}





void InfoItem::recalc() // ��������
{
	this->BaseItem::recalc(); // �������� �������� ������
	capobj.setPosition(position.x + 10, position.y + 20); // ������� ���������
	sumobj.setPosition(position.x + 130, position.y + 20); // ������� �����
}

void InfoItem::draw(sf::RenderTarget& target, sf::RenderStates states) const //��������� ��������
{
	target.draw(rectobj, states); // ��������� 
	target.draw(capobj, states); // ��������� 
	target.draw(sumobj, states); // ��������� �����
}

InfoItem::InfoItem()
{
	characterSize = 180; // ������ ������
	size.x = 300; // ������ �� �
	size.y = 70; // ������ �� Y
	position.x = 0; // ������� �� �
	position.y = 0; // ������� �� Y
	color = Color::White; // ����
	borderThicknes = 1; // ������� �������
	borderColor = Color::Black; // ���� �������

	capobj.setFont(font); // ��������� ������
	capobj.setFillColor(Color::Black); // ��������� �����
	capobj.setString("�����:"); // ��������� ������
	
	sumobj.setFont(font); // ��������� ������
	sumobj.setFillColor(Color::Black); // ��������� �����
	sumobj.setString("0000.00"); // ��������� ������
	
	recalc(); // ��������
}

void InfoItem::SetSum(double sum) // �������� �����
{
	sumobj.setString(doubleToString(sum, 2)); // �������� ����� c ����������� �� ���� ������
}

void InfoItem::SetString(String str) // �������� ������
{
	sumobj.setString(str); // �������� ������
}

void InfoItem::SetCaption(String str) // �������� ���������
{
	capobj.setString(str); // �������� ���������
}

void OrderFrame::recalc()
{
	this->BaseItem::recalc(); // �������� �������� ������
	sumInfo.setPosition(Vector2i(position.x + 10, position.y + 55)); // ������� �����

	orderInfo.setPosition(Vector2i(position.x + 10, position.y + 130)); // ������� ������

	String sorder = ""; // ����� ������
	double sum = 0.0; // ����� ������
	for (const Item& tp : items) // ��������� �� ���� ��������� ������
	{
		sum = sum + tp.price * tp.count; // �������� ����� ������
		String st = tp.id + ".  " + tp.name + " " + doubleToString(tp.price, 2) + " � " + doubleToString(tp.count, 0) + "��. = " + doubleToString(tp.price * tp.count, 2) ; // �������� ����� ������
		sorder += st + "\n"; // ������� ������
		
	}
	orderInfo.SetString(sorder); // ��������� ����� ������
	sumInfo.SetSum(sum); // ��������� ����� ������
	addressInfo.setPosition(Vector2i(position.x + 10, position.y + 500)); // ������� ���� ������

	if (txtbuffer != NULL) // �������� �� ������� ������ � ������
	{
		String s = *txtbuffer; // �������� �����
		addressInfo.SetString(s); // �������� �����
		if (s.getSize()>10) // ���� �������� ������ 10
			appruveBtn.setIsPushed(false); // ������ �� ������
	}
	textobj.setPosition(position.x + 20, position.y + 10); // ������� ������
}

void OrderFrame::draw(sf::RenderTarget& target, sf::RenderStates states) const //��������� ��������
{
	this->BaseItem::draw(target, states);
	target.draw(sumInfo, states); // ��������� �����
	target.draw(orderInfo, states); // ��������� ������
	target.draw(addressInfo, states); // ��������� ������
	target.draw(appruveBtn, states); // ��������� ������ �������������
	target.draw(closeBtn, states); // ��������� ������ ��������
}

OrderFrame::OrderFrame()
{
	sumInfo.setSize(Vector2i(975, 70)); // ��������� �������
	
	orderInfo.setSize(Vector2i(975,365));  // ��������� �������
	orderInfo.SetCaption(" �����:"); // ��������� ���������

	addressInfo.setSize(Vector2i(975, 360)); // ��������� �������
	addressInfo.SetCaption(" �����:"); // ��������� ���������

	closeBtn.setSize(Vector2i(25, 25)); // ��������� �������
	closeBtn.setText("X"); // ��������� ������
	closeBtn.setCharacterSize(25); // ��������� ������� ������
	closeBtn.setTextOffSet(Vector2i(4, -5)); // �������� ������ ������������ ������
	closeBtn.setPosition(Vector2i(1655, 40)); // ��������� �������

	appruveBtn.setSize(Vector2i(290, 30)); // ��������� ������� ������
	appruveBtn.setText("����������� �����!"); // ��������� ������
	appruveBtn.setPosition(Vector2i(1100, 900)); // ��������� �������
	appruveBtn.setIsPushed(true); // ������ ������


	characterSize = 30; // ������ ������
	size.x = 1000; // ������ �� �
	size.y = 910; // ������ �� Y
	position.x = 0; // ������� �� �
	position.y = 0; // ������� �� Y
	text = "�����"; // �����

	textBorderColor = Color::Magenta; // ���� ������� ������
	color = Color::Black; // ����
	borderThicknes = 3; // ������� �������
	borderColor = Color::White; // ���� �������
	recalc(); // ��������
}

bool OrderFrame::checkMouseOn(Vector2i pos) // �������� ������� �������
{
	closeBtn.checkMouseOn(pos); // �������� ��������
	appruveBtn.checkMouseOn(pos); // �������� ��������
	return false; // ��������� false
}

bool OrderFrame::checkClick() // �������� �� �������
{
	bool ans = false; // ������
	ans = closeBtn.checkClick(); // �������� �� ������ ��������
	if (appruveBtn.getIsPushed() == false && appruveBtn.checkClick()) // �������� �� ������ ��������
	{
		orderStatus = true; // ������ ������
		ans = true; // ������
	}

	return ans; // ���������� ������
}

void OrderFrame::setSelectedItems(vector<Item> itms) // �������� ������ ��������� ���������
{
	this->items = itms; // ��������� ������ ��������� ������
	recalc(); // ��������
}

void OrderFrame::setTxtBuffer(String& buffer) // �������� ����� ������ ������
{
	this->txtbuffer = &buffer; // �������� ����� ������ ������
}
bool OrderFrame::getOrderStatus() // ���������� ������ ������
{
	return orderStatus; // ���������� ������ ������
}