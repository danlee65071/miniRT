# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 19:13:21 by hcharlsi          #+#    #+#              #
#    Updated: 2021/07/20 19:50:36 by hcharlsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Имя проекта
NAME = miniRT

#Переменная SRCS будет хранить пути си файлов от директории srcs
SRCS = minirt.c init_scene.c

#Добавление файлов UTILS
UTILS_SRCS = utils1.c utils2.c keyboard.c vectors_operations.c color_utils.c \
				color_utils_2.c vectors_operations_2.c vectors_operations_3.c \
				utils3.c
#Папка с си файлами в директории utils
#Эта переменная нужна для создвния папок в будующей папке objs
DIR_UTILS = utils
#addprefix добавляет префикс utils/ ко всем названиям си файлов в директории utils
PATH_UTILS = $(addprefix $(DIR_UTILS)/, $(UTILS_SRCS))
#К переменной SRCS добавляем содержание переменной PATH_UTILS
SRCS += $(PATH_UTILS)
#К перемнной DIRS добавляем сожержание переменной DIR_UTILS
DIRS = $(DIR_UTILS)

#Добавление файлов для парсинга
PARSER_SRCS = parser.c get_next_line.c parse_ambient.c parse_camera.c parse_light.c\
				parse_sphere.c parse_plane.c parse_cylinder.c parse_paraboloid.c
DIR_PARSER = parser
PATH_PARSER = $(addprefix $(DIR_PARSER)/, $(PARSER_SRCS))
SRCS += $(PATH_PARSER)
DIRS += $(DIR_PARSER)

#Добавление файлов для работы со сферой
SPHERE_SRCS = add_sphere.c intersect_ray_sphere.c closest_intersection_sphere.c
DIR_SPHERE = sphere
PATH_SPHERE = $(addprefix $(DIR_SPHERE)/, $(SPHERE_SRCS))
SRCS += $(PATH_SPHERE)
DIRS += $(DIR_SPHERE)

#Добавление файлов для работы с плоскостью
PLANE_SRCS = add_plane.c closest_intersection_plane.c intersect_ray_plane.c
DIR_PLANE = plane
PATH_PLANE = $(addprefix $(DIR_PLANE)/, $(PLANE_SRCS))
SRCS += $(PATH_PLANE)
DIRS += $(DIR_PLANE)

#Добавление файлов для работы с цилиндром
CYLINDER_SRCS = add_cylinder.c closest_intersection_cylinder.c intersect_ray_cylinder.c
DIR_CYLINDER = cylinder
PATH_CYLINDER = $(addprefix $(DIR_CYLINDER)/, $(CYLINDER_SRCS))
SRCS += $(PATH_CYLINDER)
DIRS += $(DIR_CYLINDER)

#Добавление файлов для работы с параболоидом
PARABOLOID_SRCS = add_paraboloid.c closest_intersection_paraboloid.c intersect_ray_paraboloid.c
DIR_PARABOLOID = paraboloid
PATH_PARABOLOID = $(addprefix $(DIR_PARABOLOID)/, $(PARABOLOID_SRCS))
SRCS += $(PATH_PARABOLOID)
DIRS += $(DIR_PARABOLOID)

#Добавление файлов для работы с кватернионами
QUAT_SRCS = quaternions_operations.c quaternions_operations_2.c
DIR_QUAT = quaternions
PATH_QUAT = $(addprefix $(DIR_QUAT)/, $(QUAT_SRCS))
SRCS += $(PATH_QUAT)
DIRS += $(DIR_QUAT)

#Добавления файлов рендеринга
RENDERING_SRCS = trace_ray.c rendering.c closest_intersection.c compute_lightning.c\
					add_light.c chess_color.c
DIR_RENDERING = rendering
PATH_RENDEIRNG = $(addprefix $(DIR_RENDERING)/, $(RENDERING_SRCS))
SRCS += $(PATH_RENDEIRNG)
DIRS += $(DIR_RENDERING)

#Добавление полного пути к си файлам
DIR_SRCS = srcs
PATH_SRCS = $(addprefix $(DIR_SRCS)/, $(SRCS))

#Объявление переменных для объектных файлов
OBJS = $(patsubst %.c, %.o, $(SRCS))
DIR_OBJS = objs
CREATED_DIRS = $(addprefix $(DIR_OBJS)/, $(DIRS))
PATH_OBJS = $(addprefix $(DIR_OBJS)/, $(OBJS))

#Добавление хэдеров
HEADERS = minirt.h ambient.h camera.h utils.h shapes.h parser.h sphere.h plane.h\
			cylinder.h rendering.h paraboloid.h
