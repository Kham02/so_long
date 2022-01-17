#include "so_long.h"
#include "so_long_utils.h"

int	main(int ac, char *av)
{
	t_game	game;

	if (ac != 1)
		error(&game, "invalid number of parameters");
	map_valid(av[1], &game);
	mlx = mlx_init();
	create_window(&mlx);
	mlx_loop(&mlx);
}
	/*
	проверить название карты перед валидностью		**DONE**
	записать координаты объектов
	в одной функ:
	<
	создаем окно (размер блоков 35) * на ширину и высоту
	init img: game->wall.img = mlx_xpm_file_to_img(); //&game
	>
	<
	отрисовать карту пройтись по массиву и вызывать функцию (mlx_put_img_to_window) длоя отрисовки каждого объекта
	отрисовать непостоянные объекты (перс, монетки)
	mlx_hook(переменная окна (указатель mlx_new_window), 2, 1L << 1, функция которая отвечает за нажатие на W,A,S,D и ESC, game) для движения перса
	>
	проверка на шаги и проверка на выигрышь (все монетки собраны и координа ты перса = коорд выхода (сравнивать со всми возможными))
	*/
	// mlx_hook(переменная окна (указатель mlx_new_window), 17, 1L << 0, функция для закрытия окна, game);