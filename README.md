Программа для публикации видеопотока на видеосервер



Отправляет список видеопотоков (с ип-камер или из видеофайла) на сервер (адрес сервервера в файле: serverip.txt), находящихся в списке videostreams.txt посредством ffmpeg
Список каналов читает из файла: videostreams_channels.txt. А в случае отсутствия этого файла генерирует список каналов.
Затем публикует на сервер.

файл serverip.txt содержит тип потока и адрес сервера, например:

flv rtmp://212.119.243.135/


или, например:

rtsp rtsp://логин:пароль@212.119.243.135/


Работает это следующим образом:

Скомпилировать программу и отредактировать текстовый файл videostreams.txt содержащий в себе список видеоконтента (videostreams.txt), который будет отправлен на видеосервер (serverip.txt) порсредством запуска этой программы. Видеопоток будет доступен для просмотра плеером ffplay из состава ffmpeg в командной строке, на канале sleep (videostreams_channels.txt) по адресу:

ffplay rtmp://212.119.243.135/sleep

Для работы программы потребуется ffmpeg, скачать можно отсюда: https://ffmpeg.org/ Инструкция по установке ffmpeg: https://www.youtube.com/watch?v=2eSRuadzJxA

Компилятор можно скачать отсюда: https://jmeubank.github.io/tdm-gcc/download/ или отсюда: https://www.embarcadero.com/free-tools/dev-cpp

Для проверки установлен ли компилятор, ввести в командную строку: g++ -v

Для компиляции программы: перейти в каталог с исходником и ввести в командную строку:

Linux:

g++ -std=c++11 -o sendvideo sendvideo.cpp

Win:

g++ -std=c++11 -o sendvideo.exe sendvideo.cpp

English language

Programme for publishing a video stream to a video server

Sends list of video streams (from ip-cameras or from video file) to server (server address in file: serverip.txt), which are in list videostreams.txt by means of ffmpeg List of channels reads from file: videostreams_channels.txt. And in case of absence of this file it generates the list of channels. Then publishes it to the server.

serverip.txt file contains stream type and server address, for example:

flv rtmp://212.119.243.135/

or, for example:

rtsp rtsp://логин:пароль@212.119.243.135/

It works as follows:

Compile the programme and edit the text file videostreams.txt containing a list of video content (videostreams.txt), which will be sent to the video server (serverip.txt) by running this programme. The video stream will be available for viewing by the ffplay player from ffmpeg on the command line, on the sleep channel (videostreams_channels.txt) at the address:

ffplay rtmp://212.119.243.135/sleep

The programme requires ffmpeg, downloadable from here: https://ffmpeg.org/ Installation instructions for ffmpeg: https://www.youtube.com/watch?v=2eSRuadzJxA.

The compiler can be downloaded from here: https://jmeubank.github.io/tdm-gcc/download/ or from here: https://www.embarcadero.com/free-tools/dev-cpp.

To check if the compiler is installed, enter into the command line: g++ -v

To compile the program: go to the directory with the source and enter at the command line:

Linux:

g++ -std=c++11 -o sendvideo sendvideo.cpp

Win:

g++ -std=c++11




