# How to style code
- [Naming conventions](#naming-conventions)
    - [Types and classes](#types-and-classes)
    - [Functions and methods](#functions-and-methods)
    - [Variables](#variables)
    - [Constants and macros](#constants-and-macros)
    - [Type traits and template metaprogramming](#type-traits-and-template-metaprogramming)
- [Code style](#code-style)

## Foreword
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
