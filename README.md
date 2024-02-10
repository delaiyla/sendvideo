Программа для публикации видеопотока на видеосервер



Отправляет список видеопотоков (с ип-камер или из видеофайла) на сервер (адрес сервервера в файле: serverip.txt), находящихся в списке videostreams.txt посредством ffmpeg
Список каналов читает из файла: videostreams_channels.txt. А в случае отсутствия этого файла генерирует список каналов.
Затем публикует на сервер.

файл serverip.txt содержит тип потока и адрес сервера, например:

flv rtmp://212.119.243.135/


или, например:

rtsp rtsp://логин:пароль@212.119.243.135/


Работает это следующим образом:

Скомпилировать программу и отредактировать текстовый файл videostreams.txt содержащий в себе список видеоконтента, который будет отправлен на видеосервер порсредством запуска этой программы

Для работы программы потребуется ffmpeg, скачать можно отсюда: https://ffmpeg.org/ Инструкция по установке ffmpeg: https://www.youtube.com/watch?v=2eSRuadzJxA

Компилятор можно скачать отсюда: https://jmeubank.github.io/tdm-gcc/download/ или отсюда: https://www.embarcadero.com/free-tools/dev-cpp

Для проверки установлен ли компилятор, ввести в командную строку: g++ -v

Для компиляции программы: перейти в каталог с исходником и ввести в командную строку:

Linux:

g++ -std=c++11 -o sendvideo sendvideo.cpp

Win:

g++ -std=c++11 -o sendvideo.exe sendvideo.cpp
