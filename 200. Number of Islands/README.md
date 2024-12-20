https://leetcode.com/problems/number-of-islands/  - задача на количество компонент связности

https://walkccc.me/LeetCode/problems/200/

________

[Разбор задачи 200 leetcode.com Number of Islands. Решение на C++](https://www.youtube.com/watch?v=F66bSGiWXEA)

200a.cpp == поиск в глубину == DFS -- рекурсия не самый эффективный по времени инструмент  
200b.cpp == поиск в ширину == BFS

____

Асимптотический анализ данного кода:

Временная сложность

Временная сложность кода определяется как 
O(M×N), где M и N — это количество строк и столбцов в сетке grid соответственно.

Обоснование:
Внешние два вложенных цикла проходят по всем элементам сетки 
M×N один раз.
Каждый элемент сетки обрабатывается в функции DFS только один раз.
Функция DFS также выполняется 
O(1) для каждого вызова, так как она только посещает соседние ячейки и помечает их как посещенные. В худшем случае, каждый элемент проверяется несколько раз, но это не увеличивает общую временную сложность, так как все элементы помечаются посещенными.
Таким образом, сложность функции numIslands остается 

O(M×N).

Пространственная сложность

Пространственная сложность кода также определяется как 

O(M×N).

Обоснование:
Дополнительная память используется для стека вызовов функции DFS. В худшем случае, глубина стека вызовов может быть равна 
M×N (например, если вся сетка состоит из одного острова).
Внутри функции DFS не создается значительного дополнительного пространства, кроме стека вызовов.
Итак, общая пространственная сложность алгоритма составляет 
O(M×N) из-за возможной глубины рекурсии.
