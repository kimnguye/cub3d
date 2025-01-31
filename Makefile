NAME = cub3D

FILES  = 

BUILTIN = 

REDIR = events_handler.c ft_close.c ft_init.c ft_parse_map.c

PARSING = 

SRCS = $(LIBFT_SRCS:%=libft/src/%) $(FILES:%=src/%) \
		$(PARSING:%=parsing/%) $(BUILTIN:%=builtin/%) $(REDIR)\
		main.c

OBJS = $(SRCS:src/%.c=obj/%.o)

LIBFT_MAKE = make --no-print-directory -C libft
LIBFT = libft.a

LIBFT_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_strnstr.c ft_memset.c ft_memcpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_bzero.c ft_toupper.c ft_tolower.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_atoi_base.c ft_concat.c ft_isnumericlli.c\
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
		get_next_line.c get_next_line_utils.c \
		ft_printf.c ft_printf_c.c ft_printf_d.c ft_printf_i.c ft_printf_p.c \
		ft_printf_s.c ft_printf_u.c ft_printf_x.c ft_printf_X.c ft_put_lld_base.c \
		ft_pow.c

#make --no-print-directory -C [directory name]
CC = cc -g
#-Wall -Wextra -Werror -g

all: $(NAME) $(LIBFT)

#supprimer les objets
clean:
	@rm -rf obj
	@$(LIBFT_MAKE) clean
	@echo "removing obj directory"

#supprimer les objets et les programmes
fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)
	@$(LIBFT_MAKE) fclean
	@echo "removing $(NAME)"

re: fclean all

print: $(SRCS)
	@echo $(SRCS)

# Compilation du programme
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "creating minishell"
	@echo "\033[1;32m""🎉 compilation of $(NAME): ""SUCCESS !🎉""\033[0m"
# Compilation de la libft + copier la libft dans le dossier actuel
$(LIBFT): $(SRCS)
	@$(LIBFT_MAKE) all
	@cp libft/$(LIBFT) .
	@echo "copying libft.a"
# Compilation des fichiers objets
obj/%.o : src/%.c | obj
	@$(CC) -c $< -o $@

# Créer le dossier objs s'il n'existe pas
obj:
	@mkdir -p obj

.PHONY: clean fclean re all




