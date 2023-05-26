FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
  build-essential \
  gcc \
  g++ \
  vim \
  grep

RUN mkdir /gabrielscota

ADD q1.cpp /gabrielscota
RUN g++ /gabrielscota/q1.cpp -o /gabrielscota/q1

ADD q2.cpp /gabrielscota
RUN g++ /gabrielscota/q2.cpp -o /gabrielscota/q2
