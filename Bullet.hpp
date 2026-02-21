/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:30:33 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 19:21:14 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

# include "GameEntity.hpp"
# include "ft_shmup.h"

class Bullet : public GameEntity
{
private:
	float	_speed;
	int		_direction; // +1 destra (player), -1 sinistra (nemico)

public:
	Bullet(float y, float x, const char *b, int direction);
	~Bullet();
	void	update(float dt, int maxCols);
};


#endif