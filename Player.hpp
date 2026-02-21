/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:44:52 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 14:51:26 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "GameEntity.hpp"

class Player : public GameEntity
{
private:
	/* data */
public:
	Player();
	Player(int y, int x);
	~Player();
	const char	*getSymbol() const;
	int			getY() const;
	int			getX() const;
	void		move(int direction);
};


#endif