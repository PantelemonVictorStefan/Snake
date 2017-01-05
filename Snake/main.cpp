#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace sf;
int score=0;
int rows=30,columns=25;
int length=30;
int width = length*rows;
int height = length*columns;
int ok=0;
int dir=0,num=5;
bool gameover=false;
bool imput=false;
bool valid=false;

struct Snake
{ int x,y;}  snake[1400];

struct Fruct
{ int x,y;} fruit;

void Logic()
 {
    for (int i=num;i>0;--i)
	 {snake[i].x=snake[i-1].x;
	 snake[i].y=snake[i-1].y;}

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
            ok=rand()%4;

            for(int i=1; i<num; i++)
                if((snake[i].x==fruit.x)&&(snake[i].y)==(fruit.y))
                    valid=false;
        }
        while(valid==false);
    }

    if (snake[0].x>=rows) gameover=true;
    if (snake[0].x<0) gameover=true;
    if (snake[0].y>columns-1) gameover=true;
    if (snake[0].y<0) gameover=true;

    for (int i=1;i<num;i++)
     if (snake[0].x==snake[i].x && snake[0].y==snake[i].y) gameover=true;
imput=false;
 }

int main()
{
	srand(time(0));

    RenderWindow window(VideoMode(width, height), "Snake Game!");

	Texture t1,t2,t3,t4,t5,t6;
	t1.loadFromFile("images/fundalS.png");
	t2.loadFromFile("images/sarpe1.png");
	t3.loadFromFile("images/mar.png");
    t4.loadFromFile("images/cirese.png");
    t5.loadFromFile("images/lamaie.png");
    t6.loadFromFile("images/gandac2.png");
	Sprite sprite1(t1);
	Sprite sprite2(t2);
	Sprite sprite3(t3);
	Sprite sprite4(t4);
    Sprite sprite5(t5);
    Sprite sprite6(t6);
	Clock clock;
    float timer=0, delay=0.5;

	fruit.x=10;
    fruit.y=10;

    Event e;
    while (window.isOpen())
    {
        if (gameover==true)
            window.close();
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

		if (timer>delay) {timer=0; Logic();}

   ////// draw  ///////
    window.clear();

    /*for (int i=0; i<N; i++)
	  for (int j=0; j<M; j++)
		{ sprite1.setPosition(i*length,j*length);*/
		 window.draw(sprite1);
		 //}


    //set snake
	for (int i=0;i<num;i++)
	    { sprite2.setPosition(snake[i].x*length, snake[i].y*length);
	     window.draw(sprite2);

	     }

    //set fruits

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

        window.display();
    }

    return 0;
}
