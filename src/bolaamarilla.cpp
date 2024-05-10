#include <fstream>
#include "Bolaamarilla.hpp" // Asegúrate de incluir el archivo de encabezado de la clase Bolaamarilla.

using namespace std;
using namespace ftxui;

Bolaamarilla::Bolaamarilla(int x, int y) : x_(x), y_(y)
{
    ifstream file("boladerecha.txt");
    wstring line;
    while (getline(file, line))
    {
        bola_dibujo_ += line + L"\n";
    }
    file.close();
}

Element Bolaamarilla::Render()
{
    return hbox() | hcenter(text(bola_dibujo_));
}

void Bolaamarilla::MoveRight()
{
    x_++;
}

void Bolaamarilla::MoveLeft()
{
    x_--;
}

void Bolaamarilla::MoveUp()
{
    y_++;
}

void Bolaamarilla::MoveDown()
{
    y_--;
}
