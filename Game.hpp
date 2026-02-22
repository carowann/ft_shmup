/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:06:57 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/22 16:48:35 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "ft_shmup.h"
# include "Player.hpp"
# include "Enemy.hpp"
# include "Bullet.hpp"

class Game {
private:
	int										_rows;
	int										_cols;
	bool									_running;
	std::chrono::steady_clock::time_point	_startTime;
	std::chrono::steady_clock::time_point	_lastTime;
	Player									_player;
	std::vector<Bullet>						_playerBullets;
	std::vector<Bullet>						_enemyBullets;
	std::vector<Enemy>						_enemies;
	float									_shootCooldown;
	float									_shootTimer;
	float									_enemyTimer;
	float									_enemyCooldown;
	float									_scrollOffset;
	int										_score;
public:
	Game();
	~Game();
	void	run();

private:
	void	handleInput();
	void	update(float dt, int maxCols);
	void	render();
	void	renderGameover();
	void	renderTrees();
	void	createEnemies();
};

#endif