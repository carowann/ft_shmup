/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:07:19 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 15:41:12 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game() : _running(true), _player(0, 0), _enemy(0,0) {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	getmaxyx(stdscr, _rows, _cols);
	_player = Player(_rows / 2, 3);
	_enemy = Enemy(_rows / 2, _cols - 3);
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
	attron(COLOR_PAIR(2));
	mvprintw(_enemy.getY(), _enemy.getX(), "%s", _enemy.getSymbol());
	mvprintw(0, 0, "rows: %d cols: %d", _rows, _cols);
	attroff(COLOR_PAIR(2));
	refresh();
}

void	Game::handleInput() {
	//prendera' input -> muovera' il player e/p sparera'
	//if su o giu -> muove player
	//if space bar -> player spara
}
