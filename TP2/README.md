# Trabalho Prático 2

docker image rm -f gabrielscota/bcc264_19_1_4054:2.0

docker build -t gabrielscota/bcc264_19_1_4054:2.0 .

docker images

docker run -it gabrielscota/bcc264_19_1_4054:2.0

docker ps -a

docker commit -m "Trabalho Prático 2" -a "Gabriel Scotá Arruda" CONTAINER_ID gabrielscota/bcc264_19_1_4054:2.0

docker push gabrielscota/bcc264_19_1_4054:2.0
