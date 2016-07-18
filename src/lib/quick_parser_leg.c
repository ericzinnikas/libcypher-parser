/* A recursive-descent parser generated by peg 0.1.15 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYRULECOUNT 19
#ifndef YY_MALLOC
#define YY_MALLOC(C, N)		malloc(N)
#endif
#ifndef YY_REALLOC
#define YY_REALLOC(C, P, N)	realloc(P, N)
#endif
#ifndef YY_FREE
#define YY_FREE(C, P)		free(P)
#endif
#ifndef YY_LOCAL
#define YY_LOCAL(T)	static T
#endif
#ifndef YY_ACTION
#define YY_ACTION(T)	static T
#endif
#ifndef YY_RULE
#define YY_RULE(T)	static T
#endif
#ifndef YY_PARSE
#define YY_PARSE(T)	T
#endif
#ifndef YYPARSE
#define YYPARSE		yyparse
#endif
#ifndef YYPARSEFROM
#define YYPARSEFROM	yyparsefrom
#endif
#ifndef YYRELEASE
#define YYRELEASE	yyrelease
#endif
#ifndef YY_BEGIN
#define YY_BEGIN	( yy->__begin= yy->__pos, 1)
#endif
#ifndef YY_END
#define YY_END		( yy->__end= yy->__pos, 1)
#endif
#ifdef YY_DEBUG
# define yyprintf(args)	fprintf args
#else
# define yyprintf(args)
#endif
#ifndef YYSTYPE
#define YYSTYPE	int
#endif
#ifndef YY_STACK_SIZE
#define YY_STACK_SIZE 128
#endif

#ifndef YY_BUFFER_SIZE
#define YY_BUFFER_SIZE 1024
#endif

#ifndef YY_PART

typedef struct _yycontext yycontext;
typedef void (*yyaction)(yycontext *yy, char *yytext, int yyleng);
typedef struct _yythunk { int begin, end;  yyaction  action;  struct _yythunk *next; } yythunk;

struct _yycontext {
  char     *__buf;
  int       __buflen;
  int       __pos;
  int       __limit;
  char     *__text;
  int       __textlen;
  int       __begin;
  int       __end;
  int       __textmax;
  yythunk  *__thunks;
  int       __thunkslen;
  int       __thunkpos;
  YYSTYPE   __;
  YYSTYPE  *__val;
  YYSTYPE  *__vals;
  int       __valslen;
#ifdef YY_CTX_MEMBERS
  YY_CTX_MEMBERS
#endif
};

#ifdef YY_CTX_LOCAL
#define YY_CTX_PARAM_	yycontext *yyctx,
#define YY_CTX_PARAM	yycontext *yyctx
#define YY_CTX_ARG_	yyctx,
#define YY_CTX_ARG	yyctx
#ifndef YY_INPUT
#define YY_INPUT(yy, buf, result, max_size)		\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#else
#define YY_CTX_PARAM_
#define YY_CTX_PARAM
#define YY_CTX_ARG_
#define YY_CTX_ARG
yycontext _yyctx= { 0, 0 };
yycontext *yyctx= &_yyctx;
#ifndef YY_INPUT
#define YY_INPUT(buf, result, max_size)			\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#endif

YY_LOCAL(int) yyrefill(yycontext *yy)
{
  int yyn;
  while (yy->__buflen - yy->__pos < 512)
    {
      yy->__buflen *= 2;
      yy->__buf= (char *)YY_REALLOC(yy, yy->__buf, yy->__buflen);
    }
#ifdef YY_CTX_LOCAL
  YY_INPUT(yy, (yy->__buf + yy->__pos), yyn, (yy->__buflen - yy->__pos));
#else
  YY_INPUT((yy->__buf + yy->__pos), yyn, (yy->__buflen - yy->__pos));
#endif
  if (!yyn) return 0;
  yy->__limit += yyn;
  return 1;
}

YY_LOCAL(int) yymatchDot(yycontext *yy)
{
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  ++yy->__pos;
  return 1;
}

YY_LOCAL(int) yymatchChar(yycontext *yy, int c)
{
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  if ((unsigned char)yy->__buf[yy->__pos] == c)
    {
      ++yy->__pos;
      yyprintf((stderr, "  ok   yymatchChar(yy, %c) @ %s\n", c, yy->__buf+yy->__pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchChar(yy, %c) @ %s\n", c, yy->__buf+yy->__pos));
  return 0;
}

YY_LOCAL(int) yymatchString(yycontext *yy, const char *s)
{
  int yysav= yy->__pos;
  while (*s)
    {
      if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
      if (yy->__buf[yy->__pos] != *s)
        {
          yy->__pos= yysav;
          return 0;
        }
      ++s;
      ++yy->__pos;
    }
  return 1;
}

YY_LOCAL(int) yymatchClass(yycontext *yy, unsigned char *bits)
{
  int c;
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  c= (unsigned char)yy->__buf[yy->__pos];
  if (bits[c >> 3] & (1 << (c & 7)))
    {
      ++yy->__pos;
      yyprintf((stderr, "  ok   yymatchClass @ %s\n", yy->__buf+yy->__pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchClass @ %s\n", yy->__buf+yy->__pos));
  return 0;
}

YY_LOCAL(void) yyDo(yycontext *yy, yyaction action, int begin, int end)
{
  while (yy->__thunkpos >= yy->__thunkslen)
    {
      yy->__thunkslen *= 2;
      yy->__thunks= (yythunk *)YY_REALLOC(yy, yy->__thunks, sizeof(yythunk) * yy->__thunkslen);
    }
  yy->__thunks[yy->__thunkpos].begin=  begin;
  yy->__thunks[yy->__thunkpos].end=    end;
  yy->__thunks[yy->__thunkpos].action= action;
  ++yy->__thunkpos;
}

YY_LOCAL(int) yyText(yycontext *yy, int begin, int end)
{
  int yyleng= end - begin;
  if (yyleng <= 0)
    yyleng= 0;
  else
    {
      while (yy->__textlen < (yyleng + 1))
	{
	  yy->__textlen *= 2;
	  yy->__text= (char *)YY_REALLOC(yy, yy->__text, yy->__textlen);
	}
      memcpy(yy->__text, yy->__buf + begin, yyleng);
    }
  yy->__text[yyleng]= '\0';
  return yyleng;
}

YY_LOCAL(void) yyDone(yycontext *yy)
{
  int pos;
  for (pos= 0;  pos < yy->__thunkpos;  ++pos)
    {
      yythunk *thunk= &yy->__thunks[pos];
      int yyleng= thunk->end ? yyText(yy, thunk->begin, thunk->end) : thunk->begin;
      yyprintf((stderr, "DO [%d] %p %s\n", pos, thunk->action, yy->__text));
      thunk->action(yy, yy->__text, yyleng);
    }
  yy->__thunkpos= 0;
}

YY_LOCAL(void) yyCommit(yycontext *yy)
{
  if ((yy->__limit -= yy->__pos))
    {
      memmove(yy->__buf, yy->__buf + yy->__pos, yy->__limit);
    }
  yy->__begin -= yy->__pos;
  yy->__end -= yy->__pos;
  yy->__pos= yy->__thunkpos= 0;
}

YY_LOCAL(int) yyAccept(yycontext *yy, int tp0)
{
  if (tp0)
    {
      fprintf(stderr, "accept denied at %d\n", tp0);
      return 0;
    }
  else
    {
      yyDone(yy);
      yyCommit(yy);
    }
  return 1;
}

YY_LOCAL(void) yyPush(yycontext *yy, char *text, int count)
{
  yy->__val += count;
  while (yy->__valslen <= yy->__val - yy->__vals)
    {
      long offset= yy->__val - yy->__vals;
      yy->__valslen *= 2;
      yy->__vals= (YYSTYPE *)YY_REALLOC(yy, yy->__vals, sizeof(YYSTYPE) * yy->__valslen);
      yy->__val= yy->__vals + offset;
    }
}
YY_LOCAL(void) yyPop(yycontext *yy, char *text, int count)   { yy->__val -= count; }
YY_LOCAL(void) yySet(yycontext *yy, char *text, int count)   { yy->__val[count]= yy->__; }

#endif /* YY_PART */

