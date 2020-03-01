FROM gcc:9.2.0

WORKDIR /usr/src/http-server

RUN apt-get -qq update \
    && apt-get -qq install --no-install-recommends cmake \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN git clone --depth=1 -b master https://github.com/google/googletest.git
RUN mkdir googletest/build

WORKDIR /usr/src/http-server/googletest/build

RUN cmake .. \
    && make \
    && make install \
    && rm -rf /usr/src/http-server/googletest

WORKDIR /usr/src/http-server

# FROM gcc:latest
# COPY . /usr/src/http-server
# WORKDIR /usr/src/http-server
# EXPOSE 8080
# RUN make clean build
# CMD ["./bin/out.exe"]
