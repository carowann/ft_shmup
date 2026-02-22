/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:07:19 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/22 12:40:36 by pdessant         ###   ########.fr       */
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
	attron(COLOR_PAIR(2)); // rosso come i nemici     //PROVA 
	for (size_t i = 0; i < _enemyBullets.size(); i++)
		mvprintw(_enemyBullets[i].getY(), _enemyBullets[i].getX(), "%s", _enemyBullets[i].getSymbol());
	attroff(COLOR_PAIR(2));  //PROVA
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
    _player.update(dt, maxCols);

    // -------------------------
    // Aggiorna nemici e bullet
    // -------------------------
    for (size_t i = 0; i < _enemies.size(); i++)
    {
        _enemies[i].update(dt, maxCols);

        if (_enemies[i].shouldShoot())
        {
            _enemyBullets.push_back(
                Bullet(_enemies[i].getY(), _enemies[i].getX() - 1, "-", -1)
            );
            _enemies[i].resetShootTimer();
        }

        if (!_enemies[i].getAlive())
        {
            _enemies.erase(_enemies.begin() + i);
            i--; // importante perché abbiamo rimosso un elemento
        }
    }

    // -------------------------
    // Alternanza nemici (1-2 alla volta)
    // -------------------------
    int activeCount = 0;
    for (size_t i = 0; i < _enemies.size(); i++)
        if (_enemies[i].isShootingPhase()) activeCount++;

    if (activeCount < 2)
    {
        std::vector<size_t> inactiveEnemies;
        for (size_t i = 0; i < _enemies.size(); i++)
            if (!_enemies[i].isShootingPhase()) inactiveEnemies.push_back(i);

        int toActivate = 1 + (rand() % 2); // 1 o 2 nemici
        for (int j = 0; j < toActivate && !inactiveEnemies.empty(); j++)
        {
            size_t idx = inactiveEnemies[rand() % inactiveEnemies.size()];
            _enemies[idx].startShootingPhase();

            inactiveEnemies.erase(
                std::remove(inactiveEnemies.begin(), inactiveEnemies.end(), idx),
                inactiveEnemies.end()
            );
        }
    }

    // -------------------------
    // Aggiorna bullets player
    // -------------------------
    for (size_t i = 0; i < _playerBullets.size();)
    {
        _playerBullets[i].update(dt, maxCols);
        if (!_playerBullets[i].getAlive())
            _playerBullets.erase(_playerBullets.begin() + i);
        else
            i++;
    }

    // -------------------------
    // Aggiorna bullets nemici
    // -------------------------
    for (size_t i = 0; i < _enemyBullets.size();)
    {
        _enemyBullets[i].update(dt, maxCols);
        if (!_enemyBullets[i].getAlive())
            _enemyBullets.erase(_enemyBullets.begin() + i);
        else
            i++;
    }

    // -------------------------
    // qui eventuali collisioni / morte
    // -------------------------
}

// void Game::update(float dt, int maxCols) {
// 	if (_shootTimer > 0.0f)
// 		_shootTimer -= dt;
// 	if (_enemyTimer > 0.0f)
// 		_enemyTimer -= dt;
// 	_scrollOffset -= SCROLL_SPEED * dt;
// 	if (_scrollOffset <= -46.0f)
// 		_scrollOffset += 46.0f;
// 	createEnemies();
// 	_player.update(dt, maxCols );
// 	for (size_t i = 0; i < _enemies.size();)
// 	{
// 		_enemies[i].update(dt, maxCols);
// 		// forse qui fai sputare le lumache, altrimenti quando nascono in create enemies
// 		// Aggiorna nemici e bullet
// 		for (size_t i = 0; i < _enemies.size(); i++) //PROVA
// 		{
// 			_enemies[i].update(dt, maxCols);

// 			if (_enemies[i].shouldShoot())
// 			{
// 				_enemyBullets.push_back(
// 					Bullet(_enemies[i].getY(), _enemies[i].getX() - 1, "-", -1)
// 				);
// 				_enemies[i].resetShootTimer();
// 			}

// 			if (!_enemies[i].getAlive())
// 			{
// 				_enemies.erase(_enemies.begin() + i);
// 				i--;
// 			}
// 		}

// 		// Controlla quanti nemici sono attivi
// 		int activeCount = 0;
// 		for (size_t i = 0; i < _enemies.size(); i++)
// 			if (_enemies[i].isShootingPhase()) activeCount++;

// 		// Solo se meno di 2 nemici stanno sparando, attiva uno o due inattivi
// 		if (activeCount < 2)
// 		{
// 			std::vector<size_t> inactiveEnemies;
// 			for (size_t i = 0; i < _enemies.size(); i++)
// 				if (!_enemies[i].isShootingPhase()) inactiveEnemies.push_back(i);

// 			int toActivate = 1 + (rand() % 2); // 1 o 2 nemici alla volta
// 			for (int j = 0; j < toActivate && !inactiveEnemies.empty(); j++)
// 			{
// 				size_t idx = inactiveEnemies[rand() % inactiveEnemies.size()];
// 				_enemies[idx].startShootingPhase();
// 				inactiveEnemies.erase(
// 					std::remove(inactiveEnemies.begin(), inactiveEnemies.end(), idx),
// 					inactiveEnemies.end()
// 				);
// 			}
// 		} //PROVA
// 	for (size_t i = 0; i < _playerBullets.size();)
// 	{
// 		_playerBullets[i].update(dt, maxCols);
// 		if (!_playerBullets[i].getAlive())
// 			_playerBullets.erase(_playerBullets.begin() + i);
// 		else
// 			i++;
// 	}
// 	for (size_t i = 0; i < _enemyBullets.size();) //prova aggiornamento bullet nemici
// 	{
// 		_enemyBullets[i].update(dt, maxCols);
// 		if (!_enemyBullets[i].getAlive())
// 			_enemyBullets.erase(_enemyBullets.begin() + i);
// 		else
// 			i++;
// 	}		//prova aggiornamento bullet nemici
// 	//vari controlli di morte
// 	// i bullet hanno incontrato un player o un nemico? se si -> morte
// }

void Game::createEnemies() {
	if (_enemyTimer <= 0.0f)
	{
		int y = rand() % (_rows) + 1;
		_enemies.push_back(Enemy(y, _cols - 3));
		_enemyTimer = _enemyCooldown;
	}
}
