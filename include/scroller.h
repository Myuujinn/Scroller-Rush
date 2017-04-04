/*
** scroller.h for scroller in /home/victor/Rushs/scroller
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Mar 31 21:58:44 2017 Victor LE DANTEC
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#undef	EXIT_FAILURE
#define	EXIT_FAILURE	84

#define WINDOW_HEIGHT	900
#define	WINDOW_WIDTH	900

#define ASSET_FOLDER	"./assets"

typedef struct		s_tracker
{
  char			*file;
  sfMusic		*music;
  size_t		nb_track;
  float			*duration;
  float			*frequency;
  clock_t		timer;
  size_t		index;
  char			playing;
}			t_tracker;

typedef struct          s_window
{
  sfVideoMode		mode;
  sfRenderWindow	*window;
  sfEvent		event;
  sfTexture		*texture;
  sfSprite		*sprite;
}			t_window;

typedef struct		s_evil_scene
{
  sfSprite		*bunny;
  sfTexture		*bunny_texture;
  sfVector2f		bunny_pos;
  sfSprite		*taz;
  sfTexture		*taz_texture;
  sfVector2f		taz_pos;
  sfIntRect		*rect_taz;
  clock_t		taz_timer;
  sfRectangleShape	*background;
  sfColor		bg_color;
  sfText		*text;
  sfText		*text2;
  sfText		*text3;
  sfText		*text4;
  sfVector2f		text_pos;
  sfVector2f		text_pos2;
  sfVector2f		text_pos3;
  sfVector2f		text_pos4;
  sfFont		*bitmap_font;
  sfVector2f		scale_text4;
  sfSprite		*scroller;
  sfTexture		*scroller_texture;
  sfVector2f		scroller_pos;
}			t_evil_scene;

typedef struct		s_happy_scene
{
  sfMusic		*music;
  sfTexture		*fence_texture;
  sfSprite		*fence;
  sfTexture		*cloud_texture;
  sfSprite		*cloud;
  sfTexture		*grass_texture;
  sfSprite		*grass;
  sfSprite		*grass2;
  sfTexture		*background_texture;
  sfSprite		*background;
  sfSprite		*background2;
  sfVector2f		fence_pos;
  sfVector2f		cloud_pos;
  sfVector2f		grass_pos;
  sfVector2f		grass2_pos;
  sfVector2f		background_pos;
  sfVector2f		background2_pos;
  sfFont		*bitmap_font;
  sfText		*text;
  sfVector2f		text_pos;
  float			text_move_pos;
  sfSprite		*taz;
  sfTexture		*taz_texture;
  sfVector2f		taz_pos;
  sfIntRect		*rect_taz;
  clock_t		taz_timer;
  sfSprite		*bug;
  sfTexture		*bug_texture;
  sfUint8		*bug_pixel_buffer;
  clock_t		timer;
  sfText		*segfault_text;
  sfText		*segfault_text2;
  sfText		*segfault_text3;
  sfText		*segfault_text4;
  sfVector2f		segfault_text_pos;
  sfVector2f		segfault_text_pos2;
  sfVector2f		segfault_text_pos3;
  sfVector2f		segfault_text_pos4;
  sfRectangleShape	*cursor;
  sfVector2f		rect_pos;
}			t_happy_scene;

typedef struct		s_text_scene
{
  sfTexture		*text_texture;
  sfSprite		*texte;
  sfVector2f		*text_pos;
}			t_text_scene;

int		init_cloud(t_happy_scene *);
int		init_background(t_happy_scene *);
int		init_grass(t_happy_scene *);
int		init_text(t_happy_scene *);
int		init_taz(t_happy_scene *);
int		init_bug_screen(t_happy_scene *);
void		init_segfault(t_happy_scene *);
void		move_text_sin_wave(t_happy_scene *);
int		init_happy_scene(t_happy_scene *);
int		loop_happy_scene(t_window *, t_happy_scene *, t_evil_scene *);
int		loop_taz(t_happy_scene *);
void		loop_bug(t_happy_scene *, t_window *);
void		loop_segfault(t_happy_scene *, t_window *);

t_tracker	*init_tracker(char *);
int		start_tracker(t_tracker *);
int		loop_tracker(t_tracker *);

int		play_music(t_happy_scene *);

void		loop_bunny(t_evil_scene *, t_window *);
int		init_bunny(t_evil_scene *);
int		init_evil_scene(t_evil_scene *);
void		loop_evil_scene(t_evil_scene *, t_window *);
int		loop_evil_taz(t_evil_scene *, t_window *);
int		init_evil_taz(t_evil_scene *);
void		init_bg_evil(t_evil_scene *);
void		loop_bg_evil(t_evil_scene *, t_window *);
int		init_evil_text(t_evil_scene *);
void		loop_evil_text(t_evil_scene *, t_window *);
int		init_scroller_evil(t_evil_scene *);
void		loop_scroller_evil(t_evil_scene *, t_window *);

void		loop_sorry(t_happy_scene *, t_window *);