#define	YYACCEPT	yyAccept(yy, yythunkpos0)

YY_RULE(int) yy__line_start_(yycontext *yy); /* 19 */
YY_RULE(int) yy_WS(yycontext *yy); /* 18 */
YY_RULE(int) yy_double_quoted(yycontext *yy); /* 17 */
YY_RULE(int) yy_single_quoted(yycontext *yy); /* 16 */
YY_RULE(int) yy_ESC(yycontext *yy); /* 15 */
YY_RULE(int) yy_comment(yycontext *yy); /* 14 */
YY_RULE(int) yy_statement_body(yycontext *yy); /* 13 */
YY_RULE(int) yy_EOL(yycontext *yy); /* 12 */
YY_RULE(int) yy_line_comment(yycontext *yy); /* 11 */
YY_RULE(int) yy_block_comment(yycontext *yy); /* 10 */
YY_RULE(int) yy_HWS(yycontext *yy); /* 9 */
YY_RULE(int) yy_quoted(yycontext *yy); /* 8 */
YY_RULE(int) yy_EOF(yycontext *yy); /* 7 */
YY_RULE(int) yy_line_end(yycontext *yy); /* 6 */
YY_RULE(int) yy_command_body(yycontext *yy); /* 5 */
YY_RULE(int) yy__(yycontext *yy); /* 4 */
YY_RULE(int) yy_statement(yycontext *yy); /* 3 */
YY_RULE(int) yy_command(yycontext *yy); /* 2 */
YY_RULE(int) yy_directive(yycontext *yy); /* 1 */

