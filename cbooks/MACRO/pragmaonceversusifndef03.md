## `#pragma once` versus `#ifndef`
I've heard that these are essentially the same:

	//Automobile.h
	#ifndef _AUTOMOBILE_H
	#define _AUTOMOBILE_H
	#else
	//...
	#endif 

vs

	//Automobile.h
	#pragma once
	//... 

I've used the first way (`#ifndef`) in the past... but `#pragma once` seems simpler and less lines to type and what not so I'm wondering if it's legit.

### 1
Pragmas are machine- or operating system-specific by definition, and are usually different for every compiler. So if you want your code to be portable use the first method.

### 2
I've always used both. That way, if `#pragma once` is supported, it will include the file only once but if not, it is ignored and will used the `#ifndef` method. I wonder if that would be redundant...?

### 3
The `#ifndef` version is wrong.

	//Automobile.h
	#ifndef _AUTOMOBILE_H
	#define _AUTOMOBILE_H
	//#else
	//...
	#endif

### 4
@2 - it is redundant since all compilers support the include guard via `#ifndef`.

### 5
`#pragma once` can fail if the file system contains links to the same file that the compiler cannot follow.

For example, NTFS5 (Windows) supports hard links, but you can't detect that files are linked if you access the file sytem across an (SMB) network.

### 6
Not only should you use a unique and predictable (internal) `include guard` but you should also consider using (external) `include guards` around each preprocessor include directive in header files.

The following is a small example, both `a.h` and `b.h` include `base.h` but preprocessor will have information to not even visit base.h a second time. It makes little difference on a small project, but a large difference on big ones.

	// a.h 
	#ifndef INCLUDE_A
	#define INCLUDE_A

	#ifndef INCLUDE_BASE
	#include "base.h"
	#endif

	// code

	#endif

	---------------------------------------------------

	// b.h 
	#ifndef INCLUDE_B
	#define INCLUDE_B

	#ifndef INCLUDE_BASE
	#include "base.h"
	#endif

	// code

	#endif

	---------------------------------------------------

	// base.h
	#ifndef INCLUDE_BASE
	#define INCLUDE_BASE

	// code

	#endif





**Refs**

 * [#pragma once versus #ifndef](http://www.cplusplus.com/forum/beginner/7877/)
