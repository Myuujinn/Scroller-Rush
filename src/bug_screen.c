/*
** bug_screen.c for scroller in /home/victor/Rushs/scroller
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sat Apr  1 19:55:00 2017 Victor LE DANTEC
** Last update Sat Apr  1 21:22:24 2017 Victor LE DANTEC
*/

#include <time.h>
#include "scroller.h"

void	my_put_pixel(sfUint8 *pixels, int x, int y, sfColor color)
{
  if (x < 0)
    return ;
  if (y < 0)
    return ;
  pixels[(WINDOW_WIDTH * y + x) * 4] = color.r;
  pixels[(WINDOW_WIDTH * y + x) * 4 + 1] = color.g;
  pixels[(WINDOW_WIDTH * y + x) * 4 + 2] = color.b;
  pixels[(WINDOW_WIDTH * y + x) * 4 + 3] = color.a;
}

void		loop_bug(t_happy_scene *scene, t_window *window)
{
  static size_t	i = 2;
  int		x;
  int		y;

  srand(time(NULL) * i++);
  while (i % 1000 != 0)
    {
      x = rand() % WINDOW_WIDTH;
      y = rand() % WINDOW_WIDTH;
      (rand() % 10 >= 5) ? my_put_pixel
	(scene->bug_pixel_buffer, x, y, sfWhite)
	: my_put_pixel(scene->bug_pixel_buffer, x, y, sfBlack);
      i++;
    }
  sfTexture_updateFromPixels(scene->bug_texture, scene->bug_pixel_buffer,
			     WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(window->window, scene->bug, NULL);
}

int	create_framebuffer(t_happy_scene *scene)
{
  size_t	i;
  size_t	j;
  sfColor	alpha;

  alpha.r = alpha.g = alpha.b = alpha.a = 0;
  if ((scene->bug_pixel_buffer = malloc
       (sizeof(sfUint8) * 4 * WINDOW_WIDTH * WINDOW_HEIGHT)) == NULL)
    return (EXIT_FAILURE);
  i = 0;
  while (i < WINDOW_HEIGHT)
    {
      j = 0;
      while (j < WINDOW_WIDTH)
	{
	  srand(time(NULL) * j * i);
	  (rand() % 10 >= 5) ? my_put_pixel(scene->bug_pixel_buffer, i, j, alpha)
	    : my_put_pixel(scene->bug_pixel_buffer, i, j, alpha);
	  j++;
	}
      i++;
    }
  sfTexture_updateFromPixels(scene->bug_texture, scene->bug_pixel_buffer,
			     WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
  return (EXIT_SUCCESS);
}

int	init_bug_screen(t_happy_scene *scene)
{
  scene->bug = sfSprite_create();
  scene->bug_texture = sfTexture_create(WINDOW_WIDTH, WINDOW_HEIGHT);
  sfSprite_setTexture(scene->bug, scene->bug_texture, sfTrue);
  if (create_framebuffer(scene) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
