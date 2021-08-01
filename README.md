# miniRT
## Описание проекта
Этот проект посвящен теме трассировки лучей. Программа может изобразить 4 геометрических фигур: сфера, плоскость, цилиндр и параболоид. В сцене могут существовать одна камера, одно окружающее освещение, несколько точечных источников света и переменное количество фигур. Фигуры поддерживают полную модель Фонга (т.е. добавлена зеркальность), а также шахматную раскраску. Проект выполнен на ОП macos.

## Проверка на [norminette v3](https://github.com/42School/norminette)
Если у вас не установлен morminette, то выполните следующую инструкцию:

source venv/bin/activate

Далее вы можете проверить файлы с расширениями .h и .c. Для этого напишите в командной строке:

norminette srcs includes libft

Должно быть примерно так:

![alt text](https://github.com/danlee65071/miniRT/blob/master/png/norm1.png "norm1")
![alt text](https://github.com/danlee65071/miniRT/blob/master/png/norm2.png "norm2")

## Для запуска прогарммы выполните следующие указания в командной строке:
1. make
2. ./miniRT "имя файла".rt

## Структура rt файла

Окружающее освещение:
* Идентификатор: A
* Коэффициент внешнего освещения в диапазоне [0.0,1.0]
* Цвет (r, g, b) в диапазоне [0-255]

## Примеры:
![alt text](https://github.com/danlee65071/miniRT/blob/master/png/hi.png "hi_scene")
![alt text](https://github.com/danlee65071/miniRT/blob/master/png/sub.png "sub_scene")
![alt text](https://github.com/danlee65071/miniRT/blob/master/png/test.png "test_scene")

## Project Description
This project focuses on the topic of ray tracing. The program can draw 4 geometric shapes: a sphere, a plane, a cylinder and a paraboloid. There is one camera, one ambient light, several point lights, and a variable number of shapes in a scene. The figures are a complete Phong model, as well as a checkerboard coloring. The project is made on OS macos.

## Checking for [norminette v3](https://github.com/42School/norminette)
If you do not have a Morminette installed, then check the instructions:

source venv/bin/activate

Next, you can check files with .h and .c extensions. To do this, write in the command line:

norminette srcs includes libft

It should be something like this:

![alternative text](https://github.com/danlee65071/miniRT/blob/master/png/norm1.png "norm1")
![alternative text](https://github.com/danlee65071/miniRT/blob/master/png/norm2.png "norm2")

## To run the program, do the following on the command line:
1. make
2. ./miniRT "filename".rt

## Examples:
![alt text](https://github.com/danlee65071/miniRT/blob/master/png/hi.png "hi_scene")
![alt text](https://github.com/danlee65071/miniRT/blob/master/png/sub.png "sub_scene")
![alt text](https://github.com/danlee65071/miniRT/blob/master/png/test.png "test_scene")

