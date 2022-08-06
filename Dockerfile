# FROM ubuntu:jammy
FROM python:3.9.13-bullseye

RUN apt update && apt upgrade -y \
    && apt install -y vim byobu build-essential cmake python3-dev python3-pip
RUN python3 -m pip install pytest
