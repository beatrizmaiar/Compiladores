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

  
#define YYPARSER

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#include "symbolTable.h"

#define YYSTYPE TreeNode *
static TreeNode * savedTree; 
static int yylex();

extern int lineno;
extern int tab;

char *scope = "";
char * idtype = "";
char * datatype = "";
char currentScope[100] = "Global";  
static char *savedname = "";
int flag = 0;
int params=0;

SymbolTable *st;

int yyerror(char *message);

#line 101 "parser.tab.c"

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
  YYSYMBOL_ELSE = 3,                       /* ELSE  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_NUM = 10,                       /* NUM  */
  YYSYMBOL_ADD = 11,                       /* ADD  */
  YYSYMBOL_SUB = 12,                       /* SUB  */
  YYSYMBOL_MUL = 13,                       /* MUL  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
  YYSYMBOL_MEQ = 15,                       /* MEQ  */
  YYSYMBOL_MEIQ = 16,                      /* MEIQ  */
  YYSYMBOL_MAQ = 17,                       /* MAQ  */
  YYSYMBOL_MAIQ = 18,                      /* MAIQ  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_NEQ = 20,                       /* NEQ  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_VIRG = 22,                      /* VIRG  */
  YYSYMBOL_LPAR = 23,                      /* LPAR  */
  YYSYMBOL_RPAR = 24,                      /* RPAR  */
  YYSYMBOL_LCHA = 25,                      /* LCHA  */
  YYSYMBOL_RCHA = 26,                      /* RCHA  */
  YYSYMBOL_LCO = 27,                       /* LCO  */
  YYSYMBOL_RCO = 28,                       /* RCO  */
  YYSYMBOL_TB = 29,                        /* TB  */
  YYSYMBOL_LINE = 30,                      /* LINE  */
  YYSYMBOL_SPACE = 31,                     /* SPACE  */
  YYSYMBOL_NL = 32,                        /* NL  */
  YYSYMBOL_END = 33,                       /* END  */
  YYSYMBOL_FIM = 34,                       /* FIM  */
  YYSYMBOL_ERR = 35,                       /* ERR  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_decla_seq = 38,                 /* decla_seq  */
  YYSYMBOL_decla = 39,                     /* decla  */
  YYSYMBOL_var_decla = 40,                 /* var_decla  */
  YYSYMBOL_tam = 41,                       /* tam  */
  YYSYMBOL_tipo = 42,                      /* tipo  */
  YYSYMBOL_43_fun_id = 43,                 /* fun-id  */
  YYSYMBOL_fun_decla = 44,                 /* fun_decla  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_params = 46,                    /* params  */
  YYSYMBOL_param_seq = 47,                 /* param_seq  */
  YYSYMBOL_param = 48,                     /* param  */
  YYSYMBOL_comp_decla = 49,                /* comp_decla  */
  YYSYMBOL_local_decla = 50,               /* local_decla  */
  YYSYMBOL_stmt_seq = 51,                  /* stmt_seq  */
  YYSYMBOL_stmt = 52,                      /* stmt  */
  YYSYMBOL_exp_decla = 53,                 /* exp_decla  */
  YYSYMBOL_sele_decla = 54,                /* sele_decla  */
  YYSYMBOL_itera_decla = 55,               /* itera_decla  */
  YYSYMBOL_return_decla = 56,              /* return_decla  */
  YYSYMBOL_exp = 57,                       /* exp  */
  YYSYMBOL_var = 58,                       /* var  */
  YYSYMBOL_simple_exp = 59,                /* simple_exp  */
  YYSYMBOL_rel = 60,                       /* rel  */
  YYSYMBOL_sum_exp = 61,                   /* sum_exp  */
  YYSYMBOL_sum = 62,                       /* sum  */
  YYSYMBOL_ope = 63,                       /* ope  */
  YYSYMBOL_mul = 64,                       /* mul  */
  YYSYMBOL_fac = 65,                       /* fac  */
  YYSYMBOL_acti = 66,                      /* acti  */
  YYSYMBOL_arg_seq = 67                    /* arg_seq  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   140

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  112

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    43,    43,    46,    55,    58,    58,    61,    81,    96,
     100,   107,   112,   119,   125,   125,   151,   158,   161,   170,
     173,   186,   203,   215,   216,   217,   220,   230,   233,   243,
     246,   247,   248,   249,   250,   252,   269,   278,   290,   301,
     305,   308,   335,   340,   352,   360,   366,   369,   375,   380,
     385,   390,   395,   402,   408,   411,   415,   422,   428,   431,
     435,   442,   443,   444,   445,   450,   466,   486,   496
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
  "\"end of file\"", "error", "\"invalid token\"", "ELSE", "IF", "INT",
  "RETURN", "VOID", "WHILE", "ID", "NUM", "ADD", "SUB", "MUL", "DIV",
  "MEQ", "MEIQ", "MAQ", "MAIQ", "EQ", "NEQ", "ASSIGN", "VIRG", "LPAR",
  "RPAR", "LCHA", "RCHA", "LCO", "RCO", "TB", "LINE", "SPACE", "NL", "END",
  "FIM", "ERR", "$accept", "program", "decla_seq", "decla", "var_decla",
  "tam", "tipo", "fun-id", "fun_decla", "$@1", "params", "param_seq",
  "param", "comp_decla", "local_decla", "stmt_seq", "stmt", "exp_decla",
  "sele_decla", "itera_decla", "return_decla", "exp", "var", "simple_exp",
  "rel", "sum_exp", "sum", "ope", "mul", "fac", "acti", "arg_seq", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-17)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     116,   -78,   -78,   -78,    23,   115,   -78,   -78,    17,   -78,
     -78,   -78,     8,    10,    30,   -78,   -78,   -78,    42,    -2,
      18,    43,    72,    59,    65,   -78,   -78,    66,    75,    91,
      80,    11,   -78,    65,   -78,    74,    -1,    84,    26,   -78,
      81,   -78,   -78,   117,    39,   -78,    38,    46,   -78,   -78,
     -78,   -78,   -78,    92,   103,   -78,    94,   105,   -78,   -78,
      81,   -78,    95,    81,   106,     8,    79,    81,   -78,   -78,
      69,   -78,   -78,   -78,    81,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,    81,    81,   -78,   -78,    81,   107,   -78,
     108,   -78,   -78,   -78,    52,    99,   -78,   -78,   -78,    48,
     105,   -78,    76,    76,    81,   -78,   -78,   126,   -78,   -78,
      76,   -78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    11,    12,     0,     0,     4,     5,     0,     6,
       1,     3,    13,     0,     0,     7,    14,    10,     0,     0,
       0,    12,     0,     0,    17,    19,     8,    20,     0,     0,
       0,     0,    15,    18,    21,     0,     0,     0,    43,    64,
       0,    23,    27,     0,     0,    31,     0,     0,    29,    30,
      32,    33,    34,     0,    62,    42,    46,    54,    58,    63,
       0,    40,     0,     0,     0,     0,     0,     0,    24,    26,
       0,    25,    28,    35,     0,    55,    56,    48,    47,    49,
      50,    51,    52,     0,     0,    59,    60,     0,     0,    39,
       0,    61,    66,    68,     0,     0,    22,    41,    62,    45,
      53,    57,     0,     0,     0,    65,    44,    36,    38,    67,
       0,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   -78,   128,   -17,   -78,   -18,   127,   -78,   -78,
     -78,   109,   -78,   111,   -78,    88,   -45,   -78,   -78,   -78,
     -78,   -36,   -77,   -78,   -78,    53,   -78,    56,   -78,    50,
     -78,   -78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    18,     8,    44,     9,    19,
      23,    24,    25,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    83,    56,    84,    57,    87,    58,
      59,    94
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      62,    22,    72,     2,    64,    21,    98,    98,    38,    39,
      98,    22,     1,    43,    42,    35,     2,    36,     3,    37,
      38,    39,    40,    10,    88,    72,    12,    90,    43,    69,
      93,    95,    61,    16,    40,    14,    31,    41,    97,     1,
      17,    15,    35,     2,    36,     3,    37,    38,    39,   -13,
      35,    26,    36,   -13,    37,    38,    39,   107,   108,    75,
      76,    40,    66,    31,    68,   111,    67,   -16,   109,    40,
      20,    31,    71,    35,   104,    36,   105,    37,    38,    39,
      35,    27,    36,    28,    37,    38,    39,    29,    38,    39,
      38,    39,    40,    30,    31,    96,     2,    60,     3,    40,
      31,    31,    40,    92,    40,    75,    76,    63,    34,    77,
      78,    79,    80,    81,    82,    -2,     1,     1,    85,    86,
       2,     2,     3,     3,    74,    73,    65,   106,    89,   110,
      91,   102,   103,    11,    70,    13,    99,   101,    33,    32,
     100
};

static const yytype_int8 yycheck[] =
{
      36,    19,    47,     5,    40,     7,    83,    84,     9,    10,
      87,    29,     1,    31,    31,     4,     5,     6,     7,     8,
       9,    10,    23,     0,    60,    70,     9,    63,    46,    46,
      66,    67,    33,    23,    23,    27,    25,    26,    74,     1,
      10,    33,     4,     5,     6,     7,     8,     9,    10,    23,
       4,    33,     6,    27,     8,     9,    10,   102,   103,    11,
      12,    23,    23,    25,    26,   110,    27,    24,   104,    23,
      28,    25,    26,     4,    22,     6,    24,     8,     9,    10,
       4,     9,     6,    24,     8,     9,    10,    22,     9,    10,
       9,    10,    23,    27,    25,    26,     5,    23,     7,    23,
      25,    25,    23,    24,    23,    11,    12,    23,    28,    15,
      16,    17,    18,    19,    20,     0,     1,     1,    13,    14,
       5,     5,     7,     7,    21,    33,     9,    28,    33,     3,
      24,    24,    24,     5,    46,     8,    83,    87,    29,    28,
      84
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,     7,    37,    38,    39,    40,    42,    44,
       0,    39,     9,    43,    27,    33,    23,    10,    41,    45,
      28,     7,    42,    46,    47,    48,    33,     9,    24,    22,
      27,    25,    49,    47,    28,     4,     6,     8,     9,    10,
      23,    26,    40,    42,    43,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    61,    63,    65,    66,
      23,    33,    57,    23,    57,     9,    23,    27,    26,    40,
      51,    26,    52,    33,    21,    11,    12,    15,    16,    17,
      18,    19,    20,    60,    62,    13,    14,    64,    57,    33,
      57,    24,    24,    57,    67,    57,    26,    57,    58,    61,
      63,    65,    24,    24,    22,    24,    28,    52,    52,    57,
       3,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    40,    40,    40,
      41,    42,    42,    43,    45,    44,    46,    46,    47,    47,
      48,    48,    49,    49,    49,    49,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    53,    54,    54,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    65,    65,    65,    65,    66,    66,    67,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     1,     1,     1,     0,     7,     1,     1,     3,     1,
       2,     4,     4,     2,     3,     3,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     5,     7,     5,     3,
       2,     3,     1,     1,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     4,     3,     3,     1
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
  YY_USE (yykind);
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
  case 2: /* program: decla_seq  */
