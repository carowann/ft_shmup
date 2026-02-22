/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:44:52 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/22 16:39:21 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "GameEntity.hpp"
# include "ft_shmup.h"

class Player : public GameEntity
{
private:
	int		_lives;
public:
	Player(float y, float x);
	~Player();
	void	update(float dt, int maxCols);
	void	moveUp();
	void	moveDown(int maxRows);
	int		getLives() const;
	void	decrementLives();

};


#endif