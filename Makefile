
NAME		:= philo

SRC_DIR     := src
SRCS		:= 	main.c \
				checkargs.c  \
				init.c       \
				simulator.c  \
				simulation.c \
				sim_utils.c  \
				time.c \
				utils.c

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)
#DEPS        := $(OBJS:.o=.d)

CC          := clang
CFLAGS      := -Wall -Wextra -Werror -g3 -fsanitize=thread
LDLIBS      := -lpthread
RM          := rm -f


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(LDLIBS) -o $(NAME)
	@$(info [+] CREATE $@)

clean:
	@$(RM) $(OBJS) $(DEPS)
	$(info [-] *.o files)

fclean: clean
	@$(RM) $(NAME)
	$(info [-] $(NAME))

re:
	$(MAKE) fclean
	$(MAKE) all