#line 43 "parser.y"
                   { savedTree = yyvsp[0]; }
#line 1237 "parser.tab.c"
    break;

  case 3: /* decla_seq: decla_seq decla  */
#line 46 "parser.y"
                            {
            YYSTYPE t = yyvsp[-1];
              if (t != NULL){
                while (t->sibling != NULL)
                   t = t->sibling;
                t->sibling = yyvsp[0];
                yyval = yyvsp[-1];
              }
              else yyval = yyvsp[0];
          }
#line 1252 "parser.tab.c"
    break;

  case 4: /* decla_seq: decla  */
#line 55 "parser.y"
                   { yyval = yyvsp[0]; }
#line 1258 "parser.tab.c"
    break;

  case 5: /* decla: var_decla  */
#line 58 "parser.y"
                  { yyval = yyvsp[0];}
#line 1264 "parser.tab.c"
    break;

  case 6: /* decla: fun_decla  */
#line 58 "parser.y"
                                          { yyval = yyvsp[0];}
#line 1270 "parser.tab.c"
    break;

  case 7: /* var_decla: tipo ID END  */
#line 61 "parser.y"
                       {
            yyval = newExpNode(VarDeclK);
            yyval->attr.name = copyString(id);
            yyval->child[0] = yyvsp[-2];
            yyval->type = yyvsp[-2]->type;
            yyval->scope = currentScope;
            yyval->kind.exp = VarDeclK;
            yyval->lineno = lineno;

            char kindInfo[50];
            snprintf(kindInfo, sizeof(kindInfo), (strcmp(currentScope, "Global") == 0) ? "Global" : "Local (%s)", currentScope);
            if (yyvsp[-2]->type == VOIDTYPE) {
                printf("Erro Semântico: '%s' declarado como 'void' na linha %d (Escopo: %s)\n", 
                        id, lineno+1, currentScope);
                Error = 1;
            } else {
            insertSymbol(st, id, lineno, yyvsp[-2]->attr.name, currentScope, kindInfo, VAR_ID);
          }
        }
