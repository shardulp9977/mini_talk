SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra

CC = cc

FLAGS = -Wall -Wextra -Werror -I$(PRINTF)/headers -L$(PRINTF) -lftprintf

PRINTF = printf

all:
	@make -sC $(PRINTF)
	@cc $(FLAGS) server.c -o $(SERVER)
	@cc $(FLAGS) client.c -o $(CLIENT)

clean:
	@make clean -s -C $(PRINTF)

fclean: clean
	@make fclean -s -C $(PRINTF)
	@rm -f $(SERVER) $(CLIENT)

.PHONY: all clean fclean re