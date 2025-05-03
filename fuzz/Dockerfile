FROM nocodenolife3742/afixl-builder

RUN apt-get update && apt-get upgrade -y
RUN git clone https://github.com/nocodenolife3742/fuzz-example.git ${SRC}/fuzz-example
WORKDIR ${SRC}/fuzz-example
COPY build.sh ${SRC}
COPY input ${SRC}/input
