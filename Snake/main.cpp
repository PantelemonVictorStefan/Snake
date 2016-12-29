#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace sf;

int N=30,M=20;
int size=15;
int w = size*N;
int h = size*M;
int ok=0;
int dir,num=4;

struct Snake
{ int x,y;}  s[100];

struct Fruct
{ int x,y;} f;

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
    	f.x=rand() % N;
        f.y=rand() % M;
        ok=0;
        }

    if (s[0].x>N) s[0].x=0;  if (s[0].x<0) s[0].x=N;
    if (s[0].y>M) s[0].y=0;  if (s[0].y<0) s[0].y=M;

    for (int i=1;i<num;i++)
     if (s[0].x==s[i].x && s[0].y==s[i].y)  break;

 }

int main()
{
	srand(time(0));

    RenderWindow window(VideoMode(w, h), "Snake Game!");

	Texture t1,t2,t3,t4;
	t1.loadFromFile("images/fundalp.png");
	t2.loadFromFile("images/f1.png");
	t3.loadFromFile("images/cirese.png");
    t4.loadFromFile("images/mar.png");

	Sprite sprite1(t1);
	Sprite sprite2(t2);
	Sprite sprite3(t3);
	Sprite sprite4(t4);

	Clock clock;
    float timer=0, delay=0.1;

	f.x=10;
    f.y=10;


   while (window.isOpen())
    {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
        timer+=time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) and dir!=2) dir=1;
	    if (Keyboard::isKeyPressed(Keyboard::Right) and dir!=1)  dir=2;
	    if (Keyboard::isKeyPressed(Keyboard::Up) and dir!=0) dir=3;
		if (Keyboard::isKeyPressed(Keyboard::Down) and dir!=3) dir=0;

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


    sprite4.setPosition(f.x*size, f.y*size);
	window.draw(sprite4);


	sprite3.setPosition(f.x*size, f.y*size);
	window.draw(sprite3);

	window.display();
	}

    return 0;
}
