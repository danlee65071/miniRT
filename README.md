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

## Примеры:
![alt text](https://github.com/danlee65071/miniRT/blob/master/png/hi.png "hi_scene")
![alt text](https://github.com/danlee65071/miniRT/blob/master/png/sub.png "sub_scene")
![alt text](https://github.com/danlee65071/miniRT/blob/master/png/test.png "test_scene")
