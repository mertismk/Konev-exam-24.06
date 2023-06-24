FROM ubuntu

LABEL author="Makar Konev"

RUN apt-get update && \
    apt-get -y install make g++ && \
    rm -rf /var/lib/apt/lists/*

COPY . /MyProj_221-3210_Konev

WORKDIR /MyProj_221-3210_Konev

RUN make all

CMD ["./my_Program"]