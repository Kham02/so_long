#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		error(&game, "Error\n invalid number of parameters");
	map_valid(av[1], &game);
	create_window(&game);
	mlx_hook(game.mlx_win, 2, (1L << 1), key, &game);
	mlx_hook(game.mlx_win, 17, (1L << 0), end_game, &game);
	mlx_loop(game.mlx);
}
	/*
	проверить название карты перед валидностью		**DONE**
	записать координаты объектов
	в одной функ:									**DONE**
	<
	создаем окно (размер блоков 35) * на ширину и высоту		**DONE**
	init img: game->wall.img = mlx_xpm_file_to_img(); //&game	------
	>
	<
	отрисовать карту пройтись по массиву и вызывать функцию (mlx_put_img_to_window) для отрисовки каждого объекта		**DONE**
	отрисовать непостоянные объекты (перс, монетки)																		**DONE**
	mlx_hook(переменная окна (указатель mlx_new_window), 2, 1L << 1, функция которая отвечает за нажатие на W,A,S,D и ESC, game) для движения перса
	>
	проверка на шаги и проверка на выигрышь (все монетки собраны и координа ты перса = коорд выхода (сравнивать со всми возможными))		**DONE**
	*/
	// mlx_hook(переменная окна (указатель mlx_new_window), 17, 1L << 0, функция для закрытия окна, game);		**DONE**