YY_ACTION(void) yy_1_EOF(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_EOF\n"));
  {
   yy->eof = true; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_statement(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_statement\n"));
  {
   segment(yy); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_command(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_command\n"));
  {
   segment(yy); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}

YY_RULE(int) yy__line_start_(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "_line_start_"));  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!( (line_start(yy), 1) )) goto l1;
#undef yytext
#undef yyleng
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "_line_start_", yy->__buf+yy->__pos));
  return 1;
  l1:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "_line_start_", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_WS(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "WS"));
  {  int yypos3= yy->__pos, yythunkpos3= yy->__thunkpos;  if (!yy_HWS(yy)) goto l4;  goto l3;
  l4:;	  yy->__pos= yypos3; yy->__thunkpos= yythunkpos3;  if (!yy_EOL(yy)) goto l2;
  }
  l3:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "WS", yy->__buf+yy->__pos));
  return 1;
  l2:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "WS", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_double_quoted(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "double_quoted"));  if (!yymatchChar(yy, '"')) goto l5;
  l6:;	
  {  int yypos7= yy->__pos, yythunkpos7= yy->__thunkpos;
  {  int yypos8= yy->__pos, yythunkpos8= yy->__thunkpos;  if (!yy_ESC(yy)) goto l9;  goto l8;
  l9:;	  yy->__pos= yypos8; yy->__thunkpos= yythunkpos8;  if (!yy_EOL(yy)) goto l10;  goto l8;
  l10:;	  yy->__pos= yypos8; yy->__thunkpos= yythunkpos8;
  {  int yypos11= yy->__pos, yythunkpos11= yy->__thunkpos;  if (!yymatchChar(yy, '"')) goto l11;  goto l7;
  l11:;	  yy->__pos= yypos11; yy->__thunkpos= yythunkpos11;
  }  if (!yymatchDot(yy)) goto l7;
  }
  l8:;	  goto l6;
  l7:;	  yy->__pos= yypos7; yy->__thunkpos= yythunkpos7;
  }  if (!yymatchChar(yy, '"')) goto l5;
  yyprintf((stderr, "  ok   %s @ %s\n", "double_quoted", yy->__buf+yy->__pos));
  return 1;
  l5:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "double_quoted", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_single_quoted(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "single_quoted"));  if (!yymatchChar(yy, '\'')) goto l12;
  l13:;	
  {  int yypos14= yy->__pos, yythunkpos14= yy->__thunkpos;
  {  int yypos15= yy->__pos, yythunkpos15= yy->__thunkpos;  if (!yy_ESC(yy)) goto l16;  goto l15;
  l16:;	  yy->__pos= yypos15; yy->__thunkpos= yythunkpos15;  if (!yy_EOL(yy)) goto l17;  goto l15;
  l17:;	  yy->__pos= yypos15; yy->__thunkpos= yythunkpos15;
  {  int yypos18= yy->__pos, yythunkpos18= yy->__thunkpos;  if (!yymatchChar(yy, '\'')) goto l18;  goto l14;
  l18:;	  yy->__pos= yypos18; yy->__thunkpos= yythunkpos18;
  }  if (!yymatchDot(yy)) goto l14;
  }
  l15:;	  goto l13;
  l14:;	  yy->__pos= yypos14; yy->__thunkpos= yythunkpos14;
  }  if (!yymatchChar(yy, '\'')) goto l12;
  yyprintf((stderr, "  ok   %s @ %s\n", "single_quoted", yy->__buf+yy->__pos));
  return 1;
  l12:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "single_quoted", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_ESC(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "ESC"));  if (!yymatchChar(yy, '\\')) goto l19;  if (!yymatchDot(yy)) goto l19;
  yyprintf((stderr, "  ok   %s @ %s\n", "ESC", yy->__buf+yy->__pos));
  return 1;
  l19:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "ESC", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_comment(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "comment"));
  {  int yypos21= yy->__pos, yythunkpos21= yy->__thunkpos;  if (!yy_line_comment(yy)) goto l22;  goto l21;
  l22:;	  yy->__pos= yypos21; yy->__thunkpos= yythunkpos21;  if (!yy_block_comment(yy)) goto l20;
  }
  l21:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "comment", yy->__buf+yy->__pos));
  return 1;
  l20:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "comment", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_statement_body(yycontext *yy)
{
  yyprintf((stderr, "%s\n", "statement_body"));
  l24:;	
  {  int yypos25= yy->__pos, yythunkpos25= yy->__thunkpos;
  {  int yypos26= yy->__pos, yythunkpos26= yy->__thunkpos;  if (!yy_comment(yy)) goto l27;  goto l26;
  l27:;	  yy->__pos= yypos26; yy->__thunkpos= yythunkpos26;  if (!yy_quoted(yy)) goto l28;  goto l26;
  l28:;	  yy->__pos= yypos26; yy->__thunkpos= yythunkpos26;  if (!yy_ESC(yy)) goto l29;  goto l26;
  l29:;	  yy->__pos= yypos26; yy->__thunkpos= yythunkpos26;
  {  int yypos30= yy->__pos, yythunkpos30= yy->__thunkpos;  if (!yy__(yy)) goto l30;  if (!yymatchChar(yy, ';')) goto l30;  goto l25;
  l30:;	  yy->__pos= yypos30; yy->__thunkpos= yythunkpos30;
  }  if (!yymatchDot(yy)) goto l25;
  }
  l26:;	  goto l24;
  l25:;	  yy->__pos= yypos25; yy->__thunkpos= yythunkpos25;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "statement_body", yy->__buf+yy->__pos));
  return 1;
}
YY_RULE(int) yy_EOL(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "EOL"));
  {  int yypos32= yy->__pos, yythunkpos32= yy->__thunkpos;  if (!yymatchChar(yy, '\n')) goto l33;  goto l32;
  l33:;	  yy->__pos= yypos32; yy->__thunkpos= yythunkpos32;  if (!yymatchString(yy, "\r\n")) goto l31;
  }
  l32:;	  if (!yy__line_start_(yy)) goto l31;
  yyprintf((stderr, "  ok   %s @ %s\n", "EOL", yy->__buf+yy->__pos));
  return 1;
  l31:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "EOL", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_line_comment(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "line_comment"));  if (!yymatchString(yy, "//")) goto l34;
  l35:;	
  {  int yypos36= yy->__pos, yythunkpos36= yy->__thunkpos;
  {  int yypos37= yy->__pos, yythunkpos37= yy->__thunkpos;  if (!yy_EOL(yy)) goto l37;  goto l36;
  l37:;	  yy->__pos= yypos37; yy->__thunkpos= yythunkpos37;
  }  if (!yymatchDot(yy)) goto l36;  goto l35;
  l36:;	  yy->__pos= yypos36; yy->__thunkpos= yythunkpos36;
  }  if (!yy_EOL(yy)) goto l34;
  yyprintf((stderr, "  ok   %s @ %s\n", "line_comment", yy->__buf+yy->__pos));
  return 1;
  l34:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "line_comment", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_block_comment(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "block_comment"));  if (!yymatchString(yy, "/*")) goto l38;
  l39:;	
  {  int yypos40= yy->__pos, yythunkpos40= yy->__thunkpos;
  {  int yypos41= yy->__pos, yythunkpos41= yy->__thunkpos;  if (!yy_EOL(yy)) goto l42;  goto l41;
  l42:;	  yy->__pos= yypos41; yy->__thunkpos= yythunkpos41;
  {  int yypos43= yy->__pos, yythunkpos43= yy->__thunkpos;  if (!yymatchString(yy, "*/")) goto l43;  goto l40;
  l43:;	  yy->__pos= yypos43; yy->__thunkpos= yythunkpos43;
  }  if (!yymatchDot(yy)) goto l40;
  }
  l41:;	  goto l39;
  l40:;	  yy->__pos= yypos40; yy->__thunkpos= yythunkpos40;
  }  if (!yymatchString(yy, "*/")) goto l38;
  yyprintf((stderr, "  ok   %s @ %s\n", "block_comment", yy->__buf+yy->__pos));
  return 1;
  l38:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "block_comment", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_HWS(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "HWS"));  if (!yymatchClass(yy, (unsigned char *)"\000\002\000\000\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l44;
  yyprintf((stderr, "  ok   %s @ %s\n", "HWS", yy->__buf+yy->__pos));
  return 1;
  l44:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "HWS", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_quoted(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "quoted"));
  {  int yypos46= yy->__pos, yythunkpos46= yy->__thunkpos;  if (!yy_single_quoted(yy)) goto l47;  goto l46;
  l47:;	  yy->__pos= yypos46; yy->__thunkpos= yythunkpos46;  if (!yy_double_quoted(yy)) goto l45;
  }
  l46:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "quoted", yy->__buf+yy->__pos));
  return 1;
  l45:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "quoted", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_EOF(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "EOF"));
  {  int yypos49= yy->__pos, yythunkpos49= yy->__thunkpos;  if (!yymatchDot(yy)) goto l49;  goto l48;
  l49:;	  yy->__pos= yypos49; yy->__thunkpos= yythunkpos49;
  }  yyDo(yy, yy_1_EOF, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "EOF", yy->__buf+yy->__pos));
  return 1;
  l48:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "EOF", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_line_end(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "line_end"));
  l51:;	
  {  int yypos52= yy->__pos, yythunkpos52= yy->__thunkpos;
  {  int yypos53= yy->__pos, yythunkpos53= yy->__thunkpos;  if (!yy_HWS(yy)) goto l54;  goto l53;
  l54:;	  yy->__pos= yypos53; yy->__thunkpos= yythunkpos53;  if (!yy_block_comment(yy)) goto l52;
  }
  l53:;	  goto l51;
  l52:;	  yy->__pos= yypos52; yy->__thunkpos= yythunkpos52;
  }
  {  int yypos55= yy->__pos, yythunkpos55= yy->__thunkpos;  if (!yy_line_comment(yy)) goto l56;  goto l55;
  l56:;	  yy->__pos= yypos55; yy->__thunkpos= yythunkpos55;  if (!yy_EOL(yy)) goto l50;
  }
  l55:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "line_end", yy->__buf+yy->__pos));
  return 1;
  l50:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "line_end", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_command_body(yycontext *yy)
{
  yyprintf((stderr, "%s\n", "command_body"));
  l58:;	
  {  int yypos59= yy->__pos, yythunkpos59= yy->__thunkpos;
  {  int yypos60= yy->__pos, yythunkpos60= yy->__thunkpos;  if (!yy_quoted(yy)) goto l61;  goto l60;
  l61:;	  yy->__pos= yypos60; yy->__thunkpos= yythunkpos60;
  {  int yypos62= yy->__pos, yythunkpos62= yy->__thunkpos;  if (!yy_line_end(yy)) goto l62;  goto l59;
  l62:;	  yy->__pos= yypos62; yy->__thunkpos= yythunkpos62;
  }  if (!yymatchDot(yy)) goto l59;
  }
  l60:;	  goto l58;
  l59:;	  yy->__pos= yypos59; yy->__thunkpos= yythunkpos59;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "command_body", yy->__buf+yy->__pos));
  return 1;
}
YY_RULE(int) yy__(yycontext *yy)
{
  yyprintf((stderr, "%s\n", "_"));
  l64:;	
  {  int yypos65= yy->__pos, yythunkpos65= yy->__thunkpos;
  {  int yypos66= yy->__pos, yythunkpos66= yy->__thunkpos;  if (!yy_WS(yy)) goto l67;  goto l66;
  l67:;	  yy->__pos= yypos66; yy->__thunkpos= yythunkpos66;  if (!yy_comment(yy)) goto l65;
  }
  l66:;	  goto l64;
  l65:;	  yy->__pos= yypos65; yy->__thunkpos= yythunkpos65;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "_", yy->__buf+yy->__pos));
  return 1;
}
YY_RULE(int) yy_statement(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "statement"));  if (!yy__(yy)) goto l68;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l68;
#undef yytext
#undef yyleng
  }  if (!yy_statement_body(yy)) goto l68;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l68;
