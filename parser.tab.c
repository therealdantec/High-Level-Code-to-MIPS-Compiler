/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "Assembly.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

FILE * IRcode;
//FILE * MIPScode;


void yyerror(const char* s);
char* currentScope = "global"; // "global" or the name of the function
int semanticCheckPassed = 1; // flags to record correctness of semantic checks

#line 95 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_CHAR = 4,                       /* CHAR  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_BOOL = 6,                       /* BOOL  */
  YYSYMBOL_STRUC = 7,                      /* STRUC  */
  YYSYMBOL_FUNCT = 8,                      /* FUNCT  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_NUMBER = 10,                    /* NUMBER  */
  YYSYMBOL_SEMICOLON = 11,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 12,                     /* COMMA  */
  YYSYMBOL_UNDERSCORE = 13,                /* UNDERSCORE  */
  YYSYMBOL_PERIOD = 14,                    /* PERIOD  */
  YYSYMBOL_LT = 15,                        /* LT  */
  YYSYMBOL_GT = 16,                        /* GT  */
  YYSYMBOL_LTE = 17,                       /* LTE  */
  YYSYMBOL_GTE = 18,                       /* GTE  */
  YYSYMBOL_NE = 19,                        /* NE  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_TRUTH = 23,                     /* TRUTH  */
  YYSYMBOL_FALSITY = 24,                   /* FALSITY  */
  YYSYMBOL_ASS = 25,                       /* ASS  */
  YYSYMBOL_WRITE = 26,                     /* WRITE  */
  YYSYMBOL_REEE = 27,                      /* REEE  */
  YYSYMBOL_IF = 28,                        /* IF  */
  YYSYMBOL_ELSE = 29,                      /* ELSE  */
  YYSYMBOL_SWITCH = 30,                    /* SWITCH  */
  YYSYMBOL_CASE = 31,                      /* CASE  */
  YYSYMBOL_WHILE = 32,                     /* WHILE  */
  YYSYMBOL_REPEAT = 33,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 34,                     /* UNTIL  */
  YYSYMBOL_PLUS = 35,                      /* PLUS  */
  YYSYMBOL_MINUS = 36,                     /* MINUS  */
  YYSYMBOL_TIMES = 37,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 38,                    /* DIVIDE  */
  YYSYMBOL_LPRN = 39,                      /* LPRN  */
  YYSYMBOL_RPRN = 40,                      /* RPRN  */
  YYSYMBOL_LCB = 41,                       /* LCB  */
  YYSYMBOL_RCB = 42,                       /* RCB  */
  YYSYMBOL_LSB = 43,                       /* LSB  */
  YYSYMBOL_RSB = 44,                       /* RSB  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_Program = 46,                   /* Program  */
  YYSYMBOL_DeclareFunct = 47,              /* DeclareFunct  */
  YYSYMBOL_Code = 48,                      /* Code  */
  YYSYMBOL_FunctCall = 49,                 /* FunctCall  */
  YYSYMBOL_Type = 50,                      /* Type  */
  YYSYMBOL_ParamsList = 51,                /* ParamsList  */
  YYSYMBOL_Param = 52,                     /* Param  */
  YYSYMBOL_CallParamsList = 53,            /* CallParamsList  */
  YYSYMBOL_StrucAccess = 54,               /* StrucAccess  */
  YYSYMBOL_VarDecl = 55,                   /* VarDecl  */
  YYSYMBOL_SwitchBlock = 56,               /* SwitchBlock  */
  YYSYMBOL_ElseBlock = 57,                 /* ElseBlock  */
  YYSYMBOL_Stmt = 58,                      /* Stmt  */
  YYSYMBOL_Expr = 59,                      /* Expr  */
  YYSYMBOL_BoolExpr = 60                   /* BoolExpr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    64,    68,    72,    79,    89,    93,    97,
     105,   114,   118,   122,   126,   134,   138,   142,   149,   157,
     161,   165,   173,   176,   185,   201,   224,   231,   235,   242,
     246,   253,   271,   278,   293,   297,   302,   307,   312,   322,
     329,   333,   339,   344,   349,   378,   400,   429,   451,   480,
     502,   531,   557,   561,   565,   569,   573,   577,   581,   585
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "CHAR",
  "STRING", "BOOL", "STRUC", "FUNCT", "ID", "NUMBER", "SEMICOLON", "COMMA",
  "UNDERSCORE", "PERIOD", "LT", "GT", "LTE", "GTE", "NE", "AND", "OR",
  "EQ", "TRUTH", "FALSITY", "ASS", "WRITE", "REEE", "IF", "ELSE", "SWITCH",
  "CASE", "WHILE", "REPEAT", "UNTIL", "PLUS", "MINUS", "TIMES", "DIVIDE",
  "LPRN", "RPRN", "LCB", "RCB", "LSB", "RSB", "$accept", "Program",
  "DeclareFunct", "Code", "FunctCall", "Type", "ParamsList", "Param",
  "CallParamsList", "StrucAccess", "VarDecl", "SwitchBlock", "ElseBlock",
  "Stmt", "Expr", "BoolExpr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    74,   -23,     9,   -56,    11,   -56,   -56,   -56,   -56,
      34,    10,   -56,     5,    97,   -56,   -14,    16,    58,   -56,
      -2,    42,   -56,    48,   -19,    49,    10,    31,    33,    35,
      19,    57,    72,   -56,   -56,    74,    73,    10,    10,    10,
      10,    80,    10,    10,    10,    10,    10,   -56,    88,    64,
      10,   103,    87,    96,    10,    10,    10,   -56,   -56,    -6,
     111,     0,   -56,   -56,   -56,   -56,   -56,   -56,    82,   -56,
     -56,   -56,   -56,   -56,   -56,    59,   117,    90,   -56,   -56,
     100,   -17,   113,    21,   105,   -56,    10,   -56,    74,    95,
     -56,   114,   -56,   120,    10,    10,    10,    10,    10,    10,
      10,    10,   116,   118,   119,   121,   122,   -56,   -56,   -56,
      10,   -56,   -56,   -56,   -56,   -56,   -56,    29,    29,   -56,
     -56,   -56,   123,   147,   150,   137,   143,   145,    10,   -56,
     -56,   139,    10,   177,   -56,    27,   135,   -56,   144,   -56,
     -56,   -56,   -56,   185,   217,   -56,   -56
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     0,     9,     0,    11,    12,    13,    14,
       0,    21,     1,     4,     0,     3,     0,    39,    43,    41,
       0,    42,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     2,     0,
       0,     0,    16,    23,    44,    46,    48,    50,     0,    45,
      47,    49,    51,    19,    22,     0,     0,     0,    33,    34,
       0,     0,     0,     0,     0,    24,     0,    18,     0,     0,
      40,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     6,    26,
       0,    52,    53,    54,    55,    56,    57,    58,    59,     9,
      28,     9,     0,     0,     0,     0,     9,     0,     0,    25,
      32,    30,     0,     0,    37,     0,     0,    35,     0,    36,
      38,     9,     9,     0,     0,    29,    27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -56,   193,   -56,   -50,     8,     1,   -56,   107,   -56,   -56,
     124,   -56,   -56,   -56,   -11,   -55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    13,     4,    14,    19,    32,    61,    62,    20,    21,
      33,   126,   137,    34,    80,    81
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      22,    83,    10,   100,   101,    85,    50,    84,     5,    12,
      46,     5,    88,     1,     2,    53,    11,     1,     2,    17,
      18,     5,    15,   102,    51,    35,    64,    65,    66,    67,
      36,    69,    70,    71,    72,    73,    60,    86,    47,    76,
      89,   100,   101,    16,    82,   117,   118,   100,   101,   100,
     101,    37,    38,    39,    40,    11,    48,    49,    52,    41,
      57,   104,     6,     7,     8,     9,    23,   140,    58,   125,
      54,   127,    55,   135,    56,   106,   133,     6,     7,     8,
       9,    59,    63,   111,   112,   113,   114,   115,   116,    60,
      68,   143,   144,    42,    43,    44,    45,    74,    78,   124,
       6,     7,     8,     9,    23,    75,    24,    79,     6,     7,
       8,     9,    23,    77,    24,    94,    95,    96,    97,    98,
      87,   138,    99,    25,    26,    27,    90,    28,    92,    29,
      30,    25,    26,    27,    93,    28,   108,    29,    30,    31,
       6,     7,     8,     9,    23,   110,    24,   105,     6,     7,
       8,     9,    23,   103,    24,   122,   109,   119,   129,   120,
     121,   130,   128,    25,    26,    27,   123,    28,   136,    29,
      30,    25,    26,    27,   132,    28,   141,    29,    30,   131,
       6,     7,     8,     9,    23,   142,    24,   134,     6,     7,
       8,     9,    23,     3,    24,   107,     0,     0,     0,    91,
       0,     0,     0,    25,    26,    27,     0,    28,     0,    29,
      30,    25,    26,    27,     0,    28,     0,    29,    30,   139,
       6,     7,     8,     9,    23,     0,    24,   145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,     0,    28,     0,    29,
      30,     0,     0,     0,     0,     0,     0,     0,     0,   146
};

static const yytype_int16 yycheck[] =
{
      11,    56,     1,    20,    21,    11,    25,    57,     0,     0,
      12,     3,    12,     8,     9,    26,    39,     8,     9,     9,
      10,    13,    11,    40,    43,    39,    37,    38,    39,    40,
      14,    42,    43,    44,    45,    46,    35,    43,    40,    50,
      40,    20,    21,     9,    55,   100,   101,    20,    21,    20,
      21,    35,    36,    37,    38,    39,    14,     9,     9,    43,
      41,    40,     3,     4,     5,     6,     7,    40,    11,   119,
      39,   121,    39,   128,    39,    86,   126,     3,     4,     5,
       6,     9,     9,    94,    95,    96,    97,    98,    99,    88,
      10,   141,   142,    35,    36,    37,    38,     9,    11,   110,
       3,     4,     5,     6,     7,    41,     9,    11,     3,     4,
       5,     6,     7,    10,     9,    15,    16,    17,    18,    19,
       9,   132,    22,    26,    27,    28,    44,    30,    11,    32,
      33,    26,    27,    28,    44,    30,    41,    32,    33,    42,
       3,     4,     5,     6,     7,    25,     9,    42,     3,     4,
       5,     6,     7,    40,     9,    34,    42,    41,    11,    41,
      41,    11,    39,    26,    27,    28,    44,    30,    29,    32,
      33,    26,    27,    28,    31,    30,    41,    32,    33,    42,
       3,     4,     5,     6,     7,    41,     9,    42,     3,     4,
       5,     6,     7,     0,     9,    88,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,    -1,    32,
      33,    26,    27,    28,    -1,    30,    -1,    32,    33,    42,
       3,     4,     5,     6,     7,    -1,     9,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,    -1,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,     9,    46,    47,    49,     3,     4,     5,     6,
      50,    39,     0,    46,    48,    11,     9,     9,    10,    49,
      53,    54,    59,     7,     9,    26,    27,    28,    30,    32,
      33,    42,    50,    55,    58,    39,    14,    35,    36,    37,
      38,    43,    35,    36,    37,    38,    12,    40,    14,     9,
      25,    43,     9,    59,    39,    39,    39,    41,    11,     9,
      50,    51,    52,     9,    59,    59,    59,    59,    10,    59,
      59,    59,    59,    59,     9,    41,    59,    10,    11,    11,
      59,    60,    59,    60,    48,    11,    43,     9,    12,    40,
      44,    55,    11,    44,    15,    16,    17,    18,    19,    22,
      20,    21,    40,    40,    40,    42,    59,    52,    41,    42,
      25,    59,    59,    59,    59,    59,    59,    60,    60,    41,
      41,    41,    34,    44,    59,    48,    56,    48,    39,    11,
      11,    42,    31,    48,    42,    60,    29,    57,    59,    42,
      40,    41,    41,    48,    48,    42,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    46,    46,    47,    48,    48,    48,
      49,    50,    50,    50,    50,    51,    51,    51,    52,    53,
      53,    53,    54,    54,    55,    55,    55,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     2,     2,     0,     7,     2,     2,     0,
       4,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       1,     0,     3,     3,     3,     6,     5,     6,     0,     4,
       0,     4,     7,     3,     3,     8,     8,     7,     8,     1,
       4,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_ID: /* ID  */
