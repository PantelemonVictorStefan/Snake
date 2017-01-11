#include "Menu.h"

Menu::Menu(float width, float height)
{

    if(!font.loadFromFile("images/WoW-plexus.ttf"))
    {
        //handle error
    }
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2,height/(MAX_NUMBER_OF_ITEMS+1)*1));

    /*menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Obtions");
    menu[1].setPosition(sf::Vector2f(width/2,height/(MAX_NUMBER_OF_ITEMS+1)*2));*/

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Quit");
    menu[1].setPosition(sf::Vector2f(width/2,height/(MAX_NUMBER_OF_ITEMS+1)*2));

    selectedItemIndex=0;
}

Menu::~Menu()
{
    //dtor
}


void Menu::draw(sf::RenderWindow &window)
{
    for(int i=0;i<MAX_NUMBER_OF_ITEMS;i++)
    {
        window.draw(menu[i]);
    }
}


void Menu::MoveUp()
{
    if(selectedItemIndex-1>=0)
    {
        menu[selectedItemIndex].setColor(sf::Color::Blue);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Green);
    }
}

void Menu::MoveDown()
{
    if(selectedItemIndex+1<MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setColor(sf::Color::Blue);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Green);
    }
}
