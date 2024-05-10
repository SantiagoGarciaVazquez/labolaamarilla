#include <iostream>
#include <string>
#include <thread>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include <ftxui/screen/terminal.hpp>
#include <fstream>

using namespace std;
using namespace ftxui;

int main()
{
    auto screen = ScreenInteractive::FitComponent();

    int mascara_x = 0; //Posición (0, 0).
    int mascara_y = 0;
    Mascara mascara(mascara_x, mascara_y);

    while (true)
    {
        // Lógica de movimiento de la máscara
        if (screen.GetEvent().type == EventType::ArrowRight)
            mascara.MoveRight();
        else if (screen.GetEvent().type == EventType::ArrowLeft)
            mascara.MoveLeft();
        else if (screen.GetEvent().type == EventType::ArrowUp)
            mascara.MoveUp();
        else if (screen.GetEvent().type == EventType::ArrowDown)
            mascara.MoveDown();

        Elements elements;
        elements.push_back(mascara.Render());
        auto document = hbox(move(elements));
        Render(screen, document);

        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}
