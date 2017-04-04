/*
** tracker.c for scroller in /home/victor/Rushs/scroller
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sat Apr  1 01:46:47 2017 Victor LE DANTEC
** Last update Sat Apr  1 14:43:13 2017 Victor LE DANTEC
*/

#include <string.h>
#include <stdio.h>
#include <time.h>
#include "scroller.h"

int			loop_tracker(t_tracker *audio)
{
  clock_t		timer2;
  float			time;

  timer2 = clock();
  time = (float)((double)timer2 - audio->timer) / CLOCKS_PER_SEC * 1000;
  if (time * 1.5f >= audio->duration[audio->index - 1])
    {
      sfMusic_stop(audio->music);
      if (audio->index == audio->nb_track)
	{
	  audio->playing = 0;
	  return (EXIT_SUCCESS);
	}
      audio->index++;
      audio->timer = clock();
      sfMusic_setPitch(audio->music, audio->frequency[audio->index - 1] / 100.f);
      sfMusic_play(audio->music);
    }
  return (EXIT_SUCCESS);
}

int		start_tracker(t_tracker *audio)
{
  char		folder[18];

  strcpy(folder, "assets/modlike/");
  audio->index = 1;
  audio->playing = 1;
  audio->file = strcat(folder, strdup(audio->file));
  if ((audio->music = sfMusic_createFromFile(audio->file)) == NULL)
    return (EXIT_FAILURE);
  audio->timer = clock();
  sfMusic_setPitch(audio->music, audio->frequency[audio->index - 1] / 100.f);
  sfMusic_play(audio->music);
  return (EXIT_SUCCESS);
}

int		parse_duration(t_tracker *audio, char line[],
			       char *token, FILE *fp)
{
  size_t	i;

  i = 0;
  while ((token = strtok(NULL, "\"")) != NULL)
    {
      audio->nb_track++;
      if ((audio->duration = realloc
	   (audio->duration, sizeof(float) * (audio->nb_track + 1))) == NULL)
	return (EXIT_FAILURE);
      audio->duration[audio->nb_track - 1] = atof(token);
      token = strtok(NULL, "\"");
    }
  fgets(line, 10000, fp);
  token = strtok(line, "\"");
  if ((audio->frequency = malloc(sizeof(float)
				 * (audio->nb_track + 1))) == NULL)
    return (EXIT_FAILURE);
  while ((token = strtok(NULL, "\"")) != NULL)
    {
      if (token[0] != ',')
	audio->frequency[i++] = atof(token);
      token = strtok(NULL, "\"");
    }
  return (EXIT_SUCCESS);
}

t_tracker	*init_tracker(char *name)
{
  t_tracker	*audio;
  FILE		*fp;
  char		line[10000];
  char		*token;

  if ((audio = calloc(1, sizeof(t_tracker))) == NULL
      || (fp = fopen(name, "r")) == NULL)
    return (NULL);
  audio->nb_track = 0;
  fgets(line, 10000, fp);
  memset(line, 0, 10000);
  fgets(line, 10000, fp);
  token = strtok(strdup(line), "\"");
  audio->file = strdup(strtok(NULL, "\""));
  memset(line, 0, 10000);
  fgets(line, 10000, fp);
  token = strtok(strdup(line), "\"");
  if (parse_duration(audio, line, token, fp) == EXIT_FAILURE)
    return (NULL);
  if (fclose(fp) == -1)
    return (NULL);
  return (audio);
}
