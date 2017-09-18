# WinAVR Makefile Template written by Eric B. Weddington, Jörg Wunsch, et al.
# Released to the Public Domain
#
# Additional material for this makefile was written by:
# Peter Fleury, Tim Henigan, Colin O'Flynn, Reiner Patommel, Markus Pfaff,
# Sander Pool, Frederik Rouleau, Carlos Lamas
#
# Improved by Taz8du29 (c) 2017
#
#----------------------------------------------------------------------------

# MCU name
#   Because compiler & avrdude don't use the same MCU names, we need a variable
#   for each one (MCU for avr-gcc, MCUPROG for avrdude).
MCU = attiny2313a
MCUPROG = t2313

# Processor frequency, in Hz
F_CPU = 1000000

# Output format. (can be srec, ihex, binary)
FORMAT = ihex

# Target file name (without extension).
TARGET = matrixNecklace

# List source files here. (C/C++ dependencies are automatically generated.)
CSRC =
CPPSRC = matrixNecklace.cpp
ASRC =

# Optimization level, can be [0, 1, 2, 3, s].
OPT = s

# List any extra directories to look for include files here.
EXTRAINCDIRS = ../../myUtils


# Programming hardware
AVRDUDE_PROGRAMMER = usbasp

# com1 = serial port. Use lpt1 to connect to parallel port.
AVRDUDE_PORT = com1



#---------------- Compiler Options C ----------------
#  -g*:          generate debugging information
#  -Wa,...:      tell GCC to pass this to the assembler.
#    -adhlns...: create assembler listing
CFLAGS =  -gdwarf-2 -DF_CPU=$(F_CPU)UL -O$(OPT)
CFLAGS += -Wall -Wstrict-prototypes
CFLAGS += -ffunction-sections
CFLAGS += -save-temps=obj
CFLAGS += -Wa,-adhlns=$(<:%.c=.obj/%.lst)
CFLAGS += $(patsubst %,-I%,$(EXTRAINCDIRS)) -std=gnu99


#---------------- Compiler Options C++ ----------------
#  -g*:          generate debugging information
#  -Wa,...:      tell GCC to pass this to the assembler.
#    -adhlns...: create assembler listing
CPPFLAGS =  -gdwarf-2 -DF_CPU=$(F_CPU)UL -O$(OPT)
CPPFLAGS += -Wall
CPPFLAGS += -Wundef
CPPFLAGS += -Wa,-adhlns=$(<:%.cpp=.obj/%.lst)
CPPFLAGS += $(patsubst %,-I%,$(EXTRAINCDIRS))
#CPPFLAGS += $(CSTANDARD)


#---------------- Assembler Options ----------------
#  -Wa,...:   tell GCC to pass this to the assembler.
#  -adhlns:   create listing
#  -gstabs:   have the assembler create line number information; note that
#             for use in COFF files, additional information about filenames
#             and function names needs to be present in the assembler source
#             files -- see avr-libc docs [FIXME: not yet described there]
#  -listing-cont-lines: Sets the maximum number of continuation lines of hex
#       dump that will be displayed for a given single line of source input.
ASFLAGS =  -DF_CPU=$(F_CPU)
ASFLAGS += -Wa,-adhlns=$(<:%.S=.obj/%.lst),-gstabs,--listing-cont-lines=100


#---------------- Linker Options ----------------
#  -Wl,...:     tell GCC to pass this to linker.
#    -Map:      create map file
#    --cref:    add cross reference to  map file
#  -lm          include math library
LDFLAGS = -Wl,-Map=$(TARGET).map,--cref
LDFLAGS += $(EXTMEMOPTS)
LDFLAGS += $(patsubst %,-L%,$(EXTRALIBDIRS))
LDFLAGS += -lm
#LDFLAGS += -T linker_script.x


#============================================================================

# Define compiler.
CC = avr-gcc

# Define all object files.
OBJ = $(CSRC:%.c=.obj/%.o) $(CPPSRC:%.cpp=.obj/%.o) $(ASRC:%.S=.obj/%.o)

# Define all listing files.
LST = $(CSRC:%.c=.obj/%.lst) $(CPPSRC:%.cpp=.obj/%.lst) $(ASRC:%.S=.obj/%.lst)


# Combine all necessary flags and optional flags.
# Add target processor to flags.
# Flags to generate dependency files (-MMD -MP -MF .dep/$(@F).d).
ALL_CFLAGS = -mmcu=$(MCU) -I. $(CFLAGS) -MMD -MP -MF .dep/$(@F).d
ALL_CPPFLAGS = -mmcu=$(MCU) -I. -x c++ $(CPPFLAGS) -MMD -MP -MF .dep/$(@F).d
ALL_ASFLAGS = -mmcu=$(MCU) -I. -x assembler-with-cpp $(ASFLAGS)



# Default target.
all: init sizebefore build sizeafter

.PHONY : all


# Full compilation and upload to the chip.
program: init sizebefore build sizeafter upload

.PHONY : program


# Create developpement directories.
init:
	$(shell mkdir .dep .out .obj 2>/dev/null)
.PHONY : init


# Build target.
build: elf hex eep lss sym lib

.PHONY : build

# Build HEX and symbols files.
elf: .out/$(TARGET).elf
hex: .out/$(TARGET).hex
eep: .out/$(TARGET).eep
lss: .out/$(TARGET).lss
sym: .out/$(TARGET).sym

