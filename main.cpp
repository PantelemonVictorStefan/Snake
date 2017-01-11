#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <time.h>
#include <iostream>

using namespace sf;
int score=0,BoosterON=0,effect=-1,highColor=0;
int rows=30,columns=25;
int length=35;
int width = length*rows;
int height = length*columns;
int ok=0;
int dir=0,num=3;
int ScoreSkin=0,TextureSkin=0;
int ScoreTrap=0,TextureTrap=0;
bool gameover=false;
bool imput=false;
bool valid=false;
bool SpawnBoost=false;
bool ChangeSkin=false;
bool TrapOn=false,high=false,pausegame=false;

float delay=0.1;

struct Trap
{
    int x,y;
}trapp;

struct Fruct2
{
    int x,y;
} fruit2;

struct Snake
{
    int x,y;
}  snake[1400];

struct Fruct
{
    int x,y;
} fruit;

struct Booster
{
    int x,y;
} booster;

void Logic()
{
    for (int i=num; i>0; --i)
    {
        snake[i].x=snake[i-1].x;
        snake[i].y=snake[i-1].y;
    }

    if (dir==0) snake[0].y+=1;
    if (dir==1) snake[0].x-=1;
    if (dir==2) snake[0].x+=1;
    if (dir==3) snake[0].y-=1;

    if ((snake[0].x==fruit.x) && (snake[0].y==fruit.y))
    {
        num++;
        do
        {
            valid=true;
            fruit.x=rand() % rows;
            fruit.y=rand() % columns;
            ok=rand()%12;

            for(int i=1; i<num; i++)
                if((snake[i].x==fruit.x)&&(snake[i].y)==(fruit.y))
                    valid=false;
        }
        while(valid==false);


        score++;
        ScoreSkin++;


        if(score>=10)
        {
            score=score-10;
            BoosterON=100;
            SpawnBoost=true;
            effect=rand()%5;

            do
            {
                valid=true;
                booster.x=rand() % rows;
                booster.y=rand() % columns;
                for(int i=1; i<num; i++)
                    if((snake[i].x==booster.x)&&(snake[i].y)==(booster.y))
                        valid=false;
            }
            while(valid==false);



        }
    }


    if(ScoreSkin>=30)
        {
            ScoreSkin=0;
            ChangeSkin=true;
            TextureSkin=rand()%6;
        }


    if(BoosterON<=0)
        SpawnBoost=false;
    if(SpawnBoost)
        BoosterON--;
    if ((snake[0].x==booster.x) && (snake[0].y==booster.y))
    {
        SpawnBoost=false;
        if(effect==0)
            delay=delay-0.01;
        if(effect==1)
            delay=delay+0.01;
        if(effect==2)
            num=num+3;
        if(effect==3)
            gameover=true;
        if(effect==4)
            {
            high=true;

            }
    }

    if(high)
        highColor++;
    if(highColor>100)
    {
        high=false;
        highColor=0;
    }
    if(!SpawnBoost)
    {
        booster.x=-1;
        booster.y=-1;
    }

    if (snake[0].x>=rows) gameover=true;
    if (snake[0].x<0) gameover=true;
    if (snake[0].y>columns-1) gameover=true;
    if (snake[0].y<0) gameover=true;

    /*if((snake[0].y==0) and dir==3) dir=2;
    if((snake[0].x==rows-1) and dir==2) dir=0;
    if((snake[0].y==columns-1) and dir==0) dir=1;
    if((snake[0].x==0) and dir==1) dir=3;*/

    for (int i=1;i<num;i++)
     if (snake[0].x==snake[i].x && snake[0].y==snake[i].y) gameover=true;
imput=false;
 }

 void Play()
{
	srand(time(0));

    RenderWindow window(VideoMode(width, height), "Snake Game!");

	Texture t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30,t31,t32;
	t1.loadFromFile("images/fundal.png");
	t2.loadFromFile("images/sarpeORG.png");
	t3.loadFromFile("images/mouse1.png");//1
    t4.loadFromFile("images/mouse2.png");//2
    t5.loadFromFile("images/mouse13.png");//3
    t6.loadFromFile("images/mouse11.png");//4
    t7.loadFromFile("images/mouse12.png");//5
    t8.loadFromFile("images/mouse14.png");//6
    t9.loadFromFile("images/mar.png");
    t10.loadFromFile("images/capsune.png");
    t11.loadFromFile("images/mouse7.png");
    t12.loadFromFile("images/mouse8.png");
    t13.loadFromFile("images/mouse9.png");
    t14.loadFromFile("images/mouse10.png");
    t15.loadFromFile("images/sarpeORG1.png");
    t16.loadFromFile("images/sarpe3.png");
    t17.loadFromFile("images/sarpe3.1.png");
    t18.loadFromFile("images/sarpe2.png");
    t19.loadFromFile("images/sarpe2.1.png");
    t20.loadFromFile("images/lamaie.png");

    t21.loadFromFile("images/mouse4.png");//free to use
    t22.loadFromFile("images/mouse6.png");//free to use

    t23.loadFromFile("images/moarte1.png");
    t24.loadFromFile("images/sarpe/1.png");
    t25.loadFromFile("images/sarpe/2.png");
    t26.loadFromFile("images/sarpe/3.png");
    t27.loadFromFile("images/sarpe/4.png");
    t28.loadFromFile("images/sarpe/5.png");
    t29.loadFromFile("images/sarpe/6.png");
    t30.loadFromFile("images/sarpe/7.png");
    t31.loadFromFile("images/drog.png");
    t32.loadFromFile("images/fundalM.png");
	Sprite sprite1(t1);
	Sprite sprite2(t2);
	Sprite sprite3(t3);
	Sprite sprite4(t4);
    Sprite sprite5(t5);
    Sprite sprite6(t6);
    Sprite sprite7(t7);
    Sprite sprite8(t8);
    Sprite sprite9(t9);
    Sprite sprite10(t10);
    Sprite sprite11(t11);
    Sprite sprite12(t12);
    Sprite sprite13(t13);
    Sprite sprite14(t14);
    Sprite sprite15(t15);
    Sprite sprite16(t16);
    Sprite sprite17(t17);
    Sprite sprite18(t18);
    Sprite sprite19(t19);
    Sprite sprite20(t20);
    Sprite sprite21(t21);
    Sprite sprite22(t22);
    Sprite sprite23(t23);
    Sprite sprite24(t24);
    Sprite sprite25(t25);
    Sprite sprite26(t26);
    Sprite sprite27(t27);
    Sprite sprite28(t28);
    Sprite sprite29(t29);
    Sprite sprite30(t30);
    Sprite sprite31(t31);
    Sprite sprite32(t32);
	Clock clock;
    float timer=0;


	fruit.x=10;
    fruit.y=10;

    Event e;
    while (window.isOpen())
    {
        if (gameover==true)
            {
                window.close();
            }
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;


        while (window.pollEvent(e))
        {
            if (gameover==true)
                window.close();
            if (e.type == Event::Closed)
                window.close();
            if (gameover==true)
                window.close();
		}

		if ((Keyboard::isKeyPressed(Keyboard::Left) and dir!=2)and imput==false) {dir=1;imput=true;}
	    if ((Keyboard::isKeyPressed(Keyboard::Right) and dir!=1)and imput==false)  {dir=2;imput=true;}
	    if ((Keyboard::isKeyPressed(Keyboard::Up) and dir!=0)and imput==false) {dir=3;imput=true;}
		if ((Keyboard::isKeyPressed(Keyboard::Down) and dir!=3)and imput==false) {dir=0;imput=true;}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) gameover=true;
		if (Keyboard::isKeyPressed(Keyboard::P))  pausegame=true;
		if (Keyboard::isKeyPressed(Keyboard::Return)) pausegame=false;
		if ((timer>delay)&&(!pausegame)) {timer=0; Logic();}

   ////// draw  ///////
    window.clear();
    window.draw(sprite1);


    //set snake

        for (int i=0; i<num; i++)
            {sprite2.setPosition(snake[i].x*length, snake[i].y*length);
            window.draw(sprite2);
        }

        if(ChangeSkin)
        {
            if(TextureSkin==0)
                for (int i=0; i<num; i++)
                {
                    sprite15.setPosition(snake[i].x*length, snake[i].y*length);
                window.draw(sprite15);
                }

            if(TextureSkin==1)
                for (int i=0; i<num; i++)
                {
                    sprite16.setPosition(snake[i].x*length, snake[i].y*length);
                    window.draw(sprite16);
                }
            if(TextureSkin==2)
                for (int i=0; i<num; i++)
                {
                    sprite17.setPosition(snake[i].x*length, snake[i].y*length);
                    window.draw(sprite17);
                }
            if(TextureSkin==3)
                for (int i=0; i<num; i++)
                {
                    sprite17.setPosition(snake[i].x*length, snake[i].y*length);
                    window.draw(sprite17);
                }

            if(TextureSkin==4)
                for (int i=0; i<num; i++)
                {
                    sprite18.setPosition(snake[i].x*length, snake[i].y*length);
                    window.draw(sprite18);
                }

            if(TextureSkin==5)
                for (int i=0; i<num; i++)
                {
                    sprite19.setPosition(snake[i].x*length, snake[i].y*length);
                    window.draw(sprite19);
                }

        }
            if(high)
            {
                window.draw(sprite32);
                if(highColor%7==0)
                     for (int i=0; i<num; i++)
                {
                    sprite24.setPosition(snake[i].x*length, snake[i].y*length);
                    window.draw(sprite24);
                }
                if(highColor%7==1)
                 for (int i=0; i<num; i++)
                {
                    sprite25.setPosition(snake[i].x*length, snake[i].y*length);
                    window.draw(sprite25);
                }
                if(highColor%7==2)
                 for (int i=0; i<num; i++)
                {
                    sprite26.setPosition(snake[i].x*length, snake[i].y*length);
                    window.draw(sprite26);
                }
                if(highColor%7==3)
                 for (int i=0; i<num; i++)
                {
                    sprite27.setPosition(snake[i].x*length, snake[i].y*length);
                    window.draw(sprite27);
                }
                if(highColor%7==4)
                 for (int i=0; i<num; i++)
                {
                    sprite28.setPosition(snake[i].x*length, snake[i].y*length);
                    window.draw(sprite28);
                }
                if(highColor%7==5)
                 for (int i=0; i<num; i++)
                {
                    sprite29.setPosition(snake[i].x*length, snake[i].y*length);
                    window.draw(sprite29);
                }
                if(highColor%7==6)
                 for (int i=0; i<num; i++)
                {
                    sprite30.setPosition(snake[i].x*length, snake[i].y*length);
                    window.draw(sprite30);
                }
            }
    //set food

        if(ok==0)
        {
            sprite4.setPosition(fruit.x*length, fruit.y*length);
            window.draw(sprite4);

        }
        if(ok==1)
        {
            sprite3.setPosition(fruit.x*length, fruit.y*length);
            window.draw(sprite3);

        }
        if(ok==2)
            {
            sprite5.setPosition(fruit.x*length, fruit.y*length);
            window.draw(sprite5);

            }
        if(ok==3)
            {
            sprite6.setPosition(fruit.x*length, fruit.y*length);
            window.draw(sprite6);
            }
        if(ok==4)
        {
            sprite7.setPosition(fruit.x*length, fruit.y*length);
            window.draw(sprite7);
        }
        if(ok==5)
        {
            sprite8.setPosition(fruit.x*length, fruit.y*length);
            window.draw(sprite8);
        }
        if(ok==6)
        {
            sprite11.setPosition(fruit.x*length, fruit.y*length);
            window.draw(sprite11);
        }
        if(ok==7)
        {
            sprite12.setPosition(fruit.x*length, fruit.y*length);
            window.draw(sprite12);
        }
        if(ok==8)
        {
            sprite13.setPosition(fruit.x*length, fruit.y*length);
            window.draw(sprite13);
        }
        if(ok==9)
        {
            sprite14.setPosition(fruit.x*length, fruit.y*length);
            window.draw(sprite14);
        }
        if(ok==10)
        {
            sprite21.setPosition(fruit.x*length, fruit.y*length);
            window.draw(sprite21);
        }
        if(ok==11)
        {
            sprite22.setPosition(fruit.x*length, fruit.y*length);
            window.draw(sprite22);
        }


        if(SpawnBoost)
        {
            if(effect==0)
            {
                sprite9.setPosition(booster.x*length, booster.y*length);
                window.draw(sprite9);
            }
            if(effect==1)
            {
                 sprite10.setPosition(booster.x*length, booster.y*length);
                window.draw(sprite10);
            }
             if(effect==2)
            {
                 sprite20.setPosition(booster.x*length, booster.y*length);
                window.draw(sprite20);
            }


            if(effect==3)
            {
                 sprite23.setPosition(booster.x*length, booster.y*length);
                window.draw(sprite23);
            }
            if(effect==4)
            {
                 sprite31.setPosition(booster.x*length, booster.y*length);
                window.draw(sprite31);
            }
        }




        window.display();
    }

    //return 0;
}


