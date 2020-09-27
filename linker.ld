ENTRY(entry)
SECTIONS
{
<<<<<<< HEAD
  . = 0x10000000;
  .text : { *(.entry_section) }
  .text : { *(.text) }
  .text : { *(.text.startup) }
  .text : { *(.rodata) }
  .text : { *(.rodata.*) }

  . = 0x20000000;
  .data : { *(.data) }
  .bss : { *(.bss) }
=======
. = 0x10000000;
.text : { *(.entry_section) }
.text : { *(.text) }
.text : { *(.text.startup) }
.text : { *(.rodata) }
.text : { *(.rodata.*) }

. = 0x20000000;
.data : { *(.data) }
.bss : { *(.bss) }
>>>>>>> fb4b75da280720fdc7d7f7104514565fa3f09aee
}
