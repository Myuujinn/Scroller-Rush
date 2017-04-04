/*
** scroller_evil.c for scroller in /home/victor/Rushs/scroller
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Apr  2 14:53:39 2017 Victor LE DANTEC
** Last update Sun Apr  2 15:13:17 2017 Victor LE DANTEC
*/

#include "scroller.h"

void	loop_scroller_evil(t_evil_scene *scene, t_window *window)
{
  scene->scroller_pos.x++;
  sfSprite_setPosition(scene->scroller, scene->scroller_pos);
  sfRenderWindow_drawSprite(window->window, scene->scroller, NULL);
}

int	init_scroller_evil(t_evil_scene *scene)
{
  if (!(scene->scroller_texture = sfTexture_createFromFile
	(ASSET_FOLDER"/title.png", NULL)))
    return (EXIT_FAILURE);
  scene->scroller = sfSprite_create();
  sfSprite_setTexture(scene->scroller, scene->scroller_texture, sfTrue);
  scene->scroller_pos.x = -200.f;
  scene->scroller_pos.y = 0.f;
  sfSprite_setRotation(scene->scroller, 30);
  return (EXIT_SUCCESS);
}
