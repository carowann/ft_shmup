/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:07:19 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/22 19:24:15 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game() : _running(true), _player(0, 0), _shootCooldown(SHOOT_COOLDOWN), _shootTimer(0.0f), _enemyTimer(0.0f), _enemyCooldown(ENEMY_COOLDOWN), _scrollOffset(0.0f), _score(0) {
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
	_startTime = std::chrono::steady_clock::now();
	_lastTime = std::chrono::steady_clock::now();
}

Game::~Game() {
	endwin();
}

void Game::run() {
	while (_running)
	{
		auto now = std::chrono::steady_clock::now();
		float elapsed = std::chrono::duration<float>(now - _lastTime).count();
		if (elapsed < 1.0f / 60.0f)
			continue;
		_lastTime = now;
		handleInput();
		update(elapsed, _cols);
		if (!_player.getAlive())
		{
			_running = false;
			break;
		}
		render();
	}
	if (!_player.getAlive())
		renderGameover();
}

void	Game::renderGameover() {
	clear();
	attron(COLOR_PAIR(2));
	mvprintw(_rows / 2, _cols / 2 - 6, "Game Over :( ");
	mvprintw(_rows / 2 + 1, _cols / 2 - 10, "You killed %d snails!", _score);
	mvprintw(_rows / 2 + 2, _cols / 2 - 8, "Press 'q' to quit");
	attroff(COLOR_PAIR(2));
	refresh();
	int ch;
	while ((ch = getch()) != 'q')
		;
}

void	Game::render() {
	erase();
	renderTrees();
	attron(COLOR_PAIR(1));
	mvprintw(_player.getY(), _player.getX(), "%s", _player.getSymbol());
	int elapsed = (int)std::chrono::duration<float>(std::chrono::steady_clock::now() - _startTime).count();
	mvprintw(0, 0, "score: %d  lives: %d  time: %ds", _score, _player.getLives(), elapsed);
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	for (size_t i = 0; i < _enemies.size(); i++)
		mvprintw(_enemies[i].getY(), _enemies[i].getX(), "%s", _enemies[i].getSymbol());
	attroff(COLOR_PAIR(2));
	attron(COLOR_PAIR(1));
	for (size_t i = 0; i < _playerBullets.size(); i++)
		mvprintw(_playerBullets[i].getY(), _playerBullets[i].getX(), "%s", _playerBullets[i].getSymbol());
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	for (size_t i = 0; i < _enemyBullets.size(); i++)
		mvprintw(_enemyBullets[i].getY(), _enemyBullets[i].getX(), "%s", _enemyBullets[i].getSymbol());
	attroff(COLOR_PAIR(2));
	refresh();
}

