/*
   Цвето-цветомузыка на Arduino и адресной светодиодной ленте WS2815
 
   *******************************************************************
   Разработано: AlexGyver
   Страница проекта: http://alexgyver.ru/colormusic/


   Доработано: OlegAnadyr
               technotrasher

   Переработано: Slenk
   Ссылка:       https://community.alexgyver.ru/threads/cvetomuzyka-na-arduino-fireedition.4683/
   
   Доработано: vsv070
   *******************************************************************

   Версия 0.1:

  +-----+---------------------+--------------+--------------+
  | №   | Режим               | Кнопки ↕     | Кнопки ↔     |
  +-----+---------------------+--------------+--------------+
  |     |                     | settings[0]  | settings[1]  |
  +-----+---------------------+--------------+--------------+
  |     |                     | WHITE_TEMP   | LIGHT_SAT    |
  |     |                     | LIGHT_COLOR  |              |
  |     |                     | EFFECT_DELAY |              |
  +-----+---------------------+--------------+--------------+
  | 1.1 | Белый свет          | Температура  | Яркость      |
  | 1.2 | Постоянный свет     | Цвет         | Насыщенность |
  | 1.3 | Плавная смета цвета | Скорость     | Насыщенность |
  +-----+---------------------+--------------+--------------+

  Массив таймеров
  +-------+-----------------+
  | index |      Режим      |
  +-------+-----------------+
  |   0   |       Main      |
  |   1   | Server Requests |
  |   2   |    Effect_1_3   |
  +-------+-----------------+
*/