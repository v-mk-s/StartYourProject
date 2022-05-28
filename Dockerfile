FROM gcc:latest
RUN apt update -y && \
    apt install -y cppcheck clang-tidy python3-pip libc6-dbg cmake libgtest-dev libgmock-dev lcov
RUN pip install cpplint

RUN cd /home && wget https://sourceware.org/pub/valgrind/valgrind-3.18.1.tar.bz2 && \
    tar xfv valgrind-3.18.1.tar.bz2 && \
    cd valgrind-3.18.1 && \
    ./autogen.sh && \
    ./configure && \
    make && \
    make install

RUN cd /home && wget https://boostorg.jfrog.io/artifactory/main/release/1.79.0/source/boost_1_79_0.tar.bz2 && \
    tar xfv boost_1_79_0.tar.bz2 && \
    cd boost_1_79_0 && \
    ./bootstrap.sh && \
    ./b2 install

RUN cd /home && wget https://dev.mysql.com/get/Downloads/MySQL-8.0/mysql-community-client-plugins_8.0.29-1ubuntu20.04_amd64.deb && \
    wget https://dev.mysql.com/get/Downloads/Connector-C++/libmysqlcppconn9_8.0.29-1ubuntu20.04_amd64.deb && \
    wget https://dev.mysql.com/get/Downloads/Connector-C++/libmysqlcppconn8-2_8.0.29-1ubuntu20.04_amd64.deb && \
    wget https://dev.mysql.com/get/Downloads/Connector-C++/libmysqlcppconn-dev_8.0.29-1ubuntu20.04_amd64.deb && \
    apt install -y ./mysql-community-client-plugins_8.0.29-1ubuntu20.04_amd64.deb && \
    apt install -y ./libmysqlcppconn9_8.0.29-1ubuntu20.04_amd64.deb && \
    apt install -y ./libmysqlcppconn8-2_8.0.29-1ubuntu20.04_amd64.deb && \
    apt install -y ./libmysqlcppconn-dev_8.0.29-1ubuntu20.04_amd64.deb

EXPOSE 80

COPY . /usr/src/StartYourProject
WORKDIR /usr/src/StartYourProject
RUN make rebuild