.PHONY : elf hex eep lss sym

# Buil libraries.
lib: .out/lib$(TARGET).a

.PHONY : lib


# Display size of file.
HEXSIZE = avr-size --target=$(FORMAT) $(TARGET).hex
ELFSIZE = avr-size --mcu=$(MCU) --format=avr $(TARGET).elf

sizebefore:
	@if test -f $(TARGET).elf; then echo; echo "Size before:"; $(ELFSIZE); \
	2>/dev/null; fi
.PHONY : sizebefore

sizeafter:
	@if test -f $(TARGET).elf; then echo; echo "Size after:"; $(ELFSIZE); \
	2>/dev/null; fi
.PHONY : sizeafter


# Upload to the device.
upload:
	avrdude -p $(MCUPROG) -P $(AVRDUDE_PORT) -c $(AVRDUDE_PROGRAMMER) \
	-U flash:w:.out/$(TARGET).hex -U eeprom:w:$(TARGET).eep
.PHONY : upload


# Convert ELF to COFF for use in debugging / simulating in AVR Studio or VMLAB.
COFFCONVERT = avr-objcopy --debugging
COFFCONVERT += --change-section-address .data-0x800000
COFFCONVERT += --change-section-address .bss-0x800000
COFFCONVERT += --change-section-address .noinit-0x800000
COFFCONVERT += --change-section-address .eeprom-0x810000


coff: $(TARGET).elf
	@echo "\nConverting to AVR COFF:" .out/$(TARGET).cof
	$(COFFCONVERT) -O coff-avr $< .out/$(TARGET).cof
.PHONY : coff

extcoff: $(TARGET).elf
	@echo "\nConverting to AVR Extended COFF:" .out/$(TARGET).cof
	$(COFFCONVERT) -O coff-ext-avr $< .out/$(TARGET).cof
.PHONY : extcoff


# Create final output files (.hex, .eep) from ELF output file.
%.hex: %.elf
	@echo "\nCreating load file for flash:" $@
	avr-objcopy -O $(FORMAT) -R .eeprom -R .fuse -R .lock -R .signature $< $@

%.eep: %.elf
	@echo "\nCreating load file for EEPROM:" $@
	avr-objcopy -j .eeprom --set-section-flags=.eeprom="alloc,load" \
	--change-section-lma .eeprom=0 --no-change-warnings -O $(FORMAT) $< $@ || exit 0

# Create extended listing file from ELF output file.
%.lss: %.elf
	@echo "\nCreating Extended Listing:" $@
	avr-objdump -h -S -z $< > $@

# Create a symbol table from ELF output file.
%.sym: %.elf
	@echo "\nCreating Symbol Table:" $@
	avr-nm -n $< > $@


# Create library from object files.
.SECONDARY : $(TARGET).a
.PRECIOUS : $(OBJ)
%.a: $(OBJ)
	@echo "\nCreating library:" $@
	avr-ar rcs $@ $(OBJ)

# Link: create ELF output file from object files.
.SECONDARY : $(TARGET).elf
.PRECIOUS : $(OBJ)
.out/%.elf: $(OBJ)
	@echo "\nLinking:" $@
	$(CC) $(ALL_CFLAGS) $^ --output $@ $(LDFLAGS)


# Compile: create object files from C source files.
.obj/%.o : %.c
	@echo "\nCompiling C:" $<
	$(CC) -c $(ALL_CFLAGS) $< -o $@

# Compile: create object files from C++ source files.
.obj/%.o : %.cpp
	@echo "\nCompiling C++:" $<
	$(CC) -c $(ALL_CPPFLAGS) $< -o $@

# Assemble: create object files from assembler source files.
.obj/%.o : %.S
	@echo "\nAssembling:" $<
	$(CC) -c $(ALL_ASFLAGS) $< -o $@


# Compile: create assembler files from C source files.
%.s : %.c
	$(CC) -S $(ALL_CFLAGS) $< -o $@

# Compile: create assembler files from C++ source files.
%.s : %.cpp
	$(CC) -S $(ALL_CPPFLAGS) $< -o $@


# Create preprocessed source for use in sending a bug report.
%.i : %.c
	$(CC) -E -mmcu=$(MCU) -I. $(CFLAGS) $< -o $@


# Clean project target.
clean:
	@echo "Cleaning project:"
	rm -rf $(CSRC:.c=.s)
	rm -rf $(CSRC:.c=.d) $(CSRC:.c=.i)
	rm -rf $(CPPSRC:.cpp=.map)
	rm -rf .out/ .obj/ .dep/
.PHONY : clean



# Help Target
help:
	@echo "The following are the valid targets for this Makefile: \n"
	@echo " ... all        = Make software (default if no target provided)."
	@echo " ... clean      = Clean out built project files."
	@echo " ... [ext]coff  = Convert ELF to AVR (Extended) COFF."
	@echo " ... upload     = Download the hex file to the device, using avrdude."
	@echo " ... filename.s = Compile filename.c[pp] into the assembler code only."
	@echo " ... filename.i = Create a preprocessed source file from filename.c."
	@echo " ... compile    = Rebuild the project (clean->all)"
	@echo " ... program    = Compile and upload to chip (= clean->all->upload)."
.PHONY : help



# Include the dependency files.
-include $(wildcard .dep/*)
