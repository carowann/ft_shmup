/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:35:56 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 14:19:59 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_HPP
# define  GAMEENTITY_HPP

class GameEntity
{
private:
	/* data */
protected:
	int			_x;
	int			_y;
	const char	*_symbol;
public:
	GameEntity(/* args */);
	virtual	~GameEntity();
};


#endif