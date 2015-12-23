Chapter 2 - Types, Operators and Expressions
============================================


Variables and constants are the basic data objects manipulated in a program.
Declarations list the variables to be used, and state what type they have and
perhaps what their initial values are. Operators specify what is to be done to
them. Expressions combine variables and constants to produce new values. The
type of an object determines the set of values it can have and what operations
can be performed on it. These building blocks are the topics of this chapter.

The ANSI standard has made many small changes and additions to basic types and
expressions. There are now `signed` and `unsigned` forms of all integer types,
and notations for `unsigned` constants and hexadecimal character constants.
Floating-point operations may be done in single precision; there is also a
`long` double type for extended precision. String constants may be concatenated
at compile time. Enumerations have become part of the language, formalizing a
feature of long standing. Objects may be declared `const`, which prevents them
from being changed. The rules for automatic coercions among arithmetic types
have been augmented to handle the richer set of types.

## 2.1 Variable Names

Although we didn't say so in Chapter 1, there are some restrictions on the
names of variables and symbolic constants. Names are made up of letters and
digits; the first character must be a letter. The underscore "\_" counts as a
letter; it is sometimes useful for improving the readability of long variable
names. Don't begin variable names with underscore, however, since library
routines often use such names. Upper and lower case letters are distinct, so
`x` and `X` are two different names. Traditional C practice is to use lower
case for variable names, and all upper case for symbolic constants.

At least the first 31 characters of an internal name are significant. For
function names and external variables, the number may be less than 31, because
external names may be used by assemblers and loaders over which the language
has no control. For external names, the standard guarantees uniqueness only for
6 characters and a single case. Keywords like `if`, `else`, `int`, `float`,
etc., are reserved: you can't use them as variable names. They must be in lower
case.

It's wise to choose variable names that are related to the purpose of the
variable, and that are unlikely to get mixed up typographically. We tend to use
short names for local variables, especially loop indices, and longer names for
external variables.

## 2.2 Data Types and Sizes

There are only a few basic data types in C:

name | Description
---- | ------------
`char` | a single byte, capable of holding one character in the local character set
`int`  | an integer, typically reflecting the natural size of integers on the host machine
`float`	| single-precision floating point
`double` | double-precision floating point

In addition, there are a number of qualifiers that can be applied to these
basic types. `short` and `long` apply to integers:

```c
short int sh;
long int counter;
```

The word `int` can be omitted in such declarations, and typically it is.

The intent is that `short` and `long` should provide different lengths of
integers where practical; `int` will normally be the natural size for a
particular machine. `short` is often 16 bits long, and `int` either 16 or 32
bits. Each compiler is free to choose appropriate sizes for its own hardware,
subject only to the the restriction that `short`s and `int`s are at least 16
bits, `long`s are at least 32 bits, and `short` is no longer than `int`, which
is no longer than `long`.

The qualifier `signed` or `unsigned` may be applied to `char` or any integer.
`unsigned` numbers are always positive or zero, and obey the laws of arithmetic
modulo 2n, where n is the number of bits in the type. So, for instance, if
`char`s are 8 bits, `unsigned char` variables have values between 0 and 255,
while `signed char`s have values between -128 and 127 (in a two's complement
machine.) Whether plain `char`s are `signed` or `unsigned` is
machine-dependent, but printable characters are always positive.

The type `long double` specifies extended-precision floating point. As with
integers, the sizes of floating-point objects are implementation-defined;
`float`, `double` and `long double` could represent one, two or three distinct
sizes.

The standard headers `<limits.h>` and `<float.h>` contain symbolic constants
for all of these sizes, along with other properties of the machine and
compiler. These are discussed in Appendix B.

**Exercise 2-1**. Write a program to determine the ranges of `char`, `short`,
`int`, and `long` variables, both `signed` and `unsigned`, by printing
appropriate values from standard headers and by direct computation. Harder if
you compute them: determine the ranges of the various floating-point types.

## 2.3 Constants

