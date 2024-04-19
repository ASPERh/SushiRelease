#include "Menu.h"
#include "Windows.h"
#include <algorithm>


void Menu::setExePath() // ������� ��� ��������� ���� � ������������ ����� (.EXE)
{
    TCHAR buffer[MAX_PATH] = { 0 }; // �������� ������ ��� �������� ���� � �����
    GetModuleFileName(NULL, buffer, MAX_PATH); // ��������� ���� � ������������ ����� � ���������� ��� � ������
    wstring::size_type pos = wstring(buffer).find_last_of(L"\\/"); // ������� ��������� ���� ��� �������� ���� � ������
    wstring wpath = wstring(buffer).substr(0, pos); // �������� ��������� �� ������ �� ���������� ����� ��� ����� ���� � ����������
    size_t size; // ���������� ��� �������� �������
    path.resize(wpath.length()); // �������� ������ ������� path ��� �������� ����
    wcstombs_s(&size, &path[0], path.size() + 1, wpath.c_str(), wpath.size()); // �������������� ������� ������ � ������������� � ���������� � ������ path
}

Menu::Menu() // ����� ����
{
    setExePath(); // ��������� ���� .EXE �����
    
    ifstream file(path + "\\Menu\\Menu.txt"); // ��������� ���� ����.���
    if (!file) // ��������� �� �������� �����
    {
        cout << "������ �������� ����\n"; // ���������� ������
        exit(1); // ����� � ������� 1
    }


    string line = ""; // �������� ����������
    while (getline(file, line)) { // ��������� ������ �� �����

        stringstream iString(line); // ����������� ������ String � Stringstream

        int id; // ����
        string name; // ���
        double price; // ����
        string descript; // ��������
        string iname; // ��� ��������
        string tempString; // ��������� ������

        getline(iString, tempString, '#'); // �� ������� �����������
        id = atoi(tempString.c_str()); // ���������/������������� � id 
        getline(iString, name, '#'); // �� ������� ����������� �������� ���
        getline(iString, tempString, '#'); // �� �������� �����������
        price = atof(tempString.c_str()); // �������� ����

        getline(iString, descript, '#'); // �� ���������� ����������� �������� ��������

        getline(iString, iname, '#'); // �� ������ ����������� �������� �������� ��������


        Product tSushi{ id, name, price, descript, iname }; // ������� ������ ������

        menu.push_back(tSushi); // ����� � ������
        line = ""; // �������� ������ 

    }

    file.close(); // ��������� ����
}

vector<Product> Menu::getProducts() // ��������� ������� ������
{
    return this->menu; // ������� ������ ����
}

Product Menu::getProduct(int id) // ��������� �������� �� ������� �� �������
{
    Product p{ 0, "", 0.0, "", "" }; // ������ ������
    for (const Product& tprod : menu) // ��������� �� ������� ����
    {
        if (tprod.id == id) // ��������� ����
        {
            return tprod; // ��������� ��������� ������
        }
        
    }
    return p; // ��������� ������ ������
}

string Menu::getProductPath(int id) // ��������� ���� � ��������
{
    return  path + "\\Menu\\" + getProduct(id).imageName; // ������������ ���� � ��������
}