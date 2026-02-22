/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:07:19 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/22 11:24:48 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game() : _running(true), _player(0, 0), _shootCooldown(0.3f), _shootTimer(0.0f), _enemyTimer(0.0f), _enemyCooldown(1.0f), _scrollOffset(0.0f) {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, 8, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	srand(time(NULL));
	getmaxyx(stdscr, _rows, _cols);
	_player = Player(_rows / 2, 3);
	_lastTime = std::chrono::steady_clock::now();
}

Game::~Game() {
	endwin();
}

void Game::run() {
	while (_running)
	{
		handleInput();
		auto now = std::chrono::steady_clock::now();
		float elapsed = std::chrono::duration<float>(now - _lastTime).count();
		if (elapsed < 1.0f / 60.0f)
			continue;
		_lastTime = now;
		update(elapsed, _cols);
		render();
	}
}

void	Game::render() {
	clear();
	renderTrees();
	attron(COLOR_PAIR(1));
	mvprintw(_player.getY(), _player.getX(), "%s", _player.getSymbol());
	mvprintw(0, 0, "rows: %d cols: %d", _rows, _cols);
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	for (size_t i = 0; i < _enemies.size(); i++)
		mvprintw(_enemies[i].getY(), _enemies[i].getX(), "%s", _enemies[i].getSymbol());
	mvprintw(0, 0, "rows: %d cols: %d", _rows, _cols);
	attroff(COLOR_PAIR(2));
	attron(COLOR_PAIR(4));
	for (size_t i = 0; i < _playerBullets.size(); i++)
		mvprintw(_playerBullets[i].getY(), _playerBullets[i].getX(), "%s", _playerBullets[i].getSymbol());
	attroff(COLOR_PAIR(4));
	refresh();
}

void	Game::handleInput() {
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
		case ' ' :
			if (_shootTimer <= 0.0f) {
				_playerBullets.push_back(Bullet(_player.getY(), _player.getX() + 1, "*", 1));
				_shootTimer = _shootCooldown;
			}
			break;
	}
}

void Game::renderTrees() {
	attron(COLOR_PAIR(3));
	int startRow = _rows - 10;

	std::string lines[] = {
		"               ,@@@@@@@,",
		"       ,,,.   ,@@@@@@/@@,  .oo8888o.",
		"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o",
		"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'",
		"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'",
		"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'",
		"   `&%\\ ` /%&'    |.|        \\ '|8'",
		"       |o|        | |         | |",
		"       |.|        | |         | |",
		"___ \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_"};

	for (int repeat = 0; repeat < NUMBER_TREES; repeat++)
	{
		int treeX = (int)_scrollOffset + repeat * 46;
		for (int row = 0; row < 10; row++)
		{
			for (int col = 0; col < (int)lines[row].size(); col++)
			{
				int screenX = treeX + col;
				if (screenX >= 0 && screenX < _cols)
					mvaddch(startRow + row, screenX, lines[row][col]);
			}
		}
	}
	attroff(COLOR_PAIR(3));
}

void Game::update(float dt, int maxCols) {
	if (_shootTimer > 0.0f)
		_shootTimer -= dt;
	if (_enemyTimer > 0.0f)
		_enemyTimer -= dt;
	_scrollOffset -= SCROLL_SPEED * dt;
	if (_scrollOffset <= -46.0f)
		_scrollOffset += 46.0f;
	createEnemies();
	_player.update(dt, maxCols );
	for (size_t i = 0; i < _enemies.size();)
	{
		_enemies[i].update(dt, maxCols);
		if (!_enemies[i].getAlive())
			_enemies.erase(_enemies.begin() + i);
		else
			i++;
	}
	for (size_t i = 0; i < _playerBullets.size();)
	{
		_playerBullets[i].update(dt, maxCols);
		if (!_playerBullets[i].getAlive())
			_playerBullets.erase(_playerBullets.begin() + i);
		else
			i++;
	}
}

void Game::createEnemies() {
	if (_enemyTimer <= 0.0f)
	{
		int y = rand() % (_rows) + 1; // tra 1 e _rows-12 per evitare gli alberi
		_enemies.push_back(Enemy(y, _cols - 3));
		_enemyTimer = _enemyCooldown;
	}
}
