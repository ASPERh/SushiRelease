#include "Items.h"

string doubleToString(double number, int precision) {
	ostringstream stream; // Создаем объект потока для конвертации данных в строку
	stream.precision(precision); // Устанавливаем точность (количество знаков после запятой) для вывода числа
	stream << fixed << number; // Помещаем число в поток с фиксированной точкой что означает фиксированное количество знаков после десятичной запятой
	return stream.str(); // Возвращаем содержимое потока в виде строки
}

void Button::recalc() // пересчет
{
	this->BaseItem::recalc(); // вызов пересчета базового класса
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const //отрисовка обьектов
{
	this->BaseItem::draw(target, states); // вызов отрисовки базового класса
}


Button::Button() // конструктор кнопки
{
	characterSize = 30; // размер шрифта
	size.x = 100; // размер по Х
	size.y = 30; // размер по Y
	position.x = 0; // позиция по X
	position.y = 0; //позиция по Y
	text = "Button"; // текст
	color = Color(0, 102, 102); // цвет кнопки по умолчанию 
	selectedColor = Color::Cyan; // цвет при наводки на кнопку
	pushedColor = Color(100, 100, 100); // цвет нажатия на кнопку
	borderThicknes = 3; // толщина границы
	borderColor = Color::Black; // цвет границы
	recalc(); // пересчет
}

void MenuFrame::recalc() //отрисовка обьектов
{
	itmobj1.setVisibe(false); // установка невидимости обьекта 1
	itmobj2.setVisibe(false); // установка невидимости обьекта 2
	itmobj3.setVisibe(false); // установка невидимости обьекта 3
	itmobj4.setVisibe(false); // установка невидимости обьекта 4
	itmobj5.setVisibe(false); // установка невидимости обьекта 5
	itmobj6.setVisibe(false); // установка невидимости обьекта 6
	itmobj7.setVisibe(false); // установка невидимости обьекта 7
	itmobj8.setVisibe(false); // установка невидимости обьекта 8
	itmobj9.setVisibe(false); // установка невидимости обьекта 9
	
	float s = items.size(); // получение количество данных обьектов
	numPages = ceil (s / 9); // количество страниц
	int numProd = items.size() % 9; // количество продуктов на последней странице
	int minProd = 0; // стартовая продукт отображения
	int maxProd = 9; // конечнная продукт отображения
	if (curPage > 1)
		minProd = minProd + 9 * (numPages - 1); // вычесляем стартовый продукт для страницы
	if (curPage == numPages) // проверка страницы
		maxProd = minProd + numProd; // вычесляем конечнный продукт для страницы

	if (items.size() > 0) // если обьект данных бюльше нуля то начинается заполнение
	{
		if (minProd < maxProd && items.size() > minProd) // заполнение
			itmobj1.setItem(items[minProd]); // заполнение
		if (minProd + 1 < maxProd && items.size() > minProd+1) // заполнение
			itmobj2.setItem(items[minProd + 1]); // заполнение
		if (minProd + 2 < maxProd && items.size() > minProd+2) // заполнение
			itmobj3.setItem(items[minProd + 2]); // заполнение
		if (minProd + 3 < maxProd && items.size() > minProd+3) // заполнение
			itmobj4.setItem(items[minProd + 3]); // заполнение
		if (minProd + 4 < maxProd && items.size() > minProd+4) // заполнение
			itmobj5.setItem(items[minProd + 4]); // заполнение
		if (minProd + 5 < maxProd && items.size() > minProd+5) // заполнение
			itmobj6.setItem(items[minProd + 5]); // заполнение
		if (minProd + 6 < maxProd && items.size() > minProd+6) // заполнение
			itmobj7.setItem(items[minProd + 6]); // заполнение
		if (minProd + 7 < maxProd && items.size() > minProd+7) // заполнение
			itmobj8.setItem(items[minProd + 7]); // заполнение
		if (minProd + 8 < maxProd && items.size() > minProd+8) // заполнение
			itmobj9.setItem(items[minProd + 8]); // заполнение
	}

	if (curPage == 1) // если выбрана первая страница
		prevBtn.setIsPushed(true); // кнопка предыдущей страницы устанавливается нажатой
	else
		prevBtn.setIsPushed(false); // или кнопка предыдущей страницы устанавливается не нажатой

	if (curPage == numPages) // если текущая страница является последней
		nextBtn.setIsPushed(true); // кнопка следующей страницы устанавливается нажатой
	else
		nextBtn.setIsPushed(false); // или кнопка следующей страницы устанавливается не нажатой

	double sum = 0.0; // цена по умолчанию
	for (const Item& tp : items) // вычесляем сумму всех выбранных элементов
	{
		if (tp.select) // если элемент выбран
			sum = sum + tp.price * tp.count; // добавляем к сумме
	}
	info.SetSum(sum); // передаем в обьект Info
	if (sum > 0.0) // если цена больше нуля
		orderBtn.setIsPushed(false); // кнопка заказа устанавливается не нажатой
	else
		orderBtn.setIsPushed(true); // кнопка заказа устанавливается нажатой


	this->BaseItem::recalc(); // вызов пересчета базового класса
	textobj.setPosition(position.x + 20, position.y + 10 ); // отрисовка текста
}

void MenuFrame::draw(sf::RenderTarget& target, sf::RenderStates states) const //отрисовка обьектов
{
	this->BaseItem::draw(target, states); // вызов отрисовки базового класса

	target.draw(itmobj1, states); //отрисовка обьекта 1
	target.draw(itmobj2, states); //отрисовка обьекта 2
	target.draw(itmobj3, states); //отрисовка обьекта 3
	target.draw(itmobj4, states); //отрисовка обьекта 4
	target.draw(itmobj5, states); //отрисовка обьекта 5
	target.draw(itmobj6, states); //отрисовка обьекта 6
	target.draw(itmobj7, states); //отрисовка обьекта 7
	target.draw(itmobj8, states); //отрисовка обьекта 8
	target.draw(itmobj9, states); //отрисовка обьекта 9

	target.draw(prevBtn, states); //отрисовка кнопки назад
	target.draw(nextBtn, states); //отрисовка кнопки вперед
	target.draw(orderBtn, states); //отрисовка кнопки заказа
	target.draw(closeBtn, states); //отрисовка кнопки закрытия
	
	target.draw(info, states); // отрисовка обьекта Info
	
}

MenuFrame::MenuFrame() // конструктор
{
	//Значения по умолчанию
	curPage = 1; // текущая страница
	orderStatus = false; // статус заказа
	info.setPosition(Vector2i(720, 845)); // установка позиции

	prevBtn.setText("Пред."); // текст кнопки пред.
	prevBtn.setPosition(Vector2i(1090, 865)); // установка позиции

	nextBtn.setText("След."); // текст кнопки след.
	nextBtn.setPosition(Vector2i(1210, 865)); // установка позиции
	nextBtn.setIsPushed(true); // устанавливаем кнопку след. нажатой

	orderBtn.setSize(Vector2i(150, 30)); // установка размера кнопки заказать
	orderBtn.setText("Заказать!"); // текст кнопки заказать
	orderBtn.setPosition(Vector2i(1480, 865)); // установка позиции
	orderBtn.setIsPushed(true); // устанавливаем кнопку заказать нажатой

	closeBtn.setSize(Vector2i(25, 25)); // установка размера кнопки закрыть
	closeBtn.setText("X"); // текст кнопки закрыть
	closeBtn.setCharacterSize(25); // установка размера текста кнопки закрыть
	closeBtn.setTextOffSet(Vector2i(4,-5)); // установка смещения текста относительно кнопки
	closeBtn.setPosition(Vector2i(1655, 40)); // установка позиции
	


	itmobj1.setPosition(Vector2i(720, 100)); // установка позиции
	itmobj2.setPosition(Vector2i(1050, 100)); // установка позиции
	itmobj3.setPosition(Vector2i(1380, 100)); // установка позиции
	itmobj4.setPosition(Vector2i(720, 350)); // установка позиции
	itmobj5.setPosition(Vector2i(1050, 350)); // установка позиции
	itmobj6.setPosition(Vector2i(1380, 350)); // установка позиции
	itmobj7.setPosition(Vector2i(720, 600)); // установка позиции
	itmobj8.setPosition(Vector2i(1050,600)); // установка позиции
	itmobj9.setPosition(Vector2i(1380, 600)); // установка позиции
	
	
	characterSize = 30; // установка размера шрифта
	size.x = 1000; //размер по Х
	size.y = 910; // размер по Y
	position.x = 0; //позиция по X
	position.y = 0; //позиция по Y
	text = "Меню"; //текст меню
	textBorderColor = Color::Magenta; // цвет границы шрифта
	color = Color::Black; // цвет
	borderThicknes = 3; // толщина границы
	borderColor = Color::White; // цвет границы
	recalc(); // пересчет
}

bool MenuFrame::checkMouseOn(Vector2i pos) // проверка события наведении курсора
{
	prevBtn.checkMouseOn(pos); // передача проверки события
	nextBtn.checkMouseOn(pos); // передача проверки события
	orderBtn.checkMouseOn(pos); // передача проверки события
	closeBtn.checkMouseOn(pos); // передача проверки события

	itmobj1.checkMouseOn(pos); // передача проверки события
	itmobj2.checkMouseOn(pos); // передача проверки события
	itmobj3.checkMouseOn(pos); // передача проверки события
	itmobj4.checkMouseOn(pos); // передача проверки события
	itmobj5.checkMouseOn(pos); // передача проверки события
	itmobj6.checkMouseOn(pos); // передача проверки события
	itmobj7.checkMouseOn(pos); // передача проверки события
	itmobj8.checkMouseOn(pos); // передача проверки события
	itmobj9.checkMouseOn(pos); // передача проверки события


	return false; // возвращается false
}

bool MenuFrame::checkClick() // проверка события нажатия
{
	if (prevBtn.checkClick() && curPage > 1) // проверка на возможность уменьшения страницы
		curPage--; // уменьшение страницы
	if (nextBtn.checkClick() && curPage < numPages) // проверка на возможность увелечения страницы
		curPage++; // увелечение страницы

	itmobj1.checkClick(); // передача проверки нажатия
	itmobj2.checkClick(); // передача проверки нажатия
	itmobj3.checkClick(); // передача проверки нажатия
	itmobj4.checkClick(); // передача проверки нажатия
	itmobj5.checkClick(); // передача проверки нажатия
	itmobj6.checkClick(); // передача проверки нажатия
	itmobj7.checkClick(); // передача проверки нажатия
	itmobj8.checkClick(); // передача проверки нажатия
	itmobj9.checkClick(); // передача проверки нажатия
	
	recalc(); // пересчет
	bool ans=false; // отклик
	ans = closeBtn.checkClick(); // проверка на нажатие кнопки close
	if (orderBtn.getIsPushed()==false && orderBtn.checkClick()) // проверяем на нажатие кнопки order
	{
		orderStatus = true; // назначение статуса заказа
		ans = true; // назначение отклика
	}
	
	return ans; // возвращение отклик
}
bool MenuFrame::getOrderStatus() // получение статуса заказа
{

	return orderStatus; // возвращение статуса заказа
}

vector<Item> MenuFrame::getSelectedItems() // получение вектора данных выбранных элементов
{
	vector<Item> tv; // создание возвращаемого обьекта
	for (const Item& tp : items) // пробегаем все элементы
	{
		if (tp.select) // если элемент выбран
			tv.push_back(tp); // добавляем в
	}
	return tv; // возращаемый обьект
}

void MenuFrame::pushProd(Item &itm) // добавляем элемент данных в вектор
{
	items.push_back(itm); // добавляем элемент данных в вектор
}

void MenuFrame::clearProd() // очищаем вектор данных
{
	items.clear(); // очищаем вектор данных
}


void ProdItem::recalc() // пересчет
{
	if (itm == NULL) // проверка на существование обьекта данных
		return; // выходим из пересчета
	Vector2f sizef(size.x, size.y); // создаем размер
	rectobj.setSize(sizef); // передаем размер
	rectobj.setPosition(position.x, position.y); // передаем позицию
	rectobj.setOutlineColor(color); // передаем цвет границы
	rectobj.setOutlineThickness(borderThicknes); // передаем толщину границы
	rectobj.setFillColor(color); // передаем цвет заполнения

	capobj.setFont(font); // передаем шрифт
	capobj.setFillColor(Color::Black); // передаем цвет заполнения
	capobj.setCharacterSize(20); // передаем размер шрифта
	capobj.setString(getItem().name); // передаем название
	capobj.setPosition(position.x + 5, position.y); // передаем позицию
	
	sumobj.setFont(font); // передаем шрифт
	sumobj.setFillColor(Color::Black); // передаем цвет заполнения
	sumobj.setCharacterSize(20); // передаем размер шрифта
	
	
	sumobj.setString(doubleToString(getItem().count, 0) + " шт  Цена: " + doubleToString(getItem().price,2) + "грн."); // заполняем строку с суммой и количеством
	sumobj.setPosition(position.x + 10, position.y + 190); // передаем позицию
	if (getItem().imageName != "") // проверка наличия название картинки
	{
		pic.loadFromFile("Menu/" + getItem().imageName); // загрузка картинки из файла
		image.setTexture(pic); // установка текстуры
		image.setScale(0.5, 0.5); // установка соотношения картинки
	}

	orderBtn.setPosition(Vector2i(position.x + 10, position.y + 100)); // установка позиции кнопки заказа
	incBtn.setPosition(Vector2i(position.x + 10, position.y + 130)); // установка позиции кнопки увеличения
	decBtn.setPosition(Vector2i(position.x + 10, position.y + 160)); // установка позиции кнопки уменьшения
	image.setPosition(position.x + 110, position.y + 30); // установка позиции картинки

	if (getItem().select == true) // если элемент выбран
	{
		incBtn.setIsPushed(false); // устанавливаем кнопку увелечения не нажатой
		decBtn.setIsPushed(false); // устанавливаем кнопку уменьшить не нажатой
		orderBtn.setText("V"); // ставится галочка
	}
	else // или
	{
		incBtn.setIsPushed(true); // устанавливаем кнопку увелечения нажатой
		decBtn.setIsPushed(true); // устанавливаем кнопку уменьшить нажатой
		orderBtn.setText(""); // убрать галочку
	}


	if (isSelected) // если элемент выбран
		rectobj.setOutlineColor(selectedColor); // подсвечеваем границу
	else
		rectobj.setOutlineColor(color); // не подсвечеваем границу
}

void ProdItem::draw(sf::RenderTarget& target, sf::RenderStates states) const //отрисовка обьектов
{
	if (isVisible)
	{
		target.draw(rectobj, states); //отрисовка рамки
		target.draw(capobj, states); //отрисовка заголовка
		target.draw(sumobj, states); //отрисовка суммы
		target.draw(orderBtn, states); //отрисовка заказа
		target.draw(incBtn, states); //отрисовка увелечения
		target.draw(decBtn, states); //отрисовка уменьшения
		target.draw(image, states); //отрисовка картинки
	}
}

ProdItem::ProdItem() // конструктор
{
	btnSize.x = 20; // размер по Х
	btnSize.y = 20; // размер по Y

	capobj.setString("Caption"); // заголовок
	capobj.setCharacterSize(20); // размер шрифта
	
	sumobj.setString("Цена: 200"); // цена
	sumobj.setCharacterSize(20); // размер шрифта
	
	orderBtn.setSize(btnSize); // размер кнопки выбора заказа
	orderBtn.setCharacterSize(15); // размер шрифта
	orderBtn.setText(""); // нет галочки
	orderBtn.setTextOffSet(Vector2i(4, 0)); // смещение текста относительно кнопки

	incBtn.setSize(btnSize); // размер кнопки увелечения
	incBtn.setCharacterSize(40); // размер шрифта
	incBtn.setText("+"); // +
	incBtn.setIsPushed(true); // установка кнопки нажатой
	incBtn.setTextOffSet(Vector2i(0, -20)); // смещение текста относительно кнопки

	decBtn.setSize(btnSize); // размер кнопки уменьшения
	decBtn.setCharacterSize(40); // размер шрифта
	decBtn.setText("-"); // -
	decBtn.setIsPushed(true); // установка кнопки нажатой
	decBtn.setTextOffSet(Vector2i(4,-20)); // смещение текста относительно кнопки
	
	


	characterSize = 180; // размер шрифта
	size.x = 300; // размер по Х
	size.y = 220; // размер по Y
	position.x = 0; // позиция по Х
	position.y = 0; // позиция по Y
	color = Color::White; // цвет
	borderThicknes = 5; // толщина границы
	borderColor = Color::Black; // цвет границы
	recalc(); // пересчет
}

bool ProdItem::checkMouseOn(Vector2i pos) // проверка наведение курсора
{
	bool ischeck; // переменная проверки
	ischeck = orderBtn.checkMouseOn(pos); // передаем проверку на кнопку выбора заказа
	ischeck = incBtn.checkMouseOn(pos); // передаем проверку на кнопку увелечения
	ischeck = decBtn.checkMouseOn(pos); // передаем проверку на кнопку уменьшения
	if (ischeck) // если есть наведение курсора
		recalc(); // пересчет
	return this->BaseItem::checkMouseOn(pos); // вызов проверки базового класса
}
bool ProdItem::checkClick() // проверка нажатия
{
	bool check = false; // переменная проверки
	if (orderBtn.getIsSelected() == true ) // если наведенно на галочку
	{
		if (getItem().select == false) // если элемент не выбран
		{
			getItem().count = 1; // задаем 1
			getItem().select = true; // и выделяем
			
		}
		else
		{
			getItem().count = 0; // задаем 0
			getItem().select = false; // и не выделяем
		}
		check = true; // пересчитываем
	}

	if (decBtn.checkClick() && getItem().select && getItem().count > 1) // проверка на нажатия уменьшения
	{
		getItem().count--; // уменьшаем
		check = true; // пересчитываем
	}
	if (incBtn.checkClick() && getItem().select) // проверка на нажатия увелечения
	{
		getItem().count++; // увеличиваем
		check = true; // пересчитываем
	}
	if (check) // если пересчитываем
		recalc(); // пересчет
	return check; // возвращаем пересчитывание
}
void ProdItem::setItem(Item &itm) // передача элемента данных
{
	this->itm = &itm; // передача ссылки элемента данных
	isVisible = true; // видимость
}

void ProdItem::setVisibe(bool isVisible) // передача элемента данных
{
	this->isVisible = isVisible; // передача ссылки элемента данных
}

Item& ProdItem::getItem() // возврщаение элемента данных
{
	return *itm; // возвращаение элемента данных
}





void InfoItem::recalc() // пересчет
{
	this->BaseItem::recalc(); // пересчет базового класса
	capobj.setPosition(position.x + 10, position.y + 20); // позиция заголовка
	sumobj.setPosition(position.x + 130, position.y + 20); // позиция суммы
}

void InfoItem::draw(sf::RenderTarget& target, sf::RenderStates states) const //отрисовка обьектов
{
	target.draw(rectobj, states); // отрисовка 
	target.draw(capobj, states); // отрисовка 
	target.draw(sumobj, states); // отрисовка суммы
}

InfoItem::InfoItem()
{
	characterSize = 180; // размер шрифта
	size.x = 300; // размер по Х
	size.y = 70; // размер по Y
	position.x = 0; // позиция по Х
	position.y = 0; // позиция по Y
	color = Color::White; // цвет
	borderThicknes = 1; // толщина границы
	borderColor = Color::Black; // цвет границы

	capobj.setFont(font); // установка шрифта
	capobj.setFillColor(Color::Black); // установка цвета
	capobj.setString("Сумма:"); // установка текста
	
	sumobj.setFont(font); // установка шрифта
	sumobj.setFillColor(Color::Black); // установка цвета
	sumobj.setString("0000.00"); // установка текста
	
	recalc(); // пересчет
}

void InfoItem::SetSum(double sum) // передача суммы
{
	sumobj.setString(doubleToString(sum, 2)); // передача суммы c округлением до двух знаков
}

void InfoItem::SetString(String str) // передача строки
{
	sumobj.setString(str); // передача строки
}

void InfoItem::SetCaption(String str) // передача заголовка
{
	capobj.setString(str); // передача заголовка
}

void OrderFrame::recalc()
{
	this->BaseItem::recalc(); // пересчет базового класса
	sumInfo.setPosition(Vector2i(position.x + 10, position.y + 55)); // позиция суммы

	orderInfo.setPosition(Vector2i(position.x + 10, position.y + 130)); // позиция заказа

	String sorder = ""; // текст заказа
	double sum = 0.0; // сумма заказа
	for (const Item& tp : items) // пробегаем по всем элементам заказа
	{
		sum = sum + tp.price * tp.count; // собираем сумму заказа
		String st = tp.id + ".  " + tp.name + " " + doubleToString(tp.price, 2) + " х " + doubleToString(tp.count, 0) + "шт. = " + doubleToString(tp.price * tp.count, 2) ; // собираем текст заказа
		sorder += st + "\n"; // перенос строки
		
	}
	orderInfo.SetString(sorder); // добавляем текст заказа
	sumInfo.SetSum(sum); // добавляем сумму заказа
	addressInfo.setPosition(Vector2i(position.x + 10, position.y + 500)); // позиция поля адреса

	if (txtbuffer != NULL) // проверка на наличие текста в буфере
	{
		String s = *txtbuffer; // приводим буфер
		addressInfo.SetString(s); // передаем буфер
		if (s.getSize()>10) // если символов меньше 10
			appruveBtn.setIsPushed(false); // кнопка не нажата
	}
	textobj.setPosition(position.x + 20, position.y + 10); // позиция текста
}

void OrderFrame::draw(sf::RenderTarget& target, sf::RenderStates states) const //отрисовка обьектов
{
	this->BaseItem::draw(target, states);
	target.draw(sumInfo, states); // отрисовка суммы
	target.draw(orderInfo, states); // отрисовка заказа
	target.draw(addressInfo, states); // отрисовка адреса
	target.draw(appruveBtn, states); // отрисовка кнопки подтверждения
	target.draw(closeBtn, states); // отрисовка кнопки закрытия
}

OrderFrame::OrderFrame()
{
	sumInfo.setSize(Vector2i(975, 70)); // установка размера
	
	orderInfo.setSize(Vector2i(975,365));  // установка размера
	orderInfo.SetCaption(" Заказ:"); // установка заголовка

	addressInfo.setSize(Vector2i(975, 360)); // установка размера
	addressInfo.SetCaption(" Адрес:"); // установка заголовка

	closeBtn.setSize(Vector2i(25, 25)); // установка размера
	closeBtn.setText("X"); // установка текста
	closeBtn.setCharacterSize(25); // установка размера текста
	closeBtn.setTextOffSet(Vector2i(4, -5)); // смещение текста относительно кнопки
	closeBtn.setPosition(Vector2i(1655, 40)); // установка позиции

	appruveBtn.setSize(Vector2i(290, 30)); // установка размера шрифта
	appruveBtn.setText("Подтвердить Заказ!"); // установка текста
	appruveBtn.setPosition(Vector2i(1100, 900)); // установка позиции
	appruveBtn.setIsPushed(true); // кнопка нажата


	characterSize = 30; // размер шрифта
	size.x = 1000; // размер по Х
	size.y = 910; // размер по Y
	position.x = 0; // позиция по Х
	position.y = 0; // позиция по Y
	text = "Заказ"; // текст

	textBorderColor = Color::Magenta; // цвет границы текста
	color = Color::Black; // цвет
	borderThicknes = 3; // толщина границы
	borderColor = Color::White; // цвет границы
	recalc(); // пересчет
}

bool OrderFrame::checkMouseOn(Vector2i pos) // проверка наводки курсора
{
	closeBtn.checkMouseOn(pos); // передача проверки
	appruveBtn.checkMouseOn(pos); // передача проверки
	return false; // возрвщаем false
}

bool OrderFrame::checkClick() // проверка на нажатие
{
	bool ans = false; // отклик
	ans = closeBtn.checkClick(); // проверка на кнопку закрытия
	if (appruveBtn.getIsPushed() == false && appruveBtn.checkClick()) // проверка на кнопку заказать
	{
		orderStatus = true; // статус заказа
		ans = true; // отклик
	}

	return ans; // возвращаем отклик
}

void OrderFrame::setSelectedItems(vector<Item> itms) // передаем вектор выбранных элементов
{
	this->items = itms; // назначаем вектор выбранных данных
	recalc(); // пересчет
}

void OrderFrame::setTxtBuffer(String& buffer) // передаем буфер набора текста
{
	this->txtbuffer = &buffer; // назначем буфер обмена текста
}
bool OrderFrame::getOrderStatus() // возвращаем статус заказа
{
	return orderStatus; // возвращаем статус заказа
}