#undef yytext
#undef yyleng
  }  if (!yy__(yy)) goto l68;
  {  int yypos69= yy->__pos, yythunkpos69= yy->__thunkpos;  if (!yymatchChar(yy, ';')) goto l70;  goto l69;
  l70:;	  yy->__pos= yypos69; yy->__thunkpos= yythunkpos69;  if (!yy_EOF(yy)) goto l68;
  }
  l69:;	  yyDo(yy, yy_1_statement, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "statement", yy->__buf+yy->__pos));
  return 1;
  l68:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "statement", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_command(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "command"));  if (!yy__(yy)) goto l71;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l71;
#undef yytext
#undef yyleng
  }  if (!yymatchChar(yy, ':')) goto l71;  if (!yy_command_body(yy)) goto l71;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l71;
#undef yytext
#undef yyleng
  }
  {  int yypos72= yy->__pos, yythunkpos72= yy->__thunkpos;  if (!yy_line_end(yy)) goto l73;  goto l72;
  l73:;	  yy->__pos= yypos72; yy->__thunkpos= yythunkpos72;  if (!yy_EOF(yy)) goto l71;
  }
  l72:;	  yyDo(yy, yy_1_command, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "command", yy->__buf+yy->__pos));
  return 1;
  l71:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "command", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_directive(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "directive"));
  {  int yypos75= yy->__pos, yythunkpos75= yy->__thunkpos;  if (!yy_command(yy)) goto l76;  goto l75;
  l76:;	  yy->__pos= yypos75; yy->__thunkpos= yythunkpos75;  if (!yy_statement(yy)) goto l74;
  }
  l75:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "directive", yy->__buf+yy->__pos));
  return 1;
  l74:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "directive", yy->__buf+yy->__pos));
  return 0;
}

