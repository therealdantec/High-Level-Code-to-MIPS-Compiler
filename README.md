# Lexical-Analyzer

This is a custom-made compiler that translates high-level language into MIPS Assembly code that is able to then successfully run in the application 'QT SPIM'.

**HOW TO USE**
1. Use IDE of choice to host program.
2. In TERMINAL: use 'Make all' to run program, use 'Make clean' to remove files generated from 'Make all'.


**COMPILER DESIGN AND IMPLEMENTATION**

1. Lexical Analysis: The lexical analyzer scans the test code and converts it into a sequence of tokens.
2. Syntax Analysis: The parser takes the tokens and forms an AST based on the grammar rules defined in the parser.
3. IR Code Generation: The compiler traverses the AST, translating the nodes into IR Code. 
4. MIPS Assembly Generation: The compiler passes the IR Code through OpenAI’s API to generate functional MIPS Assembly code.
