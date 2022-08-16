﻿===Колбэк-функции===
---
Функции не отличаются от чисел, 
строк или массивов - это просто специальный тип данных (объект высшего порядка), 
значение, которое можно хранить в переменной или передавать как аргумент в другую функцию.
---
function greet(name) {
  return `Добро пожаловать ${name}.`;
}
// Вызываем функцию greet и выводим результат в консоль
console.log(greet("Манго")); // Добро пожаловать Манго.
// Выводим функцию greet в консоль не вызывая её
console.log(greet); // ƒ greet() { return `Добро пожаловать ${name}.`; }
---
В первом логе мы вызываем функцию greet при помощи круглых скобок 
и в консоль выводится результат её выполнения. 
Во втором логе передаётся ссылка на функцию, 
а не результат вызова (отсуствуют круглые скобки), 
поэтому в консоль выводится её тело. Это значит, 
что функцию можно присвоить в переменную или передать как аргумент другой функции.
---
Функция обратного вызова (callback, колбэк) - это функция, 
которая передаётся другой функции в качестве аргумента и та, 
в свою очередь, вызывает переданную функцию.
---
Функция высшего порядка(higher order function) - функция, 
принимающая в качестве параметров другие функции 
или возвращающая функцию как результат.
---
// Колбэк-функция
function greet(name) {
  console.log(`Добро пожаловать ${name}.`);
}
// Функция высшего порядка
function registerGuest(name, callback) {
  console.log(`Регистрируем гостя ${name}.`);
  callback(name);
}
registerGuest("Манго", greet);
---
Мы передали ссылку на функцию greet как аргумент, 
поэтому она будет присвоена в параметр callback 
и вызвана внури функции registerGuest через круглые скобки.
Имя параметра для колбэка может быть произвольным, 
главное помнить, что значением будет функция.
---
===Инлайн колбэки===
---
Если колбэк-функция маленькая и нужна только для передачи аргументом, 
её можно объявить прямо при вызове функции в которую передаём колбэк. 
Такая функция будет доступна только как значение параметра и больше нигде в коде.
---
function registerGuest(name, callback) {
  console.log(`Регистрируем гостя ${name}.`);
  callback(name);
}
// Передаём инлайн функцию greet как колбэк
registerGuest("Манго", function greet(name) {
  console.log(`Добро пожаловать ${name}.`);
});
// Передаём инлайн функцию notify как колбэк
registerGuest("Поли", function notify(name) {
  console.log(`Уважаемый(ая) ${name}, ваш номер будет готов через 30 минут.`);
});
---
===Несколько колбэков===
---
Функция может принимать произвольное количество колбэков. 
Например, представим что мы пишем логику принятия звонков для телефона. 
Программа должна включить автоответчик если абонент недоступен, 
или соединить звонок в противном случае. 
Доступность абонента будем имитировать генератором случайного числа, 
чтобы между разными вызовами функции можно было получить различные результаты.
---
function processCall(recipient) {
  // Имитируем доступность абонента случайным числом
  const isRecipientAvailable = Math.random() > 0.5;

  if (!isRecipientAvailable) {
    console.log(`Абонент ${recipient} недоступен, оставьте сообщение.`);
    // Логика активации автоответчика
  } else {
    console.log(`Соединяем с ${recipient}, ожидайте...`);
    // Логика принятия звонка
  }
}
processCall("Манго");
---
Проблема такого подхода в том, 
что функция processCall делает слишком много 
и привязывает проверку доступности абонента к двум заранее определённым действиям. 
Что если в будущем вместо автоответчика нужно будет оставлять голограмму?
---
Мы могли бы написать функцию так, 
чтобы она возвращала какое-то значение 
и потом по результату её выполнения делать проверки 
и выполнять нужный код. 
Но проверки не относятся к внешнему коду 
и будут его засорять.
---
Выполним рефакторинг функции так, 
чтобы она принимала два колбэка onAvailable и onNotAvailable, 
и вызывала их по условию.
---
function processCall(recipient, onAvailable, onNotAvailable) {
  // Имитируем доступность абонента случайным числом
  const isRecipientAvailable = Math.random() > 0.5;

  if (!isRecipientAvailable) {
    onNotAvailable(recipient);
    return;
  }

  onAvailable(recipient);
}
function takeCall(name) {
  console.log(`Соединяем с ${name}, ожидайте...`);
  // Логика принятия звонка
}
function activateAnsweringMachine(name) {
  console.log(`Абонент ${name} недоступен, оставьте сообщение.`);
  // Логика активации автоответчика
}
function leaveHoloMessage(name) {
  console.log(`Абонент ${name} недоступен, записываем голограмму.`);
  // Логика записи голограммы
}
processCall("Манго", takeCall, activateAnsweringMachine);
processCall("Поли", takeCall, leaveHoloMessage);
---
Колбэки применяются для обработки действий пользователя на странице, 
при обработке запросов на сервер, 
выполнения заранее неизвестных функций и т. п. 
В этом и заключается их суть - это функции предназначенные для отложенного выполнения.
---
===Абстрагирование повторения===
---
Абстракция - скрытие деталей реализации. 
Позволяет думать о задачах на более высоком (абстрактном) уровне. 
Функции это хороший способ построения абстракций.
---
Например, скрипт выполняет какое-то действие определенное количество раз.
Для этого можно написать цикл for.
---
for (let i = 0; i < 10; i += 1) {
  console.log(i);
}
---
Можем ли мы абстрагировать 
«делать что-то N раз» как функцию? - да, 
напишем функцию, которая вызывает console.log() N раз.
---
function repeatLog(n) {
  for (let i = 0; i < n; i += 1) {
    console.log(i);
  }
}
repeatLog(5);
---
Но что, если мы хотим сделать что-то, 
кроме логирования чисел? 
Поскольку «делать что-то» можно представить как функцию, 
а функции - это просто значения, 
мы можем передать действие как аргумент.
---
function printValue(value) {
  console.log(value);
}
function prettyPrint(value) {
  console.log("Logging value: ", value);
}
function repeat(n, action) {
  for (let i = 0; i < n; i += 1) {
    action(i);
  }
}
// Передаем printValue как callback-функцию
repeat(3, printValue);
// 0
// 1
// 2
// Передаем prettyPrint как callback-функцию
repeat(3, prettyPrint);
// Logging value: 0
// Logging value: 1
// Logging value: 2
---