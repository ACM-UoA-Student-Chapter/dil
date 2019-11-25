# Department of Informatics Programming  Language

_Important note: This post is intended to provide useful info about the project to experienced programmers, to completely novice programmers and everything in between.
Realistically one can't do that without throwing novice programmers off.
Hence, if there's something that you don't understand, just skip it. If by reading this post you still have questions, please post them on Slack. With that in mind, let's get started._

## Motivation
In the Open Source Action, of the University of Athens ACM Student Chapter, we wanted
a mock project to help people get involved in open source development in a project of our own.
This is a proposal for a project - a programming language. Since most members study in the Department of Informatics in the University of Athens, I propose the name of this language to be: Department of Informatics Programming Language or **DIL**.

### Why this can be a good option for a mock project
A good mock project should:
- Have as much variety as possible.
- This variety should be in technologies / programming languages / concepts etc. that most
   members are comfortable with.
- It's useful, i.e. a real-world application.
- Since I (Stefanos Baziotis) will coordinate this project (at least at the start), it will be good if the project revolves around concepts that are familiar to me.

A programming language has a variety of things that it needs ranging from high-level (i.e. we may need Python to make a test suite) to low-level (i.e. assembly to implement library routines). There's a specific section that describes roughly but more in detail what we will need.

## Language Description

### Summary
The language is in very early development so many things might not make it to the final version. For now, you can check the sample programs in the
directory `/samples` to get a rough idea.

Essentially, it is a simple C-like language with either 3 primitive types (`int[]` (i.e. array of integers), `int` and `bool`) or 2 (by skipping `bool`) and user-defined types (kind of like structs in C).
It has all the usual things that one might need to make simple programs: Functions, structs, basic expressions and statements (ifs, loops etc.).

### Grammar
**WIP...**
The grammar is one of the core things one has to think about when writing a language. I have thought about it but hey, since this is a project that is supposed to be developed by newcomers to open-source, I leave
it to other people.

### Caveats
There are a couple of important caveats:
1) All the arrays will be heap-allocated, i.e. malloc'd. Underneath, an array will really be a pointer to the allocated memory. At some point, we may actually support stack-allocated arrays as in C. Those are essentially a pointer again, but allocated on the stack and this is not much different. For the time being though, only heap-allocated arrays.
2) All structs will be heap-allocated. Normal structs are difficult to handle for various reasons. It's difficult to do operations on them, it's difficult to pass them around etc. So, an object will really be the respective of reference in C++ or like an object in Java i.e. a pointer to the object and so the only thing we have to pass around is a pointer.
3) The arrays will be one-dimensional. Again, if you have 1-dimensional arrays adding more dimensions is not that difficult but there's no reason to do that for now.
4) Note in the grammar that the syntax will be limited, especially for expressions.
   You probably know that in C you can throw all the craziness that exists in an expression,
   like *(a->b).c + 2 + ... We won't do those here. Since we have limited our primitive types, handling complex expressions is not that of a problem in type-checking or code generation as it is in parsing. But again, no reason to do anything fancy yet.
5) No `else if`.
6) Only `while` loops.
7) No floating-point arithmetic.
8) No pointers.

### Development process
I think that one good way to organize this project is to start with issues in which one can work independently.
These are the standard github issues and they have been separated into differnet categories (e.g. easy, medium, hard, question etc.).
You can start from those and if you're inexperienced, start with the "easy" ones.
Apart from that, at some point I want to also provide a list of bigger "projects". These would be projects that require some
more time to be implemented and they will potentially revolve around different parts of the project.

### Can it be used for anything of any reasonable complexity ?
Yes! Even with this small set of features, you can write many interesting programs (i.e. you can almost write a compiler). One interesting goal is to be able to support most of the (C/C++) programming assignments of the Department of Informatics, UoA (or really, any university). This is an ambitious goal. There is at least one feature that has to be added and that is _strings_. A simple implementation of strings (i.e. array of 8-byte integers) is not that difficult but we leave it for later.

### What do we need to implement a programming language ?
At least a compiler. That's obvious but I thought I'd mention it. Also, we potentially need a runtime library. That is, when you call e.g. `memcpy()` in C, this is a function that is part of the standard library. We can of course use the C runtime library but we can also implement routines of our own.

### If I don't know anything about compilers, how can I help ?

Then, you probably fall in one of 2 categories:
1) You don't really care to learn about compilers so you want to get involved in coding that does not involve compiler specific knowledge.
I have you covered - there's a specific issue label exactly for this purpose: `not-compiler-specific`.

Here is a list off the top of my head of things that we will need that don't require compiler-specific knowledge (in random order):
- 2-3 hash tables.
- 2 `std::vector`-like data structures.
- **A memory allocator**. We need something to manage memory efficiently without continuously using `malloc()` and `free()`. This will require some low-level knowledge but it will be relatively simple.
- **The test code**. We need code written in this programming language (DIL) that will test the correctness of the compiler. An example of this is when we intentionally write some incorrect code and we want to verify that the compiler finds all the errors that it should. Writing test code is an art. The better test code you have, the more bugs you can catch in the compiler.
- **The test suite**. This is related to the above. We want some code that will help us perform the tests. This can be as simple as: I save in a file what the compiler _should_ output for a piece of code. Then, I call the compiler with this piece of code and verify that its output agrees with the saved output. The better test suite we have, the easier we make the testing of the compiler.
- **Writing tools for the language**. You probably could not write in your favorite programming language if your editor didn't have syntax-highlighting for it. Part of making a programming language is supporting the general environment that a programmer needs to use it. For the time being, this definitely includes syntax-highlighting in your favorite editor.
- **Implementing runtime utilities**. This is of least priority right now but it basically means implementing general runtime utilities. We may want to provide some utilities for reading files in DIL. Those are part of this.
- **Documentation**. You might not want to start by _writing_ code but instead understand code and explain it to other people.
That's very important both for you and this project, so please do so if you're interested. You can do that through comments or
even specific files devoted to documentation.
- **Bug reporting**. One other way to help is to test the compiler for edge cases that it might not handle and report them to us
by opening an issue.
- **Help in the separation of effort**. This is an educational project and one that tries to be quite friendly to
newcomers. As such, it's beneficial to the community to separate the work in small chunks rather than big projects.
In that way, one can pick a small piece to work on, preferably one that is not connected with many parts of the whole
project. If you have an idea about a small piece of work, please submit an issue. Especially if it is easy to newcomers
(i.e. good first issue).

2) You want to learn about compilers. In that case, this project is not intended to replace the imporant theory of textbooks
and courses. However, it can provide a very good practical experience. So, you can try to start with this project or a textbook
or both and ask me for questions, more resources, info etc.
