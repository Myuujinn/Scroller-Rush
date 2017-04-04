/*
** bg_evil.c for scroller in /home/victor/Rushs/scroller
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Apr  2 02:36:12 2017 Victor LE DANTEC
** Last update Sun Apr  2 14:12:03 2017 Victor LE DANTEC
*/

#include "scroller.h"

void			loop_bg_evil(t_evil_scene *scene, t_window *window)
{
  srand(time(NULL));
  if (time(NULL) % 2)
    scene->bg_color.a++;
  else
    scene->bg_color = sfWhite;
  if (rand() % 500 > 200)
    scene->bg_color.r++;
  else
    scene->bg_color.g++;
  sfRectangleShape_setFillColor(scene->background, scene->bg_color);
  if (rand() % 2 == 1)
    sfRenderWindow_drawRectangleShape(window->window, scene->background, NULL);
}

void		init_bg_evil(t_evil_scene *scene)
{
  sfVector2f	bg_size;

  scene->background = sfRectangleShape_create();
  bg_size.x = WINDOW_WIDTH;
  bg_size.y = WINDOW_HEIGHT;
  scene->bg_color = sfWhite;
  sfRectangleShape_setFillColor(scene->background, scene->bg_color);
  sfRectangleShape_setSize(scene->background, bg_size);
}
