/*
** init_happy_scene.c for scroller in /home/victor/Rushs/scroller
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sat Apr  1 00:53:05 2017 Victor LE DANTEC
** Last update Sun Apr  2 00:07:19 2017 Victor LE DANTEC
*/

#include "scroller.h"

int		init_cloud(t_happy_scene *scene)
{
  sfVector2f	factor_scale;

  if (!(scene->cloud_texture = sfTexture_createFromFile
        (ASSET_FOLDER"/picture/nuages1.png", NULL)))
    return (EXIT_FAILURE);
  scene->cloud = sfSprite_create();
  sfSprite_setTexture(scene->cloud, scene->cloud_texture, sfTrue);
  scene->cloud_pos.x = -700.f;
  scene->cloud_pos.y = 100.f;
  factor_scale.x = factor_scale.y = 0.5f;
  sfSprite_scale(scene->cloud, factor_scale);
  return (EXIT_SUCCESS);
}

int	init_grass(t_happy_scene *scene)
{
  if (!(scene->grass_texture = sfTexture_createFromFile
        (ASSET_FOLDER"/picture/herbe4.png", NULL)))
    return (EXIT_FAILURE);
  scene->grass = sfSprite_create();
  scene->grass2 = sfSprite_create();
  sfSprite_setTexture(scene->grass, scene->grass_texture, sfTrue);
  sfSprite_setTexture(scene->grass2, scene->grass_texture, sfTrue);
  scene->grass_pos.x = -(WINDOW_WIDTH);
  scene->grass2_pos.x = 0.f;
  scene->grass_pos.y = scene->grass2_pos.y = WINDOW_HEIGHT - 44.f;
  return (EXIT_SUCCESS);
}

int	init_background(t_happy_scene *scene)
{
  if (!(scene->background_texture = sfTexture_createFromFile
        (ASSET_FOLDER"/picture/background.png", NULL)))
    return (EXIT_FAILURE);
  scene->background = sfSprite_create();
  scene->background2 = sfSprite_create();
  sfSprite_setTexture(scene->background, scene->background_texture, sfTrue);
  sfSprite_setTexture(scene->background2, scene->background_texture, sfTrue);
  scene->background_pos.x = scene->background_pos.y =
    scene->background2_pos.y = 0.f;
  scene->background2_pos.x = -(WINDOW_WIDTH);
  return (EXIT_SUCCESS);
}

int	init_fence(t_happy_scene *scene)
{
  if (!(scene->fence_texture = sfTexture_createFromFile
        (ASSET_FOLDER"/picture/barriere.png", NULL)))
    return (EXIT_FAILURE);
  scene->fence = sfSprite_create();
  sfSprite_setTexture(scene->fence, scene->fence_texture, sfTrue);
  scene->fence_pos.x = 100000.f;
  scene->fence_pos.y = WINDOW_HEIGHT - 44.f - 83.f;
  return (EXIT_SUCCESS);
}

int	init_happy_scene(t_happy_scene *scene)
{
  if (init_cloud(scene) == EXIT_FAILURE || init_grass(scene) == EXIT_FAILURE
      || init_background(scene) == EXIT_FAILURE
      || init_fence(scene) == EXIT_FAILURE
      || init_text(scene) == EXIT_FAILURE
      || init_taz(scene) == EXIT_FAILURE
      || init_bug_screen(scene) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  init_segfault(scene);
  scene->timer = time(NULL);
  return (EXIT_SUCCESS);
}
