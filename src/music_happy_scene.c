/*
** music_happy_scene.c for scroller in /home/victor/Rushs/scroller
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sat Apr  1 16:58:45 2017 Victor LE DANTEC
** Last update Sat Apr  1 17:01:42 2017 Victor LE DANTEC
*/

#include "scroller.h"

int	play_music(t_happy_scene *scene)
{
  if (!(scene->music = sfMusic_createFromFile(ASSET_FOLDER"/music.ogg")))
    return (EXIT_FAILURE);
  sfMusic_play(scene->music);
  return (EXIT_SUCCESS);
}
