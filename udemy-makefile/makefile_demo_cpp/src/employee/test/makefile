#************************************************************************
# SAMPLE MAKEFILE FOR TEST - BINARY
# # NOTES:
# We may have to modify following attributes.

#************************************************************************
BUILD_TYPE = $(RELEASE)
#BUILD_TYPE = $(DEBUG)
MODULE_NAME = employee
TARGET_NAME = test_$(MODULE_NAME)

PROJ_ROOT_DIR = ../../..
OBJ_DIR = $(PROJ_ROOT_DIR)/objs/test/$(MODULE_NAME)

#*****DONT MODIFY BELOW ATTRIBUTES****#
BUILD_TIMESTAMP = $(shell date +'%d-%m-%Y.%H-%M-%S.%N')

INSTALLATION_PATH = $(shell echo $$INSTALLATION_PATH)
ifeq ($(INSTALLATION_PATH),)
        INSTALLATION_PATH = $(PROJ_ROOT_DIR)
#       INSTALLATION_PATH = /usr/local/mycustombuild

endif

TARGET_DIR = $(INSTALLATION_PATH)/test_bins
TARGET = $(TARGET_DIR)/$(TARGET_NAME)

LIBRARY_DIR = $(INSTALLATION_PATH)/libs

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


INC = -I./ -I$(PROJ_ROOT_DIR)/share_headers


#debug(For developer doing testing) -D stands for DEFINE. If want to define any macro which is used in code for timestamp or git revision etc, can use in this way. This is helpful for FACTORY
#choose release/debug
DEBUG = -pipe -g -Wall -W -fPIC
#RELEASE =-DNDEBUG -W -fPIC
RELEASE = -pipe -O2 -Wall -W -fPIC

CC_OPT = -DBUILD_TIMESTAMP_STR=\"$(BUILD_TIMESTAMP)\" -DINSTALLATION_PATH_STR=\"$(INSTALLATION_PATH)\"
#LD_OPT = -Wl,-O1

#UNCOMMENT IF LIKE TO SEE FOLLOWING WARNINGS. ATLEAST ONCE THIS NEEDS TO BE RUN FOR EACH MODULE
#WARN=-Wall -Wextra -Werror -Wwrite-strings -Wno-parentheses -pedantic -Warray-bounds -Wno-unused-variable -Wno-unused-function -Wno-unused-parameter
WARN=-Wall -Wextra -Werror -Wwrite-strings -Wno-parentheses -pedantic -Warray-bounds -Wno-unused-variable -Wno-unused-function -Wno-unused-parameter -Wno-unused-result

CCFLAGS = $(STDFLAG) $(BUILD_TYPE) $(CC_OPT) $(WARN) $(INC)

# Add dependency library here by speparating them with space. Below example is to add libzmq, libm & libcustomlib

#Note: Add the "<path-to-library> -llibaryname" by keeping space in between as shown below. If library is present in the current directory, we can use path as L.
#DEP_LIBS = -lzmq -lm -L$(LIBRARY_DIR) -lcustomlib -L. -lnewlibincurrentdir
DEP_LIBS = -L$(LIBRARY_DIR) -lemployee
# RPATH IS USED FOR LINKING LIBS IN SPECIFIC PATH
# BUILDING THE MODULE.It is needed for the User of the .so. Here unit test binary should use it.
#RPATH="-Wl,-rpath,$(LIBRARY_DIR):$(THIRD_PARTY_LIB_DIR)"
RPATH="-Wl,-rpath,$(LIBRARY_DIR)"

#LDFLAGS = $(DEBUG) $(PROF) -L$(LIBRARY_DIR) -L$(THIRD_PARTY_LIB_DIR) -fPIC -lpthread $(DEP_LIBS) $(RPATH)
LDFLAGS = $(DEP_LIBS) $(RPATH)

all: $(TARGET)

$(TARGET): $(MAIN_OBJ)
	$(LDXX) $(LD_OPT) -o $@ $^ $(LDFLAGS)

$(MAIN_OBJ): main.cpp
	$(CXX) $(CCFLAGS) -o $@ -c $<


build_dir:
	@echo Creating object directory if not exist
	mkdir -p $(OBJ_DIR)
	mkdir -p $(TARGET_DIR)

clean:
	@echo Clean Build
	rm $(MAIN_OBJ)
	rm $(TARGET)

.PHONY: clean build_dir all
