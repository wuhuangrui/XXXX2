LIB = app

#source dir

ACINC = ../../AcSample

CCTINC = ../../app/Cct
CTRLINC = ../../app/Ctrl
DBINC = ../../app/DataBase
DPINC = ../../app/DataProc
DISPINC = ../../app/Display
DRVAPPINC = ../../app/Driver
FAINC = ../../app/fa
MTRINC = ../../app/Meter
PROINC = ../../app/Proto
TASKINC = ../../app/Task

COMINC = ../../common
ACLIBINC = ../../common/LibAc
CCTLIBINC = ../../common/LibCct
DBLIBINC = ../../common/LibDb
MTRLIBINC = ../../common/LibMtr
MODEMINC = ../../common/Modem
PROTOIFINC = ../../common/ProtoIf
TASKDBINC = ../../common/TaskDB
ZIPLIBINC = ../../common/Zip

ARCHINC = ../../arch/linux

DRIVERSINC = ../../drivers/linux
DRVCOMMINC = ../../drivers/common

MTRPROINC = ../../MeterPro

INCS = -I$(ACINC) \
	-I$(CCTINC) -I$(CTRLINC) -I$(DBINC) -I$(DPINC) -I$(DISPINC) -I$(DRVAPPINC) -I$(FAINC) -I$(MTRINC) -I$(PROINC) -I$(TASKINC) \
	-I$(COMINC) -I$(ACLIBINC) -I$(CCTLIBINC) -I$(DBLIBINC) -I$(MTRLIBINC) -I$(MODEMINC) -I$(PROTOIFINC) -I$(TASKDBINC) -I$(ZIPLIBINC) \
	-I$(ARCHINC) -I$(DRIVERSINC) -I$(DRVCOMMINC) -I$(MTRPROINC)
	
LIBS = -lnsl -lpthread -ldl

##################################################
ROOTDIR = ../../../Prj/Linux
OBJDIR = $(ROOTDIR)/obj
BINDIR = $(ROOTDIR)/bin
LIBDIR = $(ROOTDIR)/lib

##################################################
SRCDIR = .
SRCS = $(notdir $(wildcard $(SRCDIR)/*.c $(SRCDIR)/*.cpp))
	
#OBJS = $(SRCS:%.=$(OBJDIR)/%.o)
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS)))

##################################################


CC       = arm-none-linux-gnueabi-g++
AR       = arm-none-linux-gnueabi-ar
CPPFLAGS = -g -c -O2 $(INCS)  -DARM9
CPPFLAGS += -DLINUX -fno-builtin-log
LDFLAGS  = -L$(LIBDIR) $(LIBS)

#########################################################
$(LIBDIR)/lib$(LIB).a: $(LIBDIR) $(OBJDIR) $(OBJS) 
	$(AR) rv $@ $(OBJS)
	ranlib $@

$(OBJDIR):
	@test -d $@ || mkdir $@
	
$(LIBDIR):
	@test -d $@ || mkdir $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CPPFLAGS) -o $@ $<
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CPPFLAGS) -o $@ $<

clean:
	@rm -r -f $(OBJDIR) $(LIBDIR)/lib$(LIB).a $(SRCDIR)/*~