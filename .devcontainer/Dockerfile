FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

ARG USERNAME=developer
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN apt-get update
# [Optional] Add sudo support. Omit if you don't need to install software after connecting.
RUN apt-get install -y sudo

# Create the user
RUN groupadd --gid $USER_GID $USERNAME 
RUN useradd --uid $USER_UID --gid $USER_GID -m $USERNAME 
RUN echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME && chmod 0440 /etc/sudoers.d/$USERNAME
RUN apt-get upgrade -y

RUN apt-get install -y git build-essential clang clang-format clang-tidy pkg-config cmake gdb

RUN apt-get install -y libgtest-dev
# Build GTest library
RUN cd /usr/src/googletest && \
    cmake . && \
    cmake --build . --target install

# [Optional] Uncomment this section to install additional vcpkg ports.
# RUN su vscode -c "${VCPKG_ROOT}/vcpkg install <your-port-name-here>"

USER $USERNAME