#line 44 "parser.y"
         { fprintf(yyoutput, "%s", ((*yyvaluep).string)); }
#line 868 "parser.tab.c"
        break;

    case YYSYMBOL_NUMBER: /* NUMBER  */
#line 45 "parser.y"
         { fprintf(yyoutput, "%s", ((*yyvaluep).string)); }
#line 874 "parser.tab.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: DeclareFunct Code RCB SEMICOLON  */
#line 57 "parser.y"
                                        { 
		printf("RULE Program: Function\n");
		// $$ = astCreateFunct($3, nodeToString($2));
		// IRfunction(nodeToString($2), $3);
		// emitMIPSFunction($3);
		emitMIPSjal();
	}
#line 1270 "parser.tab.c"
    break;

  case 3: /* Program: FunctCall SEMICOLON  */
#line 64 "parser.y"
                              {
		printf("RULE Program: FunctCall\n");
		(yyval.ast_node) = (yyvsp[-1].ast_node);
	}
#line 1279 "parser.tab.c"
    break;

  case 4: /* Program: Program Program  */
#line 68 "parser.y"
                          {
		printf("RULE Program: Program Program\n");
		(yyval.ast_node) = (yyvsp[-1].ast_node);
	}
#line 1288 "parser.tab.c"
    break;

  case 5: /* Program: %empty  */