DIR_HEADERS = includes
PATH_HEADERS = $(addprefix $(DIR_HEADERS)/, $(HEADERS))

#Добавление библиотеки libft
LIBFT = libft.a
LIBFT_DIR = libft

CC = clang

FLAGS = -Wall -Werror -Wextra -g

#Добавление библиотеки mlx
MLX = libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_DIR = mlx

RM = rm -rf

#Добавление переменных для изменения цвета текста
GREEN = \033[0;32m
RESET = \033[0m

#Главное правило
all: $(NAME)

#Оператор @ используется для того, чтобы не выводились инструкции исполнения комманд

#Для выполнения all нужно выполнить цель $(NAME)
#Цель $(NAME) зависит от целей представленных ниже
#Пока не будут выполненые зависимости не будет выполняться цель $(NAME)
#Завсисмость write_logo абстрактная, т.е. не создает физического объекта
#Для того, чтобы получить бинарник необходимы объектные файлы, поэтому есть зависимоть от $(PATH_OBJS)
$(NAME): write_logo $(PATH_OBJS)
	@#Вывод на экран строки "\nObjects was created" с зеленным цветом
	@echo "$(GREEN)\nObjects was created $(RESET)"
	@#Рекурсивный вызов make в директории libft, в директории libft получится архив libft.a
	@make -sC $(LIBFT_DIR)
	@#Копирование архива libft.a из директории libft в директерию проекта
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@echo "$(GREEN)\nLibft was compiled $(RESET)"
	@#Рекурсивный вызов make в директории mlx, в директории mlx получится архив libmlx.dylib, а также передача всех предупреждений на нулевое устройство (2> /dev/null)
	@make -sC $(MLX_DIR) 2> /dev/null
	@#Копирование архива libmlx.dylib из директории mlx в директерию проекта
	@cp $(MLX_DIR)/$(MLX) .
	@echo "$(GREEN)\nMLX was compiled $(RESET)"
	@#Линковка программы и получения бинарника с именем, которое сожержит переменная $(NAME)
	@$(CC) $(FLAGS) $(MLX_FLAGS) -I $(DIR_HEADERS) $(LIBFT) $(PATH_OBJS) -o $@
	@echo "$(GREEN)miniRT was compiled $(RESET)"

#Цель write_logo не имеет зависимостей
#Она существует только лишь для красоты проекта
#Эта цель выводит логотип в самом начале при сборке проекта
write_logo:
	@echo "$(GREEN)\n\
		███╗░░░███╗██╗███╗░░██╗██╗██████╗░████████╗\n\
		████╗░████║██║████╗░██║██║██╔══██╗╚══██╔══╝\n\
		██╔████╔██║██║██╔██╗██║██║██████╔╝░░░██║░░░\n\
		██║╚██╔╝██║██║██║╚████║██║██╔══██╗░░░██║░░░\n\
		██║░╚═╝░██║██║██║░╚███║██║██║░░██║░░░██║░░░\n\
		╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝╚═╝░░╚═╝░░░╚═╝░░░\n\
    $(RESET)"

#Получение объектных файлов
#Для удобства объектные файлы были помещены в отдеьную директорию
#Объектные файлы зависят от си файлов
#Ещё есть зависимость от хэдеров. Это нужно, чтобы при измении хэдера проект перекомпилировался
$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(PATH_HEADERS)
	@mkdir -p $(DIR_OBJS) $(CREATED_DIRS)
	@$(CC) $(FLAGS) -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(DIR_HEADERS) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

#Абстрактная цель clean
clean:
	@#Удаление директории objs с объектными файлами
	@$(RM) $(DIR_OBJS)
	@#Удаление libmlx.dylib в директории проекта
	@$(RM) $(MLX)
	@#Удаление libft.a в директории проекта
	@$(RM) $(LIBFT)
	@#Рекурсивный вызов make fclean в директории libft
	@make fclean -sC $(LIBFT_DIR)
	@#Рекурсивный вызов make clean в директории mlx
	@make clean -sC $(MLX_DIR)
	@echo "$(GREEN) clean instruction was executed $(RESET)"

#Абстрактная цель fclean, зависящая от clean
fclean: clean
	@#Удаление бинарного файла с именем NAME
	@$(RM) $(NAME)
	@echo "$(GREEN) fclean instruction was executed $(RESET)"

#Абстактная цель re, зависящая от fclean и all
re: fclean all

#Т.к. all clean fclean re write_logo абстрактные цели , то через мы .PHONY указываем
#Что они не связаны с физическими файлами такого же названия (если вдруг такое будет)
.PHONY: all clean fclean re write_logo
