//Headers
#include <SFML/Graphics.hpp>
#include <iostream>
#include "help.hpp"
#include "credit.hpp"


using namespace std;
int GetHelp();
int GetCredit();

int main()
{
    //SECTION START: create main rendering window
    sf::VideoMode VMode(400,600,32);
    sf::RenderWindow MenuWindow(VMode, "THE AMAZING RACE");
    MenuWindow.SetFramerateLimit(60);

    //SECTION END: create main rendering window

    //SECTION START: load sprite image from a file
    sf::Image menuscreen;
    menuscreen.LoadFromFile("images/background.jpg");

    sf::Image menubutton;
    menubutton.LoadFromFile("images/menu_button.png");

    //SECTION END: load sprite image from a file

    //SECTION START: create sprite images

    sf::Sprite menu(menuscreen);
    int a1=0, b1=0;
    menu.SetPosition(a1, b1);

    sf::Sprite menubutton1(menubutton);
    menubutton1.SetPosition(60.0f, 90.0f);

    sf::Sprite menubutton2(menubutton);
    menubutton2.SetPosition(60.0f, 160.0f);

    sf::Sprite menubutton3(menubutton);
    menubutton3.SetPosition(60.0f, 230.0f);

    sf::Sprite menubutton4(menubutton);
    menubutton4.SetPosition(60.0f, 300.0f);

    sf::Sprite menubutton5(menubutton);
    menubutton5.SetPosition(60.0f, 370.0f);


    //SECTION END: create sprite images

    sf::Font font1;
    font1.LoadFromFile("fonts/106beats.ttf");

    sf::Font font2;
    font2.LoadFromFile("fonts/AbcKids.ttf");

    sf::String menutitle("THE AMAZING RACE", font1, 40.0f);
    menutitle.SetPosition(40.0f, 5.0f);
    menutitle.SetColor(sf::Color(255,255,255));
    menutitle.SetStyle(sf::String::Bold);

    sf::String s_menubutton1("QUICK RACE", font2, 25.0f);
    s_menubutton1.SetPosition(90.0f, 110.0f);
    s_menubutton1.SetColor(sf::Color(255,255,255));
    s_menubutton1.SetStyle(sf::String::Regular);

    sf::String s_menubutton2("SINGLE PLAYER", font2, 25.0f);
    s_menubutton2.SetPosition(110.0f, 180.0f);
    s_menubutton2.SetColor(sf::Color(255,255,255));
    s_menubutton2.SetStyle(sf::String::Regular);

    sf::String s_menubutton3("HELP", font2, 25.0f);
    s_menubutton3.SetPosition(110.0f, 250.0f);
    s_menubutton3.SetColor(sf::Color(255,255,255));
    s_menubutton3.SetStyle(sf::String::Regular);

    sf::String s_menubutton4("CREDITS", font2, 25.0f);
    s_menubutton4.SetPosition(110.0f, 320.0f);
    s_menubutton4.SetColor(sf::Color(255,255,255));
    s_menubutton4.SetStyle(sf::String::Regular);

    sf::String s_menubutton5("EXIT", font2, 25.0f);
    s_menubutton5.SetPosition(110.0f, 400.0f);
    s_menubutton5.SetColor(sf::Color(255,255,255));
    s_menubutton5.SetStyle(sf::String::Regular);


    MenuWindow.ShowMouseCursor(false);






    bool hold = true;
    int menu_option = 0;




    while(hold)
    {

        sf::Event Event;

        while(MenuWindow.GetEvent(Event))
        {
            if(Event.Type==sf::Event::Closed)
            {
                MenuWindow.Close();
                hold = false;
            }

            if(Event.Type==sf::Event::KeyPressed && Event.Key.Code==sf::Key::Up)
            {
                if(menu_option>0)
                {
                    menu_option-=1;
                }

            }

            if(Event.Type==sf::Event::KeyPressed && Event.Key.Code==sf::Key::Down)
            {
                if(menu_option<4)
                {
                    menu_option+=1;
                }
            }

            if(Event.Type==sf::Event::KeyPressed && Event.Key.Code == sf::Key::Return)
            {
                switch(menu_option)
                {
                    case 0:

                    cout <<" play game" <<endl;
                    break;

                    case 1:

                    cout <<"single player" <<endl;
                    break;

                    case 2:
                    GetHelp();
                    cout <<"get help " <<endl;
                    break;

                    case 3:
                    GetCredit();
                    cout <<"credits" <<endl;
                    break;

                    case 4:
                    return EXIT_FAILURE;
                    break;

                    default:
                    cout<< " no such option" <<endl;
                    break;



                }
            }
        }

        if(menu_option==0)
        {
            s_menubutton1.SetStyle(sf::String::Bold);
            s_menubutton2.SetStyle(sf::String::Regular);
            s_menubutton3.SetStyle(sf::String::Regular);
            s_menubutton4.SetStyle(sf::String::Regular);
            s_menubutton5.SetStyle(sf::String::Regular);


        }
        else if (menu_option==1)
        {
            s_menubutton1.SetStyle(sf::String::Regular);
            s_menubutton2.SetStyle(sf::String::Bold);
            s_menubutton3.SetStyle(sf::String::Regular);
            s_menubutton4.SetStyle(sf::String::Regular);
            s_menubutton5.SetStyle(sf::String::Regular);
        }
        else if (menu_option==2)
        {
            s_menubutton1.SetStyle(sf::String::Regular);
            s_menubutton2.SetStyle(sf::String::Regular);
            s_menubutton3.SetStyle(sf::String::Bold);
            s_menubutton4.SetStyle(sf::String::Regular);
            s_menubutton5.SetStyle(sf::String::Regular);

        }
        else if (menu_option==3)
        {
            s_menubutton1.SetStyle(sf::String::Regular);
            s_menubutton2.SetStyle(sf::String::Regular);
            s_menubutton3.SetStyle(sf::String::Regular);
            s_menubutton4.SetStyle(sf::String::Bold);
            s_menubutton5.SetStyle(sf::String::Regular);

        }
        else
        {
            s_menubutton1.SetStyle(sf::String::Regular);
            s_menubutton2.SetStyle(sf::String::Regular);
            s_menubutton3.SetStyle(sf::String::Regular);
            s_menubutton4.SetStyle(sf::String::Regular);
            s_menubutton5.SetStyle(sf::String::Bold);

        }



        MenuWindow.Clear(sf::Color(255,255,255));
        MenuWindow.Draw(menu);
        MenuWindow.Draw(menubutton1);
        MenuWindow.Draw(menubutton2);
        MenuWindow.Draw(menubutton3);
        MenuWindow.Draw(menubutton4);
        MenuWindow.Draw(menubutton5);

        MenuWindow.Draw(s_menubutton1);
        MenuWindow.Draw(s_menubutton2);
        MenuWindow.Draw(s_menubutton3);
        MenuWindow.Draw(s_menubutton4);
        MenuWindow.Draw(s_menubutton5);
        MenuWindow.Draw(menutitle);

        MenuWindow.Display();

    }
    return EXIT_SUCCESS;

    //SECTION END: load sprite image from a file
}
