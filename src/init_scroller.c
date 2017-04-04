/*
** init_scroller.c for remi in /home/remi.roussel/Epitech/scroller/src
** 
** Made by remi.roussel
** Login   <remi.roussel@epitech.eu>
** 
** Started on  Sat Apr  1 14:44:41 2017 remi.roussel
** Last update Sat Apr  1 15:36:34 2017 remi.roussel
*/

#include "scroller.h"

int	init_text(t_text_scene *scene)
{
  if (!(scene->text_texture = sdTexture_createFromFile
	(ASSET_FOLDER"title.png", NULL)))
    return (EXIT_FAILURE);
  scene->text = sfSprite_create();
  sfSprite_setTexture(scene->texte, scene->text_texture, sfTrue);
  scene->text_pos.x = -(WINDOW_WIDTH);
  scene->text_pos.y = 0.f;
  return (EXIT_SUCCESS);
}

void	loop_text_scene_move(t_text_scene *scene)
{
  scene->text_pos.x += 0.075f;
}

int	loop_text_scene(t_window *window, t_text_scene *scene)
{
  loop_text_scene_move(scene);
  sfSprite_setPosition(scene->text, scene->text_pos);
  sfRenderWindow_drawSprite(window->window, scene->text, NULL)
}
