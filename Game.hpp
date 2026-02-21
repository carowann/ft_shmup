/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:06:57 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 12:06:58 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "ft_shmup.h"

class Game {
private:
	int _rows;
	int _cols;
	bool _running;
	// Player, vector<Enemy>, vector<Bullet>, ecc.

public:
	Game();
	~Game();	// endwin() qui
	void run(); // il loop principale

private:
	void handleInput();
	void update(float dt);
	void render();
};

#endif