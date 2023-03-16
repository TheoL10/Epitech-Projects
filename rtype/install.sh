#!/bin/bash

sudo pip3 install conan -U

sudo pip3 install cmake

conan remote add bincrafters https://bincrafters.jfrog.io/artifactory/api/conan/conan

conan remote add community https://api.bintray.com/conan/conan-community/conan

sudo apt-get install libfontenc-devel libXaw-devel libXcomposite-devel libXdmcp-devel libXtst-devel libxkbfile-devel libXres-devel libXScrnSaver-devel libXvMC-devel xorg-x11-xtrans-devel xcb-util-wm-devel xcb-util-keysyms-devel xcb-util-renderutil-devel xcb-util-devel xkeyboard-config-devel

sudo dnf install -y libfontenc-devel libXaw-devel libXcomposite-devel libXdmcp-devel libXtst-devel libxkbfile-devel libXres-devel libXScrnSaver-devel libXvMC-devel xorg-x11-xtrans-devel xcb-util-wm-devel xcb-util-keysyms-devel xcb-util-renderutil-devel xcb-util-devel xkeyboard-config-devel

conan user conancenter -r conancenter

export CONAN_SYSREQUIRES_MODE="disabled"

export CONAN_SYSREQUIRES_SUDO="1"

conan install . --build=missing && cmake . -G "Unix Makefiles" && cmake --build .