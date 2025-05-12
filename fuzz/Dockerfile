FROM nocodenolife3742/afixl-builder

RUN apt-get update && apt-get upgrade -y
RUN git clone https://github.com/nocodenolife3742/fuzz-example.git /src/fuzz-example
COPY build.sh /src
COPY input /src/input