#line 72 "parser.y"
          {
		printf("RULE Program: EMPTY\n");
		(yyval.ast_node) = NULL;
	}
#line 1297 "parser.tab.c"
    break;

  case 6: /* DeclareFunct: FUNCT Type ID LPRN ParamsList RPRN LCB  */
#line 79 "parser.y"
                                               {
		printf("RULE Function: Function Declaration");
		IRfunction(nodeToString((yyvsp[-5].ast_node)), (yyvsp[-4].string));
		emitMIPSFunction((yyvsp[-4].string));
		
	}
#line 1308 "parser.tab.c"
    break;

  case 7: /* Code: Code VarDecl  */
#line 89 "parser.y"
                     {
		printf("RULE Code: VarDecl\n");
		(yyval.ast_node) = (yyvsp[-1].ast_node);
	}
#line 1317 "parser.tab.c"
    break;

  case 8: /* Code: Code Stmt  */
#line 93 "parser.y"
                    {
		printf("RULE Code: Stmt\n");
		(yyval.ast_node) = (yyvsp[-1].ast_node);
	}
#line 1326 "parser.tab.c"
    break;

  case 9: /* Code: %empty  */
#line 97 "parser.y"
          {
		printf("RULE Code: EMPTY\n");
		(yyval.ast_node) = NULL;
	}
#line 1335 "parser.tab.c"
    break;

  case 10: /* FunctCall: ID LPRN CallParamsList RPRN  */
