/*
** windows.c for wireframe in /home/julian-ladjani/delivery/CGP/wireframe/src/window
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Dec 6 17:42:42 2016 Julian Ladjani
** Last update Jan Jan 15 22:49:01 2017 Julian Ladjani
*/

#include "my.h"

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	*buffer;

  buffer = malloc(sizeof(t_my_framebuffer));
  buffer->pixels = malloc(sizeof(sfUint8) * 4 * width * height);
  buffer->width = width;
  buffer->height = height;
  init_framebuffer(buffer);
  return (buffer);
}

void			init_framebuffer(t_my_framebuffer *buffer)
{
  int			lenght;
  int			i;

  i = -1;
  lenght = sizeof(sfUint8) * 4 * buffer->width * buffer->height;
  while (++i < lenght)
    buffer->pixels[i] = 0;
}

void			set_sprite(t_my_framebuffer *buffer,
				   sfSprite *sprite, sfTexture *texture)
{
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfTexture_updateFromPixels(texture, buffer->pixels,
			     buffer->width, buffer->height, 0, 0);
}

int			my_event(t_int_tab tab)
{
  if (sfKeyboard_isKeyPressed(sfKeyZ) ||
      sfKeyboard_isKeyPressed(sfKeyQ) ||
      sfKeyboard_isKeyPressed(sfKeyS) ||
      sfKeyboard_isKeyPressed(sfKeyD) ||
      sfKeyboard_isKeyPressed(sfKeyA) ||
      sfKeyboard_isKeyPressed(sfKeyE) ||
      my_mouse(tab) > 0)
    return (1);
  return (0);
}

void			my_window(sfRenderWindow *window, sfSprite *sprite,
				  t_int_tab tab, sfTexture *texture)
{
  while (sfRenderWindow_isOpen(window))
    {
      tab = my_window2(window, sprite, tab, texture);
      sfRenderWindow_setMouseCursorVisible(window, sfFalse);
      sfRenderWindow_clear(window, tab.colorreset);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
  sfRenderWindow_destroy(window);
}
