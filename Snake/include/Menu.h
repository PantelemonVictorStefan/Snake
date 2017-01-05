#ifndef MENU_H
#define MENU_H
#include"SFML/Graphics.hpp"

class Menu
{
    public:
        Menu(float width,float height);
        ~Menu();

        void draw(sf::RenderWindow &window);
        void MoveUP();
        void MoveDown();
    protected:

    private:
        int SelectedItemIndex;
        sf::Font font;
        sf::Text menu[3];
};

#endif // MENU_H
