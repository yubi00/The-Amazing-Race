//Headers
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.hpp"
#include "Map2.hpp"
#include "Map3.hpp"






using namespace std;

void GetMap1();
void GetMap2();
void GetMap3();




void  SinglePlayer()
{
    //SECTION START: create the main rendering window

    sf::VideoMode VMode(400,600,32);
    sf::RenderWindow Window1(VMode, "THE AMAZING RACE");
    Window1.SetFramerateLimit(60);

    //------SECTION END: create the main rendering window-------//

    //load sprite image from a file
    sf::Image desert;
    desert.LoadFromFile("images/desert.png");

    sf::Image city;
    city.LoadFromFile("images/city.png");

    sf::Image forest;
    forest.LoadFromFile("images/forest.jpg");

    sf::Image background;
    background.LoadFromFile("images/menuscreen.jpg");

    //create sprite image
    sf::Sprite s_desert(desert);

    sf::Sprite s_city(city);

    sf::Sprite s_forest(forest);

    sf::Sprite s_background(background);
    s_background.SetPosition(0.0f, 0.0f);

    //create string

    sf::String map_title("Choose your Map ");
    map_title.SetPosition(100.0f, 10.0f);
    map_title.SetColor(sf::Color(255,255,255));

    sf::String map1("Forest");
    map1.SetPosition(100.0f, 60.0f);

    sf::String map2("Desert");
    map2.SetPosition(100.0f, 110.0f);

    sf::String map3("City");
    map3.SetPosition(100.0f, 160.0f);


    int map_option = 0;
    bool hold = true;
    while(hold)
    {
        sf::Event Event1;

        while(Window1.GetEvent(Event1))
        {
            if(Event1.Type==sf::Event::Closed)
            {
                Window1.Close();
                hold = false;
            }
            if(Event1.Type== sf::Event::KeyPressed && Event1.Key.Code==sf::Key::Escape)
            {
                Window1.Close();
                hold = false;
            }





            if(Event1.Type==sf::Event::KeyPressed && Event1.Key.Code==sf::Key::Up)
            {
                    if(map_option>0)
                    {
                        map_option-=1;
                    }
            }
            if(Event1.Type==sf::Event::KeyPressed && Event1.Key.Code==sf::Key::Down)
            {
                if(map_option<2)
                {
                    map_option+=1;
                }
            }

            if(Event1.Type==sf::Event::KeyPressed && Event1.Key.Code==sf::Key::Return)
            {
                switch(map_option)
                {
                    case 0:
                    Window1.Close();
                    GetMap1();
                    break;

                    case 1:
                    Window1.Close();
                    GetMap2();
                    break;

                    case 2:
                    Window1.Close();
                    GetMap3();
                    break;

                    default:
                    cout <<"map not found" <<endl;
                    break;
                }
            }

        }
        if(map_option==0)
        {
           map1.SetStyle(sf::String::Bold);
           map2.SetStyle(sf::String::Regular);
           map3.SetStyle(sf::String::Regular);
           map1.SetSize(40.0f);
           map2.SetSize(30.0f);
           map3.SetSize(30.0f);
           s_forest.SetPosition(100.0f, 275.0f);
           s_forest.SetScale(0.5f, 0.5f);
           s_desert.SetPosition(-500.0f, -1000.0f);
           s_city.SetPosition(-500.0f, -1000.0f);



        }
        else if(map_option==1)
        {
           map1.SetStyle(sf::String::Regular);
           map2.SetStyle(sf::String::Bold);
           map3.SetStyle(sf::String::Regular);
           map1.SetSize(30.0f);
           map2.SetSize(40.0f);
           map3.SetSize(30.0f);

           s_desert.SetPosition(100.0f, 275.0f);
           s_desert.SetScale(0.5f, 0.5f);
           s_forest.SetPosition(-500.0f, -1000.0f);
           s_city.SetPosition(-500.0f, -1000.0f);



        }
        else
        {
           map1.SetStyle(sf::String::Regular);
           map2.SetStyle(sf::String::Regular);
           map3.SetStyle(sf::String::Bold);
           map1.SetSize(30.0f);
           map2.SetSize(30.0f);
           map3.SetSize(40.0f);

           s_city.SetPosition(100.0f, 275.0f);
            s_city.SetScale(0.5f, 0.5f);
            s_forest.SetPosition(-500.0f, -1000.0f);

        }

        Window1.Clear();
        Window1.Draw(s_background);
        Window1.Draw(map_title);
        Window1.Draw(map1);
        Window1.Draw(map2);
        Window1.Draw(map3);
        Window1.Draw(s_forest);
        Window1.Draw(s_desert);
        Window1.Draw(s_city);


        Window1.Display();
    }



}
