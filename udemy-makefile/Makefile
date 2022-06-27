# static library creation
# author:subrat(v1.0)
#----------------------------
# notes:
#************************************************************************

build_type = $(release)
#build_type = $(debug)
module_name = employee
target_name = emp

proj_root_dir = ../..
obj_dir = $(proj_root_dir)/objs/$(module_name)

#*****dont modify below attributes****#
build_timestamp = $(shell date +'%d-%m-%y.%h-%m-%s.%n')

installation_path = $(shell echo $$installation_path)
ifeq ($(installation_path),)
        installation_path = $(proj_root_dir)
#       installation_path = /usr/local/mycustombuild

endif

target_dir = $(installation_path)/libs
target = $(target_dir)/lib$(target_name).a

# c++ compiler
cxx = $(shell echo $$cxx)
ifeq ($(cxx),)
cxx = g++
endif

ldxx = ar rcs 

stdflag = -std=c++17

#*****dont modify above attributes****#
source_1 = $(module_name).cpp
obj_1 = $(obj_dir)/$(module_name).o

all_objs = $(obj_1)

inc = -i./ -i$(proj_root_dir)/shared_headers

#choose release/debug
debug = -pipe -g -wall -w -fpic
release = -pipe -o2 -wall -w -fpic

# -d stands for define. if want to define any macro which is used in code for\