#line 105 "parser.y"
                                    {
		printf("RULE RECOGNIZED: FunctCall\n");
		callIRfunction((yyvsp[-3].string));
		(yyval.ast_node) = (yyvsp[-1].ast_node);
	}
#line 1345 "parser.tab.c"
    break;

  case 11: /* Type: INT  */
#line 114 "parser.y"
            {
		printf("RULE Type: INT\n");
		(yyval.ast_node) = astCreateType((yyvsp[0].string));
	}
#line 1354 "parser.tab.c"
    break;

  case 12: /* Type: CHAR  */
#line 118 "parser.y"
               {
		printf("RULE Type: CHAR\n");
		(yyval.ast_node) = astCreateType((yyvsp[0].string));
	}
#line 1363 "parser.tab.c"
    break;

  case 13: /* Type: STRING  */
#line 122 "parser.y"
                 {
		printf("RULE Type: STRING\n");
		(yyval.ast_node) = astCreateType((yyvsp[0].string));
	}
#line 1372 "parser.tab.c"
    break;

  case 14: /* Type: BOOL  */
#line 126 "parser.y"
               {
		printf("RULE Type: BOOL\n");
		(yyval.ast_node) = astCreateType((yyvsp[0].string));
	}
#line 1381 "parser.tab.c"
    break;

  case 15: /* ParamsList: ParamsList COMMA Param  */
#line 134 "parser.y"
                               {
		printf("RULE ParamsList: ParamsList COMMA Param\n");
		(yyval.ast_node) = (yyvsp[0].ast_node);
	}
#line 1390 "parser.tab.c"
    break;

  case 16: /* ParamsList: Param  */
#line 138 "parser.y"
                {
		printf("RULE ParamsList: Param\n");
		(yyval.ast_node) = (yyvsp[0].ast_node);
	}
#line 1399 "parser.tab.c"
    break;

  case 17: /* ParamsList: %empty  */
#line 142 "parser.y"
          {
		printf("RULE ParamsList: EMPTY\n");
		(yyval.ast_node) = NULL;
	}
#line 1408 "parser.tab.c"
    break;

  case 18: /* Param: Type ID  */
#line 149 "parser.y"
                {
		printf("RULE Param: ID=%s\n", (yyvsp[0].string));
		(yyval.ast_node) = astCreateFunctParam(nodeToString((yyvsp[-1].ast_node)), (yyvsp[0].string));	

	}
#line 1418 "parser.tab.c"
    break;

  case 19: /* CallParamsList: CallParamsList COMMA Expr  */
#line 157 "parser.y"
                                  {
		printf("RULE CallParamsList: CallParamsList COMMA Expr\n");
		(yyval.ast_node) = (yyvsp[0].ast_node);
	}
#line 1427 "parser.tab.c"
    break;

  case 20: /* CallParamsList: Expr  */
#line 161 "parser.y"
               {
		printf("RULE CallParamsList: Expr\n");
		(yyval.ast_node) = (yyvsp[0].ast_node);
	}
#line 1436 "parser.tab.c"
    break;

  case 21: /* CallParamsList: %empty  */
#line 165 "parser.y"
          {
		printf("RULE CallParamsList: EMPTY\n");
		(yyval.ast_node) = NULL;
	}
#line 1445 "parser.tab.c"
    break;

  case 22: /* StrucAccess: StrucAccess PERIOD ID  */
#line 173 "parser.y"
                              {
		printf("RULE StructAccess: StrucAccess PERIOD ID\n");
	}
#line 1453 "parser.tab.c"
    break;

  case 23: /* StrucAccess: ID PERIOD ID  */
#line 176 "parser.y"
                       {
		printf("RULE StructAccess: ID PERIOD ID\n");
	}
#line 1461 "parser.tab.c"
    break;

  case 24: /* VarDecl: Type ID SEMICOLON  */
#line 185 "parser.y"
                          { 
		printf("\n RECOGNIZED RULE: Variable declaration %s\n", (yyvsp[-1].string));
		// Symbol Table operations
		int inSymTab = found((yyvsp[-1].string), currentScope);
		// semantic checks
		if (inSymTab == 0) {
			addItem((yyvsp[-1].string), "Var", nodeToString((yyvsp[-2].ast_node)), 0, currentScope);
			// AST operations
			(yyval.ast_node) = astCreateVarDecl(nodeToString((yyvsp[-2].ast_node)), (yyvsp[-1].string));
		}
		else {
			printf("SEMANTIC ERROR: Var %s is already declared\n", (yyvsp[-1].string));
		}
		showSymTable();
	}
#line 1481 "parser.tab.c"
    break;

  case 25: /* VarDecl: Type ID LSB Expr RSB SEMICOLON  */
#line 201 "parser.y"
                                         {
		printf("\n RECOGNIZED RULE: Array Declaration\n");

		//Semantic check
		int inSymTab = found((yyvsp[-4].string), currentScope);

		if (inSymTab == 0){
			addItem((yyvsp[-4].string), "Arr", nodeToString((yyvsp[-5].ast_node)), atoi(nodeToString((yyvsp[-2].ast_node))), currentScope);

			IRarray((yyvsp[-4].string), nodeToString((yyvsp[-5].ast_node)), nodeToString((yyvsp[-2].ast_node)));

			// Add to AST. Null for now
			(yyval.ast_node) = NULL;

		}
		else {
			printf("SEMANTIC ERROR: Arr %s is already declared\n", (yyvsp[-4].string));
		}

		showSymTable();

	}
