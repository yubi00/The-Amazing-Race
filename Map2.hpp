#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <string>
#include "Collision.h"


using namespace std;






void GetMap2()
{
    //SECTION START: create the main rendering window

    sf::VideoMode VMode(400,600,32);
    sf::RenderWindow Window1(VMode, "THE AMAZING RACE");
    Window1.SetFramerateLimit(60);


    //------SECTION END: create the main rendering window-------//

    //SECTION START: load sprite image from a file
    sf::Image image1;
    image1.LoadFromFile("images/desert.png"); //Background image


    sf::Image image2;
    image2.LoadFromFile("images/maincar.png"); //main car(orange)


    sf::Image image3;
    image3.LoadFromFile("images/enemy1.png"); //green enemy car


    sf::Image image4;
    image4.LoadFromFile("images/enemy2.png"); //blue enemy car


    sf::Image image5;
    image5.LoadFromFile("images/enemy3.png"); //red enemy car


    sf::Image image6;
    image6.LoadFromFile("images/stripe.png"); //white stripe


    sf::Image image7;
    image7.LoadFromFile("images/score2.png"); //point


    sf::Image image8;
    image8.LoadFromFile("images/explosion.png"); //explosion


    sf::Image image9;
    image9.LoadFromFile("images/gameover.jpg"); //game over

    sf::Image image10;
    image10.LoadFromFile("images/fuel.png"); //fuel



    //SECTION END: load sprite image from a file

     //load font from a file
    sf::Font font1;
    font1.LoadFromFile("BUBBLEGUMS.ttf");


    //SECTION START: create sprite images
    sf::Sprite sprite1(image1);
    int a1= 0, b1= 0;                       //Background map
    sprite1.SetPosition(a1, b1);

    sf::Sprite sprite1_1(image1);
    int a2= 0, b2 = 600;
    sprite1_1.SetPosition(a2,b2);
    bool bckground1 = false;
    bool bckground2 = false;

    sf::Sprite sprite2(image2);
    sprite2.SetPosition(200.0f,570.0f);     //main car
    sf::Sprite sprite3;                     //green enemy car
    sf::Sprite sprite4;                     //blue car
    sf::Sprite sprite5;                     //red car
    sf::Sprite sprite6(image6);             //white stripe
    int x=0,y=0;
    sprite6.SetPosition(x,y);


    sf::Sprite sprite6_1(image6);
    int x2=0,y2=-600;
    sprite6_1.SetPosition(x2,y2);
    bool stripe1=false;
    bool stripe2=false;

    sf::Sprite sprite7;
    //sprite7.SetScale(0.5f, 0.48f);
    sf::Sprite sprite8(image8);
    sprite8.SetPosition(-200.0f, 0.0f);
    sf::Sprite sprite9;
    sf::Sprite sprite10;



    //SECTION END: create sprite images

    //create string (score)
     int hitscore = 0;
    sf::String score;
    score.SetPosition(0.0f,20.0f);

    //create string (fuel points)
    int fuel_point = 100;
    sf::String fuel;
    fuel.SetPosition(350.0f, 20.0f);

    //clock timer
    sf::Clock Clock1;
    sf::Clock Clock_Point;
    sf::Clock clock_score;
    sf::Clock clock_fuel;
    sf::Clock clock_fuel_point;

    Window1.ShowMouseCursor(false);

    bool running = true; //boolean variable to keep the window ruuning


    while(running)
    {
        //SECTION START: Process Events
        sf::Event Event1;
        while(Window1.GetEvent(Event1))
        {
            if(Event1.Type==sf::Event::Closed)
            {
                Window1.Close();
                running = false;
            }

            if(Event1.Type== sf::Event::KeyPressed && Event1.Key.Code==sf::Key::Escape)
            {
                Window1.Close();
                running = false;
            }
        }
        //SECTION END: Process Events

        float speed = Clock1.GetElapsedTime();
        //converting score into string

        stringstream stream;
        stream << hitscore;
        string string_hitscore;
        string_hitscore = stream.str();
        score.SetText(string_hitscore);
        score.SetFont(font1);
        score.SetSize(20.0f);
        score.SetStyle(sf::String::Bold);
        score.SetColor(sf::Color(255,0,0));

        //converting fuel into string

        stringstream out;
        out<<fuel_point;
        string string_fuel;
        string_fuel = out.str();
        fuel.SetText(string_fuel);
        fuel.SetFont(font1);
        fuel.SetSize(20.0f);
        fuel.SetStyle(sf::String::Bold);
        fuel.SetColor((sf::Color(255, 0, 0)));


        if(clock_score.GetElapsedTime() >1)
        {
            hitscore = hitscore + 10;
            clock_score.Reset();
        }

        if(clock_fuel_point.GetElapsedTime()>5)
        {
            fuel_point = fuel_point - 10;
            clock_fuel_point.Reset();
        }

        if(speed>5)
        {

            int randomno = sf::Randomizer::Random(1, 3); //generate random numbers between 1 and 3

            if(randomno==1)
            {
                sprite3.SetImage(image3);
                int randomx = sf::Randomizer::Random(50, 200); //generate random x-co-ordinates between 50 and 100
                sprite3.SetPosition(randomx, -150);
                Clock1.Reset();
            }

            if(randomno==2)
            {
                sprite4.SetImage(image4);
                int randomx = sf::Randomizer::Random(50, 200);
                sprite4.SetPosition(randomx, -150);
                Clock1.Reset();
            }

            if(randomno==3)
            {
                sprite5.SetImage(image5);
                int randomx = sf::Randomizer::Random(50, 200);
                sprite5.SetPosition(randomx, -150);
                Clock1.Reset();
            }




        }
        if(clock_fuel.GetElapsedTime() >= 10)
         {

                int randomx = sf::Randomizer::Random(50, 200);
                sprite10.SetImage(image10);
                sprite10.SetPosition(randomx, -150);
                clock_fuel.Reset();
        }





        if(Clock_Point.GetElapsedTime() >= 10)
        {
            int random_scorex = sf::Randomizer::Random(50, 200);
            sprite7.SetImage(image7);
            sprite7.SetPosition(random_scorex, -10);
            Clock_Point.Reset();
        }

        //Get elapsed time
        float ElapsedTime = Window1.GetFrameTime();

        // Move the sprite
        if (Window1.GetInput().IsKeyDown(sf::Key::Left))
        {
            sprite2.Move(-100 * ElapsedTime, 0);
            //collision with the blue car on hitting left directional key
            if (Collision::PixelTest(sprite2,sprite3))
            {
                sprite2.Move(+100 * ElapsedTime, 0);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }

            }
            //collision with the green car on hitting left directional key

            if (Collision::PixelTest(sprite2,sprite4))
            {
                sprite2.Move(+100 * ElapsedTime, 0);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }
            //collision with the red car on hitting left directional key

            if (Collision::PixelTest(sprite2,sprite5))
            {
                sprite2.Move(+100 * ElapsedTime, 0);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }

            if (Collision::PixelTest(sprite2,sprite10))
            {
                fuel_point = fuel_point + 10;
                clock_fuel_point.Reset();
                sprite10.SetPosition(-200.0f, 0.0f);
            }

            if (Collision::PixelTest(sprite2,sprite7))
            {

                hitscore = hitscore + 100;
                clock_score.Reset();
                sprite7.SetPosition(-200.0f,0.0f);

            }


        }
        if (Window1.GetInput().IsKeyDown(sf::Key::Right))
        {
            sprite2.Move( 100 * ElapsedTime, 0);
            //collision with the blue car on pressing right directional key
            if (Collision::PixelTest(sprite2,sprite3))
            {
                sprite2.Move(-100 * ElapsedTime, 0);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);

                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }

            }
            //collision with the green car on hitting right directional key

            if (Collision::PixelTest(sprite2,sprite4))
            {
                sprite2.Move(-100 * ElapsedTime, 0);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }
            //collision with the red car on hitting right directional key

            if (Collision::PixelTest(sprite2,sprite5))
            {
                sprite2.Move(-100 * ElapsedTime, 0);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }
             if (Collision::PixelTest(sprite2,sprite10))
            {
                 fuel_point = fuel_point + 10;
                clock_fuel_point.Reset();
                sprite10.SetPosition(-200.0f, 0.0f);
            }
            if (Collision::PixelTest(sprite2,sprite7))
            {

                hitscore = hitscore + 100;
                clock_score.Reset();
                sprite7.SetPosition(-200.0f,0.0f);


            }
        }

        if (Window1.GetInput().IsKeyDown(sf::Key::Up))
         {
            sprite2.Move(0, -150 * ElapsedTime);
            sprite3.Move(0, 75 * ElapsedTime);
            sprite4.Move(0, 75 * ElapsedTime);
            sprite5.Move(0, 75 * ElapsedTime);
            sprite7.Move(0, 75 * ElapsedTime);
            sprite10.Move(0, 75 * ElapsedTime);

            //collision with the blue car on pressing up directional key
            if (Collision::PixelTest(sprite2,sprite3))
            {
                sprite2.Move(0, +100 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }

            }
            //collision with the green car on pressing up directional key

            if (Collision::PixelTest(sprite2,sprite4))
            {
                sprite2.Move(0, +100 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }
            //collision with the red car on pressing up directional key

            if (Collision::PixelTest(sprite2,sprite5))
            {
                sprite2.Move(0, +100 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }
             if (Collision::PixelTest(sprite2,sprite10))
            {
                 fuel_point = fuel_point + 10;
                clock_fuel_point.Reset();
                sprite10.SetPosition(-200.0f, 0.0f);
            }
            if (Collision::PixelTest(sprite2,sprite7))
            {

                hitscore = hitscore + 100;
                clock_score.Reset();
                sprite7.SetPosition(-200.0f,0.0f);


            }
        }
        //if up key is not pressed
        else
        {
            sprite2.Move(0, -50 * ElapsedTime);
            sprite3.Move(0, 50 * ElapsedTime);
            sprite4.Move(0, 50 * ElapsedTime);
            sprite5.Move(0, 50 * ElapsedTime);
            sprite7.Move(0, 50 * ElapsedTime);
            sprite10.Move(0, 50* ElapsedTime);

             //collision with the blue car on pressing up directional key
            if (Collision::PixelTest(sprite2,sprite3))
            {
                sprite2.Move(0, +30 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }

            }
            //collision with the green car on pressing up directional key

            if (Collision::PixelTest(sprite2,sprite4))
            {
                sprite2.Move(0, +100 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }
            //collision with the red car on pressing up directional key

            if (Collision::PixelTest(sprite2,sprite5))
            {
                sprite2.Move(0, +100 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }
             if (Collision::PixelTest(sprite2,sprite10))
            {
                 fuel_point = fuel_point + 10;
                clock_fuel_point.Reset();
                sprite10.SetPosition(-200.0f, 0.0f);
            }
            if (Collision::PixelTest(sprite2,sprite7))
            {

                hitscore = hitscore + 100;
                clock_score.Reset();
                sprite7.SetPosition(-200.0f,0.0f);


            }

        }

        if (Window1.GetInput().IsKeyDown(sf::Key::Down))
        {
            sprite2.Move(0,  120 * ElapsedTime);
            //collision with the blue car on pressing down directional key
            if (Collision::PixelTest(sprite2,sprite3))
            {
                sprite2.Move(0, -120 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }

            }
            //collision with the green car on pressing down directional key

            if (Collision::PixelTest(sprite2,sprite4))
            {
                sprite2.Move(0, -120 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }
            //collision with the red car on pressing down directional key

            if (Collision::PixelTest(sprite2,sprite5))
            {
                sprite2.Move(0, -120 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }
             if (Collision::PixelTest(sprite2,sprite10))
            {
                 fuel_point = fuel_point + 10;
                clock_fuel_point.Reset();
                sprite10.SetPosition(-200.0f, 0.0f);
            }
            if (Collision::PixelTest(sprite2,sprite7))
            {

                hitscore = hitscore + 100;
                clock_score.Reset();
                sprite7.SetPosition(-200.0f,0.0f);

            }
        }

        // Rotate the sprite (Move diagonally)
        if (Window1.GetInput().IsKeyDown(sf::Key::Add))
        {
            sprite2.Rotate(- 100 * ElapsedTime);
            //collision with the blue car on moving diagonally
            if (Collision::PixelTest(sprite2,sprite3))
            {
                sprite2.Rotate( +100 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }

            }
            //collision with the green car on moving diagonally

            if (Collision::PixelTest(sprite2,sprite4))
            {
                sprite2.Rotate(+100 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }
            //collision with the red car on moving diagonally

            if (Collision::PixelTest(sprite2,sprite5))
            {
                sprite2.Rotate(+100 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }
             if (Collision::PixelTest(sprite2,sprite10))
            {
                fuel_point = fuel_point + 10;
                clock_fuel_point.Reset();
                sprite10.SetPosition(-200.0f, 0.0f);
            }
            if (Collision::PixelTest(sprite2,sprite7))
            {

                hitscore = hitscore + 100;
                clock_score.Reset();
                sprite7.SetPosition(-200.0f,0.0f);

            }
        }

        if (Window1.GetInput().IsKeyDown(sf::Key::Subtract))
        {
            sprite2.Rotate(+ 100 * ElapsedTime);
            //collision with the blue car on moving diagonally back
            if (Collision::PixelTest(sprite2,sprite3))
            {
                sprite2.Rotate(-100 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }

            }
            //collision with the green car on moving diagonally back

            if (Collision::PixelTest(sprite2,sprite4))
            {
                sprite2.Rotate(-100 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }
            //collision with the red car on moving diagonally back

            if (Collision::PixelTest(sprite2,sprite5))
            {
                sprite2.Rotate(-100 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }
             if (Collision::PixelTest(sprite2,sprite5))
            {
                sprite2.Rotate(-100 * ElapsedTime);
                int a= sprite2.GetPosition().x;
                int b= sprite2.GetPosition(). y;
                sprite8.SetPosition(a+5, b-5);
                sprite9.SetImage(image9);
                sprite9.SetPosition(0.0f, 0.0f);
                if(Window1.GetInput().IsKeyDown(sf::Key::Return))
                {
                    Window1.Close();
                    GetMap2();
                }
            }
            if (Collision::PixelTest(sprite2,sprite10))
            {
                 fuel_point = fuel_point + 10;
                clock_fuel_point.Reset();
                sprite10.SetPosition(-200.0f, 0.0f);
            }
            if (Collision::PixelTest(sprite2,sprite7))
            {

                hitscore = hitscore + 100;
                clock_score.Reset();
                sprite7.SetPosition(-200.0f,0.0f);

            }
        }


        //vertical scolling of middle white stripe)
         if(y2==0)
        {
            stripe1=true;
            y=0;
        }
        if(stripe1==true and y==0)
        {
            stripe2=true;
            y2=-600;
        }
        if(stripe2==true and y2==0)
        {
            y=0;
        }

        sprite6.SetPosition(x,y+=2);
        sprite6_1.SetPosition(x2,y2+=2);

        //vertical scrolling of background image  (map1)

        if(b2==0)
        {
            bckground1=true;
            b1=0;
        }
        if(bckground1==true and b1==0)
        {
            bckground2=true;
             b2=-600;
        }
        if(bckground2==true and b2==0)
        {
            b1=0;
        }


        sprite1.SetPosition(x,y+=2);
        sprite1_1.SetPosition(x2,y2+=2);



        if(sprite2.GetPosition().y < 0)
        {
            sprite2.SetY(0);
        }
        else if((sprite2.GetPosition().y + sprite2.GetSize().y) > 600)
        {
            sprite2.SetY(600 - sprite2.GetSize().y);
        }
        if(sprite2.GetPosition().x < 40)
        {
            sprite2.SetX(40);
        }
        else if((sprite2.GetPosition().x + sprite2.GetSize().x) > 380)
        {
            sprite2.SetX(380 - sprite2.GetSize().x);
        }
         if(fuel_point<0)
        {
            sprite9.SetImage(image9);
            sprite9.SetPosition(0.0f, 0.0f);
            if(Window1.GetInput().IsKeyDown(sf::Key::Return))
            {
                Window1.Close();
                GetMap2();
            }
        }

        //SECTION START: Display window components and sprites
        Window1.Clear(); //clears the screen
        Window1.Draw(sprite1);
        Window1.Draw(sprite1_1);
        Window1.Draw(sprite6);
        Window1.Draw(sprite6_1);
        Window1.Draw(sprite2);
        Window1.Draw(sprite3);
        Window1.Draw(sprite4);
        Window1.Draw(sprite5);
        Window1.Draw(sprite7);
        Window1.Draw(score);
        Window1.Draw(fuel);
        Window1.Draw(sprite8);
        Window1.Draw(sprite10);
        Window1.Draw(sprite9);



        Window1.Display(); //Display window contents on screen

        //SECTION END: Display window components and sprites



    }


}

