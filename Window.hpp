#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "ft_shmup.h"

class Window
{
private:
	int	_rows;
	int	_cols;

	void	setupColors();
public:
	Window(/* args */);
	~Window();

	int	getRows() const { return _rows; }
	int	getCols() const { return _cols; }

	void	refresh();
	void	clear();
};

#endif