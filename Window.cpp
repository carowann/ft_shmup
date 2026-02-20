#include "Window.hpp"

void Window::setupColors() {
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);	 // player
	init_pair(2, COLOR_RED, COLOR_BLACK);	 // nemici
	init_pair(3, COLOR_YELLOW, COLOR_BLACK); // proiettili
	init_pair(4, COLOR_CYAN, COLOR_BLACK);	 // HUD
	init_pair(5, COLOR_WHITE, COLOR_BLACK);	 // scenery
}

Window::Window() {
	initscr(); //avvia ncurses
	curs_set(0); // cursore invisibile
	noecho(); //non mostra i tasti premuti
	cbreak(); //input immediato
	keypad(stdscr, TRUE); //abilita frecce e tasti specili
	nodelay(stdscr, TRUE); //getch() non bloccante
	setupColors();
	getmaxyx(stdscr, _rows, _cols);
}

Window::~Window() {
	endwin();
}