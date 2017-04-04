/*
** evil_scene.c for scroller in /home/victor/Rushs/scroller
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Apr  2 02:05:49 2017 Victor LE DANTEC
** Last update Sun Apr  2 15:09:50 2017 Victor LE DANTEC
*/

#include "scroller.h"

void	evil_scene_parallax(t_evil_scene *scene)
{
  if (scene->taz_pos.x <= -49.f * 5)
    scene->taz_pos.x = 200 + 20 * sinf(0) + 800;
  if (scene->text_pos.x <= -200.f)
    scene->text_pos.x = 1200.f;
  if (scene->text_pos2.x >= 1200.f)
    scene->text_pos2.x = -200.f;
  if (scene->text_pos3.x >= 1200.f)
    scene->text_pos3.x = scene->text_pos3.y = -200.f;
  if (scene->scroller_pos.x >= 1200.f)
    scene->scroller_pos.x = -500.f;
}

int	init_evil_scene(t_evil_scene *scene)
{
  if (init_bunny(scene) == EXIT_FAILURE
      || init_evil_taz(scene) == EXIT_FAILURE
      || init_evil_text(scene) == EXIT_FAILURE
      || init_scroller_evil(scene) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  init_bg_evil(scene);
  return (EXIT_SUCCESS);
}

void	loop_evil_scene(t_evil_scene *scene, t_window *window)
{
  loop_bg_evil(scene, window);
  loop_bunny(scene, window);
  loop_evil_taz(scene, window);
  loop_evil_text(scene, window);
  loop_scroller_evil(scene, window);
  evil_scene_parallax(scene);
}
