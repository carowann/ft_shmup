/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:59:52 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 15:00:15 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "GameEntity.hpp"

class Enemy : public GameEntity
{
private:

public:
	Enemy(float y, float x);
	~Enemy();

	void update(float dt);
};

#endif