/*
Time complexity: O(nk)
Space complexity: O(1)
*/
class Solution {
public:
    string removeOccurrences(string& Str, string& part) {
	int n = Str.size(), m = part.size(), i, j;
	for (i = 0, j = 0; i < n; i++) {
		Str[j++] = Str[i];
		/*
		 если j больше или равно m, это означает, что мы увидели по крайней мере m элементов, 
   		поэтому мы можем проверить, равна ли подстрока из последних m символов part или нет. 
		 Если оно равно, мы уменьшаем переменную 'j' на m, показывая, что мы удалили эту подстроку, 
   		и теперь мы перепишем символы из индекса j.
		*/
		if (j >= m && Str.substr(j - m, m) == part) {
			j -= m;
		}
	}
	return Str.substr(0, j);        
    }
};
