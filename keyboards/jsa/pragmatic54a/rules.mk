# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
NKRO_ENABLE	    = yes       # USB Nkey Rollover
LTO_ENABLE      = yes

CUSTOM_MATRIX = lite        # Custom matrix for "Duplex Matrix"
SRC += lib/duplex_matrix.c

CAPS_WORD_ENABLE = yes
