# matrixNecklace


Index
-----
* [Introduction](#introduction)
* [Project's Description](#projects-description)
* [Folders](#folders)
* [Known Issues](#known-issues)
* [To Do](#to-do)


Introduction
------------
This project is a simple customizable necklace, based on an ~~AtTiny2313a~~ AtTiny48/88 and a 8x8 dot LED matrix.

The very first idea came from furrtek's mind, called **jewelmatrix**. You can find his project on [his website](http://furrtek.free.fr/?a=jewelmatrix) (french).

I wanted to improve the thing and add a few options, like a rechargeable Li-Ion battery (instead of the coin cell furrtek used) and a cross-platform tool to add custom patterns on the fly, without the need to rebuild and flash the attiny every time.

To be implemented features :
* Fully customizable patterns
* Rechargeable by USB

Planned features :
* Easy on-the-fly programmation by any device running **\*nix**, **windows**, **MacOS** or **android** operating system, using the device's screen as the transmission support
* USB connection to host device (faster than screen transmision)


Project's Description
-------------------
* matrixEditor
    - matrixEditor is the UI for matrixNecklace's patterns creation.
    - Based on the FLTK graphic library.
    - Still at experimental level.


* matrixNecklace
    - AtTiny48/88 ~~AtTiny2313a~~ 8-bits microcontroller
    - 8x8 dot LED matrix
    - Li-Ion battery, which can be recharged via micro USB type B


Folders
-------
* **doc/**
    - Datasheets
* **editor/**
    - C++ Cross-platform editor source code
    - Compile script and instructions
* **firmware/**
    - AVR hardware source code
    - Compile script and instructions
    - Basic patterns (for reference)
    - Arduino sketch used to determinate matrix' pinout
* **hardware/**
    - **schematic/**
        - KiCad schematic files (not released yet)
* **licenses/**
    - Project's license file(s)
    - Every libraries used's specific license file(s)


Known Issues
------------
* 50/60 Hz differences may cause problems for screen transmission upload


To Do
-----
* Documentation
    - Sphinx documentation
    - Compiling HowTo


* Editor
    - Patterns import/export
    - Patterns ordering and timings
    - Integrated compiler (and it's output)
    - Device uploader


* Firmware
    - Correct pinout/registers match
    - Update for AtTiny48/88
    - Create custom bootloader
    - Add USB support


* Hardware
    - Finish pinout
    - Finish chips libraries
    - Release schematics
    - Create BOM
    - Still AtTiny2313a version ?
    - Mini USB type B version ?
