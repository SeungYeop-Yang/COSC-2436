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

- $@        The filename representing the target.
- $%        The filename element of an archive member specification.
