.SILENT:

# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

GREEN   = \033[0;32m
RED     = \033[0;31m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
RESET   = \033[0m

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

# Output Name
NAME = push_swap
NAME_BONUS = checker

# Directories
OBJ_DIR = Obj

SORT = \
		algo_simple.c \
		chunk.c \
		quick_turk.c \
		greedy.c \
		greedy_2.c 

OPS = \
		move_a.c \
		move_ab.c \
		move_b.c \

PSWAP = \
		helper_small.c \
		is_sort_and_print.c

COM = \
		parsing.c \
		push_swap.c \
		init.c

CHECK = \
		checker.c

SRCS =	\
		$(PSWAP) \
		$(SORT) \
		$(OPS)	\
		$(COM)
		

BONUS_SRCS = \
			$(CHECK) \
			$(PARS) \
			$(OPS) \
			$(COM)

INCLUDES = push_swap.h

# Disorder percentage for random tests (0 to 100)
DISORDER ?= 20
ifeq ($(origin N), command line)
DISORDER := $(N)
endif

define RANDOM_RULE
	$(MAKE) bonus >/dev/null; \
	SIZE=$(1); \
	DIS=$(DISORDER); \
	awk -v n="$$SIZE" -v p="$$DIS" 'BEGIN{ srand(); for(i=1;i<=n;i++) a[i]=i; swaps=int(n*p/100); for(i=0;i<swaps;i++){ u=int(rand()*n)+1; v=int(rand()*n)+1; tmp=a[u]; a[u]=a[v]; a[v]=tmp } for(i=1;i<=n;i++) print a[i]; }' > liste.txt; \
	VALS="$$(cat liste.txt)"; \
	if [ $(3) -eq 1 ]; then \
		make re && ./push_swap $(2) $$VALS --bench; \
	else \
		make re && ./push_swap $(2) $$VALS; \
	fi
endef

# Compilation
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -I.

# Object name
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
OBJSBONUS = $(patsubst %.c,$(OBJ_DIR)/bonus_%.o,$(BONUS_SRCS))

#
TOTAL := $(words $(OBJS))
CURRENT := 0

TOTAL_BONUS := $(words $(OBJSBONUS))
CURRENT_BONUS := 0

# **************************************************************************** #
#									Rules									   #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) 
	printf "$(CYAN)Création du programme $(NAME)...$(RESET) "
	if cc -o $@ $(OBJS) $(LIBFT) 2>/dev/null; then \
		echo "$(GREEN)✓$(RESET)"; \
	else \
		echo "$(RED)✗$(RESET)"; \
		cc -o $@ $(OBJS); \
	fi

$(OBJ_DIR)/bonus_%.o: %.c $(INCLUDES) | $(OBJ_DIR)
	$(eval CURRENT_BONUS=$(shell echo $$(($(CURRENT_BONUS)+1))))
	printf "$(CYAN)[bonus %2d/%2d]$(RESET) %-30s " $(CURRENT_BONUS) $(TOTAL_BONUS) $(notdir $<)
	if $(CC) $(CFLAGS) -c $< -o $@ 2>/dev/null; then \
		echo "$(GREEN)✓$(RESET)"; \
	else \
		echo "$(RED)✗$(RESET)"; \
		$(CC) $(CFLAGS) -c $< -o $@; \
	fi

$(OBJ_DIR)/%.o: %.c $(INCLUDES) | $(OBJ_DIR)
	$(eval CURRENT=$(shell echo $$(($(CURRENT)+1))))
	printf "$(CYAN)[%2d/%2d]$(RESET) %-30s " $(CURRENT) $(TOTAL) $(notdir $<)
	if $(CC) $(CFLAGS) -c $< -o $@ 2>/dev/null; then \
		echo "$(GREEN)✓$(RESET)"; \
	else \
		echo "$(RED)✗$(RESET)"; \
		$(CC) $(CFLAGS) -c $< -o $@; \
	fi

$(OBJ_DIR): 
	printf "$(CYAN)Création du répertoire $(OBJ_DIR)...$(RESET) "
	if mkdir -p $(OBJ_DIR) 2>/dev/null; then \
		echo "$(GREEN)✓$(RESET)"; \
	else \
		echo "$(RED)✗$(RESET)"; \
		mkdir -p $(OBJ_DIR); \
	fi

bonus: $(OBJSBONUS)
	printf "$(CYAN)Création du programme $(NAME_BONUS)...$(RESET) "
	if cc -o $(NAME_BONUS) $(OBJSBONUS) $(LIBFT) 2>/dev/null; then \
		echo "$(GREEN)✓$(RESET)"; \
	else \
		echo "$(RED)✗$(RESET)"; \
		cc -o $(NAME_BONUS) $(OBJSBONUS) $(LIBFT); \
	fi

randomSimple100Check:
	$(call RANDOM_RULE,100,--simple,0)

randomMedium100Check:
	$(call RANDOM_RULE,100,--medium,0)

randomComplex100Check:
	$(call RANDOM_RULE,100,--complex,0)

randomSimple500Check:
	$(call RANDOM_RULE,500,--simple,0)

randomMedium500Check:
	$(call RANDOM_RULE,500,--medium,0)

randomComplex500Check:
	$(call RANDOM_RULE,500,--complex,0)

randomAdaptive100Check:
	$(call RANDOM_RULE,100,--adaptive,0)

randomAdaptive500Check:
	$(call RANDOM_RULE,500,--adaptive,0)

randomSimple100Bench:
	$(call RANDOM_RULE,100,--simple,1)

randomMedium100Bench:
	$(call RANDOM_RULE,100,--medium,1)

randomComplex100Bench:
	$(call RANDOM_RULE,100,--complex,1)

randomSimple500Bench:
	$(call RANDOM_RULE,500,--simple,1)

randomMedium500Bench:
	$(call RANDOM_RULE,500,--medium,1)

randomComplex500Bench:
	$(call RANDOM_RULE,500,--complex,1)

randomAdaptive100Bench:
	$(call RANDOM_RULE,100,--adaptive,1)

randomAdaptive500Bench:
	$(call RANDOM_RULE,500,--adaptive,1)

clean: cleanLibft
	printf "$(CYAN)Suppression de $(OBJ_DIR)...$(RESET) "
	if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR) && \
		echo "$(GREEN)✓ Fichiers objets supprimés$(RESET)"; \
	else \
		echo "$(YELLOW)⚠ Rien à nettoyer$(RESET)"; \
	fi

cleanLibft:
	printf "$(CYAN)Suppression de 42-libft...$(RESET) "
	if [ -d "42-libft" ]; then \
		rm -rf 42-libft && \
		echo "$(GREEN)✓ Dossier 42-libft supprimés$(RESET)"; \
	else \
		echo "$(YELLOW)⚠ Rien à nettoyer$(RESET)"; \
	fi

fclean: clean
	printf "$(CYAN)Suppression de $(NAME)...$(RESET) "
	if rm $(NAME) 2>/dev/null; then \
		echo "$(GREEN)✓$(RESET)"; \
	else \
		echo "$(YELLOW)⚠ Déjà supprimée$(RESET)"; \
	fi
	printf "$(CYAN)Suppression de $(NAME_BONUS)...$(RESET) "
	if rm $(NAME_BONUS) 2>/dev/null; then \
		echo "$(GREEN)✓$(RESET)"; \
	else \
		echo "$(YELLOW)⚠ Déjà supprimée$(RESET)"; \
	fi

re: fclean all

.PHONY: clean fclean re bonus libft \
	randomSimple100Check randomMedium100Check \
	randomComplex100Check randomSimple500Check \
	randomMedium500Check randomComplex500Check \
	randomAdaptive100Check randomAdaptive500Check \
	randomSimple100Bench randomMedium100Bench \
	randomComplex100Bench randomSimple500Bench \
	randomMedium500Bench randomComplex500Bench \
	randomAdaptive100Bench randomAdaptive500Bench
