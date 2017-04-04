/*
** main.c for scroller in /home/victor/Rushs/scroller
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Mar 31 21:48:27 2017 Victor LE DANTEC
** Last update Sun Apr  2 16:35:33 2017 Victor LE DANTEC
*/

#include "scroller.h"

t_window	*init_window()
{
  t_window	*window;

  if ((window = malloc(sizeof(t_window))) == NULL)
    return (NULL);
  window->mode.width = WINDOW_WIDTH;
  window->mode.height = WINDOW_HEIGHT;
  window->mode.bitsPerPixel = 32;
  window->window = sfRenderWindow_create
    (window->mode, "xX 1337 5CR0773R Xx"
     , sfResize | sfClose, NULL);
  return (window);
}

int	init_a_lot_of_shit(t_happy_scene *scene, t_evil_scene *evil_scene)
{
  if (init_happy_scene(scene) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (init_evil_scene(evil_scene) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (play_music(scene) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
int	happy_scene()
{
  t_window      *window;
  t_happy_scene	scene;
  t_evil_scene	evil_scene;
  int		val;

  if ((window = init_window()) == NULL)
    return (EXIT_FAILURE);
  if (init_a_lot_of_shit(&scene, &evil_scene) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  val = 0;
  while (sfRenderWindow_isOpen(window->window))
    {
      if ((val = loop_happy_scene(window, &scene, &evil_scene)) != 1)
	break;
      sfRenderWindow_display(window->window);
      while (sfRenderWindow_pollEvent(window->window, &(window->event)))
	if (window->event.type == sfEvtClosed ||
	    sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	  sfRenderWindow_close(window->window);
    }
  sfRenderWindow_destroy(window->window);
  return (val);
}

int	test_scene()
{
  t_window      *window;
  t_tracker	*tracker;

  if ((window = init_window()) == NULL)
    return (EXIT_FAILURE);
  if ((tracker = init_tracker(ASSET_FOLDER"/modlike/zelda.bsf")) == NULL)
    return (EXIT_FAILURE);
  if (start_tracker(tracker) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while (sfRenderWindow_isOpen(window->window))
    {
      sfRenderWindow_clear(window->window, sfBlack);
      if (tracker->playing == 1 && loop_tracker(tracker) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      sfRenderWindow_display(window->window);
      while (sfRenderWindow_pollEvent(window->window, &(window->event)))
	if (window->event.type == sfEvtClosed ||
	    sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	  sfRenderWindow_close(window->window);
    }
  sfRenderWindow_destroy(window->window);
  return (EXIT_SUCCESS);
}

int		main(int argc, char **argv)
{
  if (argc == 1 && happy_scene() == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (argc == 2 && strcmp(argv[1], "synth") == 0 && test_scene() == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
