/*
** evil_text.c for scroller in /home/victor/Rushs/scroller
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Apr  2 02:50:40 2017 Victor LE DANTEC
** Last update Sun Apr  2 03:27:43 2017 Victor LE DANTEC
*/

#include "scroller.h"

char		*get_random_sentence(size_t size)
{
  static size_t	seed = 1;
  char		*str;
  size_t	i;

  srand(time(NULL) * seed++);
  i = 0;
  if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  while (i < size)
    str[i++] = (rand() % (126 - 33)) + 33;
  str[i] = '\0';
  return (str);
}

void	scale_rand(t_evil_scene *scene)
{
  static size_t	seed = 1;

  srand(time(NULL) * seed++);
  scene->scale_text4.x = rand() * 1000 % 3;
  scene->scale_text4.y = rand() * 1000 % 3;
  sfText_setScale(scene->text, scene->scale_text4);
  sfText_setScale(scene->text3, scene->scale_text4);
  sfText_setScale(scene->text4, scene->scale_text4);
}

void	loop_evil_text(t_evil_scene *scene, t_window *window)
{
  sfText_setString(scene->text, get_random_sentence(10));
  sfText_setString(scene->text2, get_random_sentence(20));
  sfText_setString(scene->text3, get_random_sentence(5));
  sfText_setString(scene->text4, get_random_sentence(15));
  scene->text_pos.x -= 0.5f;
  scene->text_pos2.x += 1.f;
  scene->text_pos3.x += 0.5f;
  scene->text_pos3.y += 0.5f;
  scale_rand(scene);
  sfText_setPosition(scene->text, scene->text_pos);
  sfText_setPosition(scene->text2, scene->text_pos2);
  sfText_setPosition(scene->text3, scene->text_pos3);
  sfText_setPosition(scene->text4, scene->text_pos4);
  sfRenderWindow_drawText(window->window, scene->text, NULL);
  sfRenderWindow_drawText(window->window, scene->text2, NULL);
  sfRenderWindow_drawText(window->window, scene->text3, NULL);
  sfRenderWindow_drawText(window->window, scene->text4, NULL);
}

void	init_one_text(sfText **text, sfFont *bitmap_font)
{
  *text = sfText_create();
  sfText_setFont(*text, bitmap_font);
  sfText_setCharacterSize(*text, 50);
  sfText_setColor(*text, sfBlack);
}

int	init_evil_text(t_evil_scene *scene)
{
  if (!(scene->bitmap_font = sfFont_createFromFile
        (ASSET_FOLDER"/font/visitor2.ttf")))
    return (EXIT_FAILURE);
  init_one_text(&scene->text, scene->bitmap_font);
  init_one_text(&scene->text2, scene->bitmap_font);
  init_one_text(&scene->text3, scene->bitmap_font);
  init_one_text(&scene->text4, scene->bitmap_font);
  scene->text_pos.x = 1200.f;
  scene->text_pos2.x = -200.f;
  scene->text_pos3.x = -200.f;
  scene->text_pos4.x = 500.f;
  scene->text_pos.y = 700.f;
  scene->text_pos2.y = 800.f;
  scene->text_pos3.y = -200.f;
  scene->text_pos4.y = 500.f;
  scene->scale_text4.x = scene->scale_text4.y = 1;
  sfText_setRotation(scene->text3, 35);
  return (EXIT_SUCCESS);
}