#line 1294 "parser.tab.c"
    break;

  case 8: /* var_decla: tipo ID LCO tam RCO END  */
#line 81 "parser.y"
                              {  
            yyval = newExpNode(VetorK);
            yyval->attr.name = copyString(id);
            yyval->child[0] = yyvsp[-5];
            yyval->child[1] = yyvsp[-2];
            yyval->type = yyvsp[-5]->type;
            yyval->scope= currentScope;
            yyval->kind.exp = VetorK;
            yyval->lineno = lineno;

            char vetorType[20];
            snprintf(vetorType, sizeof(vetorType), "%s[]", yyvsp[-5]->attr.name);  // 🔹 Agora todos os vetores são `INT[]`

            insertSymbol(st, id, lineno, vetorType, currentScope, "Vetor", VAR_ID);
          }
#line 1314 "parser.tab.c"
    break;

  case 9: /* var_decla: error  */
#line 96 "parser.y"
            {yyerror("");}
#line 1320 "parser.tab.c"
    break;

  case 10: /* tam: NUM  */
#line 100 "parser.y"
         {
            yyval = newExpNode(ConstK);
            yyval->type = INTTYPE;
            yyval->attr.name = NULL;
            yyval->attr.val = atoi(tokenString);
            }
#line 1331 "parser.tab.c"
    break;

  case 11: /* tipo: INT  */
