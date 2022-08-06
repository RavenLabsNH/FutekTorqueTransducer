FROM ubuntu:jammy

RUN apt update && apt upgrade -y && apt install -y vim byobu build-essential