#line 1508 "parser.tab.c"
    break;

  case 26: /* VarDecl: STRUC ID LCB VarDecl RCB  */
#line 224 "parser.y"
                                   {
		printf("\n RECOGNIZED RULE: Struct Declaration\n");
		IRstruct((yyvsp[-3].string), nodeToString((yyvsp[-1].ast_node)));
	}
#line 1517 "parser.tab.c"
    break;

  case 27: /* SwitchBlock: SwitchBlock CASE Expr LCB Code RCB  */
#line 231 "parser.y"
                                           {
		printf("\n RECOGNIZED RULE: SwitchBlock: SwitchBlock CASE Expr LCB Code RCB\n");
		(yyval.ast_node) = astCreateSwitchBlock((yyvsp[-5].ast_node), (yyvsp[-3].ast_node), (yyvsp[-1].ast_node));
	}
#line 1526 "parser.tab.c"
    break;

  case 28: /* SwitchBlock: %empty  */
#line 235 "parser.y"
          {
		printf("\n RECOGNIZED RULE: SwitchBlock: EMPTY\n");
		(yyval.ast_node) = NULL;
	}
#line 1535 "parser.tab.c"
    break;

  case 29: /* ElseBlock: ELSE LCB Code RCB  */
#line 242 "parser.y"
                          {
		printf("\n RECOGNIZED RULE: ElseBlock: ELSE LCB Code RCB\n");
		(yyval.ast_node) = (yyvsp[-1].ast_node);
	}
#line 1544 "parser.tab.c"
    break;

  case 30: /* ElseBlock: %empty  */
#line 246 "parser.y"
          {
		printf("\n RECOGNIZED RULE: ElseBlock: EMPTY\n");
		(yyval.ast_node) = NULL;
	}
#line 1553 "parser.tab.c"
    break;

  case 31: /* Stmt: ID ASS Expr SEMICOLON  */
#line 253 "parser.y"
                              {
		printf("\n RULE ID ASS Expr SEMICOLON\n");
		// Semantic check
		// TODO implement type checking
		if (found((yyvsp[-3].string), currentScope)) {
			(yyval.ast_node) = astCreateVar((yyvsp[-3].string));  

			char* result = generateTempVar();
			emitAssignment(result, nodeToString((yyvsp[-1].ast_node)));

			emitMIPSAssignment(result, nodeToString((yyvsp[-1].ast_node)));
		} 
		else {
			printf("SEMANTIC ERROR: Var %s has not been declared\n", (yyvsp[-3].string));
		}
		
	}
#line 1575 "parser.tab.c"
    break;

  case 32: /* Stmt: ID LSB NUMBER RSB ASS Expr SEMICOLON  */
#line 271 "parser.y"
                                               {
		printf("\n RECOGNIZED RULE: ARRAY ASSIGNMENT\n");
		char* arrayRef;
		sprintf(arrayRef, "%s[%s]", (yyvsp[-6].string), (yyvsp[-4].string));
		(yyval.ast_node) = astCreateVar(arrayRef);
	}
#line 1586 "parser.tab.c"
    break;

  case 33: /* Stmt: WRITE ID SEMICOLON  */
#line 278 "parser.y"
                             {
		printf("\n RECOGNIZED RULE: WRITE statement\n");
		
		// Check if identifiers have been declared
		if(found((yyvsp[-1].string), currentScope)) {
			emitWriteId((yyvsp[-1].string));
			char* write = generateTempAddr();
			emitMIPSWriteId(write, (yyvsp[-1].string));
			(yyval.ast_node) = astCreateWrite((yyvsp[-1].string));
		}
		else {
			printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-1].string), currentScope);
		}
	}
#line 1605 "parser.tab.c"
    break;

  case 34: /* Stmt: REEE Expr SEMICOLON  */
#line 293 "parser.y"
                              {
		(yyval.ast_node) = astCreateReee(nodeToString((yyvsp[-1].ast_node)));
	}
#line 1613 "parser.tab.c"
    break;

  case 35: /* Stmt: IF LPRN BoolExpr RPRN LCB Code RCB ElseBlock  */
