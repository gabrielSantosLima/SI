# Anotações sobre a matéria de LPC(Laboratório de Programação de Computadores)

## PEP-8
- It was written in 2001 by Guido van Rossum, Barry Warsaw, and Nick Coghlan
- It is a document that provides guidelines and best practices on how to write python code.

### Naming Conventions
```py
# package: package or mypackage
# filename: module.py or my_module.py

THIS_IS_A_CONSTANT = "Some constant Value"

my_variable = 2
name = "Sarah"

def function():
  # Some code

def other_function():
  # Some code

def do_something():
  # Some code

class SomeClass:
  # Some code
```

### Code Layouts
- Blank Lines
  - Top-level function and classes: surround with 2 blank lines
  - Between class methods: surround with 1 blank line
  - Blank line between the steps of your code
- Max line length: 79 chars
```py
# Line breaking example
total = (first_variable
         + second_variable
         - third_variable)

def function(arg_one, arg_two,
             arg_three, arg_four):
    return arg_one
```