FROM ubuntu:22.10

# Install dependencies
RUN apt-get update && \
        apt-get upgrade -y && \
        apt-get install -y --no-install-recommends \
        build-essential \
        cmake \
        g++ \
        gcc \
        make

ENV CC=/usr/bin/gcc
ENV CXX=/usr/bin/g++

WORKDIR /work

COPY . .

RUN cmake -B/build && cmake --build /build

ENTRYPOINT ["/work/build/scheduler", "/work/test/in.txt"]
# CMD ["/work/build/scheduler", "/work/test/in.txt"]