#line 107 "parser.y"
          {
            yyval = newExpNode(TypeK);
            yyval->attr.name = "INT";
            yyval->type = INTTYPE;
            yyval->kind.exp = TypeK; }
#line 1341 "parser.tab.c"
    break;

  case 12: /* tipo: VOID  */
#line 112 "parser.y"
           {
            yyval = newExpNode(TypeK);
            yyval->attr.name = "VOID";
            yyval->type = VOIDTYPE;
            yyval->kind.exp = TypeK; }
#line 1351 "parser.tab.c"
    break;

  case 13: /* fun-id: ID  */
#line 119 "parser.y"
            {
            yyval = newExpNode(IdK);
            yyval->attr.name = copyString(id);
            yyval->kind.exp = IdK; }
#line 1360 "parser.tab.c"
    break;

  case 14: /* $@1: %empty  */
#line 125 "parser.y"
                            {
              //Atualiza o escopo ANTES de adicionar os parâmetros
              strncpy(currentScope, yyvsp[-1]->attr.name, sizeof(currentScope));
          }
#line 1369 "parser.tab.c"
    break;

  case 15: /* fun_decla: tipo fun-id LPAR $@1 params RPAR comp_decla  */
#line 128 "parser.y"
                                   {
              yyval = newExpNode(FunctionK);
              yyval->kind.exp = FunctionK;
              yyval->attr.name = yyvsp[-5]->attr.name;
              yyval->child[0] = yyvsp[-6];
              yyval->type = yyvsp[-6]->type;
              yyval->child[1] = yyvsp[-2]; // Parâmetros agora vêm depois da atualização do escopo
              yyval->child[2] = yyvsp[0]; // Corpo da função
              yyval->lineno = yyvsp[-5]->lineno;

              char funcType[20];
              if (yyvsp[-6]->type == VOIDTYPE) {
                  snprintf(funcType, sizeof(funcType), "void (função)");
              } else {
                  snprintf(funcType, sizeof(funcType), "%s (função)", yyvsp[-6]->attr.name);
              }

              insertSymbol(st, yyvsp[-5]->attr.name, yyvsp[-5]->lineno, funcType, "Global", "Função", FUN_ID);
              strcpy(currentScope, "Global");
          }
#line 1394 "parser.tab.c"
    break;

  case 16: /* params: VOID  */
#line 151 "parser.y"
             {
            yyval = newExpNode(TypeK);
            yyval->attr.name = "VOID";
            yyval->size = 0;
            yyval->child[0] = NULL;
            yyval->lineno = lineno;
          }
#line 1406 "parser.tab.c"
    break;

  case 17: /* params: param_seq  */
#line 158 "parser.y"
                    { yyval = yyvsp[0]; }
#line 1412 "parser.tab.c"
    break;

  case 18: /* param_seq: param_seq VIRG param_seq  */
#line 161 "parser.y"
                                    {
                YYSTYPE t = yyvsp[-2];
                if (t != NULL){
                  while (t->sibling != NULL)
                       t = t->sibling;
                  t->sibling = yyvsp[0];
                  yyval = yyvsp[-2];
                }
                else yyval = yyvsp[0];
              }
#line 1427 "parser.tab.c"
    break;

  case 19: /* param_seq: param  */
#line 170 "parser.y"
                        { yyval = yyvsp[0]; }
#line 1433 "parser.tab.c"
    break;

  case 20: /* param: tipo ID  */
#line 173 "parser.y"
               {
          yyval = newExpNode(VarParamK);
          yyval->attr.name = copyString(id);
          yyval->kind.exp = VarParamK;
          yyval->size = 0;
          yyval->lineno = lineno;
          yyval->type = yyvsp[-1]->type;
          yyval->child[0] = yyvsp[-1];

          char paramType[20];
          snprintf(paramType, sizeof(paramType), "%s[]", yyvsp[-1]->attr.name);

          insertSymbol(st, id, lineno, yyvsp[-1]->attr.name, currentScope, "Parâmetro", PARAM_ID);
        }
