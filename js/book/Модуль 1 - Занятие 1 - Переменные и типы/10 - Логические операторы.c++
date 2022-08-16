====== Приведение типов ======
В логических операциях осуществляется приведение типов операндов к true или false. Приведение происходит если в коде обнаружен логический оператор.

Truthy и Falsy - термины, которые используются для тех значений, которые, в логической операции, приводятся к true или false, хотя изначально не были булями.

ИНТЕРЕСНО
Запомните 6 ложных(falsy) значений, приводящихся к false в логическом преобразовании: 0, NaN, null, undefined, пустая строка и false.Абсолютно все остальное приводится к true.

====== Логические операторы ======
    Есть три логических оператора, которые используются для проверки выполнения множественных выражений.
====== Логическое «И»======
Оператор && приводит все операнды к булю и возвращает значение одного из них. Левый операнд если его можно привести к false, и правый в остальных случаях.
    выражение && выражение
======
В следующем примере оба условия вернут true, поэтому результатом всего выражения будет true - вернётся значение правого операнда.
======
const age = 20;
console.log(age > 10 && age < 30); // true && true -> true
======
Если хотябы один из операндов будет приведён к false, результатом выражения будет его значение.
const age = 50;
console.log(age > 10 && age < 30); // true && false -> false
console.log(age > 80 && age < 120); // false && true -> false
======
То есть логическое «И» запинается на лжи и возвращает то на чём запнулось или последний операнд.
console.log(1 && 5); // true && true -> 5
console.log(5 && 1); // true && true -> 1
console.log(0 && 2); // false && true -> 0
console.log(2 && 0); // true && false -> 0
console.log("" && "Mango"); // false && true -> ""
console.log("Mango" && ""); // true && false -> ""
console.log("Mango" && "Poly"); // true && true -> "Poly"
console.log("Poly" && "Mango"); // true && true -> "Mango"
ИНТЕРЕСНО
При выполнении логического «И», правый операнд может не вычисляться, в случае если левый был приведен к false.

====== Логическое «ИЛИ»======
Оператор || приводит все операнды к булю и возвращает значение одного из них. Левый операнд если его можно привести к true, и правый в остальных случаях.
    выражение || выражение
В следующем примере условие слева вернёт true, поэтому результатом всего выражения будет true - вернётся значение первого операнда которое было приведено к true.
const age = 5;
console.log(age < 10 || age > 30); // true || false -> true
------
Тут результатом тоже будет true, так как хотябы один из операндов, в этом случае правый, был приведён к true.
const age = 40;
console.log(age < 10 || age > 30); // false || true -> true
------
А здесь ни одно из условий не выполняется, поэтому получаем false - значение последнего операнда.
const age = 20;
console.log(age < 10 || age > 30); // false || false -> false
------
То есть логическое «ИЛИ» запинается на правде и возвращает то на чём запнулось или последний операнд.
console.log(true || false); // true
console.log(false || true); // true
console.log(true || true); // true
console.log(3 || false); // 3
console.log(false || 3); // 3
console.log(3 || true); // 3
console.log(true || 3); // true
======
ИНТЕРЕСНО
При выполнении логического «ИЛИ», правый операнд может не вычисляться, в случае если левый был приведен к true.

====== Логическое «НЕ»======
Все операторы которые мы рассматривали до этого были бинарными - содержащими два операнда, левый и правый. Логическое «НЕ» это унарный оператор - выполняющий операцию над одним операндом справа.
!выражение
------
Оператор ! приводит операнд к булю, если необходимо, а затем делает инверсию - заменяет его на противоположный true -> false или false -> true.
console.log(!true); // false
console.log(!false); // true
console.log(!3); // !3 -> !true -> false
console.log(!"Mango"); // !"Mango" -> !true -> false
console.log(!0); // !0 -> !false -> true
console.log(!""); // !"" -> !false -> true
const isOnline = true;
const isNotOnline = !isOnline; // !isOnline -> !true -> false
======