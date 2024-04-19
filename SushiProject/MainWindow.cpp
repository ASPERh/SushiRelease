#include "MainWindow.h"
#include <windows.h>
#include <string>
#include <iostream>





MainWindow::MainWindow()
{
    window.create(VideoMode(1920, 1080), L"Сакура суши!",Style::Fullscreen); // Создание главного SFML окна
    //Glyph::lsbDelta = 1;
    
}

void MainWindow::show() // Метод запуска отрисовки окна
{
    
   
    Font font; // создание шрифта
    font.loadFromFile("CyrilicOld.ttf"); // загрузка шрифта

    Music music; // создание музыки
    music.openFromFile("main.ogg"); // загрузка музыкального файла
    music.setVolume(10); // настройка громкости
    music.play(); // запуск музыки
    music.setLoop(true); // повторение музыки по кругу

    Texture tbackground; // создание заднего фона
    tbackground.loadFromFile("Main.png"); // текстуры заднего фона
    Sprite background(tbackground); // добавление текстуры на задней фон
   

    Button menuBtn; // создание кнопки меню
    menuBtn.setText("Меню"); // установка текста
    menuBtn.setPosition(Vector2i(110, 845)); // установка позиции
    
    Button exitBtn; // создание кнопки выхода
    exitBtn.setText("Выход"); // установка текста
    exitBtn.setPosition(Vector2i(110, 900)); // установка позиции
    
    Menu tmenu; // создание обьекта данных меню
    MenuFrame frame; // создание обьекта отображения меню
    OrderFrame orderframe; // создание обьекта отображения заказа
    frame.setPosition(Vector2i(700, 30)); // установка позиции
    orderframe.setPosition(Vector2i(700, 30)); // установка позиции


    vector<Product>vp = tmenu.getProducts(); // получение вектора продуктов из обьекта данных
    for (const Product& tp : vp) // передача данных в FrameMenu
    {
        Item ti{ tp.id,tp.name,tp.price,tp.descript,tp.imageName }; // передача данных в FrameMenu
        frame.pushProd(ti); // передача данных в FrameMenu
    }
    Text hellotext("Добро пожаловать в Сакура суши!", font, 80); // создание текста приветствия
    hellotext.setOutlineColor(Color::Black); // установка цвета контуров
    hellotext.setOutlineThickness(5); // установка толщины контуров
    hellotext.setPosition(500, 500); // установка позиции

    Text apruvetext("Спасибо ваш заказ принят!", font, 80); // создание текста подтверждения заказа
    apruvetext.setOutlineColor(Color::Black); // установка цвета контуров
    apruvetext.setOutlineThickness(5); // установка толщины контуров
    apruvetext.setPosition(500, 500); // установка позиции



    Text text("Сакура суши!", font, 80); // создание текста заголовка
    text.setOutlineColor(Color::Black); // установка цвета контуров
    text.setOutlineThickness(5); // установка толщины контуров
    text.setPosition(100, 50); // установка позиции
    
    
    String txtBuffer; // создание буфера для набронного текста
    orderframe.setTxtBuffer(txtBuffer); // передача буфера в BorderFrame

    //mode 
    //0=меню приветствия
    //1=меню выбора
    //2=меню заказа
    //3=меню подтверждения
    int mode = 0; // выбор меню
    


    while (window.isOpen()) // главный цикл программы
    {
        
        Event event; // создание события
        while (window.pollEvent(event)) // обработка события
        {

            switch (event.type) // проверка по типу события
            {
            case Event::Closed:
                window.close(); // событие закрытие
                break;
            case Event::TextEntered: // событие ввод текста
                
                txtBuffer += event.text.unicode; // добавление текста в буфер
                break;
            default:
                break;
            }
            if (Keyboard::isKeyPressed(Keyboard::BackSpace)) // обработка нажатия Backspace
            {
                if (!txtBuffer.isEmpty()) // если буфер не пустой
                {
                    txtBuffer.erase(txtBuffer.getSize()-1, 1); // удаляем последний символ
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::Return)) // обработка события Return
            {
                txtBuffer += '\n'; // добавляем в буфер перевод строки
            }
            
            if (Mouse::isButtonPressed(Mouse::Left)) // обработка события LB
            {
                if (menuBtn.checkMouseOn(Mouse::getPosition(window))) // проверка нажатия на кнопку меню
                {
                    menuBtn.setIsPushed(true); // помечаем кнопку меню нажатой
                    mode = 1; // выставляем режим выбора (78-81 строка)
                }
                if (exitBtn.checkMouseOn(Mouse::getPosition(window))) // проверка нажатия на кнопку выход
                    window.close(); // закрываем окно
                if (mode == 1) // если режим выбора то обрабатыаем событие в окне выбора
                {
                    if (frame.checkClick()) // проверяем/передаем событие нажатия LB
                    {
                        menuBtn.setIsPushed(false); // если не прошло проверку то помечаем кнопку меню не нажатой
                        mode = 0; // выставляем режим приветствия (78-81 строка)
                        if (frame.getOrderStatus()) // если нажата кнопка заказать
                            mode = 2; // переход в режим заказа
                    }
                }
                if (mode == 2) // если режим заказа то обрабатыаем событие в окне заказа
                {
                    if (orderframe.checkClick()) // проверяем/передаем событие нажатия LB
                    {
                        if (orderframe.getOrderStatus()) // если нажата кнопка подтвердить
                            mode = 3; // переходим в режим подтверждения
                    }
                }
            }

        }
        
        menuBtn.checkMouseOn(Mouse::getPosition(window)); // проверка нахождения курсора над кнопкой меню
        exitBtn.checkMouseOn(Mouse::getPosition(window)); // проверка нахождения курсора над кнопкой выход
        

            
        

        window.clear(); // очистка экрана
        window.draw(background); // отрисовка фона
        window.draw(text); // отрисовка заголовка
        window.draw(menuBtn); // отрисовка кнопки меню
        window.draw(exitBtn); // отрисовка кнопки выхода
        
        
        switch (mode) // обработка режима
        {
        case 0: // если 0 то режим приветствия
            window.draw(hellotext); // отрисовка текста приветствия
            break;
        case 1: // если 1 то режим выбора
            frame.checkMouseOn(Mouse::getPosition(window)); // обработка/передача нахождения курсора над обьектами
            window.draw(frame); // отрисовка формы выбора
            break;
        case 2: // если 2 то режим заказа
            orderframe.checkMouseOn(Mouse::getPosition(window)); // обработка/передача нахождения курсора над обьектами
            orderframe.setSelectedItems(frame.getSelectedItems()); // передача выбранных данных с формы выбора на форму заказа
            window.draw(orderframe); // отрисовка формы заказа
            break;
        case 3: // если 3 то режим подвтерждения
            window.draw(apruvetext); // отрисовка текста подтверждения
            frame.clearProd(); // очистка корзины
            for (const Product& tp : vp) // возбновление исходных данных в FrameMenu
            {
                Item ti{ tp.id,tp.name,tp.price,tp.descript,tp.imageName }; // создаем обьект
                frame.pushProd(ti); // пушим обьект
                
            }
            break;
        default:
            window.draw(apruvetext); // отрисовка текста подтверждения
            
        }
        window.display(); // отрисовка главного окна
    }
}