# Уроки по Объектно Ориентированному Программированию

## В этом репозитории содержатся все лекции 4 семестра по Объектно Ориентированному Программированию.
 
Оригинальная стилистика написания кода и наименования переменных сохранена (почти)
 
 ### Лекции
 * **Лекция 1**: Вводная лекция
   * **1_1** - Классы, их поля и экземпляры
   * **1_2** - Методы класса 
   * **1_3** - Конструкторы и деструкторы
   * **1_4** - Пример конструктора и деструктора
   * **1_5** - Пример класса динамического массива
 * **Лекция 2**:
   * **2_1** - Классы, их поля и экземпляры
   * **2_2** - Синтаксис наследования
   * **2_3** - Насследование конструктора
   * **2_4** - Передача параметров в конструктор
   * **2_5** - Передача нескольких параметров в конструктор
   * **2_6** - Множественное наследование конструктора с параметрами
   * **2_7** - Многоуровневое наследование
   * **2_8** - Спецификатор "protected" при наследовании
 * **Лекция 3**:
   * **3_1** - Конструктор копирования
   * **3_2** - Конструктор копирования для одномерного массива
   * **3_3** - Перегрузка оператора присвоения
 * **Лекция 4**:
   * **4_1** - Конструктор копирования и оператор присвоения
 * **Лекция 5**:
   * **5_1** - lvalue и rvalue ссылки
   * **5_2** - Конструктор перемещения и оператор перемещения присвоением
 * **Лекция 6**:
   * **6_1** - Дружественная функция
   * **6_2** - Перегрузка оператора сложения
 * **Лекция 7**:
   * **7_1** - Перегрузка оператора инкрементации
   * **7_2** - Перегрузка оператора +=
   * **7_3** - Перегрузка оператора унарный минус
   * **7_4** - Перегрузка оператора == и !=
   * **7_5** - Перегрузка оператора индексации
 * **Лекция 8**:
   * **8_1** - Работа с функциями из разных файлов
   * **8_2** - Работа с функциями из разных файлов
   * **8_3** - Добавление заголовочных файлов
 * **Лекция 9**:
   * **9_1** - Работа с классами из разных файлов
 * **Лекция 10**:
   * **10_1** - Обработка ошибки внутри самой функции
   * **10_2** - Обработка ошибок передачей кода ошибки вызывавшей функции
 * **Лекция 11**:

 * **Лекция 12**:
   * **12_1** - Универсальный обработчик исключений
   * **12_2** - Обработка исключений: пользовательский тип данных
   * **12_3** - Работа с файлами: запись
   * **12_4** - Работа с файлами: чтение
   * **12_5** - Работа с файлами: флаги
 * **Bonus Lesson :)**:
   * **_1** - Статические пельменные
 ### Практические задания
   * **Практика 1**: Добавть в код 1_5 метод, позволяющий изменять любой элемент массива и метод, позволяющий возвращать любой элемент массива
   * **Практика 2**: На базе программы 2_1 сделать класс наследник. Наследник должен обладать методами: сортировки матрицы по спирали, нахождение наибольшего и наименьшего значения в матрице, должен быть конструктор, который создаст и инициализирует матрицу посредством трех переданных в него параметров: первые два - высота, ширина, а третий заполняет всю матрицу.
   * **Практика 3**: Написать конструктор копирования для двумерных массивов на базе программы 2_1.
   * **Практика 4**: Написать класс, который реализует работу с текстовым файлом. Реализовать конструктор, конструктор копирования, деструктор, Методы для записи в файл с консоли и чтения в консоль. 
   * **Практика 4_1**: Реализовать 4_1 для двумерного массива
   * **Практика 5**: Выяснить какая функция быстрее работает в 5_1
   * **Практика 6**: Сделать программу 6_2 для двумерного массива
   * **Практика 7**: Для данного оператора перегрузить все операторы сравнения по сумме
   * **Практика 7_1**: Сделать все то же, но для двух разных классов - двумерного и одномерного массива
   * **Практика 8**: Написать программу, которая перемножает две вещественные матрицы, написать в функционально-ориентированном стиле и использовать отдельные файлы
   * **Практика 9**: Переделать 5_2 и разбить по файлам
   * **Практика 12**: Написать программу, в которой будут функция, выполняющая деление (с двумя параметрами), функция, вычисляющая корень квадратный (с одним параметром). В случае некорректных параметров функции должны выбрасывать исключения, а main будет обрабатывать эти исключения при помощи универсального обработчика.
   * **Практика 13**: Написать программу, которая из одного файла берет целочисленный массив, сортирует по возростанию и записывает в другой файл
   * **Практика 13_1**: Написать класс, в нем конструктор, который создает файл с именем и по адресу переданному ему в качестве параметра. Метод для записи в этот файл целочисленной матрицы. Ввод с клавиатуры матрицы. Метод для удаления файла. Метод для создания нового файла по новому имени, старый файл должен быть уничтожен. В качестве данных нужно определить адрес.