#line 297 "parser.y"
                                                       {
		printf("\n RECOGNIZED RULE: Stmt: IF LPRN BoolExpr RPRN LCB Code RCB ElseBlock\n");
		(yyval.ast_node) = astCreateIfElse((yyvsp[-5].ast_node), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
	}
#line 1622 "parser.tab.c"
    break;

  case 36: /* Stmt: SWITCH LPRN Expr RPRN LCB SwitchBlock Code RCB  */
#line 302 "parser.y"
                                                         {
		printf("\n RECOGNIZED RULE: SWITCH STATEMENT\n");
		(yyval.ast_node) = astCreateSwitchStmt((yyvsp[-5].ast_node), (yyvsp[-2].ast_node), (yyvsp[-1].ast_node));
	}
#line 1631 "parser.tab.c"
    break;

  case 37: /* Stmt: WHILE LPRN BoolExpr RPRN LCB Code RCB  */
#line 307 "parser.y"
                                                {
		printf("\n RECOGNIZED RULE: WHILE LOOP\n");
		(yyval.ast_node) = astCreateLoop((yyvsp[-4].ast_node), (yyvsp[-1].ast_node));
	}
#line 1640 "parser.tab.c"
    break;

  case 38: /* Stmt: REPEAT LCB Code RCB UNTIL LPRN BoolExpr RPRN  */
#line 312 "parser.y"
                                                       {
		printf("\n RECOGNIZED RULE: REPEAT STATEMENT\n");
		(yyval.ast_node) = astCreateLoop((yyvsp[-1].ast_node), (yyvsp[-5].ast_node));
	}
#line 1649 "parser.tab.c"
    break;

  case 39: /* Expr: ID  */
#line 322 "parser.y"
           { 
		printf("\n RECOGNIZED RULE: ID, %s\n", (yyvsp[0].string)); 
		(yyval.ast_node) = astCreateVar((yyvsp[0].string));
		// char* result = generateTempVar();
		// emitAssignment(result, $1);
	}
#line 1660 "parser.tab.c"
    break;

  case 40: /* Expr: ID LSB NUMBER RSB  */
#line 329 "parser.y"
                            {
		printf("\n RECOGNIZED RULE: Array Variable\n");
	}
#line 1668 "parser.tab.c"
    break;

  case 41: /* Expr: FunctCall  */
#line 333 "parser.y"
                    {
		printf("\n RECOGNIZED RULE: Function Call\n");
		(yyval.ast_node) = (yyvsp[0].ast_node);
	}
#line 1677 "parser.tab.c"
    break;

  case 42: /* Expr: StrucAccess  */
#line 339 "parser.y"
                      {
		printf("\n RECOGNIZED RULE: Struct Access\n");
		(yyval.ast_node) = (yyvsp[0].ast_node);
	}
#line 1686 "parser.tab.c"
    break;

  case 43: /* Expr: NUMBER  */
#line 344 "parser.y"
                 { 
		printf("\n RECOGNIZED RULE: NUMBER, %s\n", (yyvsp[0].string)); 
		(yyval.ast_node) = astCreateInt((yyvsp[0].string));
	}
#line 1695 "parser.tab.c"
    break;

  case 44: /* Expr: ID PLUS Expr  */
#line 349 "parser.y"
                       {
		printf("\n RECOGNIZED RULE: ID PLUS Expr, ID is %s \n", (yyvsp[-2].string));

		

		// Check if identifiers have been declared
		if (!found((yyvsp[-2].string), currentScope)) {
			printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-2].string), currentScope);
			semanticCheckPassed = 0;
		}
		
		// see if types are compatible, currently causing segfault cuz nodes
		// if (!compareTypes($1, $3, currentScope);) {
		// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		// 	semanticCheckPassed = 0;
		// }


		// this is some wizard temp register shit
		if (semanticCheckPassed) {
			//$$ = astCreateVar($1);
			(yyval.ast_node) = astCreateBinaryOp("+", astCreateVar((yyvsp[-2].string)), (yyvsp[0].ast_node));
			char* result = generateTempVar();  // Generate a temporary variable for the result
			emitBinaryOperation("+", result, (yyvsp[-2].string), nodeToString((yyvsp[0].ast_node)));
			emitMIPSBinaryOp("add", result, (yyvsp[-2].string), nodeToString((yyvsp[0].ast_node)));
			(yyval.ast_node) = astCreateVar(result);
			
		}		
	}
#line 1729 "parser.tab.c"
    break;

  case 45: /* Expr: NUMBER PLUS Expr  */
#line 378 "parser.y"
                           {
		printf("\n RECOGNIZED RULE: NUMBER PLUS Expr, %s\n", (yyvsp[-2].string));
		
		// see if types are compatible, currently causing segfault cuz nodes
		// if (!compareTypes($1, $3, currentScope);) {
		// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		// 	semanticCheckPassed = 0;
		// }

		if (semanticCheckPassed) {
			char* result = generateTempVar();  // Generate a temporary variable for the result
			char* str = (char*)malloc(15);
			char* str1 = (char*)malloc(15);
			sprintf(str, "%s", (yyvsp[-2].string));
			sprintf(str1, "%s", nodeToString((yyvsp[0].ast_node)));
			emitBinaryOperation("+", result, str, str1);
			emitMIPSBinaryOp("add", result, str, str1);
			// Update the current expression result
			// $$ = astCreateVar(result);
			(yyval.ast_node) = astCreateBinaryOp("+", astCreateInt((yyvsp[-2].string)), (yyvsp[0].ast_node));
		}
	}
#line 1756 "parser.tab.c"
    break;

  case 46: /* Expr: ID MINUS Expr  */
