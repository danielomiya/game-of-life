FROM ubuntu:focal AS setup

RUN apt update && \
    apt install -y cmake

#---
FROM setup AS build

WORKDIR /usr/src/app
COPY . ./
RUN mkdir build && \
    cd build && \
    cmake ../ && \
    make

#---
FROM ubuntu:focal

WORKDIR /app
COPY --from=build /usr/src/app/build/main ./

CMD ["sh", "-c", "./main"]
