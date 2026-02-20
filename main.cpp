#include "Window.hpp"

#include "Window.hpp"

int main() {
    Window window;

    window.draw(window.getRows() / 2, window.getCols() / 2, '@', 1);
    window.refresh();

    napms(2000); // aspetta 2 secondi

    return 0; // distruttore chiama endwin()
}