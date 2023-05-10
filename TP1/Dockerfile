FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
  gcc \
  g++ \
  vim \
  grep

RUN mkdir /gabrielscota
RUN echo "Gabriel Scotá Arruda - 19.1.4054" >/gabrielscota/GABRIEL.txt

ADD tp1.cpp /gabrielscota
RUN g++ -o /gabrielscota/tp1 /gabrielscota/tp1.cpp

ADD shellscript.sh /gabrielscota
RUN chmod +x /gabrielscota/shellscript.sh
