/*
** bunny.c for scroller in /home/victor/Rushs/scroller
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Apr  2 02:08:15 2017 Victor LE DANTEC
** Last update Sun Apr  2 02:14:11 2017 Victor LE DANTEC
*/

#include "scroller.h"

void	loop_bunny(t_evil_scene *scene, t_window *window)
{
  srand(time(NULL));
  scene->bunny_pos.x = rand() % WINDOW_WIDTH;
  scene->bunny_pos.y = rand() % WINDOW_WIDTH;
  sfSprite_setPosition(scene->bunny, scene->bunny_pos);
  sfRenderWindow_drawSprite(window->window, scene->bunny, NULL);
}

int	init_bunny(t_evil_scene *scene)
{
   if (!(scene->bunny_texture = sfTexture_createFromFile
        (ASSET_FOLDER"/picture/lapin_noir.png", NULL)))
    return (EXIT_FAILURE);
  scene->bunny = sfSprite_create();
  sfSprite_setTexture(scene->bunny, scene->bunny_texture, sfTrue);
  scene->bunny_pos.x = scene->bunny_pos.y = 0;
  return (EXIT_SUCCESS);
}
