#include "include.h"

#include <algorithm>

struct Product { // ��������� ������ ��������
    int id; // ��
    string name; // ��������
    double price; // ����
    string descript; // ��������
    string imageName; // �������� ��������
};

class Menu // ���������� ������ ����
{
private:
	vector<Product> menu; // ������ ������
	string path; // ����
	void setExePath(); // ��������� ���� � .EXE ����� 
public:
	Menu(); // ����������� ������

	vector<Product> getProducts(); // ��������� ������ ���������
	Product getProduct(int id); // �������� �������� �� ��
	string getProductPath(int id); // ��������� ���� ��� ��������
};