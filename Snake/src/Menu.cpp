#include "Menu.h"

Menu::Menu(float width,float height)
{
    if(!font.loadFromFile("arial.ttf"))
    {

    }
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2,height/4*1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::Red);
    menu[1].setString("Credits");
    menu[1].setPosition(sf::Vector2f(width/2,height/4*2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::Red);
    menu[2].setString("Quit");
    menu[2].setPosition(sf::Vector2f(width/2,height/4*3));
}

Menu::~Menu()
{
    //dtor
}

void Menu::draw(sf::RenderWindow &window)
{
    for(int i=0;i<3;i++)
    {
        window.draw(menu[i]);
    }
}
