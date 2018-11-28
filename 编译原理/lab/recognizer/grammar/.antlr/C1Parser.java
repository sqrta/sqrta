// Generated from /home/sqrta/文档/github/PB16020582/c1recognizer/grammar/C1Parser.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class C1Parser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Comma=1, SemiColon=2, Assign=3, LeftBracket=4, RightBracket=5, LeftBrace=6, 
		RightBrace=7, LeftParen=8, RightParen=9, If=10, Else=11, While=12, Const=13, 
		Equal=14, NonEqual=15, Less=16, Greater=17, LessEqual=18, GreaterEqual=19, 
		Plus=20, Minus=21, Multiply=22, Divide=23, Modulo=24, Int=25, Float=26, 
		Void=27, Identifier=28, IntConst=29, FloatConst=30, Unformal_annotation=31, 
		Formal_annotation=32, WhiteSpace=33, Line_break=34;
	public static final int
		RULE_compilationUnit = 0, RULE_decl = 1, RULE_constdecl = 2, RULE_constdef = 3, 
		RULE_vardecl = 4, RULE_vardef = 5, RULE_funcdef = 6, RULE_block = 7, RULE_blockitem = 8, 
		RULE_stmt = 9, RULE_lval = 10, RULE_cond = 11, RULE_exp = 12, RULE_number = 13;
	public static final String[] ruleNames = {
		"compilationUnit", "decl", "constdecl", "constdef", "vardecl", "vardef", 
		"funcdef", "block", "blockitem", "stmt", "lval", "cond", "exp", "number"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "','", "';'", "'='", "'['", "']'", "'{'", "'}'", "'('", "')'", "'if'", 
		"'else'", "'while'", "'const'", "'=='", "'!='", "'<'", "'>'", "'<='", 
		"'>='", "'+'", "'-'", "'*'", "'/'", "'%'", "'int'", "'float'", "'void'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "Comma", "SemiColon", "Assign", "LeftBracket", "RightBracket", "LeftBrace", 
		"RightBrace", "LeftParen", "RightParen", "If", "Else", "While", "Const", 
		"Equal", "NonEqual", "Less", "Greater", "LessEqual", "GreaterEqual", "Plus", 
		"Minus", "Multiply", "Divide", "Modulo", "Int", "Float", "Void", "Identifier", 
		"IntConst", "FloatConst", "Unformal_annotation", "Formal_annotation", 
		"WhiteSpace", "Line_break"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "C1Parser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public C1Parser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class CompilationUnitContext extends ParserRuleContext {
		public DeclContext decl() {
			return getRuleContext(DeclContext.class,0);
		}
		public FuncdefContext funcdef() {
			return getRuleContext(FuncdefContext.class,0);
		}
		public CompilationUnitContext compilationUnit() {
			return getRuleContext(CompilationUnitContext.class,0);
		}
		public CompilationUnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compilationUnit; }
	}

	public final CompilationUnitContext compilationUnit() throws RecognitionException {
		return compilationUnit(0);
	}

	private CompilationUnitContext compilationUnit(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		CompilationUnitContext _localctx = new CompilationUnitContext(_ctx, _parentState);
		CompilationUnitContext _prevctx = _localctx;
		int _startState = 0;
		enterRecursionRule(_localctx, 0, RULE_compilationUnit, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(31);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Const:
			case Int:
			case Float:
				{
				setState(29);
				decl();
				}
				break;
			case Void:
				{
				setState(30);
				funcdef();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
			_ctx.stop = _input.LT(-1);
			setState(40);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new CompilationUnitContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_compilationUnit);
					setState(33);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(36);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case Const:
					case Int:
					case Float:
						{
						setState(34);
						decl();
						}
						break;
					case Void:
						{
						setState(35);
						funcdef();
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					} 
				}
				setState(42);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class DeclContext extends ParserRuleContext {
		public ConstdeclContext constdecl() {
			return getRuleContext(ConstdeclContext.class,0);
		}
		public VardeclContext vardecl() {
			return getRuleContext(VardeclContext.class,0);
		}
		public DeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_decl; }
	}

	public final DeclContext decl() throws RecognitionException {
		DeclContext _localctx = new DeclContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_decl);
		try {
			setState(45);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Const:
				enterOuterAlt(_localctx, 1);
				{
				setState(43);
				constdecl();
				}
				break;
			case Int:
			case Float:
				enterOuterAlt(_localctx, 2);
				{
				setState(44);
				vardecl();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstdeclContext extends ParserRuleContext {
		public TerminalNode Const() { return getToken(C1Parser.Const, 0); }
		public List<ConstdefContext> constdef() {
			return getRuleContexts(ConstdefContext.class);
		}
		public ConstdefContext constdef(int i) {
			return getRuleContext(ConstdefContext.class,i);
		}
		public TerminalNode SemiColon() { return getToken(C1Parser.SemiColon, 0); }
		public TerminalNode Int() { return getToken(C1Parser.Int, 0); }
		public TerminalNode Float() { return getToken(C1Parser.Float, 0); }
		public List<TerminalNode> Comma() { return getTokens(C1Parser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(C1Parser.Comma, i);
		}
		public ConstdeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constdecl; }
	}

	public final ConstdeclContext constdecl() throws RecognitionException {
		ConstdeclContext _localctx = new ConstdeclContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_constdecl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(47);
			match(Const);
			setState(48);
			_la = _input.LA(1);
			if ( !(_la==Int || _la==Float) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(49);
			constdef();
			setState(54);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(50);
				match(Comma);
				setState(51);
				constdef();
				}
				}
				setState(56);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(57);
			match(SemiColon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstdefContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(C1Parser.Identifier, 0); }
		public TerminalNode Assign() { return getToken(C1Parser.Assign, 0); }
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode LeftBracket() { return getToken(C1Parser.LeftBracket, 0); }
		public TerminalNode RightBracket() { return getToken(C1Parser.RightBracket, 0); }
		public TerminalNode LeftBrace() { return getToken(C1Parser.LeftBrace, 0); }
		public TerminalNode RightBrace() { return getToken(C1Parser.RightBrace, 0); }
		public List<TerminalNode> Comma() { return getTokens(C1Parser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(C1Parser.Comma, i);
		}
		public ConstdefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constdef; }
	}

	public final ConstdefContext constdef() throws RecognitionException {
		ConstdefContext _localctx = new ConstdefContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_constdef);
		int _la;
		try {
			setState(80);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(59);
				match(Identifier);
				setState(60);
				match(Assign);
				setState(61);
				exp(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(62);
				match(Identifier);
				setState(63);
				match(LeftBracket);
				setState(65);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LeftParen) | (1L << Plus) | (1L << Minus) | (1L << Identifier) | (1L << IntConst) | (1L << FloatConst))) != 0)) {
					{
					setState(64);
					exp(0);
					}
				}

				setState(67);
				match(RightBracket);
				setState(68);
				match(Assign);
				setState(69);
				match(LeftBrace);
				setState(70);
				exp(0);
				setState(75);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==Comma) {
					{
					{
					setState(71);
					match(Comma);
					setState(72);
					exp(0);
					}
					}
					setState(77);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(78);
				match(RightBrace);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VardeclContext extends ParserRuleContext {
		public List<VardefContext> vardef() {
			return getRuleContexts(VardefContext.class);
		}
		public VardefContext vardef(int i) {
			return getRuleContext(VardefContext.class,i);
		}
		public TerminalNode SemiColon() { return getToken(C1Parser.SemiColon, 0); }
		public TerminalNode Int() { return getToken(C1Parser.Int, 0); }
		public TerminalNode Float() { return getToken(C1Parser.Float, 0); }
		public List<TerminalNode> Comma() { return getTokens(C1Parser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(C1Parser.Comma, i);
		}
		public VardeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vardecl; }
	}

	public final VardeclContext vardecl() throws RecognitionException {
		VardeclContext _localctx = new VardeclContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_vardecl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(82);
			_la = _input.LA(1);
			if ( !(_la==Int || _la==Float) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(83);
			vardef();
			setState(88);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(84);
				match(Comma);
				setState(85);
				vardef();
				}
				}
				setState(90);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(91);
			match(SemiColon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VardefContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(C1Parser.Identifier, 0); }
		public TerminalNode LeftBracket() { return getToken(C1Parser.LeftBracket, 0); }
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode RightBracket() { return getToken(C1Parser.RightBracket, 0); }
		public TerminalNode Assign() { return getToken(C1Parser.Assign, 0); }
		public TerminalNode LeftBrace() { return getToken(C1Parser.LeftBrace, 0); }
		public TerminalNode RightBrace() { return getToken(C1Parser.RightBrace, 0); }
		public List<TerminalNode> Comma() { return getTokens(C1Parser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(C1Parser.Comma, i);
		}
		public VardefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vardef; }
	}

	public final VardefContext vardef() throws RecognitionException {
		VardefContext _localctx = new VardefContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_vardef);
		int _la;
		try {
			setState(120);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(93);
				match(Identifier);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(94);
				match(Identifier);
				setState(95);
				match(LeftBracket);
				setState(96);
				exp(0);
				setState(97);
				match(RightBracket);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(99);
				match(Identifier);
				setState(100);
				match(Assign);
				setState(101);
				exp(0);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(102);
				match(Identifier);
				setState(103);
				match(LeftBracket);
				setState(105);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LeftParen) | (1L << Plus) | (1L << Minus) | (1L << Identifier) | (1L << IntConst) | (1L << FloatConst))) != 0)) {
					{
					setState(104);
					exp(0);
					}
				}

				setState(107);
				match(RightBracket);
				setState(108);
				match(Assign);
				setState(109);
				match(LeftBrace);
				setState(110);
				exp(0);
				setState(115);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==Comma) {
					{
					{
					setState(111);
					match(Comma);
					setState(112);
					exp(0);
					}
					}
					setState(117);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(118);
				match(RightBrace);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FuncdefContext extends ParserRuleContext {
		public TerminalNode Void() { return getToken(C1Parser.Void, 0); }
		public TerminalNode Identifier() { return getToken(C1Parser.Identifier, 0); }
		public TerminalNode LeftParen() { return getToken(C1Parser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(C1Parser.RightParen, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public FuncdefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_funcdef; }
	}

	public final FuncdefContext funcdef() throws RecognitionException {
		FuncdefContext _localctx = new FuncdefContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_funcdef);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(122);
			match(Void);
			setState(123);
			match(Identifier);
			setState(124);
			match(LeftParen);
			setState(125);
			match(RightParen);
			setState(126);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockContext extends ParserRuleContext {
		public TerminalNode LeftBrace() { return getToken(C1Parser.LeftBrace, 0); }
		public TerminalNode RightBrace() { return getToken(C1Parser.RightBrace, 0); }
		public List<BlockitemContext> blockitem() {
			return getRuleContexts(BlockitemContext.class);
		}
		public BlockitemContext blockitem(int i) {
			return getRuleContext(BlockitemContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(128);
			match(LeftBrace);
			setState(132);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << SemiColon) | (1L << LeftBrace) | (1L << If) | (1L << While) | (1L << Const) | (1L << Int) | (1L << Float) | (1L << Identifier))) != 0)) {
				{
				{
				setState(129);
				blockitem();
				}
				}
				setState(134);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(135);
			match(RightBrace);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockitemContext extends ParserRuleContext {
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public DeclContext decl() {
			return getRuleContext(DeclContext.class,0);
		}
		public BlockitemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockitem; }
	}

	public final BlockitemContext blockitem() throws RecognitionException {
		BlockitemContext _localctx = new BlockitemContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_blockitem);
		try {
			setState(139);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SemiColon:
			case LeftBrace:
			case If:
			case While:
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(137);
				stmt();
				}
				break;
			case Const:
			case Int:
			case Float:
				enterOuterAlt(_localctx, 2);
				{
				setState(138);
				decl();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StmtContext extends ParserRuleContext {
		public LvalContext lval() {
			return getRuleContext(LvalContext.class,0);
		}
		public TerminalNode Assign() { return getToken(C1Parser.Assign, 0); }
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public TerminalNode SemiColon() { return getToken(C1Parser.SemiColon, 0); }
		public TerminalNode Identifier() { return getToken(C1Parser.Identifier, 0); }
		public TerminalNode LeftParen() { return getToken(C1Parser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(C1Parser.RightParen, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode If() { return getToken(C1Parser.If, 0); }
		public CondContext cond() {
			return getRuleContext(CondContext.class,0);
		}
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public TerminalNode Else() { return getToken(C1Parser.Else, 0); }
		public TerminalNode While() { return getToken(C1Parser.While, 0); }
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_stmt);
		try {
			setState(167);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(141);
				lval();
				setState(142);
				match(Assign);
				setState(143);
				exp(0);
				setState(144);
				match(SemiColon);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(146);
				match(Identifier);
				setState(147);
				match(LeftParen);
				setState(148);
				match(RightParen);
				setState(149);
				match(SemiColon);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(150);
				block();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(151);
				match(If);
				setState(152);
				match(LeftParen);
				setState(153);
				cond();
				setState(154);
				match(RightParen);
				setState(155);
				stmt();
				setState(158);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
				case 1:
					{
					setState(156);
					match(Else);
					setState(157);
					stmt();
					}
					break;
				}
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(160);
				match(While);
				setState(161);
				match(LeftParen);
				setState(162);
				cond();
				setState(163);
				match(RightParen);
				setState(164);
				stmt();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(166);
				match(SemiColon);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LvalContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(C1Parser.Identifier, 0); }
		public TerminalNode LeftBracket() { return getToken(C1Parser.LeftBracket, 0); }
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public TerminalNode RightBracket() { return getToken(C1Parser.RightBracket, 0); }
		public LvalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lval; }
	}

	public final LvalContext lval() throws RecognitionException {
		LvalContext _localctx = new LvalContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_lval);
		try {
			setState(175);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(169);
				match(Identifier);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(170);
				match(Identifier);
				setState(171);
				match(LeftBracket);
				setState(172);
				exp(0);
				setState(173);
				match(RightBracket);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CondContext extends ParserRuleContext {
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode Equal() { return getToken(C1Parser.Equal, 0); }
		public TerminalNode NonEqual() { return getToken(C1Parser.NonEqual, 0); }
		public TerminalNode Greater() { return getToken(C1Parser.Greater, 0); }
		public TerminalNode Less() { return getToken(C1Parser.Less, 0); }
		public TerminalNode GreaterEqual() { return getToken(C1Parser.GreaterEqual, 0); }
		public TerminalNode LessEqual() { return getToken(C1Parser.LessEqual, 0); }
		public CondContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_cond; }
	}

	public final CondContext cond() throws RecognitionException {
		CondContext _localctx = new CondContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_cond);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(177);
			exp(0);
			setState(178);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Equal) | (1L << NonEqual) | (1L << Less) | (1L << Greater) | (1L << LessEqual) | (1L << GreaterEqual))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(179);
			exp(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpContext extends ParserRuleContext {
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode Plus() { return getToken(C1Parser.Plus, 0); }
		public TerminalNode Minus() { return getToken(C1Parser.Minus, 0); }
		public TerminalNode LeftParen() { return getToken(C1Parser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(C1Parser.RightParen, 0); }
		public LvalContext lval() {
			return getRuleContext(LvalContext.class,0);
		}
		public NumberContext number() {
			return getRuleContext(NumberContext.class,0);
		}
		public TerminalNode Multiply() { return getToken(C1Parser.Multiply, 0); }
		public TerminalNode Divide() { return getToken(C1Parser.Divide, 0); }
		public TerminalNode Modulo() { return getToken(C1Parser.Modulo, 0); }
		public ExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exp; }
	}

	public final ExpContext exp() throws RecognitionException {
		return exp(0);
	}

	private ExpContext exp(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpContext _localctx = new ExpContext(_ctx, _parentState);
		ExpContext _prevctx = _localctx;
		int _startState = 24;
		enterRecursionRule(_localctx, 24, RULE_exp, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(190);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Plus:
			case Minus:
				{
				setState(182);
				_la = _input.LA(1);
				if ( !(_la==Plus || _la==Minus) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(183);
				exp(6);
				}
				break;
			case LeftParen:
				{
				setState(184);
				match(LeftParen);
				setState(185);
				exp(0);
				setState(186);
				match(RightParen);
				}
				break;
			case Identifier:
				{
				setState(188);
				lval();
				}
				break;
			case IntConst:
			case FloatConst:
				{
				setState(189);
				number();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(200);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(198);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
					case 1:
						{
						_localctx = new ExpContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_exp);
						setState(192);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(193);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Multiply) | (1L << Divide) | (1L << Modulo))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(194);
						exp(6);
						}
						break;
					case 2:
						{
						_localctx = new ExpContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_exp);
						setState(195);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(196);
						_la = _input.LA(1);
						if ( !(_la==Plus || _la==Minus) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(197);
						exp(5);
						}
						break;
					}
					} 
				}
				setState(202);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class NumberContext extends ParserRuleContext {
		public TerminalNode FloatConst() { return getToken(C1Parser.FloatConst, 0); }
		public TerminalNode IntConst() { return getToken(C1Parser.IntConst, 0); }
		public NumberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_number; }
	}

	public final NumberContext number() throws RecognitionException {
		NumberContext _localctx = new NumberContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_number);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(203);
			_la = _input.LA(1);
			if ( !(_la==IntConst || _la==FloatConst) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 0:
			return compilationUnit_sempred((CompilationUnitContext)_localctx, predIndex);
		case 12:
			return exp_sempred((ExpContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean compilationUnit_sempred(CompilationUnitContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean exp_sempred(ExpContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 5);
		case 2:
			return precpred(_ctx, 4);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3$\u00d0\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\3\2\3\2\3\2\5\2\"\n\2\3\2\3\2"+
		"\3\2\5\2\'\n\2\7\2)\n\2\f\2\16\2,\13\2\3\3\3\3\5\3\60\n\3\3\4\3\4\3\4"+
		"\3\4\3\4\7\4\67\n\4\f\4\16\4:\13\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\5\5"+
		"D\n\5\3\5\3\5\3\5\3\5\3\5\3\5\7\5L\n\5\f\5\16\5O\13\5\3\5\3\5\5\5S\n\5"+
		"\3\6\3\6\3\6\3\6\7\6Y\n\6\f\6\16\6\\\13\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7"+
		"\3\7\3\7\3\7\3\7\3\7\3\7\3\7\5\7l\n\7\3\7\3\7\3\7\3\7\3\7\3\7\7\7t\n\7"+
		"\f\7\16\7w\13\7\3\7\3\7\5\7{\n\7\3\b\3\b\3\b\3\b\3\b\3\b\3\t\3\t\7\t\u0085"+
		"\n\t\f\t\16\t\u0088\13\t\3\t\3\t\3\n\3\n\5\n\u008e\n\n\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\5\13\u00a1\n\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\5\13\u00aa\n\13\3"+
		"\f\3\f\3\f\3\f\3\f\3\f\5\f\u00b2\n\f\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3"+
		"\16\3\16\3\16\3\16\3\16\3\16\5\16\u00c1\n\16\3\16\3\16\3\16\3\16\3\16"+
		"\3\16\7\16\u00c9\n\16\f\16\16\16\u00cc\13\16\3\17\3\17\3\17\2\4\2\32\20"+
		"\2\4\6\b\n\f\16\20\22\24\26\30\32\34\2\7\3\2\33\34\3\2\20\25\3\2\26\27"+
		"\3\2\30\32\3\2\37 \2\u00dd\2\36\3\2\2\2\4/\3\2\2\2\6\61\3\2\2\2\bR\3\2"+
		"\2\2\nT\3\2\2\2\fz\3\2\2\2\16|\3\2\2\2\20\u0082\3\2\2\2\22\u008d\3\2\2"+
		"\2\24\u00a9\3\2\2\2\26\u00b1\3\2\2\2\30\u00b3\3\2\2\2\32\u00c0\3\2\2\2"+
		"\34\u00cd\3\2\2\2\36!\b\2\1\2\37\"\5\4\3\2 \"\5\16\b\2!\37\3\2\2\2! \3"+
		"\2\2\2\"*\3\2\2\2#&\f\4\2\2$\'\5\4\3\2%\'\5\16\b\2&$\3\2\2\2&%\3\2\2\2"+
		"\')\3\2\2\2(#\3\2\2\2),\3\2\2\2*(\3\2\2\2*+\3\2\2\2+\3\3\2\2\2,*\3\2\2"+
		"\2-\60\5\6\4\2.\60\5\n\6\2/-\3\2\2\2/.\3\2\2\2\60\5\3\2\2\2\61\62\7\17"+
		"\2\2\62\63\t\2\2\2\638\5\b\5\2\64\65\7\3\2\2\65\67\5\b\5\2\66\64\3\2\2"+
		"\2\67:\3\2\2\28\66\3\2\2\289\3\2\2\29;\3\2\2\2:8\3\2\2\2;<\7\4\2\2<\7"+
		"\3\2\2\2=>\7\36\2\2>?\7\5\2\2?S\5\32\16\2@A\7\36\2\2AC\7\6\2\2BD\5\32"+
		"\16\2CB\3\2\2\2CD\3\2\2\2DE\3\2\2\2EF\7\7\2\2FG\7\5\2\2GH\7\b\2\2HM\5"+
		"\32\16\2IJ\7\3\2\2JL\5\32\16\2KI\3\2\2\2LO\3\2\2\2MK\3\2\2\2MN\3\2\2\2"+
		"NP\3\2\2\2OM\3\2\2\2PQ\7\t\2\2QS\3\2\2\2R=\3\2\2\2R@\3\2\2\2S\t\3\2\2"+
		"\2TU\t\2\2\2UZ\5\f\7\2VW\7\3\2\2WY\5\f\7\2XV\3\2\2\2Y\\\3\2\2\2ZX\3\2"+
		"\2\2Z[\3\2\2\2[]\3\2\2\2\\Z\3\2\2\2]^\7\4\2\2^\13\3\2\2\2_{\7\36\2\2`"+
		"a\7\36\2\2ab\7\6\2\2bc\5\32\16\2cd\7\7\2\2d{\3\2\2\2ef\7\36\2\2fg\7\5"+
		"\2\2g{\5\32\16\2hi\7\36\2\2ik\7\6\2\2jl\5\32\16\2kj\3\2\2\2kl\3\2\2\2"+
		"lm\3\2\2\2mn\7\7\2\2no\7\5\2\2op\7\b\2\2pu\5\32\16\2qr\7\3\2\2rt\5\32"+
		"\16\2sq\3\2\2\2tw\3\2\2\2us\3\2\2\2uv\3\2\2\2vx\3\2\2\2wu\3\2\2\2xy\7"+
		"\t\2\2y{\3\2\2\2z_\3\2\2\2z`\3\2\2\2ze\3\2\2\2zh\3\2\2\2{\r\3\2\2\2|}"+
		"\7\35\2\2}~\7\36\2\2~\177\7\n\2\2\177\u0080\7\13\2\2\u0080\u0081\5\20"+
		"\t\2\u0081\17\3\2\2\2\u0082\u0086\7\b\2\2\u0083\u0085\5\22\n\2\u0084\u0083"+
		"\3\2\2\2\u0085\u0088\3\2\2\2\u0086\u0084\3\2\2\2\u0086\u0087\3\2\2\2\u0087"+
		"\u0089\3\2\2\2\u0088\u0086\3\2\2\2\u0089\u008a\7\t\2\2\u008a\21\3\2\2"+
		"\2\u008b\u008e\5\24\13\2\u008c\u008e\5\4\3\2\u008d\u008b\3\2\2\2\u008d"+
		"\u008c\3\2\2\2\u008e\23\3\2\2\2\u008f\u0090\5\26\f\2\u0090\u0091\7\5\2"+
		"\2\u0091\u0092\5\32\16\2\u0092\u0093\7\4\2\2\u0093\u00aa\3\2\2\2\u0094"+
		"\u0095\7\36\2\2\u0095\u0096\7\n\2\2\u0096\u0097\7\13\2\2\u0097\u00aa\7"+
		"\4\2\2\u0098\u00aa\5\20\t\2\u0099\u009a\7\f\2\2\u009a\u009b\7\n\2\2\u009b"+
		"\u009c\5\30\r\2\u009c\u009d\7\13\2\2\u009d\u00a0\5\24\13\2\u009e\u009f"+
		"\7\r\2\2\u009f\u00a1\5\24\13\2\u00a0\u009e\3\2\2\2\u00a0\u00a1\3\2\2\2"+
		"\u00a1\u00aa\3\2\2\2\u00a2\u00a3\7\16\2\2\u00a3\u00a4\7\n\2\2\u00a4\u00a5"+
		"\5\30\r\2\u00a5\u00a6\7\13\2\2\u00a6\u00a7\5\24\13\2\u00a7\u00aa\3\2\2"+
		"\2\u00a8\u00aa\7\4\2\2\u00a9\u008f\3\2\2\2\u00a9\u0094\3\2\2\2\u00a9\u0098"+
		"\3\2\2\2\u00a9\u0099\3\2\2\2\u00a9\u00a2\3\2\2\2\u00a9\u00a8\3\2\2\2\u00aa"+
		"\25\3\2\2\2\u00ab\u00b2\7\36\2\2\u00ac\u00ad\7\36\2\2\u00ad\u00ae\7\6"+
		"\2\2\u00ae\u00af\5\32\16\2\u00af\u00b0\7\7\2\2\u00b0\u00b2\3\2\2\2\u00b1"+
		"\u00ab\3\2\2\2\u00b1\u00ac\3\2\2\2\u00b2\27\3\2\2\2\u00b3\u00b4\5\32\16"+
		"\2\u00b4\u00b5\t\3\2\2\u00b5\u00b6\5\32\16\2\u00b6\31\3\2\2\2\u00b7\u00b8"+
		"\b\16\1\2\u00b8\u00b9\t\4\2\2\u00b9\u00c1\5\32\16\b\u00ba\u00bb\7\n\2"+
		"\2\u00bb\u00bc\5\32\16\2\u00bc\u00bd\7\13\2\2\u00bd\u00c1\3\2\2\2\u00be"+
		"\u00c1\5\26\f\2\u00bf\u00c1\5\34\17\2\u00c0\u00b7\3\2\2\2\u00c0\u00ba"+
		"\3\2\2\2\u00c0\u00be\3\2\2\2\u00c0\u00bf\3\2\2\2\u00c1\u00ca\3\2\2\2\u00c2"+
		"\u00c3\f\7\2\2\u00c3\u00c4\t\5\2\2\u00c4\u00c9\5\32\16\b\u00c5\u00c6\f"+
		"\6\2\2\u00c6\u00c7\t\4\2\2\u00c7\u00c9\5\32\16\7\u00c8\u00c2\3\2\2\2\u00c8"+
		"\u00c5\3\2\2\2\u00c9\u00cc\3\2\2\2\u00ca\u00c8\3\2\2\2\u00ca\u00cb\3\2"+
		"\2\2\u00cb\33\3\2\2\2\u00cc\u00ca\3\2\2\2\u00cd\u00ce\t\6\2\2\u00ce\35"+
		"\3\2\2\2\26!&*/8CMRZkuz\u0086\u008d\u00a0\u00a9\u00b1\u00c0\u00c8\u00ca";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}