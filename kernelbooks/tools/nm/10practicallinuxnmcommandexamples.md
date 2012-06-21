## 10 Practical Linux nu Command Examples
The `nm` commands provide information on the symbols being used in an object file or executable file.

The default information that the `nm` command provides is:

 * Virtual address of the symbol
 * A character which depicts the symbol type. If the character is in lower case then the symbol is local but if the character is upper case then the symbol is external.
 * Name of the symbol

The characters that identify symbol type describe:

 * A - Global absolute symbol.
 * a - Local absolute symbol.
 * B - Global bss symbol.
 * b - Local bss symbol.
 * D - Global data symbol.
 * d - Local data symbol.
 * f - Source file name symbol.
 * L - Global thread-local symbol (TLS).
 * l - Static thread-local symbol (TLS).
 * T - Global text symbol.
 * t - Local text symbol.
 * U - Undefined symbol.

Note that this list is not exhaustive but contains some important symbol types. For complete information please refer the man page of this utility.

















**Refs**

 * [10 Practical Linux nu Command Examples](http://www.thegeekstuff.com/2012/03/linux-nm-command/)
