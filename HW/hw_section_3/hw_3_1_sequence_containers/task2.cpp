/*
В университете проводится письменная контрольная работа. 
N студентов сдают свои работы в общую стопку, причем некоторые кладут свою работу сверху, 
а другие (считая, что чем позже их работу проверят, тем лучше) — снизу. 
Проверяются работы в том порядке, в котором лежат, начиная с верхней. 
Определите, чья работа будет проверена k-й по счёту.

Формат ввода

Первая строка содержит одно натуральное число N, не превосходящее 10000, — число студентов.

Каждая из последующих N строк содержит фамилию студента — строку из латинских букв длиной от 2 до 10 символов, 
и через пробел слово top или bottom — положил этот студент свою работу сверху или снизу.

Следующая строка содержит одно целое число M от 0 до 10000 — для какого числа работ нужно определить 
их автора.
Следующие M строк содержат по одному числу xi​ от 1 до N — номер в стопке очередной интересующей нас работы.
*/