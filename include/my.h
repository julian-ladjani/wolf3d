/*
** my.h for my in /home/julian-ladjani/delivery/CGP/wireframe/include
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Dec 6 17:39:54 2016 Julian Ladjani
** Last update Jan Jan 15 23:30:05 2017 Julian Ladjani
*/

#ifndef MY_H_
# define MY_H_

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdarg.h>

# define BUFF_SIZE 2048
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

typedef struct			s_my_framebuffer
{
	sfUint8			*pixels;
	int			width;
	int			height;
}				t_my_framebuffer;

typedef struct			s_my_raycast
{
  	sfVector2i		from;
  	sfVector2i		to;
  	float			camerax;
  	sfVector2f		raypos;
  	sfVector2f		raydir;
  	sfVector2f		sidedist;
  	sfVector2f		deltadist;
  	sfVector2i		mappos;
  	int			side;
   	float			perpwalldist;
  	int			hit;
  	sfVector2f		step;
}				t_my_raycast;

typedef struct			s_int_tab
{
  	int			**tab;
  	sfRenderWindow		*window;
  	int			xlenght;
  	int			ylenght;
  	sfVector2i		mapsize;
	sfVector2f		pos;
  	sfVector2i		moupos;
  	sfVector2f		dir;
  	sfVector2f		plane;
  	float			walk;
  	float			rotspeed;
  	float			run;
  	t_my_framebuffer	*buffer;
 	sfColor			*color;
  	sfColor			colorreset;
}				t_int_tab;

void				my_put_pixel(t_my_framebuffer *buffer, int x,
					     int y, sfColor color);
void				my_draw_line(t_my_framebuffer *buffer, sfVector2i from,
					     sfVector2i to, sfColor color);
void				my_draw_line_case_2(t_my_framebuffer *buffer,
						    sfVector2i from, sfVector2i to,
						    sfColor color);
void				my_draw_line_case_1(t_my_framebuffer *buffer,
						    sfVector2i from, sfVector2i to,
						    sfColor color);
void				set_sprite(t_my_framebuffer *buffer,
					   sfSprite *sprite, sfTexture *texture);
void				my_window(sfRenderWindow *window, sfSprite *sprite,
					  t_int_tab tab, sfTexture *texture);
void				draw_it(t_int_tab tab);
void				init_framebuffer(t_my_framebuffer *buffer);

int				char_number_dot(char *buff);
int				check_char_number_line(char *buff);
int				char_number_line(char *buff);
int				tab_number(char *buff);
int				*set_in_intab(char *buff, int *tab);
int				char_number(char *buff);
int				my_getnbrprintf(char *str);
int				my_mouse(t_int_tab tab);
int				my_printf(char *str, ...);
int				draw_wireframe(t_int_tab tab);
int				check_buffer(char *buff);
int				my_event(t_int_tab tab);
int				windows(t_int_tab tab);
int				my_strcmp(char *s1, char *s2, int n);

char				*my_realloc(char *str, int lenght);

t_int_tab			calc_line_lenght(t_int_tab tab);
t_int_tab			parse_my_int(char *buff);
t_int_tab			read_it(char *path);
t_int_tab			action_bonus(t_int_tab tab, sfEvent event);
t_int_tab			check_bonus(t_int_tab tab);
t_int_tab			my_init(t_int_tab tab);
t_int_tab			player_pos(t_int_tab tab);
t_int_tab			my_window2(sfRenderWindow *window,
					   sfSprite *sprite,
				  t_int_tab tab, sfTexture *texture);
t_int_tab			my_game(t_int_tab tab);

t_my_raycast			raycast(t_int_tab tab, t_my_raycast rayval, int x);
t_my_raycast			calc_sidedist(t_my_raycast rayval);
t_my_raycast			calc_dda(t_int_tab tab, t_my_raycast rayval);
t_my_raycast			calc_line(t_int_tab tab, t_my_raycast rayval, int x);

t_my_framebuffer		*my_framebuffer_create(int width, int height);

#endif /* !MY_H_ */
