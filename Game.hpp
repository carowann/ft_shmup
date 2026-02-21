/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:06:57 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 15:09:38 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "ft_shmup.h"
# include "Player.hpp"
# include "Enemy.hpp"

class Game {
private:
	int		_rows;
	int		_cols;
	bool	_running;
	std::chrono::steady_clock::time_point _lastTime;
	std::chrono::duration<float> _frameDuration;
	Player	_player;
	Enemy	_enemy;
	//vector<Enemy>, vector<Bullet>, ecc.

public:
	Game();
	~Game();
	void	run();

private:
	void	handleInput();
	void	update(float dt);
	void	render();
};

#endif