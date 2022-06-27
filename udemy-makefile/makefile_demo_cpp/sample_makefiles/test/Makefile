#************************************************************************
# SAMPLE MAKEFILE FOR TARGET - BINARY
# # NOTES:
# We may have to modify following attributes.

#************************************************************************
BUILD_TYPE = RELEASE
#BUILD_TYPE = DEBUG
TARGET_NAME = testingmakefile
MODULE_NAME = test1

PROJ_ROOT_DIR = ../..
OBJ_DIR = $(PROJ_ROOT_DIR)/objs/$(MODULE_NAME)

#*****DONT MODIFY BELOW ATTRIBUTES****#
BUILD_TIMESTAMP = $(shell date +'%d-%m-%Y.%H-%M-%S.%N')

INSTALLATION_PATH = $(shell echo $$INSTALLATION_PATH)
ifeq ($(INSTALLATION_PATH),)
        INSTALLATION_PATH = $(PROJ_ROOT_DIR)
#       INSTALLATION_PATH = /usr/local/mycustombuild

endif

TARGET_DIR = $(INSTALLATION_PATH)/bins
EXECUTABLE = $(TARGET_DIR)/$(TARGET_NAME)

LIBRARY_DIR = $(INSTALLATION_PATH)/libs
#THIRD_PARTY_LIB_DIR = $(INSTALLATION_PATH)/libs

# C++ compiler
CXX = $(shell echo $$CXX)
ifeq ($(CXX),)
CXX = g++
endif

# C++ linker
LDXX = $(shell echo $$CXX)
ifeq ($(LDXX),)
LDXX = g++
endif

STDFLAG = -std=c++17


#*****DONT MODIFY ABOVE ATTRIBUTES****#

MAIN_OBJ = $(OBJ_DIR)/main.o

SOURCE_1 = $(MODULE_NAME).cpp
OBJ_1 = $(OBJ_DIR)/$(MODULE_NAME).o

#MAY NEED TO ADD MORE DEPENDENCIES AS PER REQUIREMENT. FOLLOW THE BELOW LINE. SEARCH DEP_* AND CHANGE EVERYWHERE AS REQUIRED
SOURCE_2 = test2.cpp
OBJ_2 = $(OBJ_DIR)/s2.o
#SOURCE_3 = module-name.cpp

#DEP_MODULE_1_OBJ = $(OBJ_DIR)/$(DEP_MODULE_1).o
#DEP_MODULE_2_OBJ = $(OBJ_DIR)/$(DEP_MODULE_2).o

ALL_OBJS = $(OBJ_2) $(OBJ_1) $(MAIN_OBJ)

INC = -I./ -I$(PROJ_ROOT_DIR)/src -I$(PROJ_ROOT_DIR)/share_headers

#Add the -llibaryname by keeping space in between
#DEP_LIBS = -lcustomlib

#debug(For developer doing testing) -D stands for DEFINE. If want to define any macro which is used in code for timestamp or git revision etc, can use in this way. This is helpful for FACTORY
#DEBUG = -g3 -DDEBUG=0 -DINSTALLATION_PATH_7X_STR
#choose release/debug
DEBUG = -pipe -g -Wall -W -fPIC
RELEASE =-DNDEBUG -W -fPIC

CC_OPT = -Wno-unused-result -Warray-bounds -DGIT_VERSION_STR=\"$(GIT_VERSION)\" -DBUILD_TIMESTAMP_STR=\"$(BUILD_TIMESTAMP)\" -DINSTALLATION_PATH_STR=\"$(INSTALLATION_PATH)\"
LD_OPT = -Wl,-O1

#UNCOMMENT IF LIKE TO SEE FOLLOWING WARNINGS. ATLEAST ONCE THIS NEEDS TO BE RUN FOR EACH MODULE
#WARN=-Wall -Wextra -Werror -Wwrite-strings -Wno-parentheses -pedantic -Warray-bounds -Wno-unused-variable -Wno-unused-function -Wno-unused-parameter
WARN=-Wall -Wextra -Wwrite-strings -Wno-parentheses -pedantic -Warray-bounds -Wno-unused-variable -Wno-unused-function -Wno-unused-parameter -Wno-unused-result
#PROF = -pg

CCFLAGS_D = $(STDFLAG) $(DEBUG) $(CC_OPT) $(WARN) $(PROF) $(INC)
CCFLAGS_R = $(STDFLAG) $(RELEASE) $(CC_OPT) $(WARN) $(PROF) $(INC)

# RPATH IS USED FOR LINKING USER DEFINED LIBS IN SPECIFIC PATH DURING
# BUILDING THE MODULE.It is needed for the User of the .so. Here unit test binary should use it.
RPATH="-Wl,-rpath,$(LIBRARY_DIR):$(THIRD_PARTY_LIB_DIR)"

LDFLAGS = $(DEBUG) $(PROF) -L$(LIBRARY_DIR) -L$(THIRD_PARTY_LIB_DIR) -fPIC -lpthread $(DEP_LIBS) $(RPATH)

all: $(EXECUTABLE)

#IF WANT TO GET DEBUG/RELEASE BUILD, USE CCFLAGS_R
$(EXECUTABLE): $(ALL_OBJS)
	$(LDXX) $(LD_OPT) -o $@ $^ $(LDFLAGS)

$(MAIN_OBJ): main.cpp
	$(CXX) $(CCFLAGS_R) -o $@ -c $<

$(OBJ_1): $(SOURCE_1)
	$(CXX) $(CCFLAGS_R) -o $@ -c $<

$(OBJ_2): $(SOURCE_2)
	$(CXX) $(CCFLAGS_R) -o $@ -c $<


build_dir:
	@echo Creating object directory if not exist
	mkdir -p $(OBJ_DIR)

clean:
	@echo Clean Build
	rm $(ALL_OBJS)
	rm $(EXECUTABLE)

.PHONY: clean build_dir test all
