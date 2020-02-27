FROM gcc:latest
COPY . /usr/src/http-server
WORKDIR /usr/src/http-server
EXPOSE 8080
RUN make clean build
CMD ["./bin/out.exe"]
