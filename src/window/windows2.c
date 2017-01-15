/*
** windows2.c for wolf in /home/julian-ladjani/delivery/CGP/Wolf3d/wolf3d/src/window
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Jan Jan 15 21:18:28 2017 Julian Ladjani
** Last update Jan Jan 15 23:33:36 2017 Julian Ladjani
*/

#include "my.h"

int			my_mouse(t_int_tab tab)
{
  sfVector2i		pos;

  pos = sfMouse_getPosition(NULL);
  if (pos.x < tab.moupos.x)
    return (1);
  else if (pos.x > tab.moupos.x)
    return (2);
  if (pos.x != tab.moupos.x || pos.y != tab.moupos.y)
    return (3);
  return (0);
}

t_int_tab		my_game(t_int_tab tab)
{
  t_my_raycast		rayval;
  int			type;

  rayval = raycast(tab, rayval, tab.buffer->width / 2);
  type = tab.tab[rayval.mappos.x][rayval.mappos.y];
  if (type == 16)
    sfRenderWindow_close(tab.window);
  else if (type > 9 && type < 16)
    tab.tab[rayval.mappos.x][rayval.mappos.y] = 0;
  return (tab);
}

t_int_tab		my_window2(sfRenderWindow *window, sfSprite *sprite,
				  t_int_tab tab, sfTexture *texture)
{
  sfEvent		event;

  while (sfRenderWindow_pollEvent(window, &event))
    {
      if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
	sfRenderWindow_close(window);
    }
  while (my_event(tab) == 1)
    {
      init_framebuffer(tab.buffer);
      tab = action_bonus(tab);
      if (sfMouse_isButtonPressed(sfMouseLeft))
	my_game(tab);
      sfMouse_setPosition(tab.moupos, NULL);
      draw_wireframe(tab);
      set_sprite(tab.buffer, sprite, texture);
      sfRenderWindow_clear(window, tab.colorreset);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
  return (tab);
}
