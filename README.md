matrixNecklace [status : dev]
=============================

Introduction
------------

This project is a simple customizable necklace, based on an AtTiny2313a and a 8x8 dot LED matrix.

The very first idea came from furrtek's mind. You can find his project on [his blog](http://furrtek.free.fr/?a=jewelmatrix) [in french])

I wanted to improve the thing and add a few options, like a rechargeable Li-Ion battery (instead of the coin one furrtek used) and a cross-platform tool to add custom patterns on the fly, without the need to rebuild and flash the attiny everytime.


Features
--------

* Fully customizable patterns

* Rechargeable by USB

* [Planned] Easy on-the-fly programmation by any device running **\*nix**, **windows**, **MacOS** or **android** operating system

* [Planned?] USB connection to host device


Hardware
--------

* AtTiny2313a 8 bits microcontroller
* 8x8 dot LED matrix
* Micro USB type B
* TP4501 battery charger


Folders
-------

* **doc/** Sphinx documentation.
* **editor/** Cross-platform editor and programmer code.
* **firmware/** AtTiny code.
* **hardware/** KiCad schematics and PCB layout.
