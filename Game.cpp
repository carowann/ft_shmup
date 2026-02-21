/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:07:19 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 15:22:22 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game() : _running(true), _player(0, 5) {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	getmaxyx(stdscr, _rows, _cols);
	_player = Player(_rows / 2, 0);
}

Game::~Game() {
	endwin();
}

void Game::run() {
	while (_running)
	{
		// int ch = getch();
		// if (ch == 'q')
		// 	_running = false;
		handleInput();
		auto now = std::chrono::steady_clock::now();
		float elapsed = std::chrono::duration<float>(now - _lastTime).count();
		if (elapsed < 1.0f / 60.0f)
		continue;
		_lastTime = now;
		//creazione randomica nemici
		// handleInput(elapsed);
		//UPDATE tutto:
		//azioni nemico
		//movimento continuo della pellicola
		//controllo continuo vittoria o sconfitta -> popup
		// update(elapsed);
		render();
	}
}

void	Game::render() {
	clear();
	attron(COLOR_PAIR(1));
	mvprintw(_player.getY(), _player.getX(), "%s", _player.getSymbol());
	mvprintw(0, 0, "rows: %d cols: %d", _rows, _cols);
	attroff(COLOR_PAIR(1));
	refresh();
}

void	Game::handleInput() {
	//prendera' input -> muovera' il player e/p sparera'
	//if su o giu -> muove player
	//if space bar -> player spara
	int ch = getch();

	switch (ch) {
		case 'q':
			_running = false;
			break;
		case KEY_UP:
			_player.moveUp();
			break;
		case KEY_DOWN:
			_player.moveDown(_rows);
			break;
	}
}