void Game::handleInput() {
	int ch;
	while ((ch = getch()) != ERR)
	{
		switch (ch)
		{
		case 'q':
			_running = false;
			break;
		case KEY_UP:
			_player.moveUp();
			break;
		case KEY_DOWN:
			_player.moveDown(_rows);
			break;
		case ' ':
			if (_shootTimer <= 0.0f)
			{
				_playerBullets.push_back(Bullet(_player.getY(), _player.getX() + 1, "=", 1));
				_shootTimer = _shootCooldown;
			}
			break;
		}
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
		int treeX = (int)_scrollOffset + repeat * SCENERY_WIDTH;
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

void Game::update(float dt, int maxCols)
{
	if (_shootTimer > 0.0f)
		_shootTimer -= dt;
	if (_enemyTimer > 0.0f)
		_enemyTimer -= dt;
	_scrollOffset -= SCROLL_SPEED * dt;
	if (_scrollOffset <= -SCENERY_WIDTH)
		_scrollOffset += SCENERY_WIDTH;

	createEnemies();

	_player.update(dt, maxCols);

	for (size_t i = 0; i < _enemies.size(); i++)
	{
		_enemies[i].update(dt, maxCols);
		if (_enemies[i].shouldShoot())
		{
			_enemyBullets.push_back(Bullet(_enemies[i].getY(), _enemies[i].getX() - 1, "-", -1));
			_enemies[i].resetShootTimer();
		}
	}

	for (size_t i = 0; i < _playerBullets.size(); i++)
		_playerBullets[i].update(dt, maxCols);

	for (size_t i = 0; i < _enemyBullets.size(); i++)
		_enemyBullets[i].update(dt, maxCols);

	int activeCount = 0;
	for (size_t i = 0; i < _enemies.size(); i++)
		if (_enemies[i].isShootingPhase())
			activeCount++;

	if (activeCount < 2)
	{
		std::vector<size_t> inactive;
		for (size_t i = 0; i < _enemies.size(); i++)
			if (!_enemies[i].isShootingPhase())
				inactive.push_back(i);
		int toActivate = 1 + (rand() % 2);
		for (int j = 0; j < toActivate && !inactive.empty(); j++)
		{
			size_t idx = inactive[rand() % inactive.size()];
			_enemies[idx].startShootingPhase();
			inactive.erase(std::remove(inactive.begin(), inactive.end(), idx), inactive.end());
		}
	}

	// --- Collisioni ---
	for (size_t i = 0; i < _playerBullets.size(); i++)
	{
		for (size_t j = 0; j < _enemies.size(); j++)
		{
			if (!_enemies[j].getAlive())
				continue;
			int dx = _playerBullets[i].getX() - _enemies[j].getX();
			int dy = _playerBullets[i].getY() - _enemies[j].getY();
			if (dx >= -1 && dx <= 1 && dy == 0)
			{
				_playerBullets[i].setAlive(false);
				_enemies[j].setAlive(false);
				_score++;
				break;
			}
		}
	}

	// 2. Bullet nemici vs player
	for (size_t i = 0; i < _enemyBullets.size(); i++)
	{
		int dx = _enemyBullets[i].getX() - _player.getX();
		int dy = _enemyBullets[i].getY() - _player.getY();
		if (dx >= -1 && dx <= 1 && dy == 0)
		{
			_enemyBullets[i].setAlive(false);
			_player.decrementLives();
		}
	}

	// 3. Bullet player vs bullet nemico
	for (size_t i = 0; i < _playerBullets.size(); i++)
	{
		if (!_playerBullets[i].getAlive())
			continue;
		for (size_t j = 0; j < _enemyBullets.size(); j++)
		{
			if (_playerBullets[i].getX() == _enemyBullets[j].getX() &&
				_playerBullets[i].getY() == _enemyBullets[j].getY())
			{
				_playerBullets[i].setAlive(false);
				_enemyBullets[j].setAlive(false);
				break;
			}
		}
	}

	// 4. Nemico vs player (collisione diretta)
	for (size_t i = 0; i < _enemies.size(); i++)
	{
		if (!_enemies[i].getAlive())
			continue;
		if (_enemies[i].getX() == _player.getX() &&
			_enemies[i].getY() == _player.getY())
		{
			_enemies[i].setAlive(false);
			_player.decrementLives();
			_player.decrementLives();
			_player.decrementLives();
		}
	}

	for (size_t i = 0; i < _playerBullets.size();)
	{
		if (!_playerBullets[i].getAlive())
			_playerBullets.erase(_playerBullets.begin() + i);
		else
			i++;
	}

	for (size_t i = 0; i < _enemyBullets.size();)
	{
		if (!_enemyBullets[i].getAlive())
			_enemyBullets.erase(_enemyBullets.begin() + i);
		else
			i++;
	}

	for (size_t i = 0; i < _enemies.size();)
	{
		if (!_enemies[i].getAlive())
			_enemies.erase(_enemies.begin() + i);
		else
			i++;
	}
}

void Game::createEnemies() {
	if (_enemyTimer <= 0.0f)
	{
		int y = 1 + rand() % (_rows - 2);
		_enemies.push_back(Enemy(y, _cols - 3));
		_enemyTimer = _enemyCooldown;
	}
}