An integer constant like 1234 is an `int`. A `long` constant is written with a
terminal `l` (ell) or `L`, as in `123456789L`; an integer constant too big to
fit into an `int` will also be taken as a `long`. Unsigned constants are
written with a terminal `u` or `U`, and the suffix `ul` or `UL` indicates
`unsigned long`.

Floating-point constants contain a decimal point (123.4) or an exponent (1e-2)
or both; their type is `double`, unless suffixed. The suffixes `f` or `F`
indicate a `float` constant; `l` or `L` indicate a `long double`.

The value of an integer can be specified in octal or hexadecimal instead of
decimal. A leading `0` (zero) on an integer constant means octal; a leading
`0x` or `0X` means hexadecimal. For example, decimal 31 can be written as `037`
in octal and `0x1f` or `0x1F` in hex. Octal and hexadecimal constants may also
be followed by `L` to make them `long` and `U` to make them `unsigned`: `0XFUL`
is an `unsigned long` constant with value 15 decimal.

A character constant is an integer, written as one character within single
quotes, such as `'x'`. The value of a character constant is the numeric value
of the character in the machine's character set. For example, in the ASCII
character set the character constant `'0'` has the value `48`, which is
unrelated to the numeric value 0. If we write `'0'` instead of a numeric value
like 48 that depends on the character set, the program is independent of the
particular value and easier to read. Character constants participate in numeric
operations just as any other integers, although they are most often used in
comparisons with other characters.

Certain characters can be represented in character and string constants by
escape sequences like `\n` (newline); these sequences look like two characters,
but represent only one. In addition, an arbitrary byte-sized bit pattern can be
specified by

    '\ooo'

where `ooo` is one to three octal digits (0...7) or by

    '\xhh'

where `hh` is one or more hexadecimal digits (0...9, a...f, A...F). So we might write

```c
#define VTAB '\013'   /* ASCII vertical tab */
#define BELL '\007'   /* ASCII bell character */
```
or, in hexadecimal,
```c
#define VTAB '\xb'   /* ASCII vertical tab */
#define BELL '\x7'   /* ASCII bell character */
```

The complete set of escape sequences is 


sequence | name 
---------|-----
` \a` 	 |  alert (bell) character 	 
` \b`	 |  backspace	 
` \f` 	 |  formfeed	  
` \n` 	 |  newline	 
` \r` 	 |  carriage return	 
` \t` 	 |  horizontal tab	 
` \v` 	 |  vertical tab
`\\`	 |  backslash
`\?`	 |  question mark
`\'`	 |  single quote
`\"` 	 |  double quote
`\ooo`	 |  octal number
`\xhh`	 |  hexadecimal number 

The character constant `'\0'` represents the character with value zero, the
null character. `'\0'` is often written instead of 0 to emphasize the
character nature of some expression, but the numeric value is just 0.

A *constant expression* is an expression that involves only constants. Such expressions may be evaluated at during compilation rather than run-time, and accordingly may be used in any place that a constant can occur, as in

```c
#define MAXLINE 1000
char line[MAXLINE+1];
```

or

```c
#define LEAP 1 /* in leap years */
int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];
```

A *string constant*, or *string literal*, is a sequence of zero or more characters surrounded by double quotes, as in

```c
"I am a string"
```

or

```c
   "" /* the empty string */
```

The quotes are not part of the string, but serve only to delimit it. The same
escape sequences used in character constants apply in strings; `\"` represents
the double-quote character. String constants can be concatenated at compile
time:

```c
"hello, " "world"
```

is equivalent to

```c
   "hello, world"
```

This is useful for splitting up long strings across several source lines.

Technically, a string constant is an array of characters. The internal
representation of a string has a null character `'\0'` at the end, so the
physical storage required is one more than the number of characters written
between the quotes. This representation means that there is no limit to how
long a string can be, but programs must scan a string completely to determine
its length. The standard library function `strlen(s)` returns the length of its
character string argument `s`, **excluding** the terminal `'\0'`. Here is our
version:

