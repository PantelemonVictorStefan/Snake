#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int h=35,w=35;
int length=15;
int height=length*h;
int width=length*w;
void DrowMap()
{
    sf::RenderWindow window(sf::VideoMode(width,height),"This is Snake Game. Have fun!!",sf::Style::Close);
    Texture t1,t2,t3;
    t1.loadFromFile("Texturi/fundalp.png");
    t2.loadFromFile("Texturi/f1.png");//
    t3.loadFromFile("Texturi/f2.png");

    Sprite sprite1(t1);
    Sprite sprite2(t2);
    Sprite sprite3(t3);

    while(window.isOpen())
    {   window.clear(sf::Color(255,255,255));
        sf::Event e;
        while(window.pollEvent(e))
        {
            if(e.type==sf::Event::Closed)
                window.close();
        }

    /*for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
        {
            sprite1.setPosition(i*length,j*length);*/
            window.draw(sprite1);



       window.display();
    }

}

int main()
{
DrowMap();
}