#line 1452 "parser.tab.c"
    break;

  case 21: /* param: tipo ID LCO RCO  */
#line 186 "parser.y"
                          {
         yyval = newExpNode(VetParamK);
          yyval->child[0] = yyvsp[-3];
          yyval->attr.name = copyString(id);
          yyval->kind.exp = VetParamK;
          yyval->size = 0;
          yyval->lineno = lineno;
          yyval->type = yyvsp[-3]->type;
          yyval->child[0] = yyvsp[-3];

          char paramType[20];
          snprintf(paramType, sizeof(paramType), "%s[]", yyvsp[-3]->attr.name);  // 🔹 Agora registra como vetor `int[]`

          insertSymbol(st, id, lineno, paramType, currentScope, "Parâmetro", PARAM_ID);
        }
#line 1472 "parser.tab.c"
    break;

  case 22: /* comp_decla: LCHA local_decla stmt_seq RCHA  */
#line 203 "parser.y"
                                           {
                YYSTYPE t = yyvsp[-2];
                  if (t != NULL){
                    while (t->sibling != NULL)
                       t = t->sibling;
                    t->sibling = yyvsp[-1];
                    yyval = yyvsp[-2];
                  }
                  else yyval = yyvsp[-1];
                  strcpy(currentScope, "Global");

              }
#line 1489 "parser.tab.c"
    break;

  case 23: /* comp_decla: LCHA RCHA  */
#line 215 "parser.y"
                {strcpy(currentScope, "Global");}
#line 1495 "parser.tab.c"
    break;

  case 24: /* comp_decla: LCHA local_decla RCHA  */
#line 216 "parser.y"
                            { yyval = yyvsp[-1];strcpy(currentScope, "Global");  }
#line 1501 "parser.tab.c"
    break;

  case 25: /* comp_decla: LCHA stmt_seq RCHA  */
#line 217 "parser.y"
                         { yyval = yyvsp[-1];strcpy(currentScope, "Global");  }
#line 1507 "parser.tab.c"
    break;

  case 26: /* local_decla: local_decla var_decla  */
#line 220 "parser.y"
                                   {
              YYSTYPE t = yyvsp[-1];
                if (t != NULL){
                  while (t->sibling != NULL)
                     t = t->sibling;
                  t->sibling = yyvsp[0];
                  yyval = yyvsp[-1];
                }
                else yyval = yyvsp[0];
            }
#line 1522 "parser.tab.c"
    break;

  case 27: /* local_decla: var_decla  */
#line 230 "parser.y"
                { yyval = yyvsp[0]; }
#line 1528 "parser.tab.c"
    break;

  case 28: /* stmt_seq: stmt_seq stmt  */
#line 233 "parser.y"
                        {
              YYSTYPE t = yyvsp[-1];
              if (t != NULL){
                while (t->sibling != NULL)
                t = t->sibling;
                t->sibling = yyvsp[0];
                yyval = yyvsp[-1];
              }
              else yyval = yyvsp[0];
            }
#line 1543 "parser.tab.c"
    break;

  case 29: /* stmt_seq: stmt  */
#line 243 "parser.y"
           { yyval = yyvsp[0]; }
#line 1549 "parser.tab.c"
    break;

  case 30: /* stmt: exp_decla  */
#line 246 "parser.y"
                { yyval = yyvsp[0]; }
#line 1555 "parser.tab.c"
    break;

  case 31: /* stmt: comp_decla  */
#line 247 "parser.y"
                 { yyval = yyvsp[0]; }
#line 1561 "parser.tab.c"
    break;

  case 32: /* stmt: sele_decla  */
#line 248 "parser.y"
                 { yyval = yyvsp[0]; }
#line 1567 "parser.tab.c"
    break;

  case 33: /* stmt: itera_decla  */
#line 249 "parser.y"
                  { yyval = yyvsp[0]; }
#line 1573 "parser.tab.c"
    break;

  case 34: /* stmt: return_decla  */
#line 250 "parser.y"
                   { yyval = yyvsp[0]; }
#line 1579 "parser.tab.c"
    break;

  case 35: /* exp_decla: exp END  */
#line 252 "parser.y"
                   {
    yyval = yyvsp[-1];
    // Verifica se a expressão é uma chamada de função
    if (yyvsp[-1]->kind.exp == CallK) {
        Symbol *funcSymbol = lookupSymbol(st, yyvsp[-1]->attr.name);
        
        // Verifica se a função tem tipo 'void' e se está sendo atribuída
        if (funcSymbol != NULL && funcSymbol->type == "void") {
            // Se for uma atribuição
            if (yyvsp[0]->kind.stmt == AssignK) {
                printf("Erro Semântico: A função '%s' retorna void e não pode ser atribuída (linha %d)\n", yyvsp[-1]->attr.name, lineno);
                Error = 1;
            }
        }
    }
}
#line 1600 "parser.tab.c"
    break;

  case 36: /* sele_decla: IF LPAR exp RPAR stmt  */
