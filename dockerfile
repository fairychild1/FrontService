FROM twoixter/gcc48-dev
RUN mkdir -p /home/common \
	&& mkdir -p /home/web
COPY *.cpp /home/
COPY *.h /home/
COPY common/* /home/common/
COPY web/* /home/web/
RUN cd /home && g++ -std=c++11 http_server.cpp main.cpp -o frontservice
WORKDIR /home
ENTRYPOINT /home/frontservice
