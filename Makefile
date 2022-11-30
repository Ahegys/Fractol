NAME = fractol.a
# ======================================================== ARCHIVES ==============================================
FILES = $(MAIN) $(SRC) $(UTILS)

SRC = ./src/window.c ./src/print_pixel.c ./src/events_hooks/events.c

UTILS = ./utils/math_code.c ./utils/draw.c

MAIN = ./main.c
# =======================================================ARCHIVES-END=============================================
FLAGS = -Wall -Werror -Wextra -lm

MLX = -lmlx -lXext -lX11

OBJS = $(FILES:%.c=%.o)

COM =  cc -c $(FLAGS) $(MLX) $< -o $@

CRET =  ar -rcs $(NAME) $@

%.o:	%.c
	@printf "\x1b[38;5;40m >> Compiling:\033[0m \x1b[38;5;196m[\033[0m \x1b[38;5;11m${COM}\033[0m \x1b[38;5;196m]\033[0m\n"
	@$(COM)
	@printf "\x1b[38;5;40m >> Convert to objects: \033[0m  \x1b[38;5;196m[\033[0m \x1b[38;5;11m${CRET}\033[0m \x1b[38;5;196m]\033[0m\n"
	@$(CRET)
	
BIN = cc $(FLAGS) $(FILES) $(MLX) -o fractal

$(NAME):	$(OBJS)
	@printf "\x1b[38;5;39m >> Generating Binary ... \033[0m \x1b[38;5;196m[\033[0m \x1b[38;5;11m${BIN}\033[0m \x1b[38;5;196m]\033[0m\n"
	@$(BIN)
all:	$(NAME)

RMO = rm -rf $(OBJS)

RMN =  rm -rf $(NAME) fractal

clean:
	@printf "\x1b[38;5;196m Removing:\033[0m \x1b[38;5;130m${RMO}\033[0m\n"
	@$(RMO)

fclean:clean
	@printf "\x1b[38;5;196m Removing:\033[0m \x1b[38;5;130m${RMN}\033[0m\n"
	@$(RMN)

pretty:
		@printf "\x1b[48;5;22mRebuilding ...\033[0m\n"

re:pretty clean all

git:
	git status
	git add *
	git commit -m "$(m)"
	git push
