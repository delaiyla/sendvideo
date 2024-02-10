Программа для публикации видеопотока на видеосервер (sendvideo.cpp)


Видеосервер для Linux: https://github.com/bluenviron/mediamtx/releases/download/v1.5.1/mediamtx_v1.5.1_linux_amd64.tar.gz

Видеосервер для Win: https://github.com/bluenviron/mediamtx/releases/download/v1.3.1/mediamtx_v1.3.1_windows_amd64.zip

Исходный код видеосервера: https://github.com/bluenviron/mediamtx/archive/refs/tags/v1.5.1.tar.gz


Отправляет список видеопотоков (с ип-камер или из видеофайла) на сервер (адрес сервервера в файле: serverip.txt), находящихся в списке videostreams.txt посредством ffmpeg
Список каналов читает из файла: videostreams_channels.txt. А в случае отсутствия этого файла генерирует список каналов.
Затем публикует на сервер.

файл serverip.txt содержит тип потока и адрес сервера, например:

flv rtmp://212.119.243.135/

или, если программа публикации находится на том же адресе, что и запущенный видеосервер mediamtx

flv rtmp://localhost/

или, например:

rtsp rtsp://логин:пароль@212.119.243.135/


Работает это следующим образом:

Скомпилировать программу и отредактировать текстовый файл videostreams.txt содержащий в себе список видеоконтента (videostreams.txt), который будет отправлен на видеосервер (serverip.txt) порсредством запуска этой программы. Видеопоток будет доступен для просмотра плеером ffplay из состава ffmpeg в командной строке, на канале sleep (videostreams_channels.txt) по адресу, на котором запущен видеосервер, например:

ffplay rtmp://212.119.243.135/sleep

ffplay rtmp://212.119.243.135/dapa

Для просмотра опубликованного видеопотока через веб-интерфейс порт 8888:

http://212.119.243.135:8888/sleep

http://212.119.243.135:8888/dapa

Или воспользоваться программой для воспроизведения нескольких видео одновременно: https://github.com/delaiyla/playvideo

Для работы программы потребуется ffmpeg, скачать можно отсюда: https://ffmpeg.org/ Инструкция по установке ffmpeg: https://www.youtube.com/watch?v=2eSRuadzJxA

Компилятор можно скачать отсюда: https://jmeubank.github.io/tdm-gcc/download/ или отсюда: https://www.embarcadero.com/free-tools/dev-cpp

Для проверки установлен ли компилятор, ввести в командную строку: g++ -v

Для компиляции программы: перейти в каталог с исходником и ввести в командную строку:

Linux:

g++ -std=c++11 -o sendvideo sendvideo.cpp

Win:

g++ -std=c++11 -o sendvideo.exe sendvideo.cpp

