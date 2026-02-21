/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:59:52 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 18:34:00 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "GameEntity.hpp"
# include "ft_shmup.h"

class Enemy : public GameEntity
{
private:
	float	_speed;
public:
	Enemy(float y, float x);
	~Enemy();

	void update(float dt, int maxCols);
};

#endif