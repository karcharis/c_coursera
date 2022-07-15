---
date: 2022-07-13
title: ascii encoding
---

ASCII character encoding uses 1Byte (8bit) per character. Hence it stores 2^8 = 256 "characters". Originaly ASCII created as an 7bit encoding. When it became standard to use 8bits to groub data. The extra binary digit used to extend the ASCII encoding.

Basically, 0 to 31 (total 32 characters) is called as ASCII control characters. 32 to 127 characters are called as ASCII printable characters. And finally 128 to 255 is called as The extended ASCII codes. Note that a signed char in C is a 1B signed int. The extended ASCII characters correspond to the negative characters, i.e. their binary encoding ranges from 1000 0000 to 1111 1111.

For the ASCII table check [reference](http://www.ascii-code.com/)

**Note:** The term "extended ASCII" is not well defined, since it is not one character set. There are ASCII-type character sets for different usage, for example the (7bit) ASCII extension [ISO 8859-7](https://en.wikipedia.org/wiki/ISO/IEC_8859-7) is used for the greek language.