#line 269 "parser.y"
                                  {
  
            yyval = newStmtNode(IfK);
            yyval->attr.name = "IF";
            yyval->child[0] = yyvsp[-2];
            yyval->child[1] = yyvsp[0];
            yyval->lineno = lineno;
            yyval->kind.stmt = IfK;
          }
#line 1614 "parser.tab.c"
    break;

  case 37: /* sele_decla: IF LPAR exp RPAR stmt ELSE stmt  */
#line 278 "parser.y"
                                     {
            yyval = newStmtNode(IfK);
            yyval->attr.name = "IF";
            yyval->child[0] = yyvsp[-4];
            yyval->child[1] = yyvsp[-2];
            yyval->child[2] = yyvsp[0];
            yyval->scope= yyvsp[-4]->scope;
            yyval->lineno = lineno;
            yyval->kind.stmt = IfK;
          }
#line 1629 "parser.tab.c"
    break;

  case 38: /* itera_decla: WHILE LPAR exp RPAR stmt  */
#line 290 "parser.y"
                                      {
          yyval = newStmtNode(WhileK);
          yyval->attr.name = "WHILE";
          yyval->child[0] = yyvsp[-2];
          yyval->child[1] = yyvsp[0];
          yyval->scope = yyvsp[-2]->scope;
          yyval->lineno = lineno;
          yyval->kind.stmt = WhileK;
        }
#line 1643 "parser.tab.c"
    break;

  case 39: /* return_decla: RETURN exp END  */
#line 301 "parser.y"
                            {
                yyval = newStmtNode(ReturnINT);
                yyval->child[0] = yyvsp[-1];
                yyval->lineno = lineno;
            }
#line 1653 "parser.tab.c"
    break;

  case 40: /* return_decla: RETURN END  */
#line 305 "parser.y"
                          { yyval = newStmtNode(ReturnVOID); }
#line 1659 "parser.tab.c"
    break;

  case 41: /* exp: var ASSIGN exp  */
#line 308 "parser.y"
                    {
        yyval = newStmtNode(AssignK);
        yyval->kind.stmt = AssignK;
        yyval->attr.name = yyvsp[-2]->attr.name;
        yyval->scope = scope;
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
        yyval->lineno = lineno;

        // Busca informações da variável `a`
        Symbol *varSymbol = lookupSymbol(st, yyvsp[-2]->attr.name);

        // Só busca a função se `$3` for uma chamada de função (CallK)
        Symbol *funcSymbol = NULL;
        if (yyvsp[0]->kind.exp == CallK && yyvsp[0]->attr.name != NULL) {
            funcSymbol = lookupSymbol(st, yyvsp[0]->attr.name);
        }

        // Verifica se a variável é INT e a função retorna VOID
        if (varSymbol != NULL && funcSymbol != NULL) {
            if (strcmp(varSymbol->type, "INT") == 0 && strstr(funcSymbol->type, "void") != NULL) {
                printf("Erro Semântico: Atribuição inválida, variável '%s' é do tipo INT e a função '%s' retorna void (linha %d)\n",
                       yyvsp[-2]->attr.name, yyvsp[0]->attr.name, lineno);
                Error = 1;
            }
        }
      }
#line 1691 "parser.tab.c"
    break;

  case 42: /* exp: simple_exp  */
#line 335 "parser.y"
                { yyval = yyvsp[0]; }
#line 1697 "parser.tab.c"
    break;

  case 43: /* var: ID  */
#line 340 "parser.y"
        {
        yyval = newExpNode(IdK);
        yyval->attr.name = copyString(id);
        yyval->lineno = lineno;
        yyval->child[0] = NULL;

        Symbol *entry = lookupSymbol(st, id);
        if (entry == NULL) {
            printf("Erro Semântico: Identificador '%s' usado, mas não declarado (linha %d, escopo %s)\n",
                   id, lineno+1, currentScope);
            Error = 1;
        }
  }
#line 1715 "parser.tab.c"
    break;

  case 44: /* var: fun-id LCO exp RCO  */
#line 352 "parser.y"
                        {
        yyval = newExpNode(IdK);
        yyval->attr.name = yyvsp[-3]->attr.name;
        yyval->child[0] = yyvsp[-1];
        yyval->lineno = lineno;
        }
#line 1726 "parser.tab.c"
    break;

  case 45: /* simple_exp: sum_exp rel sum_exp  */
