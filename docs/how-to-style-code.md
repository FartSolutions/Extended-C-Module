# How to style code
- [Naming conventions](#naming-conventions)
    - [Types and classes](#types-and-classes)
    - [Functions and methods](#functions-and-methods)
    - [Variables](#variables)
    - [Constants and macros](#constants-and-macros)
    - [Type traits and template metaprogramming](#type-traits-and-template-metaprogramming)
- [Code style](#code-style)
    - [Indentations](#indentations)
    - [Brackets](#brackets)
    - [Spaces](#spaces)
    - [Line length](#line-length)
    - [Comments](#comments)

## Foreword
A graphic that briefly and concisely describes the difference between the used naming conventions.
![Camel-/Snake-/Pascal-Case](https://khalilstemmler.com/img/blog/camel-snake-pascal-case/camel-case-snake-case-pascal-case.png)

## Naming conventions
### Types and Classes
Types, classes and structs are written in Pascal-Case.
```cpp
typedef unsigned int Uint32;
using Uint64 = unsigned long long;
class CustomClass { };
struct CustomStruct { };
```

### Functions and methods
Public functions and methods are written in Pascal-Case and private functions and methods are written in Snake-Case or Camel-Case.
```cpp
namespace
{
    // Private example (same for classes and structures)
    void process_data() { }
    // Or
    void processData() { }
} // anonymous namespace (for this example private namespace)
// Public example (same for classes and structures)
void ProcessData() { }
```

### Variables
Public variables are written in Pascal-Case and private variables are written in Snake-Case or Camel-Case preceded by an underscore.
```cpp
class ExampleClass
{
public:
    string ExampleName;
private:
    string _exampleSecret;
    string _example_secret;
};
```

### Constants and macros
Constants and definition-macros are written in UPPER_CASE.
```cpp
const unsigned int MAX_SIZE = 512;
#define MIN_SIZE = 64;
```

### Type traits and template metaprogramming
Type traits and template metaprogramming are written in Snake-Case.
```cpp
template<typename _Ty>
struct is_lvalue_reference {
    bool value = false;
};
```

## Code style
### Indentations
Indentations are always with 4 spaces per tab.

### Brackets
Opening brackets are on the same line as the control structure or declaration, unless it is a class, structure, function or method definition.
```cpp
class ExampleClass
{
    void DoSomething()
    {
        if (condition) {
            return;
        }
        while (true) {
            break;
        }
    }
};
```

### Spaces
Spaces always follow commas and keywords such as `if`, `for`, `while` and so on.

### Line length
There are nor more than 80 characters in a line; a line break must be inserted from the 81th character.

### Comments
Documentation comments are written in Doxygen style.
```cpp
/**
 * Here the function or method is explained in basic terms and, if necessary,
 * how to use it and what needs to be observed.
 *
 * \param param Description of the parameter.
 *
 * \returns Description of the return value.
 *
 * \since v1.0.0
 *
 * \sa ExampleType
 */
int ExampleFunction(ExampleType param);
```

Documentation comments at the beginning of a file are written written in Doxygen style.
```cpp
/**
 * \file example_file.h
 *
 * \brief Briefly describes the content of a file.
 */
```

|Parameter|Description
|-|-
|param|Describes the parameter
|returns|Describes the return value
|since|Indicates the version in which the function/structure was
|sa|Shows the dependencies
|file|Specifies a file name
|brief|Briefly describes the content of a file

&uarr; [Back to top](#top)