```c
   /* strlen:  return length of s */
   int strlen(char s[])
   {
       int i;

       while (s[i] != '\0')
           ++i;
       return i;
   }
```

`strlen` and other string functions are declared in the standard header
`<string.h>`.

Be careful to distinguish between a character constant and a string that
contains a single character: `'x'` is not the same as `"x"`. The former is an
integer, used to produce the numeric value of the letter x in the machine's
character set. The latter is an array of characters that contains one character
(the letter x) and a `'\0'`.

There is one other kind of constant, the *enumeration constant*. An enumeration
is a list of constant integer values, as in

```c
enum boolean { NO, YES };
```

The first name in an `enum` has value 0, the next 1, and so on, unless explicit values are specified. If not all values are specified, unspecified values continue the progression from the last specified value, as the second of these examples:


```c
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
                NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };

enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
                JUL, AUG, SEP, OCT, NOV, DEC };
                    /* FEB = 2, MAR = 3, etc. */
```

Names in different enumerations must be distinct. Values need not be distinct
in the same enumeration.

Enumerations provide a convenient way to associate constant values with names,
an alternative to `#define` with the advantage that the values can be generated
for you. Although variables of `enum` types may be declared, compilers need not
check that what you store in such a variable is a valid value for the
enumeration. Nevertheless, enumeration variables offer the chance of checking
and so are often better than `#defines`. In addition, a debugger may be able to
print values of enumeration variables in their symbolic form. 

## 2.4 Declarations

All variables must be declared before use, although certain declarations can be made implicitly by content. A declaration specifies a type, and contains a list of one or more variables of that type, as in

```
int  lower, upper, step;
char c, line[1000];
```

Variables can be distributed among declarations in any fashion; the lists above
could well be written as

```c
int  lower;
int  upper;
int  step;
char c;
char line[1000];
```

The latter form takes more space, but is convenient for adding a comment to
each declaration for subsequent modifications.

A variable may also be initialized in its declaration. If the name is followed
by an equals sign and an expression, the expression serves as an initializer,
as in

```c
char  esc = '\\';
int   i = 0;
int   limit = MAXLINE+1;
float eps = 1.0e-5;
```

If the variable in question is not automatic, the initialization is done once
only, conceptionally before the program starts executing, and the initializer
must be a constant expression. An explicitly initialized automatic variable is
initialized each time the function or block it is in is entered; the
initializer may be any expression. External and static variables are
initialized to zero by default. Automatic variables for which is no explicit
initializer have undefined (i.e., garbage) values.

The qualifier `const` can be applied to the declaration of any variable to
specify that its value will not be changed. For an array, the `const` qualifier
says that the elements will not be altered.

```c
const double e = 2.71828182845905;
const char msg[] = "warning: ";
```

The `const` declaration can also be used with array arguments, to indicate that the function does not change that array:

```c
int strlen(const char[]);
```

The result is implementation-defined if an attempt is made to change a `const`. 

## 2.5 Arithmetic Operators

The binary arithmetic operators are `+`, `-`, `*`, `/`, and the modulus
operator `%`. Integer division truncates any fractional part. The expression

    x % y

produces the remainder when `x` is divided by `y`, and thus is zero when `y`
divides `x` exactly. For example, a year is a leap year if it is divisible by 4
but not by 100, except that years divisible by 400 are leap years. Therefore

```c
if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    printf("%d is a leap year\n", year);
else
    printf("%d is not a leap year\n", year);
```

The `%` operator cannot be applied to a `float` or `double`. The direction of
truncation for `/` and the sign of the result for `%` are machine-dependent for
negative operands, as is the action taken on overflow or underflow.

The binary `+` and `-` operators have the same precedence, which is lower than
the precedence of `*`, `/` and `%`, which is in turn lower than unary `+` and
`-`. Arithmetic operators associate left to right.

Table 2.1 at the end of this chapter summarizes precedence and associativity
for all operators.
