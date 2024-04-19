//����� ���� ��� �������� ��������
#include "include.h"


class BaseItem :
    public Drawable //��������� BaseItem ��������� �� Drawable
{
private:
protected:
	Vector2i position; // ������� �������� �������� Vector2i �� x � y
	Vector2i size; // ������ �� x � y
	Vector2i textOffSet; //������ ������ �� x � y
	string text; //�����
	Color color; //���� 
	Color selectedColor; //���� ��� ��������� ����
	Color pushedColor; //���� ������� ������
	int borderThicknes; //������� ������
	Color borderColor; //���� ������
	Color textBorderColor; //���� ������ ������
	Font font; //�����
	int characterSize; //������ ������
	RectangleShape rectobj; //������ �������������
	Text textobj; //������ �����
	
	bool isSelected = false; //������ ������� 
	bool isPushed = false; //������ �����

	virtual void recalc(); //����� ��� ��������� rectobj � textobj
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //��������� ��������
public:
	BaseItem();

	void setPosition(Vector2i position); //����� ��� ���������� �������
	void setSize(Vector2i  size); //����� ��� ���������� �������
	void setText(string  text); //����� ��� ���������� ������
	void setTextOffSet(Vector2i  textOffSet); //����� ��� ���������� ������� ������
	void setBorderThicknes(int borderThicknes); //����� ��� ���������� ������� ������
	void setBorderColor(Color borderColor); //����� ��� ���������� ����� ������
	void setTextBorderColor(Color borderColor); //����� ��� ���������� ����� ������ ������
	void setFont(Font font); //����� ��� ���������� ������
	void setCharacterSize(int characterSize); //����� ��� ���������� ������� ������
	void setColor(Color color); //����� ��� ���������� �����
	void setSelectedColor(Color selectedColor); //����� ��� ���������� ����� ���������
	virtual bool checkMouseOn(Vector2i pos); //����� ��� ����������� ���������� ������� �� �������
	virtual bool checkClick(); //����� ��� ����������� ������� �� �������
	void setIsSelected(bool isSelected); //����� ��� ��������� ���������� ������� �� �������
	bool getIsSelected(); //����� ��� ��������� ���������� ������� �� �������
	void setIsPushed(bool isPushed); //����� ��� ��������� ��������� �������
	bool getIsPushed(); //����� ��� ��������� ��������� �������
	string getText(); //����� ��� ��������� ������

};