# Description

An http server application to be deployed and run in a docker container. The project is intended for learning purposes.

# Development

A development image exists on docker hub called with the tag "dev". This image is simply a copy of the image that deploys the server, but does not build or deploy the server.



Follow these steps to setup development environment:
1. The only dependencies you need are some version of docker and git on you machine. Ensure you have both docker and git installed on your local dev machine:
```
$ git --version
git version 2.25.1.windows.1
$ docker -v
Docker version 19.03.8, build afacb8b
```

2. Navigate to directory you wish to develop in and clone this repostory:
```
$ cd <insert your dev path here>
$ git clone https://github.com/aniehuser/http-server.git
```

3. Pull down development container and put in local registry
```
# pull from docker hub
$ docker pull aniehuser/http-server:dev

# tag to local image registry (optional but I like to do this :) )
$ docker tag aniehuser/http-server:dev http-server:dev

# remove image reference to docker hub (only do this if you have tagged to local image registry)
$ docker rmi aniehuser/http-server:dev
```

4. Run and exec into the container. Mount the root repositroy directory to the container like so
```
# Windows
$ docker run --rm --name http-server-dev -v C:\<insert your dev path here>\http-server:/usr/src/http-server -it http-server:dev bash

# Mac
TODO

# Linux
TODO
```

5. You should now be "exec'd" into the running container. Run the unit tests in the container to ensure everything is working properly
```
$ make test
```

6. You are ready to develop! Use these commands to build binaries and run tests
```
$ make build    --->    Compile all source files.
$ make test     --->    Compile all source files and test files. Run unit tests.
$ ./bin/out     --->    Execute server executable after 'make build'.
```

# Objectives

Learn more about and practice the following programming principles and technologies:

### Containerization
* Developing in a container
* Deploying a container
* Dependency management in a container
* Container networking
* Cross platform development

### C++
* Relearn C++ from the college years
  * Syntax
  * Memory allocation/deallocation
* Compilation
  * Linking
  * Compiling
  * .o files
* Concurrency -- future?

### Sockets
* Use the sockets API to recieve and send data
* Concurrency -- future?

### Unit/Integration Tests
* Use a C++ unit test framework
* Integrate a C++ unit test framework into a project

### Makefiles
* Syntax and functions
* Build executables
* Testing
* Clean repository
* Reduce unnecessary compilation

### HTTP/HTTPS
* General familiarity
* Request Types
* Status Codes
* Headers
* HTTP message format

### Other Learning Opportunites
* Lexical anlaysis (text-based protocol)
* Developing daemons
  * Graceful error handling

### Protocol Implementation
* Reading and understanding RFCs
* Robustness

### CI/CD
* Github CI/CD pipelines

# Architecture
TODO
