#include<SFML/Graphics.hpp>




using namespace std;



void GetHelp()
{
    //create rendering window
    sf::VideoMode Vmode(400,600,32);
    sf::RenderWindow Window1(Vmode, "THE AMAZING RACE");

    sf::Image helpimage;
    helpimage.LoadFromFile("images/help.jpg");

    sf::Sprite help(helpimage);




    //this keeps the window running
    bool hold = true;
    while(hold)
    {
        //to activate and event in each loop following code is used
        sf::Event Event1;
        while (Window1.GetEvent(Event1))
        {

            //close button is pressed
            if(Event1.Type==sf::Event::Closed)
            {
                Window1.Close();
            }
            //if 'esc' key is pressed
            if((Event1.Type==sf::Event::KeyPressed) &&(Event1.Key.Code==sf::Key::Return))
            {
                Window1.Close();


            }
        }
        Window1.Clear(sf::Color(255,255,0));
        Window1.Draw(help);
        Window1.Display();
    }


}