#line 400 "parser.y"
                        {
		printf("\n RECOGNIZED RULE: ID PLUS Expr, ID is %s \n", (yyvsp[-2].string));

		

		// Check if identifiers have been declared
		if (!found((yyvsp[-2].string), currentScope)) {
			printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-2].string), currentScope);
			semanticCheckPassed = 0;
		}
		
		// see if types are compatible, currently causing segfault cuz nodes
		// if (!compareTypes($1, $3, currentScope);) {
		// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		// 	semanticCheckPassed = 0;
		// }


		// this is some wizard temp register shit
		if (semanticCheckPassed) {
			//$$ = astCreateVar($1);
			(yyval.ast_node) = astCreateBinaryOp("-", astCreateVar((yyvsp[-2].string)), (yyvsp[0].ast_node));
			char* result = generateTempVar();  // Generate a temporary variable for the result
			emitBinaryOperation("-", result, (yyvsp[-2].string), nodeToString((yyvsp[0].ast_node)));
			emitMIPSBinaryOp("sub", result, (yyvsp[-2].string), nodeToString((yyvsp[0].ast_node)));
			//$$ = astCreateVar(result);
			
		}		
	}
#line 1790 "parser.tab.c"
    break;

  case 47: /* Expr: NUMBER MINUS Expr  */
#line 429 "parser.y"
                            {
		printf("\n RECOGNIZED RULE: NUMBER PLUS Expr, %s\n", (yyvsp[-2].string));
		
		// see if types are compatible, currently causing segfault cuz nodes
		// if (!compareTypes($1, $3, currentScope);) {
		// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		// 	semanticCheckPassed = 0;
		// }

		if (semanticCheckPassed) {
			char* result = generateTempVar();  // Generate a temporary variable for the result
			char* str = (char*)malloc(15);
			char* str1 = (char*)malloc(15);
			sprintf(str, "%s", (yyvsp[-2].string));
			sprintf(str1, "%s", nodeToString((yyvsp[0].ast_node)));
			emitBinaryOperation("-", result, str, str1);
			emitMIPSBinaryOp("sub", result, str, str1);
			// Update the current expression result
			//$$ = astCreateVar(result);
			(yyval.ast_node) = astCreateBinaryOp("-", astCreateInt((yyvsp[-2].string)), (yyvsp[0].ast_node));
		}
	}
#line 1817 "parser.tab.c"
    break;

  case 48: /* Expr: ID TIMES Expr  */
#line 451 "parser.y"
                        {
		printf("\n RECOGNIZED RULE: ID PLUS Expr, ID is %s \n", (yyvsp[-2].string));

		

		// Check if identifiers have been declared
		if (!found((yyvsp[-2].string), currentScope)) {
			printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-2].string), currentScope);
			semanticCheckPassed = 0;
		}
		
		// see if types are compatible, currently causing segfault cuz nodes
		// if (!compareTypes($1, $3, currentScope);) {
		// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		// 	semanticCheckPassed = 0;
		// }


		// this is some wizard temp register shit
		if (semanticCheckPassed) {
			//$$ = astCreateVar($1);
			(yyval.ast_node) = astCreateBinaryOp("*", astCreateVar((yyvsp[-2].string)), (yyvsp[0].ast_node));
			char* result = generateTempVar();  // Generate a temporary variable for the result
			emitBinaryOperation("*", result, (yyvsp[-2].string), nodeToString((yyvsp[0].ast_node)));
			emitMIPSBinaryOp("mult", result, (yyvsp[-2].string), nodeToString((yyvsp[0].ast_node)));
			//$$ = astCreateVar(result);
			
		}		
	}
#line 1851 "parser.tab.c"
    break;

  case 49: /* Expr: NUMBER TIMES Expr  */
#line 480 "parser.y"
                            {
		printf("\n RECOGNIZED RULE: NUMBER PLUS Expr, %s\n", (yyvsp[-2].string));
		
		// see if types are compatible, currently causing segfault cuz nodes
		// if (!compareTypes($1, $3, currentScope);) {
		// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		// 	semanticCheckPassed = 0;
		// }

		if (semanticCheckPassed) {
			char* result = generateTempVar();  // Generate a temporary variable for the result
			char* str = (char*)malloc(15);
			char* str1 = (char*)malloc(15);
			sprintf(str, "%s", (yyvsp[-2].string));
			sprintf(str1, "%s", nodeToString((yyvsp[0].ast_node)));
			emitBinaryOperation("*", result, str, str1);
			emitMIPSBinaryOp("mult", result, str, str1);
			// Update the current expression result
			//$$ = astCreateVar(result);
			(yyval.ast_node) = astCreateBinaryOp("*", astCreateInt((yyvsp[-2].string)), (yyvsp[0].ast_node));
		}
	}
#line 1878 "parser.tab.c"
    break;

  case 50: /* Expr: ID DIVIDE Expr  */
