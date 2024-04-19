#include "include.h"
#include "BaseItem.h"

class Item  //��������� Item 
{
public:
	int id; // ��
	string name; //���
	double price; //����
	string descript;//��������
	string imageName; //��� ��������
	int count; //����������
	bool select; //���� ������
};


class Button : public BaseItem
{
private:
	void recalc();//��������
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //��������� ��������

public:
	Button(); // �����������
};


class ProdItem : public BaseItem
{
private:

	Item *itm; //������ �� ����� ������
	
	Vector2i btnSize; // ������ �� x � y
	Text capobj; //������ ���������
	Text sumobj; //������ �����
	
	Button orderBtn; // ������ ������
	Button incBtn; // ������ ����������
	Button decBtn; // ������ ����������
	Texture pic; // ��������
	Sprite image; // ������ ��� ��������

	bool isVisible; // �������/���������
 
	void recalc(); // ��������

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //��������� ��������

public:
	ProdItem(); // �����������
	bool checkMouseOn(Vector2i pos); //����� ��� ����������� ���������� ������� �� �������
	bool checkClick(); //����� ��� ����������� ������� �� �������
	void setItem(Item &itm); //����� ��� �������� ������� ������
	void setVisibe(bool isVisible); //����� ��� ��������� ���������
	Item& getItem(); // ��������� ������� ������
};

class InfoItem : public BaseItem // 
{
private:
	Text capobj; //������ ���������
	Text sumobj; //������ �����
	void recalc(); // ��������
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //��������� ��������

public:
	InfoItem(); // �����������
	void SetSum(double sum); // ������ ����
	void SetString(String str); // ������ ������
	void SetCaption(String str); // ������ ���������
};

class MenuFrame : public BaseItem
{
private:

	vector <Item> items; // ������ ������
	
	InfoItem info; // ����������� �����

	Button nextBtn; // ������ ��������� ��������
	Button prevBtn; // ������ ���������� ��������
	Button orderBtn; // ������ ������
	Button closeBtn; // ������ ��������

	ProdItem itmobj1; // ������ 1
	ProdItem itmobj2; // ������ 2
	ProdItem itmobj3; // ������ 3
	ProdItem itmobj4; // ������ 4
	ProdItem itmobj5; // ������ 5
	ProdItem itmobj6; // ������ 6
	ProdItem itmobj7; // ������ 7
	ProdItem itmobj8; // ������ 8
	ProdItem itmobj9; // ������ 9
	
	int curPage; // ������� ��������
	int numPages; // ���������� �������
	
	bool orderStatus; // ������ ������

	void recalc(); // ��������
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //��������� ��������

public:
	MenuFrame(); // �����������
	bool checkMouseOn(Vector2i pos); //����� ��� ����������� ���������� ������� �� �������
	bool checkClick(); //����� ��� ����������� ������� �� �������
	bool getOrderStatus(); // �������� ������� ������
	void pushProd(Item &itm); // ����� ������ ������
	void clearProd(); // ������� ������
	vector <Item> getSelectedItems(); // �������� ������ ��������� ������
};

class OrderFrame : public BaseItem
{
private:

	vector <Item> items; // ������ ������

	InfoItem sumInfo; // ���������� �����
	InfoItem orderInfo; // ���������� ������
	InfoItem addressInfo; // ���������� ������
	Button appruveBtn; // ������ �������������
	Button closeBtn; // ������ ��������
	String* txtbuffer; // ����� ��� ����� ������

	bool orderStatus; // ������ ������

	void recalc(); // ��������
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //��������� ��������

public:
	OrderFrame(); // �����������
	bool checkMouseOn(Vector2i pos); //����� ��� ����������� ���������� ������� �� �������
	bool checkClick(); //����� ��� ����������� ������� �� �������
	bool getOrderStatus(); // �������� ������� ������
	void setSelectedItems(vector <Item> itms); // �������� ������ ������
	void setTxtBuffer(String  &buffer); // ������������� ����� ��� ����� ������
	
};