#ifndef YY_PART

typedef int (*yyrule)(yycontext *yy);

YY_PARSE(int) YYPARSEFROM(YY_CTX_PARAM_ yyrule yystart)
{
  int yyok;
  if (!yyctx->__buflen)
    {
      yyctx->__buflen= YY_BUFFER_SIZE;
      yyctx->__buf= (char *)YY_MALLOC(yyctx, yyctx->__buflen);
      yyctx->__textlen= YY_BUFFER_SIZE;
      yyctx->__text= (char *)YY_MALLOC(yyctx, yyctx->__textlen);
      yyctx->__thunkslen= YY_STACK_SIZE;
      yyctx->__thunks= (yythunk *)YY_MALLOC(yyctx, sizeof(yythunk) * yyctx->__thunkslen);
      yyctx->__valslen= YY_STACK_SIZE;
      yyctx->__vals= (YYSTYPE *)YY_MALLOC(yyctx, sizeof(YYSTYPE) * yyctx->__valslen);
      yyctx->__begin= yyctx->__end= yyctx->__pos= yyctx->__limit= yyctx->__thunkpos= 0;
    }
  yyctx->__begin= yyctx->__end= yyctx->__pos;
  yyctx->__thunkpos= 0;
  yyctx->__val= yyctx->__vals;
  yyok= yystart(yyctx);
  if (yyok) yyDone(yyctx);
  yyCommit(yyctx);
  return yyok;
}

YY_PARSE(int) YYPARSE(YY_CTX_PARAM)
{
  return YYPARSEFROM(YY_CTX_ARG_ yy_directive);
}

YY_PARSE(yycontext *) YYRELEASE(yycontext *yyctx)
{
  if (yyctx->__buflen)
    {
      yyctx->__buflen= 0;
      YY_FREE(yyctx, yyctx->__buf);
      YY_FREE(yyctx, yyctx->__text);
      YY_FREE(yyctx, yyctx->__thunks);
      YY_FREE(yyctx, yyctx->__vals);
    }
  return yyctx;
}

#endif