#line 502 "parser.y"
                         {
		printf("\n RECOGNIZED RULE: ID PLUS Expr, ID is %s \n", (yyvsp[-2].string));

		

		// Check if identifiers have been declared
		if (!found((yyvsp[-2].string), currentScope)) {
			printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-2].string), currentScope);
			semanticCheckPassed = 0;
		}
		
		// see if types are compatible, currently causing segfault cuz nodes
		// if (!compareTypes($1, $3, currentScope);) {
		// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		// 	semanticCheckPassed = 0;
		// }


		// this is some wizard temp register shit
		if (semanticCheckPassed) {
			//$$ = astCreateVar($1);
			(yyval.ast_node) = astCreateBinaryOp("/", astCreateVar((yyvsp[-2].string)), (yyvsp[0].ast_node));
			char* result = generateTempVar();  // Generate a temporary variable for the result
			emitBinaryOperation("/", result, (yyvsp[-2].string), nodeToString((yyvsp[0].ast_node)));
			emitMIPSBinaryOp("div", result, (yyvsp[-2].string), nodeToString((yyvsp[0].ast_node)));
			//$$ = astCreateVar(result);
			
		}		
	}
#line 1912 "parser.tab.c"
    break;

  case 51: /* Expr: NUMBER DIVIDE Expr  */
#line 531 "parser.y"
                             {
		printf("\n RECOGNIZED RULE: NUMBER PLUS Expr, %s\n", (yyvsp[-2].string));
		
		// see if types are compatible, currently causing segfault cuz nodes
		// if (!compareTypes($1, $3, currentScope);) {
		// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		// 	semanticCheckPassed = 0;
		// }

		if (semanticCheckPassed) {
			char* result = generateTempVar();  // Generate a temporary variable for the result
			char* str = (char*)malloc(15);
			char* str1 = (char*)malloc(15);
			sprintf(str, "%s", (yyvsp[-2].string));
			sprintf(str1, "%s", nodeToString((yyvsp[0].ast_node)));
			emitBinaryOperation("/", result, str, str1);
			emitMIPSBinaryOp("div", result, str, str1);
			// Update the current expression result
			//$$ = astCreateVar(result);
			(yyval.ast_node) = astCreateBinaryOp("/", astCreateInt((yyvsp[-2].string)), (yyvsp[0].ast_node));
		}
	}
#line 1939 "parser.tab.c"
    break;

  case 52: /* BoolExpr: Expr LT Expr  */
#line 557 "parser.y"
                     {
		printf("\n RECOGNIZED RULE: BoolExpr: Expr LT Expr\n");
		(yyval.ast_node) = astCreateBinaryOp((yyvsp[-1].string), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
	}
#line 1948 "parser.tab.c"
    break;

  case 53: /* BoolExpr: Expr GT Expr  */
#line 561 "parser.y"
                      {
		printf("\n RECOGNIZED RULE: BoolExpr: Expr GT Expr\n");
		(yyval.ast_node) = astCreateBinaryOp((yyvsp[-1].string), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
	}
#line 1957 "parser.tab.c"
    break;

  case 54: /* BoolExpr: Expr LTE Expr  */
#line 565 "parser.y"
                       {
		printf("\n RECOGNIZED RULE: BoolExpr: Expr LTE Expr\n");
		(yyval.ast_node) = astCreateBinaryOp((yyvsp[-1].string), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
	}
#line 1966 "parser.tab.c"
    break;

  case 55: /* BoolExpr: Expr GTE Expr  */
#line 569 "parser.y"
                       {
		printf("\n RECOGNIZED RULE: BoolExpr: Expr GTE Expr\n");
		(yyval.ast_node) = astCreateBinaryOp((yyvsp[-1].string), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
	}
#line 1975 "parser.tab.c"
    break;

  case 56: /* BoolExpr: Expr NE Expr  */
#line 573 "parser.y"
                      {
		printf("\n RECOGNIZED RULE: BoolExpr: Expr NE Expr\n");
		(yyval.ast_node) = astCreateBinaryOp((yyvsp[-1].string), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
	}
#line 1984 "parser.tab.c"
    break;

  case 57: /* BoolExpr: Expr EQ Expr  */
#line 577 "parser.y"
                      {
		printf("\n RECOGNIZED RULE: BoolExpr: Expr EQ Expr\n");
		(yyval.ast_node) = astCreateBinaryOp((yyvsp[-1].string), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
	}
#line 1993 "parser.tab.c"
    break;

  case 58: /* BoolExpr: BoolExpr AND BoolExpr  */
#line 581 "parser.y"
                               {
		printf("\n RECOGNIZED RULE: BoolExpr: BoolExpr AND BoolExpr\n");
		(yyval.ast_node) = astCreateBinaryOp((yyvsp[-1].string), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
	}
#line 2002 "parser.tab.c"
    break;

  case 59: /* BoolExpr: BoolExpr OR BoolExpr  */
#line 585 "parser.y"
                              {
		printf("\n RECOGNIZED RULE: BoolExpr: BoolExpr OR BoolExpr\n");
		(yyval.ast_node) = astCreateBinaryOp((yyvsp[-1].string), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
	}
#line 2011 "parser.tab.c"
    break;


#line 2015 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 612 "parser.y"

int main(int argc, char**argv)
{

	// #ifdef YYDEBUG
	// 	yydebug = 1;
	// #endif

	printf("\n\n##### COMPILER STARTED #####\n\n");
	
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	}

	// Initialize IR and MIPS files
	initIRcodeFile();
	initAssemblyFile();

	// Start parser
	yyparse();


	// initAssemblyFile();
	// Add the closing part required for any MIPS file
	emitEndOfAssemblyCode();

}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
