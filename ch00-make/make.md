# Introduction 
GNU make defines a language for describing the relationships between source code,
intermediate files, and executables. It also provides features to manage alternate
configurations, implement reusable libraries of specifications, and parameterize
processes with user-defined macros. In short, make can be considered the center
of the development process by prroviding a roadmap of an application's components
and how they fit together.

The principle value of make comes from it ability to perform the complex series
of commands necessary to build an application and to optimize these operations
when possible to reduce the time taken by the edit-compile-debug cycle.

```
target: prereq_1 prereq_2
    commands
```

A rule of compiling a C file, foo.c, into an object file, foo.o:
```
foo.o: foo.c foo.h
    gcc -c foo.c
```

# Rules

## Automatic Variables

* $@ &emsp; The filename representing the target.
* $% &emsp; The filename element of an archive member specification.
* $< &emsp; The filename of the first prerequisite.
* $? &emsp; The names of all prerequisites taht are newer than the target, separated by spaces.
* $^ &emsp; The filenames of all the prerequisites, separated by spaces.
* \$\+ &emsp; Similar to $^, this is the names of all the prerequisites separated by spaces, 
except that \$+ includes duplicates. 
* $* &emsp; The stem of the target filename. A stem is typically a filename without its suffix.

A pattern rule looks like the normal rules except the stemp of the file (the portion before 
the suffix) is represented by a % character.

```
VPATH = src include
CPPFLAGS = -I include

%.o: %.c
    $(COMPILE.c) $(OUTPUT_OPTION) $<
```
