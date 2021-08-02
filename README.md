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

### Окружающее освещение:
* Идентификатор: A
* Коэффициент внешнего освещения в диапазоне [0.0, 1.0]
* Цвет (r, g, b) в диапазоне [0, 255]

### Камера:
* Идентификатор: C
∗ x, y, z координаты точки обзора
∗ Нормализованный вектор ориентации. В диапазоне [-1, 1] для каждой оси x, y, z
* FOV: Горизонтальное поле зрения в градусах в диапазоне [0, 180]

### Точечный свет:
* Идентификатор: L
∗ x, y, z координаты световой точки
* Коэффициент яркости света в диапазоне [0.0, 1.0]
* Цвет (r, g, b) в диапазоне [0, 255]

### Сфера:
* Идентификатор: sp
* x, y, z координаты центра сферы
* Диаметр сферы
∗ Цвет (r, g, b) в диапазоне [0, 255]

### Плоскость:
* Идентификатор: pl
* x, y, z координаты
* Нормализованный вектор ориентации. В диапазоне [-1, 1] для каждой оси x, y, z
* Цвет (r, g, b) в диапазоне [0, 255]

### Цилиндр:
* Идентификатор: cy
∗ x, y, z координаты
∗ Нормализованный вектор ориентации. В диапазоне [-1, 1] для каждой оси x, y, z
* Диаметр цилиндра
* Высота цилиндра
∗ Цвет (r, g, b) в диапазоне [0, 255]

### Параболоид
* Идентификатор: pa
* Точка экстремума (x, y, z)
* Нормализованный вектор ориентации. В диапазоне [-1, 1] для каждой оси x, y, z
* Скаляр, определяющий расстояние ядра параболоида и плоскости от точки экстремума

Для шахматной раскраски добавьте к описаниям фигур дополнительный параметр: размер шахматной ячейки.

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

## The structure of the rt file

### Ambient lighting:
* Identifier: A
* Ambient light factor in the range [0.0, 1.0]
* Color (r, g, b) in the range [0, 255]

### Camera:
* Identifier: C
* x, y, z coordinates of the viewpoint
* Normalized orientation vector. In the range [-1, 1] for each x, y, z axis
* FOV: Horizontal field of view in degrees in the range [0, 180]

### Spot light:
* Identifier: L
* x, y, z coordinates of the light point
* Luminance factor of light in the range [0.0, 1.0]
* Color (r, g, b) in the range [0, 255]

### Sphere:
* Identifier: sp
* x, y, z coordinates of the center of the sphere
* Sphere diameter
* Color (r, g, b) in the range [0, 255]

### Plane:
* Identifier: pl
* x, y, z coordinates
* Normalized orientation vector. In the range [-1, 1] for each x, y, z axis
* Color (r, g, b) in the range [0, 255]

### Cylinder:
* Identifier: cy
* x, y, z coordinates
* Normalized orientation vector. In the range [-1, 1] for each x, y, z axis
* Cylinder diameter
* Cylinder height
* Color (r, g, b) in the range [0, 255]

### Paraboloid
* Identifier: pa
* Extremum point (x, y, z)
* Normalized orientation vector. In the range [-1, 1] for each x, y, z axis
* Scalar that determines the distance of the paraboloid core and the plane from the extremum point

For a checkerboard coloring, add an additional parameter to the figure descriptions: the size of the checkerboard cell.

## Examples:
![alt text](https://github.com/danlee65071/miniRT/blob/master/png/hi.png "hi_scene")
![alt text](https://github.com/danlee65071/miniRT/blob/master/png/sub.png "sub_scene")
![alt text](https://github.com/danlee65071/miniRT/blob/master/png/test.png "test_scene")

