FROM ubuntu
RUN apt update
RUN apt install g++ -qy
COPY 3_laba.cpp .
RUN g++ -masm=intel 3_laba.cpp
CMD ./a.out

