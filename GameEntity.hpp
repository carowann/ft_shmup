/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:35:56 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/22 15:48:44 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_HPP
# define  GAMEENTITY_HPP

class GameEntity
{
private:
	/* data */
protected:
	float		_y;
	float		_x;
	const char	*_symbol;
	bool		_alive;
public:
	GameEntity(float y, float x, const char *symbol);
	virtual	~GameEntity();
	virtual const char	*getSymbol() const;
	virtual int			getY() const;
	virtual int			getX() const;
	virtual bool		getAlive() const;
	virtual void		setAlive(bool alive);
	virtual void		update(float dt, int maxCols) = 0;
};


#endif