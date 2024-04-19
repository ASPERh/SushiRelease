#include "MainWindow.h"
#include <windows.h>
#include <string>
#include <iostream>





MainWindow::MainWindow()
{
    window.create(VideoMode(1920, 1080), L"������ ����!",Style::Fullscreen); // �������� �������� SFML ����
    //Glyph::lsbDelta = 1;
    
}

void MainWindow::show() // ����� ������� ��������� ����
{
    
   
    Font font; // �������� ������
    font.loadFromFile("CyrilicOld.ttf"); // �������� ������

    Music music; // �������� ������
    music.openFromFile("main.ogg"); // �������� ������������ �����
    music.setVolume(10); // ��������� ���������
    music.play(); // ������ ������
    music.setLoop(true); // ���������� ������ �� �����

    Texture tbackground; // �������� ������� ����
    tbackground.loadFromFile("Main.png"); // �������� ������� ����
    Sprite background(tbackground); // ���������� �������� �� ������ ���
   

    Button menuBtn; // �������� ������ ����
    menuBtn.setText("����"); // ��������� ������
    menuBtn.setPosition(Vector2i(110, 845)); // ��������� �������
    
    Button exitBtn; // �������� ������ ������
    exitBtn.setText("�����"); // ��������� ������
    exitBtn.setPosition(Vector2i(110, 900)); // ��������� �������
    
    Menu tmenu; // �������� ������� ������ ����
    MenuFrame frame; // �������� ������� ����������� ����
    OrderFrame orderframe; // �������� ������� ����������� ������
    frame.setPosition(Vector2i(700, 30)); // ��������� �������
    orderframe.setPosition(Vector2i(700, 30)); // ��������� �������


    vector<Product>vp = tmenu.getProducts(); // ��������� ������� ��������� �� ������� ������
    for (const Product& tp : vp) // �������� ������ � FrameMenu
    {
        Item ti{ tp.id,tp.name,tp.price,tp.descript,tp.imageName }; // �������� ������ � FrameMenu
        frame.pushProd(ti); // �������� ������ � FrameMenu
    }
    Text hellotext("����� ���������� � ������ ����!", font, 80); // �������� ������ �����������
    hellotext.setOutlineColor(Color::Black); // ��������� ����� ��������
    hellotext.setOutlineThickness(5); // ��������� ������� ��������
    hellotext.setPosition(500, 500); // ��������� �������

    Text apruvetext("������� ��� ����� ������!", font, 80); // �������� ������ ������������� ������
    apruvetext.setOutlineColor(Color::Black); // ��������� ����� ��������
    apruvetext.setOutlineThickness(5); // ��������� ������� ��������
    apruvetext.setPosition(500, 500); // ��������� �������



    Text text("������ ����!", font, 80); // �������� ������ ���������
    text.setOutlineColor(Color::Black); // ��������� ����� ��������
    text.setOutlineThickness(5); // ��������� ������� ��������
    text.setPosition(100, 50); // ��������� �������
    
    
    String txtBuffer; // �������� ������ ��� ���������� ������
    orderframe.setTxtBuffer(txtBuffer); // �������� ������ � BorderFrame

    //mode 
    //0=���� �����������
    //1=���� ������
    //2=���� ������
    //3=���� �������������
    int mode = 0; // ����� ����
    


    while (window.isOpen()) // ������� ���� ���������
    {
        
        Event event; // �������� �������
        while (window.pollEvent(event)) // ��������� �������
        {

            switch (event.type) // �������� �� ���� �������
            {
            case Event::Closed:
                window.close(); // ������� ��������
                break;
            case Event::TextEntered: // ������� ���� ������
                
                txtBuffer += event.text.unicode; // ���������� ������ � �����
                break;
            default:
                break;
            }
            if (Keyboard::isKeyPressed(Keyboard::BackSpace)) // ��������� ������� Backspace
            {
                if (!txtBuffer.isEmpty()) // ���� ����� �� ������
                {
                    txtBuffer.erase(txtBuffer.getSize()-1, 1); // ������� ��������� ������
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::Return)) // ��������� ������� Return
            {
                txtBuffer += '\n'; // ��������� � ����� ������� ������
            }
            
            if (Mouse::isButtonPressed(Mouse::Left)) // ��������� ������� LB
            {
                if (menuBtn.checkMouseOn(Mouse::getPosition(window))) // �������� ������� �� ������ ����
                {
                    menuBtn.setIsPushed(true); // �������� ������ ���� �������
                    mode = 1; // ���������� ����� ������ (78-81 ������)
                }
                if (exitBtn.checkMouseOn(Mouse::getPosition(window))) // �������� ������� �� ������ �����
                    window.close(); // ��������� ����
                if (mode == 1) // ���� ����� ������ �� ����������� ������� � ���� ������
                {
                    if (frame.checkClick()) // ���������/�������� ������� ������� LB
                    {
                        menuBtn.setIsPushed(false); // ���� �� ������ �������� �� �������� ������ ���� �� �������
                        mode = 0; // ���������� ����� ����������� (78-81 ������)
                        if (frame.getOrderStatus()) // ���� ������ ������ ��������
                            mode = 2; // ������� � ����� ������
                    }
                }
                if (mode == 2) // ���� ����� ������ �� ����������� ������� � ���� ������
                {
                    if (orderframe.checkClick()) // ���������/�������� ������� ������� LB
                    {
                        if (orderframe.getOrderStatus()) // ���� ������ ������ �����������
                            mode = 3; // ��������� � ����� �������������
                    }
                }
            }

        }
        
        menuBtn.checkMouseOn(Mouse::getPosition(window)); // �������� ���������� ������� ��� ������� ����
        exitBtn.checkMouseOn(Mouse::getPosition(window)); // �������� ���������� ������� ��� ������� �����
        

            
        

        window.clear(); // ������� ������
        window.draw(background); // ��������� ����
        window.draw(text); // ��������� ���������
        window.draw(menuBtn); // ��������� ������ ����
        window.draw(exitBtn); // ��������� ������ ������
        
        
        switch (mode) // ��������� ������
        {
        case 0: // ���� 0 �� ����� �����������
            window.draw(hellotext); // ��������� ������ �����������
            break;
        case 1: // ���� 1 �� ����� ������
            frame.checkMouseOn(Mouse::getPosition(window)); // ���������/�������� ���������� ������� ��� ���������
            window.draw(frame); // ��������� ����� ������
            break;
        case 2: // ���� 2 �� ����� ������
            orderframe.checkMouseOn(Mouse::getPosition(window)); // ���������/�������� ���������� ������� ��� ���������
            orderframe.setSelectedItems(frame.getSelectedItems()); // �������� ��������� ������ � ����� ������ �� ����� ������
            window.draw(orderframe); // ��������� ����� ������
            break;
        case 3: // ���� 3 �� ����� �������������
            window.draw(apruvetext); // ��������� ������ �������������
            frame.clearProd(); // ������� �������
            for (const Product& tp : vp) // ������������ �������� ������ � FrameMenu
            {
                Item ti{ tp.id,tp.name,tp.price,tp.descript,tp.imageName }; // ������� ������
                frame.pushProd(ti); // ����� ������
                
            }
            break;
        default:
            window.draw(apruvetext); // ��������� ������ �������������
            
        }
        window.display(); // ��������� �������� ����
    }
}