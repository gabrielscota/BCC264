# Trabalho Prático 1

docker image rm -f gabrielscota/bcc264_19_1_4054:1.0

docker build -t gabrielscota/bcc264_19_1_4054:1.0 .

docker images

docker run -it gabrielscota/bcc264_19_1_4054:1.0

docker ps -a

docker commit -m "Trabalho Prático 1" -a "Gabriel S. Cota" e855b07c1109 gabrielscota/bcc264_19_1_4054:1.0

docker push gabrielscota/bcc264_19_1_4054:1.0
