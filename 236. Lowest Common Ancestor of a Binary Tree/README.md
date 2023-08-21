https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

тематический аналог:  
  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
  https://contest.yandex.ru/contest/29403/problems/C/

https://walkccc.me/LeetCode/problems/0236/

[Разбор задачи 236 leetcode.com Lowest Common Ancestor of a Binary Tree. Решение на C++](https://www.youtube.com/watch?v=q3z4CkOhMa4&ab_channel=3.5%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B8%D0%B2%D0%BD%D0%B5%D0%B4%D0%B5%D0%BB%D1%8E)

Если в рекурсивном вызове какой-то из аргументов изменяется по ссылке -- то он изменяется во всем стеке рекурсивных вызовов
______________________

O(n) по времени и O(h) по памяти - на обход дерева  
В обходе собираем статистику:  
- есть ли в поддереве р
- если ли в поддереве q
- какой их lca  

Эту тройку возвращаем из рекурсивного вызова. 
Когда есть такая информация по левому и правому поддереву - объединяем. 

______________________

<img src="https://github.com/SkosMartren/useful-materials/blob/main/for_236_leetcode_1.png" width="750" height="550"/>
____

https://www.techiedelight.com/ru/find-lowest-common-ancestor-lca-two-nodes-bst/  
https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/

Ме Бэ, [7/10/2023 12:49 PM]
а можно утверждать, что LCA двух нод [node_1, node_2], лежащих в одном поддереве, это первая нода с такой минимальной высотой (мин. высота == ближе к корню),  что выполняется неравенство: 

node_1 <= LCA <= node_2

Я вот доказать это не могу....

Если node_1, node_2 в разных поддеревьях, то ответ — корень дерева, а вот когда они в одном поддереве BST, не очень понимаю как доказать / обработать...

В🎄лерия, [7/10/2023 12:59 PM]
Это вроде определение лса

Slava Muravjev, [7/10/2023 1:01 PM]
Не бывает разных поддеревьев в вакууме

Slava Muravjev, [7/10/2023 1:01 PM]
Все вершины всегда лежат в поддереве корня

Slava Muravjev, [7/10/2023 1:02 PM]
Но могут лежать и в поддереве более низкой вершины

Slava Muravjev, [7/10/2023 1:02 PM]
Соответственно самая низшая вершина, в поддереве лежат обе вершины, и есть lca

Slava Muravjev, [7/10/2023 1:02 PM]
Корень - лишь частный случай

Slava Muravjev, [7/10/2023 1:02 PM]
Ты не должен как-то отделять его в своем алгоритме

Slava Muravjev, [7/10/2023 1:15 PM]
https://e-maxx.ru/algo/lca

Slava Muravjev, [7/10/2023 1:15 PM]
https://e-maxx.ru/algo/lca_simpler
