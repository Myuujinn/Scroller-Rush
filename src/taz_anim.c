/*
** animation.c for emacs in /home/gwendal.amosse/Rush_graphic/scroller/src
** 
** Made by Gwendal Amossé
** Login   <gwendal.amosse@epitech.net>
** 
** Started on  Sat Apr  1 13:11:44 2017 Gwendal Amossé
** Last update Sun Apr  2 02:30:18 2017 Victor LE DANTEC
*/

#include <time.h>
#include "scroller.h"

int	loop_evil_taz(t_evil_scene *scene, t_window *window)
{
  clock_t	timer2;
  float		time;

  timer2 = clock();
  time = (float)((double)timer2 - scene->taz_timer) / CLOCKS_PER_SEC * 1000;
  if (time >= 75.f)
    {
      if (scene->rect_taz->left == 0)
	scene->rect_taz->left = 49 * 7;
      else
	{
	  scene->taz_pos.x -= 20.f;
	  scene->taz_pos.y = 200 + 20 * sinf(scene->taz_pos.x * 50);
	  scene->taz_timer = clock();
	  scene->rect_taz->left -= 49;
	}
    }
  sfSprite_setTextureRect(scene->taz, *scene->rect_taz);
  sfSprite_setPosition(scene->taz, scene->taz_pos);
  sfRenderWindow_drawSprite(window->window, scene->taz, NULL);
  return (EXIT_SUCCESS);
}

int	init_evil_taz(t_evil_scene *scene)
{
  sfVector2f	scale_factor;

  if (!(scene->taz_texture = sfTexture_createFromFile
        (ASSET_FOLDER"/taz.png", NULL)))
    return (EXIT_FAILURE);
  if ((scene->rect_taz = malloc(sizeof(sfIntRect))) == NULL)
    return (EXIT_FAILURE);
  scene->taz = sfSprite_create();
  sfSprite_setTexture(scene->taz, scene->taz_texture, sfTrue);
  scale_factor.x = scale_factor.y = 5.f;
  sfSprite_scale(scene->taz, scale_factor);
  scene->rect_taz->left = 49 * 7;
  scene->rect_taz->top = 0;
  scene->rect_taz->width = 49;
  scene->rect_taz->height = 44;
  scene->taz_pos.x = WINDOW_WIDTH + 49.f;
  scene->taz_pos.y = WINDOW_HEIGHT - 44.f * 5;
  scene->taz_timer = clock();
  return (EXIT_SUCCESS);
}

int	loop_taz(t_happy_scene *scene)
{
  clock_t	timer2;
  float		time;

  timer2 = clock();
  time = (float)((double)timer2 - scene->taz_timer) / CLOCKS_PER_SEC * 1000;
  if (time >= 75.f)
    {
      if (scene->rect_taz->left == 0)
	scene->rect_taz->left = 49 * 7;
      else
	{
	  scene->taz_pos.x -= 20.f;
	  scene->grass_pos.x += 10.f;
	  scene->grass2_pos.x += 10.f;
	  scene->fence_pos.x += 10.f;
	  scene->taz_timer = clock();
	  scene->rect_taz->left -= 49;
	}
    }
  sfSprite_setTextureRect(scene->taz, *scene->rect_taz);
  return (EXIT_SUCCESS);
}

int	init_taz(t_happy_scene *scene)
{
  sfVector2f	scale_factor;

  if (!(scene->taz_texture = sfTexture_createFromFile
        (ASSET_FOLDER"/taz.png", NULL)))
    return (EXIT_FAILURE);
  if ((scene->rect_taz = malloc(sizeof(sfIntRect))) == NULL)
    return (EXIT_FAILURE);
  scene->taz = sfSprite_create();
  sfSprite_setTexture(scene->taz, scene->taz_texture, sfTrue);
  scale_factor.x = scale_factor.y = 5.f;
  sfSprite_scale(scene->taz, scale_factor);
  scene->rect_taz->left = 49 * 7;
  scene->rect_taz->top = 0;
  scene->rect_taz->width = 49;
  scene->rect_taz->height = 44;
  scene->taz_pos.x = WINDOW_WIDTH + 49.f;
  scene->taz_pos.y = WINDOW_HEIGHT - 44.f * 5;
  scene->taz_timer = clock();
  return (EXIT_SUCCESS);
}
