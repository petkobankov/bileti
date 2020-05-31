# Билети
**Информационна система, която обслужва билетна каса.**

Програмата работи с команди от конзолата. Започва единствено с две зали. Без да се отвори файл програмата не може да се използва. Формат за дадите е гггг-мм-дд.

**Информация с която започва програмата винаги:**
| Номер на зала  | Брой редове | Брой места на ред |
| ------------- | ---------|--------|
| 0  | 5 | 10 |
| 1  | 10 | 10 |

**Добавяне на представление**
```
>addevent 2020-06-12 0 12A //addevent <date><hall><event>
Successfully added event 12A

>addevent 2020-07-01 1 Avatar
Successfully added event Avatar
```
Успешно добавихме представления "12А" и "Аватар" в зали съответно 0 и 1.

**Закупване и запазване на билет**
```
>freeseats 2020-06-12 12A //freeseats <date><event>
Row: 0 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Row: 1 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Row: 2 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Row: 3 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Row: 4 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Seat:   0  1  2  3  4  5  6  7  8  9

>book 1 2 2020-06-12 12A empty //book <row><seat><date><name><note>
Success! You have booked your seat.

>book 1 3 2020-06-12 12A empty
Success! You have booked your seat.

>book 1 4 2020-06-12 12A empty
Success! You have booked your seat.

>buy 1 5 2020-06-12 12A //buy <row><seat><date><name>
Success! You have bought your seat.

>buy 2 5 2020-06-12 12A
Success! You have bought your seat.

>buy 2 5 2020-07-01 Avatar
Success! You have bought your seat.

>book 1 5 2020-07-01 Avatar empty
Success! You have booked your seat.

>freeseats 2020-06-12 12A
Row: 0 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Row: 1 [ ][ ][o][o][o][x][ ][ ][ ][ ]
Row: 2 [ ][ ][ ][ ][ ][x][ ][ ][ ][ ]
Row: 3 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Row: 4 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Seat:   0  1  2  3  4  5  6  7  8  9
```
**Извеждане на различни справки**
```
>bookings 2020-06-12 //bookings [<date>][<name>]
0)For event: 12A, date: 2020-06-12, hall id: 0, row: 1, seat: 2, code: 1.2.2020-06-12.0
1)For event: 12A, date: 2020-06-12, hall id: 0, row: 1, seat: 3, code: 1.3.2020-06-12.0
2)For event: 12A, date: 2020-06-12, hall id: 0, row: 1, seat: 4, code: 1.4.2020-06-12.0

>bookings 2020-07-01 Avatar
0)For event: Avatar, date: 2020-07-01, hall id: 1, row: 1, seat: 5, code: 1.5.2020-07-01.1

>report 2020-06-12 2020-07-01 //report <from><to>[<hall>]
Event name: 12A, on date: 2020-06-12, for hall: 0
Tickets sold: 2
Event name: Avatar, on date: 2020-07-01, for hall: 1
Tickets sold: 1

>report 2020-06-12 2020-07-01 0
Event name: 12A, on date: 2020-06-12, for hall: 0
Tickets sold: 2

>check 1.2.2020-06-12.0 //check <code>
This ticket is for row: 1, seat: 2
```

## Команди
| Име  | Описание |
| ------------- | ------------- |
| open \<file\>  | opens \<file\> |
| close  | closes currently opened file |
| save | saves the currently open file |
| saveas \<file\> | saves the currently open file in \<file\> |
| help | prints this information |
| exit | exists the program |
| addevent \<date\>\<hall\>\<name\> | Adds a new event for date \<date\> with the name \<name\> in hall with id \<hall\>. |
| freeseats \<date\>\<name\> | Displays the free seats for event with name \<name\> on date \<date\> |
| book \<row\>\<seat\>\<date\>\<name\>\<note\> | Books a ticket for event with name \<name\> on date \<date\> on row \<row\> and seat \<seat\>, and adds a note \<note\> |
| unbook \<row\>\<seat\>\<date\>\<name\> | Unbooks a booking for an event with name \<name\> on \<date\> at \<row\> and \<seat\> |
| buy \<row\>\<seat\>\<date\>\<name\> | Buys a ticket for an event with \<name\> on \<date\>, on \<row\> and \<seat\>. |
| bookings [\<date\>][\<name\>] | Prints out booked, but not paied tickets for event \<name\> on \<date\>. |
| check \<code\> | Checks the \<code\> of a ticket and prints out it's row and seat |
| report \<from\>\<to\>[\<hall\>] | Prints out bought tickets from date <from> to date \<to\> and if you want it can be for a specific \<hall\>. |
