#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace sf;
int score=0;
int N=30,M=25;
int size=30;
int w = size*N;
int h = size*M;
int ok=0;
int dir=0,num=25;
bool gameover=false;
bool imput=false;
bool valid=false;

struct Snake
{ int x,y;}  s[100];

struct Fruct
{ int x,y=M;} f;

void Tick()
 {
    for (int i=num;i>0;--i)
	 {s[i].x=s[i-1].x;
	 s[i].y=s[i-1].y;}

    if (dir==0) s[0].y+=1;
    if (dir==1) s[0].x-=1;
    if (dir==2) s[0].x+=1;
    if (dir==3) s[0].y-=1;

	if ((s[0].x==f.x) && (s[0].y==f.y))
      { num++;
        do
        {

        valid=true;
    	f.x=rand() % N;
        f.y=rand() % M;
        ok=rand()%4;

        for(int i=1;i<num;i++)
            if((s[i].x==f.x)&&(s[i].y)==(f.y))
                valid=false;
        }
        while(valid==false);
        }

    if (s[0].x>=N) {gameover=true;}
    if (s[0].x<0) gameover=true;
    if (s[0].y>M-1) gameover=true;
    if (s[0].y<=0) gameover=true;

    for (int i=1;i<num;i++)
     if (s[0].x==s[i].x && s[0].y==s[i].y) gameover=true; ;
imput=false;
 }

int main()
{
	srand(time(0));

    RenderWindow window(VideoMode(w, h), "Snake Game!");

	Texture t1,t2,t3,t4,t5,t6;
	t1.loadFromFile("images/fundalS.png");
	t2.loadFromFile("images/f1.png");
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
    float timer=0, delay=0.1;

	f.x=10;
    f.y=10;

     Event e;
   while (window.isOpen())
    {
        if (gameover==true)
                window.close();
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
        timer+=time;


        while (window.pollEvent(e))
        {if (gameover==true)
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

		if (timer>delay) {timer=0; Tick();}

   ////// draw  ///////
    window.clear();

    /*for (int i=0; i<N; i++)
	  for (int j=0; j<M; j++)
		{ sprite1.setPosition(i*size,j*size);*/
		 window.draw(sprite1);
		 //}


    //set snake
	for (int i=0;i<num;i++)
	    { sprite2.setPosition(s[i].x*size, s[i].y*size);
	     window.draw(sprite2);

	     }

    //set fruits

        if(ok==0)
        {
            sprite4.setPosition(f.x*size, f.y*size);
            window.draw(sprite4);

        }
        if(ok==1)
        {
            sprite3.setPosition(f.x*size, f.y*size);
            window.draw(sprite3);

        }
        if(ok==2)
            {
            sprite5.setPosition(f.x*size, f.y*size);
            window.draw(sprite5);

            }
        if(ok==3)
            {
            sprite6.setPosition(f.x*size, f.y*size);
            window.draw(sprite6);

            }

        window.display();
    }

    return 0;
}
