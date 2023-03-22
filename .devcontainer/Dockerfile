FROM ubuntu:22.04
RUN apt install -y dos2unix
RUN dos2unix ./sample.sh
RUN apt update && apt install -y build-essential libpng-dev libgmp-dev
