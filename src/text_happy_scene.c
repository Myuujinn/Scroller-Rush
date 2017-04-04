/*
** text_happy_scene.c for scroller in /home/victor/Rushs/scroller
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sat Apr  1 15:42:05 2017 Victor LE DANTEC
** Last update Sun Apr  2 03:43:35 2017 Victor LE DANTEC
*/

#include "scroller.h"

void	move_text_sin_wave(t_happy_scene *scene)
{
  scene->text_pos.x += 0.5f;
  scene->text_pos.y = 20 * sinf(scene->text_pos.x / 50);
}

void	loop_sorry(t_happy_scene *scene, t_window *window)
{
  sfText_setString(scene->segfault_text, "We are sorry if that interrupted");
  sfText_setString(scene->segfault_text2, "your scroller demo.");
  scene->segfault_text_pos.x = 100.f;
  scene->segfault_text_pos.y = 300.f;
  scene->segfault_text_pos2.x = 225.f;
  scene->segfault_text_pos2.y = 325.f;
  sfText_setPosition(scene->segfault_text, scene->segfault_text_pos);
  sfText_setPosition(scene->segfault_text2, scene->segfault_text_pos2);
  sfRenderWindow_drawText(window->window, scene->segfault_text, NULL);
  sfRenderWindow_drawText(window->window, scene->segfault_text2, NULL);
}

void	loop_segfault(t_happy_scene *scene, t_window *window)
{
  sfText_setPosition(scene->segfault_text, scene->segfault_text_pos);
  sfText_setPosition(scene->segfault_text2, scene->segfault_text_pos2);
  sfText_setPosition(scene->segfault_text3, scene->segfault_text_pos3);
  sfRenderWindow_drawText(window->window, scene->segfault_text, NULL);
  sfRenderWindow_drawText(window->window, scene->segfault_text2, NULL);
  sfRenderWindow_drawText(window->window, scene->segfault_text3, NULL);
  if (time(NULL) - scene->timer == 19)
    {
      sfText_setString(scene->segfault_text3, "$> ./scroller --evil-mode");
      scene->rect_pos.x = 590.f;
      sfRectangleShape_setPosition(scene->cursor, scene->rect_pos);
    }
  if (time(NULL) - scene->timer >= 21)
    {
      scene->rect_pos.x = 430.f;
      scene->rect_pos.y = 470.f;
      sfRectangleShape_setPosition(scene->cursor, scene->rect_pos);
      sfText_setPosition(scene->segfault_text4, scene->segfault_text_pos4);
      sfRenderWindow_drawText(window->window, scene->segfault_text4, NULL);
    }
  if (time(NULL) % 2 == 1)
    sfRenderWindow_drawRectangleShape(window->window, scene->cursor, NULL);
}

void	init_segfault(t_happy_scene *scene)
{
  scene->segfault_text = sfText_create();
  scene->segfault_text2 = sfText_create();
  scene->segfault_text3 = sfText_create();
  scene->segfault_text4 = sfText_create();
  sfText_setString(scene->segfault_text, "$> ./scroller");
  sfText_setString(scene->segfault_text2, "Segmentation fault (core dumped)");
  sfText_setString(scene->segfault_text3, "$>");
  sfText_setString(scene->segfault_text4, "Loading scroller..");
  sfText_setFont(scene->segfault_text, scene->bitmap_font);
  sfText_setFont(scene->segfault_text2, scene->bitmap_font);
  sfText_setFont(scene->segfault_text3, scene->bitmap_font);
  sfText_setFont(scene->segfault_text4, scene->bitmap_font);
  sfText_setCharacterSize(scene->segfault_text, 50);
  sfText_setCharacterSize(scene->segfault_text2, 50);
  sfText_setCharacterSize(scene->segfault_text3, 50);
  sfText_setCharacterSize(scene->segfault_text4, 50);
  scene->segfault_text_pos.x = scene->segfault_text_pos2.x =
    scene->segfault_text_pos3.x = scene->segfault_text_pos4.x = 50.f;
  scene->segfault_text_pos.y = 300.f;
  scene->segfault_text_pos2.y = 350.f;
  scene->segfault_text_pos3.y = 400.f;
  scene->segfault_text_pos4.y = 450.f;
}

int		init_text(t_happy_scene *scene)
{
  sfVector2f	rect_size;

  if (!(scene->bitmap_font = sfFont_createFromFile
        (ASSET_FOLDER"/font/visitor2.ttf")))
    return (EXIT_FAILURE);
  scene->text = sfText_create();
  sfText_setString(scene->text, "Rush Scroller :)");
  sfText_setFont(scene->text, scene->bitmap_font);
  sfText_setCharacterSize(scene->text, 50);
  scene->text_pos.x = -1000.f;
  scene->text_pos.y = 100.f;
  rect_size.x = 20.f;
  rect_size.y = 35.f;
  scene->rect_pos.x = 100.f,
  scene->rect_pos.y = 420.f;
  scene->cursor = sfRectangleShape_create();
  sfRectangleShape_setSize(scene->cursor, rect_size);
  sfRectangleShape_setPosition(scene->cursor, scene->rect_pos);
  return (EXIT_SUCCESS);
}
