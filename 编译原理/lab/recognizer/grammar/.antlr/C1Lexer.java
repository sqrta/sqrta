// Generated from /home/sqrta/文档/github/PB16020582/c1recognizer/grammar/C1Lexer.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class C1Lexer extends Lexer {
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
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"Unformal_annotation", "Formal_annotation", "LeftParen", "RightParen", 
		"LeftBrace", "RightBrace", "LeftBracket", "RightBracket", "Equal", "NonEqual", 
		"Greater", "Less", "LessEqual", "GreaterEqual", "Assign", "SemiColon", 
		"Comma", "If", "Else", "While", "Const", "Int", "Float", "Void", "Identifier", 
		"IntConst", "FloatConst", "Plus", "Minus", "Multiply", "Divide", "Modulo", 
		"WhiteSpace", "Line_break"
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


	public C1Lexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "C1Lexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2$\u015b\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\3\2\3\2\3\2\3\2\3\2\5\2M\n\2\7\2O\n\2\f\2\16\2R\13\2"+
		"\3\2\3\2\3\2\3\2\5\2X\n\2\3\2\7\2[\n\2\f\2\16\2^\13\2\3\2\3\2\3\2\3\2"+
		"\5\2d\n\2\5\2f\n\2\3\2\3\2\3\3\3\3\3\3\3\3\7\3n\n\3\f\3\16\3q\13\3\3\3"+
		"\3\3\3\3\5\3v\n\3\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t"+
		"\3\t\3\n\3\n\3\n\3\13\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\16\3\17\3"+
		"\17\3\17\3\20\3\20\3\21\3\21\3\22\3\22\3\23\3\23\3\23\3\24\3\24\3\24\3"+
		"\24\3\24\3\25\3\25\3\25\3\25\3\25\3\25\3\26\3\26\3\26\3\26\3\26\3\26\3"+
		"\27\3\27\3\27\3\27\3\30\3\30\3\30\3\30\3\30\3\30\3\31\3\31\3\31\3\31\3"+
		"\31\3\32\3\32\7\32\u00c1\n\32\f\32\16\32\u00c4\13\32\3\33\3\33\7\33\u00c8"+
		"\n\33\f\33\16\33\u00cb\13\33\3\33\3\33\7\33\u00cf\n\33\f\33\16\33\u00d2"+
		"\13\33\3\33\3\33\3\33\3\33\5\33\u00d8\n\33\3\33\7\33\u00db\n\33\f\33\16"+
		"\33\u00de\13\33\5\33\u00e0\n\33\3\34\7\34\u00e3\n\34\f\34\16\34\u00e6"+
		"\13\34\3\34\3\34\6\34\u00ea\n\34\r\34\16\34\u00eb\3\34\6\34\u00ef\n\34"+
		"\r\34\16\34\u00f0\3\34\5\34\u00f4\n\34\3\34\3\34\5\34\u00f8\n\34\3\34"+
		"\6\34\u00fb\n\34\r\34\16\34\u00fc\5\34\u00ff\n\34\3\34\6\34\u0102\n\34"+
		"\r\34\16\34\u0103\3\34\3\34\5\34\u0108\n\34\3\34\6\34\u010b\n\34\r\34"+
		"\16\34\u010c\3\34\3\34\3\34\7\34\u0112\n\34\f\34\16\34\u0115\13\34\3\34"+
		"\3\34\6\34\u0119\n\34\r\34\16\34\u011a\3\34\6\34\u011e\n\34\r\34\16\34"+
		"\u011f\3\34\5\34\u0123\n\34\3\34\3\34\5\34\u0127\n\34\3\34\6\34\u012a"+
		"\n\34\r\34\16\34\u012b\5\34\u012e\n\34\3\34\6\34\u0131\n\34\r\34\16\34"+
		"\u0132\3\34\3\34\5\34\u0137\n\34\3\34\6\34\u013a\n\34\r\34\16\34\u013b"+
		"\5\34\u013e\n\34\5\34\u0140\n\34\3\35\3\35\3\36\3\36\3\37\3\37\3 \3 \3"+
		"!\3!\3\"\6\"\u014d\n\"\r\"\16\"\u014e\3\"\3\"\3#\3#\3#\3#\3#\5#\u0158"+
		"\n#\3#\3#\5P\\o\2$\3!\5\"\7\n\t\13\13\b\r\t\17\6\21\7\23\20\25\21\27\23"+
		"\31\22\33\24\35\25\37\5!\4#\3%\f\'\r)\16+\17-\33/\34\61\35\63\36\65\37"+
		"\67 9\26;\27=\30?\31A\32C#E$\3\2\17\3\3\f\f\3\2^^\5\2C\\aac|\6\2\62;C"+
		"\\aac|\3\2\63;\3\2\62;\3\2\629\5\2\62;CHch\4\2GGgg\4\2--//\4\2ZZzz\4\2"+
		"RRrr\5\2\13\f\17\17\"\"\2\u0182\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2"+
		"\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2"+
		"\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2"+
		"\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2"+
		"\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2"+
		"\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2"+
		"\2C\3\2\2\2\2E\3\2\2\2\3G\3\2\2\2\5i\3\2\2\2\7y\3\2\2\2\t{\3\2\2\2\13"+
		"}\3\2\2\2\r\177\3\2\2\2\17\u0081\3\2\2\2\21\u0083\3\2\2\2\23\u0085\3\2"+
		"\2\2\25\u0088\3\2\2\2\27\u008b\3\2\2\2\31\u008d\3\2\2\2\33\u008f\3\2\2"+
		"\2\35\u0092\3\2\2\2\37\u0095\3\2\2\2!\u0097\3\2\2\2#\u0099\3\2\2\2%\u009b"+
		"\3\2\2\2\'\u009e\3\2\2\2)\u00a3\3\2\2\2+\u00a9\3\2\2\2-\u00af\3\2\2\2"+
		"/\u00b3\3\2\2\2\61\u00b9\3\2\2\2\63\u00be\3\2\2\2\65\u00df\3\2\2\2\67"+
		"\u013f\3\2\2\29\u0141\3\2\2\2;\u0143\3\2\2\2=\u0145\3\2\2\2?\u0147\3\2"+
		"\2\2A\u0149\3\2\2\2C\u014c\3\2\2\2E\u0157\3\2\2\2GP\7\61\2\2HL\7^\2\2"+
		"IM\7\f\2\2JK\7\17\2\2KM\7\f\2\2LI\3\2\2\2LJ\3\2\2\2MO\3\2\2\2NH\3\2\2"+
		"\2OR\3\2\2\2PQ\3\2\2\2PN\3\2\2\2QS\3\2\2\2RP\3\2\2\2Se\7\61\2\2TX\t\2"+
		"\2\2UV\7\17\2\2VX\7\f\2\2WT\3\2\2\2WU\3\2\2\2Xf\3\2\2\2Y[\13\2\2\2ZY\3"+
		"\2\2\2[^\3\2\2\2\\]\3\2\2\2\\Z\3\2\2\2]_\3\2\2\2^\\\3\2\2\2_c\n\3\2\2"+
		"`d\t\2\2\2ab\7\17\2\2bd\7\f\2\2c`\3\2\2\2ca\3\2\2\2df\3\2\2\2eW\3\2\2"+
		"\2e\\\3\2\2\2fg\3\2\2\2gh\b\2\2\2h\4\3\2\2\2ij\7\61\2\2jk\7,\2\2ko\3\2"+
		"\2\2ln\13\2\2\2ml\3\2\2\2nq\3\2\2\2op\3\2\2\2om\3\2\2\2pu\3\2\2\2qo\3"+
		"\2\2\2rs\7,\2\2sv\7\61\2\2tv\7\2\2\3ur\3\2\2\2ut\3\2\2\2vw\3\2\2\2wx\b"+
		"\3\2\2x\6\3\2\2\2yz\7*\2\2z\b\3\2\2\2{|\7+\2\2|\n\3\2\2\2}~\7}\2\2~\f"+
		"\3\2\2\2\177\u0080\7\177\2\2\u0080\16\3\2\2\2\u0081\u0082\7]\2\2\u0082"+
		"\20\3\2\2\2\u0083\u0084\7_\2\2\u0084\22\3\2\2\2\u0085\u0086\7?\2\2\u0086"+
		"\u0087\7?\2\2\u0087\24\3\2\2\2\u0088\u0089\7#\2\2\u0089\u008a\7?\2\2\u008a"+
		"\26\3\2\2\2\u008b\u008c\7@\2\2\u008c\30\3\2\2\2\u008d\u008e\7>\2\2\u008e"+
		"\32\3\2\2\2\u008f\u0090\7>\2\2\u0090\u0091\7?\2\2\u0091\34\3\2\2\2\u0092"+
		"\u0093\7@\2\2\u0093\u0094\7?\2\2\u0094\36\3\2\2\2\u0095\u0096\7?\2\2\u0096"+
		" \3\2\2\2\u0097\u0098\7=\2\2\u0098\"\3\2\2\2\u0099\u009a\7.\2\2\u009a"+
		"$\3\2\2\2\u009b\u009c\7k\2\2\u009c\u009d\7h\2\2\u009d&\3\2\2\2\u009e\u009f"+
		"\7g\2\2\u009f\u00a0\7n\2\2\u00a0\u00a1\7u\2\2\u00a1\u00a2\7g\2\2\u00a2"+
		"(\3\2\2\2\u00a3\u00a4\7y\2\2\u00a4\u00a5\7j\2\2\u00a5\u00a6\7k\2\2\u00a6"+
		"\u00a7\7n\2\2\u00a7\u00a8\7g\2\2\u00a8*\3\2\2\2\u00a9\u00aa\7e\2\2\u00aa"+
		"\u00ab\7q\2\2\u00ab\u00ac\7p\2\2\u00ac\u00ad\7u\2\2\u00ad\u00ae\7v\2\2"+
		"\u00ae,\3\2\2\2\u00af\u00b0\7k\2\2\u00b0\u00b1\7p\2\2\u00b1\u00b2\7v\2"+
		"\2\u00b2.\3\2\2\2\u00b3\u00b4\7h\2\2\u00b4\u00b5\7n\2\2\u00b5\u00b6\7"+
		"q\2\2\u00b6\u00b7\7c\2\2\u00b7\u00b8\7v\2\2\u00b8\60\3\2\2\2\u00b9\u00ba"+
		"\7x\2\2\u00ba\u00bb\7q\2\2\u00bb\u00bc\7k\2\2\u00bc\u00bd\7f\2\2\u00bd"+
		"\62\3\2\2\2\u00be\u00c2\t\4\2\2\u00bf\u00c1\t\5\2\2\u00c0\u00bf\3\2\2"+
		"\2\u00c1\u00c4\3\2\2\2\u00c2\u00c0\3\2\2\2\u00c2\u00c3\3\2\2\2\u00c3\64"+
		"\3\2\2\2\u00c4\u00c2\3\2\2\2\u00c5\u00c9\t\6\2\2\u00c6\u00c8\t\7\2\2\u00c7"+
		"\u00c6\3\2\2\2\u00c8\u00cb\3\2\2\2\u00c9\u00c7\3\2\2\2\u00c9\u00ca\3\2"+
		"\2\2\u00ca\u00e0\3\2\2\2\u00cb\u00c9\3\2\2\2\u00cc\u00d0\7\62\2\2\u00cd"+
		"\u00cf\t\b\2\2\u00ce\u00cd\3\2\2\2\u00cf\u00d2\3\2\2\2\u00d0\u00ce\3\2"+
		"\2\2\u00d0\u00d1\3\2\2\2\u00d1\u00e0\3\2\2\2\u00d2\u00d0\3\2\2\2\u00d3"+
		"\u00d4\7\62\2\2\u00d4\u00d8\7z\2\2\u00d5\u00d6\7\62\2\2\u00d6\u00d8\7"+
		"Z\2\2\u00d7\u00d3\3\2\2\2\u00d7\u00d5\3\2\2\2\u00d8\u00dc\3\2\2\2\u00d9"+
		"\u00db\t\t\2\2\u00da\u00d9\3\2\2\2\u00db\u00de\3\2\2\2\u00dc\u00da\3\2"+
		"\2\2\u00dc\u00dd\3\2\2\2\u00dd\u00e0\3\2\2\2\u00de\u00dc\3\2\2\2\u00df"+
		"\u00c5\3\2\2\2\u00df\u00cc\3\2\2\2\u00df\u00d7\3\2\2\2\u00e0\66\3\2\2"+
		"\2\u00e1\u00e3\t\7\2\2\u00e2\u00e1\3\2\2\2\u00e3\u00e6\3\2\2\2\u00e4\u00e2"+
		"\3\2\2\2\u00e4\u00e5\3\2\2\2\u00e5\u00e7\3\2\2\2\u00e6\u00e4\3\2\2\2\u00e7"+
		"\u00e9\7\60\2\2\u00e8\u00ea\t\7\2\2\u00e9\u00e8\3\2\2\2\u00ea\u00eb\3"+
		"\2\2\2\u00eb\u00e9\3\2\2\2\u00eb\u00ec\3\2\2\2\u00ec\u00f4\3\2\2\2\u00ed"+
		"\u00ef\t\7\2\2\u00ee\u00ed\3\2\2\2\u00ef\u00f0\3\2\2\2\u00f0\u00ee\3\2"+
		"\2\2\u00f0\u00f1\3\2\2\2\u00f1\u00f2\3\2\2\2\u00f2\u00f4\7\60\2\2\u00f3"+
		"\u00e4\3\2\2\2\u00f3\u00ee\3\2\2\2\u00f4\u00fe\3\2\2\2\u00f5\u00f7\t\n"+
		"\2\2\u00f6\u00f8\t\13\2\2\u00f7\u00f6\3\2\2\2\u00f7\u00f8\3\2\2\2\u00f8"+
		"\u00fa\3\2\2\2\u00f9\u00fb\t\7\2\2\u00fa\u00f9\3\2\2\2\u00fb\u00fc\3\2"+
		"\2\2\u00fc\u00fa\3\2\2\2\u00fc\u00fd\3\2\2\2\u00fd\u00ff\3\2\2\2\u00fe"+
		"\u00f5\3\2\2\2\u00fe\u00ff\3\2\2\2\u00ff\u0140\3\2\2\2\u0100\u0102\t\7"+
		"\2\2\u0101\u0100\3\2\2\2\u0102\u0103\3\2\2\2\u0103\u0101\3\2\2\2\u0103"+
		"\u0104\3\2\2\2\u0104\u0105\3\2\2\2\u0105\u0107\t\n\2\2\u0106\u0108\t\13"+
		"\2\2\u0107\u0106\3\2\2\2\u0107\u0108\3\2\2\2\u0108\u010a\3\2\2\2\u0109"+
		"\u010b\t\7\2\2\u010a\u0109\3\2\2\2\u010b\u010c\3\2\2\2\u010c\u010a\3\2"+
		"\2\2\u010c\u010d\3\2\2\2\u010d\u0140\3\2\2\2\u010e\u010f\7\62\2\2\u010f"+
		"\u013d\t\f\2\2\u0110\u0112\t\t\2\2\u0111\u0110\3\2\2\2\u0112\u0115\3\2"+
		"\2\2\u0113\u0111\3\2\2\2\u0113\u0114\3\2\2\2\u0114\u0116\3\2\2\2\u0115"+
		"\u0113\3\2\2\2\u0116\u0118\7\60\2\2\u0117\u0119\t\t\2\2\u0118\u0117\3"+
		"\2\2\2\u0119\u011a\3\2\2\2\u011a\u0118\3\2\2\2\u011a\u011b\3\2\2\2\u011b"+
		"\u0123\3\2\2\2\u011c\u011e\t\t\2\2\u011d\u011c\3\2\2\2\u011e\u011f\3\2"+
		"\2\2\u011f\u011d\3\2\2\2\u011f\u0120\3\2\2\2\u0120\u0121\3\2\2\2\u0121"+
		"\u0123\7\60\2\2\u0122\u0113\3\2\2\2\u0122\u011d\3\2\2\2\u0123\u012d\3"+
		"\2\2\2\u0124\u0126\t\r\2\2\u0125\u0127\t\13\2\2\u0126\u0125\3\2\2\2\u0126"+
		"\u0127\3\2\2\2\u0127\u0129\3\2\2\2\u0128\u012a\t\t\2\2\u0129\u0128\3\2"+
		"\2\2\u012a\u012b\3\2\2\2\u012b\u0129\3\2\2\2\u012b\u012c\3\2\2\2\u012c"+
		"\u012e\3\2\2\2\u012d\u0124\3\2\2\2\u012d\u012e\3\2\2\2\u012e\u013e\3\2"+
		"\2\2\u012f\u0131\t\t\2\2\u0130\u012f\3\2\2\2\u0131\u0132\3\2\2\2\u0132"+
		"\u0130\3\2\2\2\u0132\u0133\3\2\2\2\u0133\u0134\3\2\2\2\u0134\u0136\t\r"+
		"\2\2\u0135\u0137\t\13\2\2\u0136\u0135\3\2\2\2\u0136\u0137\3\2\2\2\u0137"+
		"\u0139\3\2\2\2\u0138\u013a\t\t\2\2\u0139\u0138\3\2\2\2\u013a\u013b\3\2"+
		"\2\2\u013b\u0139\3\2\2\2\u013b\u013c\3\2\2\2\u013c\u013e\3\2\2\2\u013d"+
		"\u0122\3\2\2\2\u013d\u0130\3\2\2\2\u013e\u0140\3\2\2\2\u013f\u00f3\3\2"+
		"\2\2\u013f\u0101\3\2\2\2\u013f\u010e\3\2\2\2\u01408\3\2\2\2\u0141\u0142"+
		"\7-\2\2\u0142:\3\2\2\2\u0143\u0144\7/\2\2\u0144<\3\2\2\2\u0145\u0146\7"+
		",\2\2\u0146>\3\2\2\2\u0147\u0148\7\61\2\2\u0148@\3\2\2\2\u0149\u014a\7"+
		"\'\2\2\u014aB\3\2\2\2\u014b\u014d\t\16\2\2\u014c\u014b\3\2\2\2\u014d\u014e"+
		"\3\2\2\2\u014e\u014c\3\2\2\2\u014e\u014f\3\2\2\2\u014f\u0150\3\2\2\2\u0150"+
		"\u0151\b\"\2\2\u0151D\3\2\2\2\u0152\u0153\7^\2\2\u0153\u0158\7\f\2\2\u0154"+
		"\u0155\7^\2\2\u0155\u0156\7\17\2\2\u0156\u0158\7\f\2\2\u0157\u0152\3\2"+
		"\2\2\u0157\u0154\3\2\2\2\u0158\u0159\3\2\2\2\u0159\u015a\b#\2\2\u015a"+
		"F\3\2\2\2)\2LPW\\ceou\u00c2\u00c9\u00d0\u00d7\u00dc\u00df\u00e4\u00eb"+
		"\u00f0\u00f3\u00f7\u00fc\u00fe\u0103\u0107\u010c\u0113\u011a\u011f\u0122"+
		"\u0126\u012b\u012d\u0132\u0136\u013b\u013d\u013f\u014e\u0157\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}