#line 360 "parser.y"
                                {
                  yyval = newStmtNode(AssignK);
                  yyval = yyvsp[-1];
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
                  yyval->scope = scope;
              }
#line 1738 "parser.tab.c"
    break;

  case 46: /* simple_exp: sum_exp  */
#line 366 "parser.y"
                         { yyval = yyvsp[0]; }
#line 1744 "parser.tab.c"
    break;

  case 47: /* rel: MEIQ  */
#line 370 "parser.y"
              {
                yyval = newExpNode(OpK);
                yyval->attr.op = MEIQ;
                yyval->lineno = lineno;
              }
#line 1754 "parser.tab.c"
    break;

  case 48: /* rel: MEQ  */
#line 375 "parser.y"
                  {
                yyval = newExpNode(OpK);
                yyval->attr.op = MEQ;
                yyval->lineno = lineno;
              }
#line 1764 "parser.tab.c"
    break;

  case 49: /* rel: MAQ  */
#line 380 "parser.y"
                  {
                yyval = newExpNode(OpK);
                yyval->attr.op = MAQ;
                yyval->lineno = lineno;
              }
#line 1774 "parser.tab.c"
    break;

  case 50: /* rel: MAIQ  */
#line 385 "parser.y"
                   {
                yyval = newExpNode(OpK);
                yyval->attr.op = MAIQ;
                yyval->lineno = lineno;
              }
#line 1784 "parser.tab.c"
    break;

  case 51: /* rel: EQ  */
#line 390 "parser.y"
                 {
                yyval = newExpNode(OpK);
                yyval->attr.op = EQ;
                yyval->lineno = lineno;
              }
#line 1794 "parser.tab.c"
    break;

  case 52: /* rel: NEQ  */
#line 395 "parser.y"
                  {
                yyval = newExpNode(OpK);
                yyval->attr.op = NEQ;
                yyval->lineno = lineno;
              }
#line 1804 "parser.tab.c"
    break;

  case 53: /* sum_exp: sum_exp sum ope  */
#line 402 "parser.y"
                         {
            yyval = yyvsp[-1];
            yyval->child[0] = yyvsp[-2];
            yyval->child[1] = yyvsp[0];
            yyval->scope = scope;
            yyval->lineno = lineno;
       }
#line 1816 "parser.tab.c"
    break;

  case 54: /* sum_exp: ope  */
#line 408 "parser.y"
              { yyval = yyvsp[0]; }
#line 1822 "parser.tab.c"
    break;

  case 55: /* sum: ADD  */
#line 411 "parser.y"
         {
         yyval = newExpNode(OpK);
         yyval->attr.op = ADD;
         yyval->lineno = lineno;
   }
#line 1832 "parser.tab.c"
    break;

  case 56: /* sum: SUB  */
#line 415 "parser.y"
          {
         yyval = newExpNode(OpK);
         yyval->attr.op = SUB;
         yyval->lineno = lineno;
       }
#line 1842 "parser.tab.c"
    break;

  case 57: /* ope: ope mul fac  */
#line 422 "parser.y"
                 {
              yyval = yyvsp[-1];
              yyval->scope = scope;
              yyval->child[0] = yyvsp[-2];
              yyval->child[1] = yyvsp[0];
              yyval->lineno = lineno;
    }
#line 1854 "parser.tab.c"
    break;

  case 58: /* ope: fac  */
#line 428 "parser.y"
           { yyval = yyvsp[0]; }
#line 1860 "parser.tab.c"
    break;

  case 59: /* mul: MUL  */
#line 431 "parser.y"
         {
         yyval = newExpNode(OpK);
         yyval->attr.op = MUL;
         yyval->lineno = lineno;
   }
#line 1870 "parser.tab.c"
    break;

  case 60: /* mul: DIV  */
#line 435 "parser.y"
          {
         yyval = newExpNode(OpK);
         yyval->attr.op = DIV;
         yyval->lineno = lineno;
       }
#line 1880 "parser.tab.c"
    break;

  case 61: /* fac: LPAR exp RPAR  */
#line 442 "parser.y"
                   { yyval = yyvsp[-1]; }
#line 1886 "parser.tab.c"
    break;

  case 62: /* fac: var  */
#line 443 "parser.y"
           { yyval = yyvsp[0]; }
#line 1892 "parser.tab.c"
    break;

  case 63: /* fac: acti  */
#line 444 "parser.y"
            { yyval = yyvsp[0]; params = 0; }
#line 1898 "parser.tab.c"
    break;

  case 64: /* fac: NUM  */
#line 445 "parser.y"
           { yyval = newExpNode(ConstK);
            yyval->type = INTTYPE;
            yyval->attr.val = atoi(tokenString); }
#line 1906 "parser.tab.c"
    break;

  case 65: /* acti: fun-id LPAR arg_seq RPAR  */
