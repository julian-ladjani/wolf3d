/*
** wireframe.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  May Dec 8 17:35:32 2016 Julian Ladjani
** Last update Jan Jan 15 17:46:18 2017 Julian Ladjani
*/

#include "my.h"

int		check_env(char **env)
{
  int		i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strcmp("DISPLAY", env[i], 6) == 0)
	return (1);
      i++;
    }
  return (0);
}

int		main(int ac, char **av, char **ae)
{
  t_int_tab	tab;

  if (ac < 2)
    {
      my_printf("%s\n", "Invalid option : wolf3d \"file.w3d\"");
      return (84);
    }
  if (check_env(ae) < 1)
    {
      my_printf("%s\n", "Install X11 Server or check env var");
      return (84);
    }
  tab = read_it(av[1]);
  if (tab.tab == NULL)
    {
      my_printf("%s\n", "Invalid file");
      return (84);
    }
  windows(tab);
  if (tab.buffer != NULL)
    free(tab.buffer);
  if (tab.tab != NULL)
    free(tab.tab);
  return (0);
}

int			windows(t_int_tab tab)
{
  sfVideoMode		mode;
  sfRenderWindow	*window;
  t_my_framebuffer	*buffer;
  sfSprite		*sprite;
  sfTexture		*texture;

  mode.width = SCREEN_WIDTH;
  mode.height = SCREEN_HEIGHT;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, "Wolf3d", sfClose, NULL);
  if (window == NULL)
    return (1);
  buffer = my_framebuffer_create(mode.width, mode.height);
  sprite = sfSprite_create();
  texture = sfTexture_create(mode.width, mode.height);
  tab.buffer = buffer;
  tab = my_init(tab);
  draw_wireframe(tab);
  set_sprite(buffer, sprite, texture);
  my_window(window, sprite, tab, texture);
  return (0);
}
