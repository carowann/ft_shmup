/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:07:19 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 12:44:37 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game() : _running(true) {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	getmaxyx(stdscr, _rows, _cols);
}

Game::~Game() {
	endwin();
}

void Game::run() {
	while (_running)
	{
		int ch = getch();
		if (ch == 'q')
			_running = false;
		//UPDATE tutto:
		//creazione randomica nemici
		//prendera' input -> muovera' il player e/p sparera'
		//azioni nemico
		//movimento continuo della pellicola
		//controllo continuo vittoria o sconfitta -> popup
		//RENDERING
		clear();
		attron(COLOR_PAIR(1));
		mvprintw(_rows / 2, _cols / 2, "@");
		mvprintw(0, 0, "rows: %d cols: %d", _rows, _cols);
		attroff(COLOR_PAIR(1));
		refresh();
	}
}