int main()
   {
    start:
    sf::RenderWindow window(sf::VideoMode(900, 400), "Snake Game.");
    Menu menu(window.getSize().x,window.getSize().y);
    Texture textura1;
    textura1.loadFromFile("images/sm1.png");
    Sprite sprite1(textura1);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch(menu.GetPressedItem())
                    {
                    case 0:
                        {
                            //if(Stop==false)
                       {

                        TextureSkin=rand()%6;
                        BoosterON=0;
                        //TrapAppear=0;
                        delay=0.1;
                        snake[0].x=0;
                        snake[0].y=0;
                        score=0;
                        gameover=false;
                        dir=0;
                        num=3;
                        ScoreSkin=0;

                        ChangeSkin=true;
                        imput=false;
                        valid=false;
                        SpawnBoost=false;
                        high=false;
                        highColor=0;
                        pausegame=false;
                        }

                        window.close();
                        Play();
                        goto start;

                        break;
                        }
                        case 1:
                            window.close();
                        break;


                       /* case 2:
                        window.close();
                        break;*/
                    }


                    break;
                }

                break;
                case sf::Event::Closed:
                window.close();
                break;
            }
        }

        window.clear();
        window.draw(sprite1);
        menu.draw(window);
        window.display();
    }

return 0;
}

