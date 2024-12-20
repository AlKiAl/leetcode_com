https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

https://walkccc.me/LeetCode/problems/0103/

Analoge:  
https://leetcode.com/problems/binary-tree-level-order-traversal/  
https://github.com/SkosMartren/leetcode_com/tree/main/102.%20Binary%20Tree%20Level%20Order%20Traversal -- отсюда можно взять структуру обхода для inorder / postorder

103 Binary Tree Zigzag Level Order Traversal <--> 102. Binary Tree Level Order Traversal -- разница лишь в выоде ответа. В обоих случаях используется preorder обход (сверху-вниз) и отображается высота дерева в элементы, находящиеся на этом уровне <-- 104. Maximum Depth of Binary Tree

103 Binary Tree Zigzag Level Order Traversal <-- 102. Binary Tree Level Order Traversal <-- 104. Maximum Depth of Binary Tree


push_back добавляет копию объекта (или обеспечивает перемещение, если возможно), а emplace_back создает объект непосредственно в конце вектора, т.е. без лишнего копирования (или перемещения).

____

[Разбор задачи 103 leetcode.com Binary Tree Zigzag Level Order Traversal. Решение на C++](https://www.youtube.com/watch?v=ULo9YFh6_DE&ab_channel=3.5%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B8%D0%B2%D0%BD%D0%B5%D0%B4%D0%B5%D0%BB%D1%8E) 

103a.cpp == 1 alg  
103b.cpp == 3 alg -- выяснилось, что алгоритм неоптимальный, поэтому не сохранне  

1. Самый простой способ - получить списки значений в каждом уровне слева направо - и списки через один reverse'нуть.

O(nodes) по времени  
O(nodes) память под результат  
O(height) временная память  

O(nodes) всего, без учёта результата O(height).


1-2: выбор, как заполнять порядок слева направо - рекурсивно или итеративно. 
У рекурсивного вариант O(height) по памяти дополнительно к отверу, у 
итеративного O(макс от суммы размеров двух соседних уровней)

Для среднего дерева рекурсивный вариант О(log(nodes)) итеративный O(nodes).

В любом случае худший случай временных расходов O(nodes).

Расход времени на рекурсивные вызовы обычно больше.

3. Если reverse запрещён. Что НЕ надо делать:  

нельзя добавлять в начало вектора. Почти наверно даст O(nodes^2) по времени.  
Можно представить себе итеративный вариант, когда каждую строчку смотрим с чередующейся стороны.  

В обходе помогает std::stack

Минус: хватает особых случаев.

идём слева направо - потомок left, потом right справа налево - right, потом left

Рекурсивная версия без reverse - я не представляю. 
Можно std::deque использовать - тогда потом будет копирование из deque в vector - это расходы больше, чем с reverse.

____

Перефраз условия: надо для каждого элемента найти его высота и вывести в опредлеенном порядке. В 1 тренировке, в контестах, была задача похожая, найти и, возможно, передалть! + занести инфу в 102