#line 450 "parser.y"
                               {
          yyval = newExpNode(CallK);
          yyval->kind.exp = CallK;
          yyval->attr.name = yyvsp[-3]->attr.name;
          yyval->child[0] = yyvsp[-1];
          yyval->params = params;
          yyval->lineno = lineno;

          if (strcmp(yyvsp[-3]->attr.name, "input") != 0 && strcmp(yyvsp[-3]->attr.name, "output") != 0) {
              Symbol *funcSymbol = lookupSymbol(st, yyvsp[-3]->attr.name);
              if (funcSymbol == NULL || funcSymbol->idType != FUN_ID) {
                  printf("Erro Semântico: Chamada de função '%s' não declarada (linha %d)\n", 
                         yyvsp[-3]->attr.name, lineno+1);
                  Error = 1;
              }
          }
       }
#line 1928 "parser.tab.c"
    break;

  case 66: /* acti: fun-id LPAR RPAR  */
#line 466 "parser.y"
                          {
           yyval = newExpNode(CallK);
           yyval->kind.exp = CallK;
           yyval->attr.name = yyvsp[-2]->attr.name;
           yyval->params = params;
           yyval->lineno = lineno;

           //Ignorar funções embutidas (input/output)
           if (strcmp(yyvsp[-2]->attr.name, "input") != 0 && strcmp(yyvsp[-2]->attr.name, "output") != 0) {
               Symbol *funcSymbol = lookupSymbol(st, yyvsp[-2]->attr.name);
               if (funcSymbol == NULL || funcSymbol->idType != FUN_ID) {
                   printf("Erro Semântico: Chamada de função '%s' não declarada (linha %d)\n", 
                          yyvsp[-2]->attr.name, lineno+1);
                   Error = 1;
               }
           }
         }
#line 1950 "parser.tab.c"
    break;

  case 67: /* arg_seq: arg_seq VIRG exp  */
#line 486 "parser.y"
                          {
              YYSTYPE t = yyvsp[-2];
              if (t != NULL){
                while (t->sibling != NULL)
                t = t->sibling;
                t->sibling = yyvsp[0];
                params ++;
                yyval = yyvsp[-2];
              }
              else yyval = yyvsp[0];
   }
#line 1966 "parser.tab.c"
    break;

  case 68: /* arg_seq: exp  */
#line 496 "parser.y"
          { 
           params ++;
           yyval = yyvsp[0]; }
#line 1974 "parser.tab.c"
    break;


#line 1978 "parser.tab.c"

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

#line 501 "parser.y"


int yyerror(char *message) {
    if (yychar == -2) return 0; 
    Error = TRUE;

    if (yychar == ERR) 
        printf("Erro léxico na linha %d. Lexema: ", lineno);
    else 
        printf("Erro sintático na linha %d. Token: ", lineno);

    switch (yychar) {
        case IF: printf("%s\n", tokenString); break;
        case RETURN: printf("%s\n", tokenString); break;
        case ELSE: printf("%s\n", tokenString); break;
        case INT: printf("%s\n", tokenString); break;
        case WHILE: printf("%s\n", tokenString); break;
        case VOID: printf("%s\n", tokenString); break;
        case EQ: printf("==\n"); break;
        case ASSIGN: printf("=\n"); break;
        case NEQ: printf("!=\n"); break;
        case MEQ: printf("<\n"); break;
        case MAQ: printf(">\n"); break;
        case MEIQ: printf("<=\n"); break;
        case MAIQ: printf(">=\n"); break;
        case LPAR: printf("(\n"); break;
        case RPAR: printf(")\n"); break;
        case LCO: printf("[\n"); break;
        case RCO: printf("]\n"); break;
        case LCHA: printf("{\n"); break;
        case RCHA: printf("}\n"); break;
        case END: printf(";\n"); break;
        case VIRG: printf(",\n"); break;
        case ADD: printf("+\n"); break;
        case SUB: printf("-\n"); break;
        case MUL: printf("*\n"); break;
        case DIV: printf("/\n"); break;
        case FIM: printf("EOF\n"); break;
        case NUM: printf("NUM, valor = %s\n", tokenString); break;
        case ID: printf("ID, lexema = %s\n", tokenString); break;
        case ERR: printf("%s\n", tokenString); break;
        default:
            printf("Token desconhecido: %d\n", yychar);
    }

    return 0;  
}


static int yylex(void){ 
  return getToken(); 
}

TreeNode * parse(void)
{ 
  st = createSymbolTable();  
  yyparse();

  printSymbolTable(st);

  checkUndeclared(st);
  checkTypeErrors(st);
  checkMainDeclared(st);

  return savedTree;
}
