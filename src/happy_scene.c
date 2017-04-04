/*
** cloud.c for scroller in /home/victor/Rushs/scroller
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Mar 31 23:23:26 2017 Victor LE DANTEC
** Last update Sun Apr  2 14:16:28 2017 Victor LE DANTEC
*/

#include <time.h>
#include "scroller.h"

void	loop_happy_scene_move(t_happy_scene *scene)
{
  scene->cloud_pos.x += 0.075f;
  scene->background_pos.x += 0.01f;
  scene->background2_pos.x += 0.01f;
  move_text_sin_wave(scene);
}

void	loop_happy_scene_parallax(t_happy_scene *scene)
{
  if (scene->cloud_pos.x > WINDOW_WIDTH + 50)
    scene->cloud_pos.x = -700.f;
  if (scene->grass_pos.x > WINDOW_WIDTH)
    {
      srand(time(NULL));
      if (scene->fence_pos.x > 1280.f && (rand() % 10) >= 3)
	scene->fence_pos.x = -1280.f;
      scene->grass_pos.x = -(WINDOW_WIDTH) + 10.f;
    }
  if (scene->grass2_pos.x > WINDOW_WIDTH)
    scene->grass2_pos.x = -(WINDOW_WIDTH) + 10.f;
  if (scene->background_pos.x > WINDOW_WIDTH)
    scene->background_pos.x = -(WINDOW_WIDTH);
  if (scene->background2_pos.x > WINDOW_WIDTH)
    scene->background2_pos.x = -(WINDOW_WIDTH);
  if (scene->text_pos.x > WINDOW_WIDTH)
    scene->text_pos.x = -825.f;
  if (scene->taz_pos.x <= -49.f * 5)
    scene->taz_pos.x = WINDOW_WIDTH + 49.f;
}

void	loop_draw(t_window *window, t_happy_scene *scene)
{
  sfRenderWindow_drawSprite(window->window, scene->background, NULL);
  sfRenderWindow_drawSprite(window->window, scene->background2, NULL);
  sfRenderWindow_drawSprite(window->window, scene->cloud, NULL);
  sfRenderWindow_drawSprite(window->window, scene->grass, NULL);
  sfRenderWindow_drawSprite(window->window, scene->grass2, NULL);
  sfRenderWindow_drawSprite(window->window, scene->fence, NULL);
  sfRenderWindow_drawSprite(window->window, scene->taz, NULL);
  sfRenderWindow_drawText(window->window, scene->text, NULL);
}

void	loop_setpos(t_happy_scene *scene)
{
  sfSprite_setPosition(scene->cloud, scene->cloud_pos);
  sfSprite_setPosition(scene->grass, scene->grass_pos);
  sfSprite_setPosition(scene->grass2, scene->grass2_pos);
  sfSprite_setPosition(scene->background, scene->background_pos);
  sfSprite_setPosition(scene->background2, scene->background2_pos);
  sfSprite_setPosition(scene->fence, scene->fence_pos);
  sfSprite_setPosition(scene->taz, scene->taz_pos);
  sfText_setPosition(scene->text, scene->text_pos);
}

int		loop_happy_scene(t_window *window, t_happy_scene *scene,
				 t_evil_scene *evil)
{
  time_t	timer;

  timer = time(NULL);
  if (!(timer - scene->timer >= 24 && timer - scene->timer < 56))
    sfRenderWindow_clear(window->window, sfBlack);
  if (timer - scene->timer >= 68)
    return (EXIT_SUCCESS);
  if (timer - scene->timer >= 17 && timer - scene->timer < 24)
    loop_segfault(scene, window);
  else if (timer - scene->timer >= 24 && timer - scene->timer < 56)
    loop_evil_scene(evil, window);
  else if (timer - scene->timer >= 56 && timer - scene->timer < 59)
    loop_sorry(scene, window);
  else
    {
      loop_happy_scene_move(scene);
      loop_happy_scene_parallax(scene);
      loop_taz(scene);
      loop_setpos(scene);
      loop_draw(window, scene);
    }
  if (timer - scene->timer >= 9
      && timer - scene->timer < 17)
    loop_bug(scene, window);
  return (1);
}
